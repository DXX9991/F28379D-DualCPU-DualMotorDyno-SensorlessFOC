/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu2_f28379d_private.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_dual_cpu2_f28379d'.
 *
 * Model version                  : 8.0
 * Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
 * C/C++ source code generated on : Wed Jul  1 19:10:49 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_dual_cpu2_f28379d_private_h_
#define mcb_pmsm_foc_dual_cpu2_f28379d_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d_types.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d.h"
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
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentSensing, "ramfuncs")

extern void mcb_pmsm_foc_CurrentSensing(void);
extern void mcb_pmsm__FocAlgorithm_Init(void);

#pragma CODE_SECTION (mcb_pmsm_foc_d_FocAlgorithm, "ramfuncs")

extern void mcb_pmsm_foc_d_FocAlgorithm(void);
extern void InverterDriverPeripher_Init(void);

#pragma CODE_SECTION (m_InverterDriverPeripherals, "ramfuncs")

extern void m_InverterDriverPeripherals(void);
extern void mc_SensorlessAlgorithm_Init(void);

#pragma CODE_SECTION (mcb_pms_SensorlessAlgorithm, "ramfuncs")

extern void mcb_pms_SensorlessAlgorithm(void);
extern void InverterDriverPeripher_Term(void);

#endif                           /* mcb_pmsm_foc_dual_cpu2_f28379d_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
