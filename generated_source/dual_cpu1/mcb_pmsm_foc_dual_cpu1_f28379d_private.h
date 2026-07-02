/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu1_f28379d_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_dual_cpu1_f28379d'.
 *
 * Model version                  : 9.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul  1 19:19:15 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_dual_cpu1_f28379d_private_h_
#define mcb_pmsm_foc_dual_cpu1_f28379d_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "mcb_pmsm_foc_dual_cpu1_f28379d.h"
#include "mcb_pmsm_foc_dual_cpu1_f28379d_types.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void InitAdcC (void);
void config_ADCC_SOC0 (void);
void InitAdcB (void);
void config_ADCB_SOC0 (void);
void config_ADCC_SOC1 (void);
void config_ADCB_SOC1 (void);
void config_ADCC_SOC2 (void);
void config_ADCB_SOC2 (void);
extern uint16_T MW_adcCInitFlag;
extern uint16_T MW_adcBInitFlag;
extern void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_d *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW);
extern void mcb_pmsm_foc_d_SpeedControl(boolean_T rtu_EnClosedLoop, boolean_T
  rtu_EnablePWM, real32_T rtu_Speed_Ref_PU, real32_T rtu_Speed_Meas_PU,
  rtB_SpeedControl_mcb_pmsm_foc_d *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW);
extern void mcb_pms_CurrentControl_Init(void);

#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

extern void mcb_pmsm_foc_CurrentControl(void);

#pragma CODE_SECTION (mcb_pmsm__Open_Loop_Control, "ramfuncs")

extern void mcb_pmsm__Open_Loop_Control(void);
extern void InverterDriverPeripher_Init(void);

#pragma CODE_SECTION (m_InverterDriverPeripherals, "ramfuncs")

extern void m_InverterDriverPeripherals(void);
extern void mcb_SensorDriverBlocks_Init(void);

#pragma CODE_SECTION (mcb_pmsm_SensorDriverBlocks, "ramfuncs")

extern void mcb_pmsm_SensorDriverBlocks(void);
extern void mc_SensorlessAlgorithm_Init(void);

#pragma CODE_SECTION (mcb_pms_SensorlessAlgorithm, "ramfuncs")

extern void mcb_pms_SensorlessAlgorithm(void);
extern void InverterDriverPeripher_Term(void);

#endif                           /* mcb_pmsm_foc_dual_cpu1_f28379d_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
