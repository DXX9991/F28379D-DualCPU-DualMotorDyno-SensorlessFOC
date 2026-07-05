# F28379D 双 CPU 无感 FOC 对拖 — 技术分析总结

> 基于 TI LAUNCHXL-F28379D + 2×BOOSTXL-DRV8305 + JIEMEIKANG 42JSF360AS-1000 电机，对 MathWorks Motor Control Blockset Dual Motor Dyno 示例的完整技术剖析。

---

## 目录

1. [系统架构概述](#1-系统架构概述)
2. [ADC 损坏根因分析](#2-adc-损坏根因分析)
3. [单核 vs 双核算力论证](#3-单核-vs-双核算力论证)
4. [QEP 有感 vs 无感架构差异](#4-qep-有感-vs-无感架构差异)
5. [SCI 数据采集与 int16 压缩](#5-sci-数据采集与-int16-压缩)
6. [Trip-Zone 保护缺失与 Safety Kernel 设计](#6-trip-zone-保护缺失与-safety-kernel-设计)
7. [电流环论文验证方法论](#7-电流环论文验证方法论)
8. [共识结论](#8-共识结论)

---

## 1. 系统架构概述

### 1.1 硬件拓扑

```
LAUNCHXL-F28379D (200 MHz, 双核 C28x)
  ├── CPU1: Motor 1 速度控制 + Host 串口 + IPC Master
  │     └── BOOSTXL-DRV8305 #1 → PMSM Motor 1 (JIEMEIKANG 42JSF360AS-1000)
  │
  └── CPU2: Motor 2 转矩控制 + IPC Slave
        └── BOOSTXL-DRV8305 #2 → PMSM Motor 2 (同型号)
             ↑
        Motor 1 ═══ Motor 2 (机械联轴，对拖/Dyno)
```

### 1.2 控制参数

| 参数 | 值 | 来源 |
|------|-----|------|
| PWM 频率 | 20 kHz | T_pwm = 50 μs |
| 电流环 Ts | 50 μs | = T_pwm |
| 速度环 Ts | 1 ms | = 20×Ts |
| 观测器 | Flux Observer (磁链观测器) | mcbsensorlessestimatorlib |
| 电流环 PI | Kp=4.95, Ki=6915.3 | mcb.internal.SetControllerParameters() |
| 速度环 PI | Kp=1.60, Ki=21.14 | 同上 |
| SMO/Flux 参数 | BackEmfObsGain=0.9, CutoffFreq=722 Hz | mcb_ComputeSMOParameters() |
| PU 基准 | V_base=13.86V, I_base=21.43A, N_base=3610 RPM | workspace_params_dump/PU_System.json |

### 1.3 IPC 通信

```
CPU1 ──→ CPU2:  转矩参考值 (Torque Reference)
                 信号选择 (Signal Select)
                 使能 Motor 2 (EnMtr2Ctrl)

CPU2 ──→ CPU1:  调试信号数据 (Debug Signals)
```

IPC 使用 SoC Blockset 的 MW_IPC_Params_T / MW_IPC_Handle 结构，通过 Core1-to-Core2 和 Core2-to-Core1 Message RAM 交换。

---

## 2. ADC 损坏根因分析

### 2.1 故障时序

```
Step 1: 300 RPM 指令 → 低于开环速度 (361 RPM = 0.1 PU)
        → 速度 PI 输出负 Iq (需要减速)
        → BEMF = 0.69V @ 300 RPM (仅为额定 3610 RPM 的 8%)

Step 2: Flux Observer 在低 BEMF 区信噪比崩溃
        Rs·I 压降 (0.89Ω × 1A = 0.89V) > BEMF (0.69V)
        → 磁链估计偏置 → 角度偏差 20°-30°
        → FOC 解耦失败 → 电流正反馈发散

Step 3: 两台电机机械耦合导致双向侵扰
        M1 观测器失稳 → 轴扭矩波动 → M2 观测器被干扰
        → M2 产生反向转矩 → "双电机打架" → 振荡无法衰减

Step 4: 尝试升速 → 速度 PI 输出巨大 Iq_ref
        → SMO/Flux Observer 锁住之前相电流已飙至额定值的 3-5 倍
        → 过流

Step 5: 过流 → DRV8305 INA240 输出逼近 3.3V rail
        → PWM 开关噪声叠加 (di/dt 尖峰可瞬间 > 1V)
        → ADC 引脚瞬间电压 = 3.3V + 1.2V ≈ 4.5V
        → 超过 VDDA + 0.3V (3.6V) 和绝对最大值 (4.6V) 之间的危险区

Step 6: ADC_A 和 ADC_C 共享 VREFHIA (缓冲器 U11)
        → 过压触发内部 VREF 污染链
        → ADC_A + ADC_C 同时通道损坏 (offset +145mV, 增益退化)
        → ADC_B 使用独立 VREFHIB (缓冲器 U19) → 完好

Step 7: Trip-Zone 全禁用 → 硬件无兜底
        EPwm1-6Regs.TZSEL.all = 0U → 无硬件关断路径
```

### 2.2 F28379D ADC 引脚损坏阈值

| 电压范围 | 状态 |
|---------|------|
| 0V ~ 3.0V | 正常线性转换 (VREFHI=3.0V) |
| 3.0V ~ 3.3V | ADC 饱和 (4095)，不损坏 |
| 3.3V ~ 3.6V | ESD 保护二极管正向导通，注入电流流入 VDDA 轨 |
| 3.6V ~ 4.6V | VREF 内部污染，持续注入电流 → 累积损伤 |
| > 4.6V | 绝对最大额定值，一次即可击穿 |

关键数据手册参数 (SPRS880)：
- 连续注入电流安全值：**±2 mA/引脚**
- 绝对最大钳位电流：**±20 mA** (单次应力)
- VREFHI 极限：**VDDA + 0.3V = 3.6V** (超过后阻断电路触发，VREFHI 内部浮空到 0V)

### 2.3 根因总结

**Flux Observer 在 BEMF 低于 Rs·I 噪声地板时失去了磁链可观测性，速度 PI 的减速指令恰使系统往"更难观测"的方向走，形成了致命的负斜率和 → 过流 → 无 Trip-Zone 保护 → ADC 硬件击穿。**

### 2.4 教训

- 无感 FOC 对拖的最低安全转速 ≈ **500 RPM**（远离 0.1 PU 开环边界）
- 启动时从开环 361 RPM 直接加速到 ≥ 1000 RPM，不在低速区逗留
- 必须在 ePWM 中启用 Trip-Zone 硬件保护

---

## 3. 单核 vs 双核算力论证

### 3.1 核心发现：单核 Sensorless 模型的 base rate 是 25 μs (非 50 μs)

```
从 ert_main.c 铁证:

双核 CPU1:  modelBaseRate = 5.0E-5  // 50 μs, ADC 中断触发
双核 CPU2:  modelBaseRate = 5.0E-5  // 50 μs, ADC 中断触发
单核无感:   modelBaseRate = 2.5E-5  // 25 μs, Timer0 触发  ← 关键!
QEP 单核:   modelBaseRate = 2.5E-5  // 25 μs, Timer0 触发
```

单核模型必须以 25 μs (两倍频率) 运行来模拟 Ts/2 交错效果，每次 step0() 处理两台电机的全部 FOC。

### 3.2 算力消耗对比

| 项目 | 单核无感 (25 μs) | 双核 (50 μs) |
|------|------|------|
| 可用 CPU cycles | 5,000 | 10,000 |
| 每电机 FOC + Observer | ~2,140 | ~2,140 |
| 两台电机 FOC | ~4,280 | — |
| ERT 框架膨胀 | ~800 | ~500 |
| ISR 开销 | ~200 | ~200 |
| SCI 串口 | ~100 | ~100 |
| **总计** | **~5,380** | **~2,940** |
| **负载率** | **108% ❌** | **29% ✅** |

### 3.3 结论

**单核在 25 μs 窗口里确实算不完两台电机的无感 FOC。** 双核不是为了"卖芯片"，是算力预算的必然结果。

---

## 4. QEP 有感 vs 无感架构差异

### 4.1 调度架构对比

| | QEP 单核 F28379D | 无感单核 F28379D | 无感双核 F28379D |
|------|------|------|------|
| 中断架构 | **2 个 ADC ISR** | **1 个 Timer0 ISR** | **2 个 ADC ISR** |
| M1/M2 控制执行 | 异步错峰 (硬件 Ts/2) | 同步串行 (同一次 ISR) | 异步错峰 (硬件 Ts/2) |
| 角度来源 | QEP 寄存器读 (~30 cycles) | Flux Observer (~570 cycles) | Flux Observer (~570 cycles) |
| 每个 ISR 算几台 | 1 台 | 2 台 | 1 台 |
| 峰值负载 | ~1,400 cycles | ~5,300 cycles | ~2,500 cycles |
| 算力是否够 | ✅ 28% | ❌ 106% | ✅ 25% |

### 4.2 为什么无感不能拆成双 ADC 中断

Flux Observer 和电流环在 Simulink 原子子系统内耦合——Observer 需要 Vd/Vq (电流环输出)，电流环需要 θ (Observer 输出)。两者必须在同一个 step 里执行。QEP 把角度变成硬件寄存器读，不存在这个耦合，所以可以拆。

### 4.3 结论

**QEP 版本省的不是"算力"，而是"架构耦合"——算力是副作用，根本差异在于观测器是否与电流环解耦。**

---

## 5. SCI 数据采集与 int16 压缩

### 5.1 当前数据流

```
每 50 μs 控制周期:
  M1 信号 (6选1 via Host Signal Select) ─┐
  M2 信号 (via IPC from CPU2)           ─┤
                                          ├→ Mux(2) → Byte Pack → Data_Logging
                                          └→ Data[2] (2×uint32)
                                                   ↓
                              Counter 0→599 (600 cycles = 30ms)
                                                   ↓
                              While Iterator → SCI_Tx_Data[3] → scia_xmit()
                                                   ↓
                              Start(12B) + 599×Data(8B) + End(12B)
                                                   ↓
                              总计 ~4,824 bytes / 30ms 帧
```

### 5.2 SCI 硬件特性 (F28379D)

- TX FIFO: **16 bytes (4×uint32)**
- RX FIFO: 16 bytes
- 最大波特率: LSPCLK/16 (LSPCLK 默认 50 MHz → 3.125 Mbps 理论最大)
  - 实际使用 12 Mbps 需要提高 LSPCLK 配置
- FIFO 后台发送：CPU 写 TXBUF 后立即返回，移位在硬件完成
- FIFO 排空速率 @12 Mbps 8N1: 1 byte / 0.833 μs

### 5.3 int16 压缩方案

**已验证方案** (test_int16_pack 模型 → ERT R2024b 代码生成):

```c
// 生成的优化代码 (Simulink 自动融合 Gain+DataTypeConv+Sum 三个 block):
test_int16_pack_Y.packed_u32 = ((uint32_T)tmp << 16U) + (uint32_T)tmp_0;

// 每信号: DataTypeConversion(single→int16, Round=Zero, Saturate=on)
// 无 floor() 调用, 无 memcpy → 直接 C cast + FPU 硬件指令
```

关键技术点：
- `RndMeth='Zero'` 绕过了 `floor()` 库调用（否则 ~40-60 cycles/信号）
- `ProdEqTarget='on'` 使能 ERT 表达式融合优化
- `Gain(65536)` 被自动强度削减为 `<< 16U`
- 实测：2 信号打包 → 1 条 C 语句, ~12 CPU cycles

### 5.4 扩展极限

| 方案 | 信号数 | byte/周期 | SCI 占用 | CPU 开销 | 推荐度 |
|------|--------|---------|---------|---------|--------|
| 当前 float | 2 | 8B | 13% | 0.1 μs | 基准 |
| **int16 压缩** | **8-10** | **16-20B** | **27-33%** | **0.4 μs** | **✅ 论文推荐** |
| int16 压缩 | 12 | 24B | 40% | ~7 μs (FIFO阻塞) | ⚠️ 边界 |
| int16 压缩 | 16+ | 32B+ | 53%+ | 持续阻塞 | ❌ 不建议 |

### 5.5 600 帧的设计意图

600 不是"缓冲 600 个再发"——数据每 50 μs 实时发送。600 是帧同步标记：

```
counter=0:   发 Start Marker → Host 知道"新一帧开始"
counter=1~598: 发纯数据
counter=599: 发 End Marker → Host 知道"帧结束"

作用:
  1. 串口丢字节后可通过下一个 Start Marker 自动恢复同步
  2. 600×50μs = 30ms = 精确的 FFT 窗口 (33.3 Hz 谱分辨率)
  3. 30ms @ 1000 RPM = 2 个完整电周期 → 可做 dq 验证
```

### 5.6 结论

**SCI 16-byte FIFO 已经提供了硬件 DMA 级别的后台发送能力。8-10 路 int16 压缩信号在 50 μs 周期中 CPU 开销 < 1%，完全不影响 FOC 算法。不需要也不应该把 SCI 搬运到 CPU2——省 0.4 μs 引入双核 IPC 依赖是负收益。**

---

## 6. Trip-Zone 保护缺失与 Safety Kernel 设计

### 6.1 铁证：Trip-Zone 全禁用

```c
// 所有模型 (双核无感 / 单核QEP / 单核无感) 的 6 个 ePWM 全部如此:
EPwm1Regs.TZSEL.all = 0U;          // 无任何 Trip 源
EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;  // 无中断

// TZ 动作已预设但永远不触发:
EPwm1Regs.TZCTL.bit.TZA = 3U;      // Force Low (如果被触发的话)
EPwm1Regs.TZCTL.bit.TZB = 3U;
// 但 TZSEL=0 → 无 Trip 源 → 永远不会触发 → 等于白设
```

### 6.2 当前示例的定位

> **这是"控制算法示例"，不是"面向危险调试的完整保护工程"。** — 保护链路的空白是故意的——MathWorks 和 TI 期望工程师在自己的项目中补齐。

### 6.3 推荐架构：三层保护

```
┌─────────────────────────────────┐
│ Algorithm Layer                  │
│ FOC / Sensorless / MIT / etc.   │
│ 输出: Vdq / duty / Idq_ref       │
└───────────────┬─────────────────┘
                ▼
┌─────────────────────────────────┐
│ Safety Kernel (软件)             │
│ Ia/Ib/Ic 过流/ ADC raw 检查     │
│ nFAULT 监控 / Fault Latch       │
│ 输出: pwm_enable, fault_code    │
└───────────────┬─────────────────┘
                ▼
┌─────────────────────────────────┐
│ Hardware Protection (硬件)       │
│ CMPSS / X-BAR / ePWM Trip-Zone  │
│ 异步硬件关断 (25ns), 不等CPU     │
└─────────────────────────────────┘
```

### 6.4 分阶段实现路径

| 阶段 | 内容 | 硬件改动 | 实现方式 |
|------|------|---------|---------|
| Phase 1 | 纯 SLX SafetySupervisor | 无 | Masked Subsystem + Simulink API |
| Phase 2 | ePWM Trip-Zone 配置 | 无 | 改 ePWM mask 参数 (C2000 Support Package 支持) |
| Phase 3 | nFAULT → Input X-BAR → TZ | 需确认 GPIO 映射 | Custom Code / C Caller |
| Phase 4 | CMPSS 相电流硬件窗口 | 需确认引脚是否有 CMPSS 功能 | Custom Code + 可能夹层板 |

### 6.5 ePWM Trip-Zone 配置能力

C2000 Support Package 的 ePWM block 包含完整的 Trip-Zone mask 参数：
- `tzselOSHT1-6`: 使能 One-Shot Trip
- `tzselCBC1-6`: 使能 Cycle-by-Cycle Trip
- `ePWMxAforced`, `ePWMxBforced`: Trip 后强制状态
- `enTzOstIntr`, `enTzCbcIntr`: Trip 中断使能
- `dcah/dcal/dcbh/dcbl`: Digital Compare 源选择

**已经过 API 验证可读写** — `set_param(epwm, 'tzselOSHT1', 'on')` 执行成功。

### 6.6 结论

**Simulink C2000 Support Package 完全支持通过 mask 参数配置 Trip-Zone，不需要手写寄存器代码。但 CMPSS 和 X-BAR 没有对应 Simulink block，必须通过 C Caller 或 Custom Code 实现。**

---

## 7. 电流环论文验证方法论

### 7.1 核心原则

**电流环验证不需要对拖。堵转测试 (Locked-Rotor Test) 是行业标准。**

原因：
- 电流环本质是电气动态 (L/R, 毫秒级)，而非机械动态 (J/B, 秒级)
- ω=0 时 d/q 电压方程解耦：Vd = Rs·Id, Vq = Rs·Iq
- 无交叉耦合 (−ωLq·Iq) 和无反电动势 (ω·λpm) 干扰
- 观测到的是 "纯 PI 调节器性能"

### 7.2 标准验证流程

```
Step 1 — 堵转电流阶跃 (核心):
  机械锁死转子 → 纯电流环控制 (无速度环)
  Id 阶跃: 0 → 0.3PU → 上升时间/超调/稳态误差
  Iq 阶跃: 0 → 0.5PU → 同上
  Id 阶跃时观察 Iq 扰动 → 评估 d/q 解耦性能

Step 2 — 频域扫频 (加分):
  注入 swept sine 或 chirp 到 Iq_ref
  → 闭环传函 → 电流环带宽 (Hz) → 与理论 ω_c 对比

Step 3 — 空转验证:
  释放转子 → 全速范围 Iq 阶跃 → 反电动势前馈验证

Step 4 — 对拖 (非必须):
  仅用于速度环抗扰验证和效率曲线
```

### 7.3 无感系统堵转注意事项

ω=0 时观测器不可收敛 → 堵转时必须切到**固定角度注入**：

```
CurrentControl 角度源 = Constant (θ=0, 对准 A 相)  [堵转模式]
CurrentControl 角度源 = Observer 输出              [正常运行]
```

Simulink 实现：一个 Constant block + Switch block 即可。

---

## 8. 共识结论

### 8.1 系统设计

1. **双核架构是算力必然** — 单核在 25 μs 窗口下跑两台无感 FOC + Flux Observer → 106% 超载
2. **Flux Observer 低速脆弱** — 300 RPM 时 BEMF < Rs·I 噪声地板, 磁链不可观测 → 对拖启动必须 ≥ 1000 RPM 后回调
3. **SCI 16-byte FIFO 已足够** — CPU 仅需填 FIFO (0.4 μs)，硬件后台发送；SCI 搬到 CPU2 是负收益的过度设计

### 8.2 保护链路

4. **Trip-Zone 全关是设计意图** — MathWorks/TI 的示例故意不配保护，期望工程师自行补齐
5. **Safety Kernel 应独立于算法** — 三层架构 (算法/软件保护/硬件保护) 可复用于所有控制模式切换
6. **C2000 Support Package 的 ePWM mask 支持 Trip-Zone 配置** — 不需要手写寄存器，但 CMPSS/X-BAR 需要 Custom Code

### 8.3 数据采集

7. **int16 压缩验证有效** — Simulink ERT R2024b 自动优化为 `(uint32_T)val << 16U`，和手写 C28x 汇编几乎同效
8. **8-10 路 int16 信号推荐** — CPU 开销 < 1%，SCI 占用 < 40%，满足对拖论文数据采集需求
9. **600 帧 = 同步标记, 非缓冲** — 数据实时每 50 μs 发送；600 提供 30ms FFT 窗口和丢字节自动恢复

### 8.4 论文验证

10. **电流环验证不需要对拖** — 堵转测试 (locked-rotor) 是行业标准；对拖仅用于速度环抗扰和效率曲线
11. **无感系统堵转需切固定角度** — ω=0 时观测器不可收敛，需旁路到常值角度

### 8.5 工程教训

12. **TI 示例 = 让你学, 不是让你直接用** — Trip-Zone 全关、无参数检查、无故障锁存。你在 300 RPM 烧板子的经历恰好暴露了所有缺省保护都缺失的工业事实。

---

*文档基于对以下内容的分析：*
- *Simulink 模型源码 (mcb_pmsm_foc_dual_cpu1/2_f28379d.slx 等)*
- *生成 C 代码 (mcb_pmsm_foc_dual_cpu*_ert_rtw/)*
- *MATLAB 参数脚本 (*_data.m, *_datascript.m)*
- *workspace_params_dump 运行时参数导出*
- *TI TMS320F28379D 数据手册 SPRS880*
- *LAUNCHXL-F28379D 用户指南 SPRUI77C*
- *DRV8305 数据手册*
- *Motor Control Blockset 文档*
- *C2000 Microcontroller Blockset (c2837xDlib) 库*
