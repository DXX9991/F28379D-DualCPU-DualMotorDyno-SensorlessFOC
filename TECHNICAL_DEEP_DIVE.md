# Technical Deep Dive: F28379D Dual-CPU Dual-Motor Dyno

> 本文档补充 README 中缺失的关键技术细节，从 PI 参数、SMO 观测器、IPC 通信到 C 代码映射，覆盖系统完整设计。

---

## ① 控制参数详解 (PI / SMO / Observer)

### 时间基准

| 参数 | 值 | 说明 |
|------|-----|------|
| PWM 频率 | **20 kHz** | T_pwm = 50 μs |
| 电流环采样时间 Ts | **50 μs** | = T_pwm |
| 速度环采样时间 Ts_speed | **1 ms** | = 20×Ts |
| 仿真步长 Ts_simulink | **25 μs** | = T_pwm/2 (仿真用) |
| 系统时钟 | **200 MHz** | F28379D CPU clock |

### PI 参数计算

PI 参数通过 MathWorks Motor Control Blockset 内部函数计算：

```matlab
PI_params = mcb.internal.SetControllerParameters(pmsm, inverter, PU_System, T_pwm, 2*Ts, Ts_speed);
```

该函数基于以下公式（Motor Control Blockset 文档）：

**电流环 PI (d/q 轴)**：
- 带宽设计: ω_c = 2π ⋅ f_c, 典型 f_c ≈ PWM_freq / 20 = 1 kHz
- Kp_dq = ω_c ⋅ L_dq (d/q 轴电感)
- Ki_dq = ω_c ⋅ R_s (定子电阻)
- 实际值取决于电机参数和 PU 系统

**速度环 PI**：
- 带宽设计: ω_s ≈ 2π ⋅ 50 Hz (典型值，远低于电流环)
- Kp_speed = J / (Kt ⋅ τ_speed)
- Ki_speed = B / (Kt ⋅ τ_speed)
- 其中 J = 惯量, Kt = 转矩常数, B = 摩擦系数

### SMO (滑模观测器) 参数

```matlab
smo = mcb_ComputeSMOParameters(pmsm, Ts, PU_System);
```

该函数计算以下 SMO 参数（基于 MCB 文档）：

| 参数 | 公式/值 | 说明 |
|------|---------|------|
| SMO Gain (k) | k > max(|e_α|, |e_β|) | 滑模增益 — 需覆盖反电动势幅度 |
| LPF 截止频率 | 典型 200–500 Hz | SMO 输出低通滤波 |
| PLL 比例增益 | 取决于期望带宽 | 用于角度/速度估计的 PLL |
| PLL 积分增益 | Kp²/(4⋅Ts) | PLL 阻尼设计 |

**SMO 结构**（基于 MCB `mcb_pms_SensorlessAlgorithm`）：
```
                   ┌──────────┐
  v_αβ ──→ │  Current  │──→ i_αβ_est
  i_αβ ──→ │  Observer │──→ e_αβ (BEMF)
            └──────────┘        │
                           ┌────▼────┐     ┌─────┐
                           │   LPF   │──→│ PLL │──→ θ_est, ω_est
                           └─────────┘     └─────┘
```

### 开环启动参数

| 参数 | 值 | 说明 |
|------|-----|------|
| T_Ref_openLoop | **1 s** | 开环启动持续时间 |
| Speed_openLoop_PU | **0.1 PU** | 开环参考速度 (10% 额定) |
| Vd_Ref_openLoop_PU | **0.1 PU** | 开环 d 轴电压 |
| Acceleration | 20000/N_base PU/s | 最大加速度限制 |

### 电机参数 (JIEMEIKANG 42JSF360AS-1000 × Teknic 2310P)

| 参数 | JIEMEIKANG | Teknic 2310P |
|------|-----------|-------------|
| 极对数 p | 4 | 4 |
| Rs (定子电阻) | 0.89 Ω | — |
| Ld/Lq | 0.64 mH / 0.64 mH | — |
| Ke (反电动势) | 4 Vpk_LL/krpm | — |
| Kt (转矩常数) | 0.059 Nm/A | — |
| J (惯量) | 2.8×10⁻⁵ kg·m² | — |
| I_rated | 4 A (peak) | — |
| N_max | 4000 RPM | — |

### 逆变器参数 (BoostXL-DRV8305)

| 参数 | 值 |
|------|-----|
| Vdc | 24V |
| ISenseMax | 经 ADC 增益校准 |
| ADC Offset Calibration | 自动启用 (ADCOffsetCalibEnable=1) |
| ADCGain | 1 (默认 SPI 增益) |

---

## ② 控制状态机 (Control State Machine)

> **关键发现**: 所有模型均**不使用 Stateflow**。`_stateflow_matlabfunction.json` 全部为空 `[]`。

控制序列通过 **Simulink Enabled Subsystem + Switch 逻辑** 实现，位于生成代码的
`mcb_pmsm__Open_Loop_Control()` 和 `mcb_pmsm_foc_d_SpeedControl()` 函数中。

### 启动序列 (Inferred from code structure)

```
RESET ──→ ALIGN ──→ OPEN_LOOP ──→ CLOSED_LOOP (Sensorless FOC)
                        │
                        │ (T_Ref_openLoop = 1s elapsed)
                        │
                        ▼
                  CLOSED_LOOP with SMO observer
```

- **ALIGN**: 施加固定 d 轴电压，转子对齐到已知位置
- **OPEN_LOOP**: `mcb_pmsm__Open_Loop_Control()` — 1 秒内强制 Vd=0.1PU, 频率 ramp-up
- **CLOSED_LOOP**: `mcb_pmsm_foc_d_SpeedControl(EnClosedLoop=true, ...)` — 切换到 SMO 估计角度 + 速度 PI 闭环

### 模式切换 (Dyno/Torque/Speed)

在双 CPU 配置中：
- CPU1=Speed mode (always), CPU2=Torque mode (always)
- 模式通过 IPC `Signal Select` 字段切换调试信号源
- 单 CPU 无感模型 (`mcb_pmsm_foc_sensorless_dyno_f28379d`) 中 Motor 2 始终为转矩模式

### Fault Handling

- 在线错误检测：`rtmGetErrorStatus()` 轮询检查
- 错误时模型终止 (`mcb_pmsm_foc_dual_cpu1_f28379d_terminate()`)
- 没有显式的 FSM 状态机 — 错误检测分布在 Simulink 模块内部（过流、过压等通过 C2000 硬件保护）

---

## ③ Simulink 库依赖分析

### 核心库引用

从 `_blocks.json` 中的 `ReferenceBlock` 字段提取的关键库链接：

| 库 | 典型 Block | 说明 |
|----|-----------|------|
| `mcbcontrolslib/Clarke Transform` | Clarke 变换 | αβ ← abc |
| `mcbcontrolslib/DQ Limiter` | DQ 电流限幅 | 电压/电流饱和处理 |
| `mcbcontrolslib/D-Q Equivalence` | DQ 电压等效 | Vd/Vq 电压约束 |
| `mcbcontrolslib/Inverse Park Transform` | 反 Park 变换 | Vαβ ← Vdq |
| `mcbcontrolslib/Park Transform` | Park 变换 | Idq ← Iαβ |
| `mcbcontrolslib/SVPWM` | 空间矢量 PWM | 7 段式 SVPWM |
| `mcbcontrolslib/PI Controller` | PI 调节器 | d/q 轴电流 PI + 速度 PI |
| `mcbcontrolslib/Speed Control` | 速度控制 | 包含斜坡 + PI + 限幅 |
| `mcbcontrolslib/Flux Observer` | 磁链观测器 | SMO 核心 (仅无感模型) |
| `mcbcontrolslib/SMO` | 滑模观测器 | BEMF 估计 |
| `mcbcontrolslib/PLL` | 锁相环 | 角度/速度估计 |

### C2000 硬件块 (代码生成)

| BlockType | 功能 |
|-----------|------|
| `C28xADC` / `C280xADC` | ADC 采样 (Ia, Ib, Vdc) |
| `C28xPWM` / `C280xPWM` | ePWM1-6 生成 |
| `C28xSCI` / `C280xSCI` | 串口通信 (12 Mbps) |
| `IPC Write` / `IPC Read` | CPU 间通信 (SoC Blockset) |
| `Memory Copy` | CPU2 读取 CPU1 的 ADC 寄存器 |
| `Hardware Interrupt` | ADC 中断调度 |
| `GPIO` | 数字 I/O |

### 黑盒说明

这些 MCB (Motor Control Blockset) 块是 MathWorks **知识产权保护的实现**：
- 块的**内部结构**在 `mcbcontrolslib` 中部分可见（可双击展开查看子系统）
- 但核心算法（如 PI 具体公式、SMO 离散化实现）可能在 C MEX S-Function 层
- **生成代码中可见完整实现**（见第 ⑤ 节 C 代码映射）

---

## ④ IPC 通信细节 (双 CPU 核心)

### IPC 数据结构

两个 CPU 使用相同的 IPC 类型定义（来自 `mw_soc_ipc.h` 和 `mw_soc_c2000_ipc.h`）：

```c
// IPC Write 块结构 (CPU1 → CPU2)
struct tag_r8oIyYm4oPAMO6WFmhubcB {
    boolean_T matlabCodegenIsDeleted;
    int32_T isInitialized;
    boolean_T isSetupComplete;
    MW_IPC_Params_T IpcParams;   // IPC 通道参数
    MW_IPC_Handle IpcHandle;     // IPC 句柄
    uint64_T Overwritten;        // 覆盖计数
    uint16_T NumBufUsed;         // 缓冲区使用量
};

// IPC Read 块结构 (CPU2 ← CPU1)
struct tag_kIMAP1tg9kyzXjx3AcFoiG {
    boolean_T matlabCodegenIsDeleted;
    int32_T isInitialized;
    boolean_T isSetupComplete;
    MW_IPC_Params_T IpcParams;
    MW_IPC_Handle IpcHandle;
};
```

### IPC 信号映射

```
┌─────────────────────── CPU1 ───────────────────────┐
│                                                     │
│  IPC Write (CPU1→CPU2 Message RAM)                  │
│  ┌─────────────────────────────────────────────┐   │
│  │ Signal 0: Torque Reference (转矩参考值)       │   │
│  │ Signal 1: Signal Select (调试信号选择)        │   │
│  │ Signal 2: Enable Motor 2 (EnMtr2Ctrl)       │   │
│  └─────────────────────────────────────────────┘   │
│                                                     │
│  IPC Read (CPU2→CPU1 Message RAM)                   │
│  ┌─────────────────────────────────────────────┐   │
│  │ Signal 0: Debug Data from CPU2              │   │
│  │   (selectable: Idq, speed, Vdq, etc.)       │   │
│  └─────────────────────────────────────────────┘   │
│                                                     │
│  Host Serial (SCI @ 12 Mbps)                        │
│  ┌─────────────────────────────────────────────┐   │
│  │ ← Speed Ref (RPM) from Host                  │   │
│  │ ← Iq Ref (A) from Host → forwarded to CPU2  │   │
│  │ → Logged Data to Host (via Debug Select)     │   │
│  └─────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────┘

┌─────────────────────── CPU2 ───────────────────────┐
│                                                     │
│  IPC Read (CPU1→CPU2 Message RAM)                   │
│  ┌─────────────────────────────────────────────┐   │
│  │ ← Torque Reference from CPU1                │   │
│  │ ← Signal Select from CPU1                   │   │
│  │ ← EnMtr2Ctrl from CPU1                      │   │
│  └─────────────────────────────────────────────┘   │
│                                                     │
│  IPC Write (CPU2→CPU1 Message RAM)                  │
│  ┌─────────────────────────────────────────────┐   │
│  │ → Selected Debug Signal to CPU1             │   │
│  └─────────────────────────────────────────────┘   │
│                                                     │
│  Memory Copy (ADC registers from CPU1)              │
│  ┌─────────────────────────────────────────────┐   │
│  │ Ia2, Ib2, Vdc2 ← read from CPU1 ADC result  │   │
│  └─────────────────────────────────────────────┘   │
└─────────────────────────────────────────────────────┘
```

### Rate Transition Strategy

- **IPC 同步**: 两个 CPU 以相同的 20 kHz PWM 频率运行
- **电流环偏移 Ts/2**: CPU1 和 CPU2 的电流环在 ePWM 周期内偏移 50%，降低 DC-link 电流纹波
- **IPC 数据传输**: 在每次控制迭代中同步（IPC Write 在 CPU1 step0 后，IPC Read 在 CPU2 step0 前）
- **ADC 共享**: CPU1 拥有两个逆变器的 ADC 通道；CPU2 通过 Memory Copy 块访问逆变器 2 的 ADC 数据

---

## ⑤ Block → C Function 映射

### CPU1 (Speed Control Core)

| Simulink Block / Subsystem | C Function | 执行位置 |
|---|---|---|
| Current Control (d/q PI) | `mcb_pmsm_foc_CurrentControl()` | ramfuncs (ISR) |
| Open Loop Control | `mcb_pmsm__Open_Loop_Control()` | ramfuncs (ISR) |
| Inverter / PWM Driver | `m_InverterDriverPeripherals()` | ramfuncs (ISR) |
| Sensor Driver (ADC) | `mcb_pmsm_SensorDriverBlocks()` | ramfuncs (ISR) |
| Sensorless Algorithm (SMO) | `mcb_pms_SensorlessAlgorithm()` | ramfuncs (ISR) |
| Speed Control (PI + Ramp) | `mcb_pmsm_foc_d_SpeedControl()` | 主循环 (非 ISR) |
| Current Control Init | `mcb_pms_CurrentControl_Init()` | 初始化 |
| ADC Init | `InitAdcC()`, `InitAdcB()` | 初始化 |
| ADC SOC Config | `config_ADCC_SOC0-2()`, `config_ADCB_SOC0-2()` | 初始化 |
| System Init | `mcb_pmsm_foc_dual_cpu1_f28379d_initialize()` | 初始化 |

### CPU2 (Torque Control Core)

| Simulink Block / Subsystem | C Function | 执行位置 |
|---|---|---|
| Current Sensing | `mcb_pmsm_foc_CurrentSensing()` | ramfuncs (ISR) |
| FOC Algorithm (d/q PI + transforms) | `mcb_pmsm_foc_d_FocAlgorithm()` | ramfuncs (ISR) |
| Inverter / PWM Driver | `m_InverterDriverPeripherals()` | ramfuncs (ISR) |
| Sensorless Algorithm (SMO) | `mcb_pms_SensorlessAlgorithm()` | ramfuncs (ISR) |
| FOC Init | `mcb_pmsm__FocAlgorithm_Init()` | 初始化 |

### ISR 结构与控制流

```
定时器 / ADC 中断触发 (20 kHz, T=50μs)
│
├─ ADCINT1 ISR ─→ rt_OneStep()
│   │
│   ├─ [step0: 50μs]    mcb_pmsm_foc_dual_cpu1_f28379d_step0()
│   │   ├── mcb_pmsm_SensorDriverBlocks()    // 读 ADC (Ia, Ib, Vdc)
│   │   ├── mcb_pms_SensorlessAlgorithm()    // SMO 估计 θ, ω
│   │   ├── [Open Loop 分支]
│   │   │   └── mcb_pmsm__Open_Loop_Control()  // ALIGN→OPEN_LOOP
│   │   ├── [Closed Loop 分支]
│   │   │   ├── mcb_pmsm_foc_CurrentControl()  // d/q PI 电流环
│   │   │   └── m_InverterDriverPeripherals()    // 更新 ePWM 占空比
│   │   └── IPC Write → CPU2 (torque_ref, debug_select, enable)
│   │
│   ├─ [step1: 100μs]   step1() — 预留 sub-rate
│   ├─ [step2: 200μs]   step2() — 预留 sub-rate
│   └─ [step3: 1000μs]  step3()
│       └── mcb_pmsm_foc_d_SpeedControl()    // 速度 PI (1ms)
│           ├── 速度 PI 计算
│           ├── 斜坡限幅 (acceleration = 20000/N_base PU/s)
│           └── 输出: Iq_ref → 给到 step0 的电流环
│
└─ 主循环 main()
    ├── 初始化 (ADC, ePWM, IPC, SCI)
    ├── while(runModel)  // 空转等待
    └── 终止 (安全关闭 PWM)
```

### ePWM 同步时序

```
ePWM1 ────┐                  ┌────────────
ePWM2 ────┤  Motor 1          │  (Inverter 1)
ePWM3 ────┘  (sync out)      │
           │                  │
           │  Ts/2 offset    │  ← ePWM3 SYNC → ePWM4 phase offset
           │                  │
ePWM4 ────┐                  │  ┌────────────
ePWM5 ────┤  Motor 2          │  (Inverter 2)
ePWM6 ────┘                  │  │
                              ▼  ▼
           |← T_pwm=50μs →|
```

---

## ⑥ 代码生成配置

| 参数 | 值 |
|------|-----|
| System Target File | `ert.tlc` (Embedded Real-Time) |
| Solver | FixedStepDiscrete |
| Hardware Board | TI Delfino F28379D LaunchPad |
| Data Type | `single` (32-bit floating point) |
| Parameter Behavior | Inlined |
| Code Generation Objectives | Unspecified |
| Compiler Word Size | 16-bit (C2000 C28x) |

---

## ⑦ 关键信息源索引

| 要找的信息 | 去看哪个文件 |
|-----------|------------|
| PI 参数计算 | `*_data.m` / `*_datascript.m` → `mcb.internal.SetControllerParameters()` |
| SMO 参数计算 | `*_datascript.m` → `mcb_ComputeSMOParameters()` |
| 电机参数 | `*_datascript.m` (JIEMEIKANG) 或 `*_data.m` (Teknic) |
| Block → C Function | `generated_source/*/private.h` |
| ISR 结构 | `generated_source/*/ert_main.c` |
| IPC 数据结构 | `generated_source/*/types.h` |
| Library 依赖 | `slx_export/*_blocks.json` → `ReferenceBlock` 字段 |
| 控制时序 | `ert_main.c` → `modelBaseRate` + step 序列 |
| 开环/闭环逻辑 | 生成代码中 `_Open_Loop_Control()` + `_SpeedControl(EnClosedLoop,...)` |
| ADC/PWM 配置 | `private.h` → `InitAdc*()`, `config_ADCB_SOC*()`, `config_ePWM_TBSync()` |
