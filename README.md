# F28379D Dual-CPU Dual-Motor Dyno with Sensorless FOC

基于 **TI Delfino F28379D** 双核处理器的**双电机对拖（Dyno）** 平台，采用**无传感器 FOC（Field-Oriented Control）** 算法，使用 MATLAB/Simulink **模型化设计（MBD）** 方法开发。

> 原始示例来自 MathWorks® Motor Control Blockset™ — Dual Motor Dyno Using C2000 Processors Example.
> Copyright 2021-2024 The MathWorks, Inc.

---

## 系统架构

```
┌─────────────────────────────────────────────────────────┐
│                   LAUNCHXL-F28379D                      │
│  ┌───────────────┐    IPC     ┌───────────────┐        │
│  │   CPU1 (Core) │◄──────────►│   CPU2 (Core) │        │
│  │               │            │               │        │
│  │  Motor 1      │            │  Motor 2      │        │
│  │  速度控制模式  │            │  转矩控制模式  │        │
│  │  Speed Ctrl   │            │  Torque Ctrl  │        │
│  │  + FOC + SMO  │            │  + FOC + SMO  │        │
│  └───┬───────────┘            └───┬───────────┘        │
│      │                            │                    │
│  ┌───▼───────────┐    ┌──────────▼───────────┐        │
│  │ BOOSTXL-      │    │ BOOSTXL-            │        │
│  │ DRV8305 #1    │    │ DRV8305 #2          │        │
│  │ (Inverter 1)  │    │ (Inverter 2)        │        │
│  └───┬───────────┘    └──────────┬───────────┘        │
│      │                            │                    │
│  ┌───▼────────────────────────────▼───────────┐        │
│  │         PMSM Motor 1 ═══ PMSM Motor 2      │        │
│  │            (机械耦合 / 对拖)                 │        │
│  └─────────────────────────────────────────────┘        │
│                         │                               │
│                    Serial (SCI)                         │
│                         │                               │
│              ┌──────────▼──────────┐                    │
│              │   Host Model (PC)   │                    │
│              │   速度/转矩指令 + 监控 │                   │
│              └─────────────────────┘                    │
└─────────────────────────────────────────────────────────┘
```

- **Motor 1** (CPU1): 闭环速度控制 — 作为原动机（Prime Mover）
- **Motor 2** (CPU2): 转矩控制 — 作为负载（Load/Dyno）
- 两电机机械耦合（背靠背连接），可在不同负载条件下测试电机性能
- 双核通过 **IPC（Inter-Processor Communication）** 交换数据
- 电流环在 M1/M2 间偏移 **Ts/2**，减小电流纹波
- 支持 **无传感器 FOC**（基于滑模观测器 SMO 的位置/速度估计）

---

## 文件说明

### 目标模型（部署到 F28379D）

| 文件 | CPU | 控制模式 | 说明 |
|------|-----|---------|------|
| `mcb_pmsm_foc_dual_cpu1_f28379d.slx` | CPU1 | 速度控制 | 双核模型 — Motor 1 速度环 + 电流环 + 串口通信 |
| `mcb_pmsm_foc_dual_cpu2_f28379d.slx` | CPU2 | 转矩控制 | 双核模型 — Motor 2 转矩环 + 电流环 |
| `mcb_pmsm_foc_sensorless_dyno_f28379d.slx` | 单核 | 速度 + 转矩 | 单核双电机无感 FOC（支持仿真） |

### 主机模型（PC 端监控界面）

| 文件 | 说明 |
|------|------|
| `mcb_pmsm_foc_dual_host_model.slx` | 双CPU 配置的主机界面 |
| `mcb_pmsm_foc_host_model_dyno_f28379d.slx` | 单核无感 FOC 的主机界面 |

### 算法库

| 文件 | 说明 |
|------|------|
| `current_control.slx` | 电流环控制库（PI 调节器、Clarke/Park 变换） |
| `foc_sensorless_algorithm.slx` | 无感 FOC 算法库（磁链观测器、SMO） |
| `sensorless_algorithm.slx` | 无感算法变体库 |

### 参数脚本（运行模型前执行）

| 文件 | 电机型号 | 适用模型 |
|------|---------|---------|
| `mcb_pmsm_foc_dual_f28379d_data.m` | Teknic 2310P | 双CPU |
| `mcb_pmsm_foc_dual_f28379d_datascript.m` | JIEMEIKANG 42JSF360AS-1000 | 双CPU |
| `mcb_pmsm_foc_sensorless_dyno_f28379d_data.m` | Teknic 2310P | 单CPU 无感 |
| `mcb_pmsm_foc_sensorless_dyno_f28379d_datascript.m` | JIEMEIKANG 42JSF360AS-1000 | 单CPU 无感 |
| `soc_mcb_pmsm_foc_dyno_f28379d_data.m` | Teknic 2310P (SoC) | SoC Blockset 分区变体 |

### 重定向脚本

| 文件 | 说明 |
|------|------|
| `c28379dpmsmfocdual_cpu1_ert.m` | CPU1 模型入口 |
| `c28379dpmsmfocdual_cpu2_ert.m` | CPU2 模型入口 |
| `c28377Spmsmfocdual_ert.m` | F28379D 系列入口（旧命名） |

---

## 硬件需求

- **控制器**: [LAUNCHXL-F28379D](https://www.ti.com/tool/LAUNCHXL-F28379D) (TI Delfino F28379D LaunchPad)
- **逆变器**: 2× [BOOSTXL-DRV8305](https://www.ti.com/tool/BOOSTXL-DRV8305) (或 BOOSTXL-3PHGANINV)
- **电机**: 2× 三相 PMSM（如 Teknic M-2310P 或 JIEMEIKANG 42JSF360AS-1000），机械耦合
- **电源**: 24V DC 输入

## 软件需求

- MATLAB & Simulink
- Motor Control Blockset™
- Embedded Coder®
- C2000™ Microcontroller Blockset
- Fixed-Point Designer™（仅优化代码生成时需要）
- TI Code Composer Studio™

## 关键技术参数

| 参数 | 值 |
|------|-----|
| PWM 频率 | 20 kHz |
| 电流环采样时间 | 50 μs (Ts = 1/PWM_freq) |
| 速度环采样时间 | 1 ms (20×Ts) |
| 控制算法 | 无传感器 FOC + 滑模观测器 (SMO) |
| PWM 同步 | ePWM1/2/3 与 ePWM4/5/6 偏移半个周期 |
| 调度方式 (双核) | ADC 中断触发 |
| 调度方式 (单核) | Timer0 基速率触发 |
| CPU 间通信 | IPC (Inter-Processor Communication) |
| 串口波特率 | 12 Mbps |

## 自定义电机参数 (JIEMEIKANG 42JSF360AS-1000)

| 参数 | 值 |
|------|-----|
| 极对数 | 4 |
| 相电阻 | 0.89 Ω |
| 相电感 | 0.64 mH |
| 反电动势常数 | 7.06 Vpk_LL/krpm |
| 转矩常数 | 0.059 Nm/A |
| 额定转速 | 3000 RPM |
| 额定电流 | 3.0 A |

---

## 快速开始

1. 在 MATLAB 中打开此文件夹
2. 运行对应参数脚本（如 `mcb_pmsm_foc_dual_f28379d_data.m`）
3. 打开目标模型（如 `mcb_pmsm_foc_dual_cpu1_f28379d.slx`）
4. 编译部署：Hardware 选项卡 → **Build, Deploy & Start**
5. 对 CPU2 重复步骤 3-4
6. 打开主机模型监控运行

> **注意**: 双核模型不支持仿真（仅代码生成和部署）。单核无感模型 (`mcb_pmsm_foc_sensorless_dyno_f28379d.slx`) 既支持仿真也可部署。

---

## IPC 通信数据流

```
CPU1 ──→ CPU2:  转矩参考值 (Torque Reference)
                 信号选择 (Signal Select)
                 使能 Motor 2 (EnMtr2Ctrl)

CPU2 ──→ CPU1:  调试信号数据 (Debug Signals)
```

- CPU1 写入 Core1-to-Core2 Message RAM，读取 Core2-to-Core1 Message RAM
- CPU2 写入 Core2-to-Core1 Message RAM，读取 Core1-to-Core2 Message RAM

---

## 参考文献

- [MathWorks Dual Motor Dyno Using C2000 Processors](https://www.mathworks.com/help/c2b/ug/dual-motor-dyno-using-c2000-processors.html)
- [TI F28379D LaunchPad](https://www.ti.com/tool/LAUNCHXL-F28379D)
- [Motor Control Blockset Documentation](https://www.mathworks.com/help/mcb/)
