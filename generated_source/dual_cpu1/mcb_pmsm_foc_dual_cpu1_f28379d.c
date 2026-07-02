/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu1_f28379d.c
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

#include "mcb_pmsm_foc_dual_cpu1_f28379d.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_dual_cpu1_f28379d_types.h"
#include "mcb_pmsm_foc_dual_cpu1_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "mw_soc_ipc.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_dual_cpu1_ mcb_pmsm_foc_dual_cpu1_f28379_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_dual_cpu1_f mcb_pmsm_foc_dual_cpu1_f2_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_mcb_pmsm_foc_du mcb_pmsm_foc_dua_PrevZCSigState;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_dual_cpu1 mcb_pmsm_foc_dual_cpu1_f2837_M_;
RT_MODEL_mcb_pmsm_foc_dual_cpu1 *const mcb_pmsm_foc_dual_cpu1_f2837_M =
  &mcb_pmsm_foc_dual_cpu1_f2837_M_;

/* Forward declaration for local functions */
static void mcb_pmsm_foc_d_SystemCore_setup(soc_blocks_IPCRead_mcb_pmsm_foc *obj);
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_dual_cpu1_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_dual_cpu1_f2837_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_dual_cpu1_f2837_M, 2));
  eventFlags[3] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_dual_cpu1_f2837_M, 3));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[1]) > 19) {/* Sample time: [0.001s, 0.0s] */
    mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[2]) > 199) {/* Sample time: [0.01s, 0.0s] */
    mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[2] = 0;
  }

  (mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[3])++;
  if ((mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[3]) > 9999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_dual_cpu1_f2837_M->Timing.TaskCounters.TID[3] = 0;
  }
}

/* System initialize for atomic system: '<S2>/Current Control' */
void mcb_pms_CurrentControl_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S137>/Integrator' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_PrevResetState = 0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_IC_LOADING = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S82>/Integrator' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_PrevResetState_e = 0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_IC_LOADING_b = 1U;
}

/* Output and update for atomic system: '<S2>/Current Control' */
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")

void mcb_pmsm_foc_CurrentControl(void)
{
  real32_T Bias;
  real32_T u0;
  uint32_T Sum;
  int16_T Integrator_PrevResetState_tmp;
  boolean_T LogicalOperator_n_tmp;
  boolean_T tmp;

  /* SignalConversion generated from: '<S15>/SCI_Tx' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Ia =
    mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[0];

  /* SignalConversion generated from: '<S15>/SCI_Tx' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Speedfb =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[1];

  /* SignalConversion generated from: '<S15>/SCI_Tx' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Pos_pu =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq;

  /* Outputs for Atomic SubSystem: '<S26>/Two phase CRL wrap' */
  /* Sum: '<S27>/a_plus_2b' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.a_plus_2b =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[0] +
     mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[1]) +
    mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[1];

  /* Gain: '<S27>/one_by_sqrt3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_sqrt3 = 0.577350259F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S27>/a16' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_k =
    mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[0];

  /* AlgorithmDescriptorDelegate generated from: '<S27>/a16' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_d =
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_sqrt3;

  /* End of Outputs for SubSystem: '<S26>/Two phase CRL wrap' */

  /* Switch: '<S33>/Switch1' incorporates:
   *  Constant: '<S33>/ChosenMethod'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_e = 3U;

  /* RelationalOperator: '<S163>/Compare' incorporates:
   *  Constant: '<S163>/Constant'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Compare =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq < 0.0F);

  /* DataTypeConversion: '<S161>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_e =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Compare;

  /* If: '<S161>/If' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_e > 0U) {
    /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem' incorporates:
     *  ActionPort: '<S164>/Action Port'
     */
    /* DataTypeConversion: '<S164>/Convert_uint16' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_uint16_e = (int16_T)(real32_T)floor
      (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq);

    /* DataTypeConversion: '<S164>/Convert_back' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_back_h =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_uint16_e;

    /* Merge: '<S161>/Merge' incorporates:
     *  Sum: '<S164>/Sum'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq -
      mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_back_h;

    /* End of Outputs for SubSystem: '<S161>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S161>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S165>/Action Port'
     */
    /* DataTypeConversion: '<S165>/Convert_uint16' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_uint16 = (int16_T)
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq;

    /* DataTypeConversion: '<S165>/Convert_back' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_back =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_uint16;

    /* Merge: '<S161>/Merge' incorporates:
     *  Sum: '<S165>/Sum'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq -
      mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_back;

    /* End of Outputs for SubSystem: '<S161>/If Action Subsystem1' */
  }

  /* End of If: '<S161>/If' */

  /* Gain: '<S159>/indexing' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.indexing = 800.0F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_m;

  /* DataTypeConversion: '<S159>/Get_Integer' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Get_Integer = (uint16_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.indexing;

  /* Sum: '<S159>/Sum' incorporates:
   *  Constant: '<S159>/offset'
   */
  Sum = mcb_pmsm_foc_dual_cpu1_f28379_B.Get_Integer + 1UL;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum[0] = Sum;

  /* Selector: '<S159>/Lookup' incorporates:
   *  Constant: '<S159>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[0] =
    mcb_pmsm_foc_dual_cpu1_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S159>/Sum' */
  Sum = mcb_pmsm_foc_dual_cpu1_f28379_B.Get_Integer;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum[1] = Sum;

  /* Selector: '<S159>/Lookup' incorporates:
   *  Constant: '<S159>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[1] =
    mcb_pmsm_foc_dual_cpu1_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S159>/Sum' incorporates:
   *  Constant: '<S159>/offset'
   */
  Sum = mcb_pmsm_foc_dual_cpu1_f28379_B.Get_Integer + 201UL;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum[2] = Sum;

  /* Selector: '<S159>/Lookup' incorporates:
   *  Constant: '<S159>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[2] =
    mcb_pmsm_foc_dual_cpu1_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S159>/Sum' incorporates:
   *  Constant: '<S159>/offset'
   */
  Sum = mcb_pmsm_foc_dual_cpu1_f28379_B.Get_Integer + 200UL;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum[3] = Sum;

  /* Selector: '<S159>/Lookup' incorporates:
   *  Constant: '<S159>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[3] =
    mcb_pmsm_foc_dual_cpu1_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S160>/Sum3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_lv =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[0] -
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[1];

  /* DataTypeConversion: '<S159>/Data Type Conversion1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1_a =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Get_Integer;

  /* Sum: '<S159>/Sum2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_d =
    mcb_pmsm_foc_dual_cpu1_f28379_B.indexing -
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1_a;

  /* Product: '<S160>/Product' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_c =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_lv *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_d;

  /* Sum: '<S160>/Sum4' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_n =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_c +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[1];

  /* Sum: '<S160>/Sum5' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum5 = mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup
    [2] - mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[3];

  /* Product: '<S160>/Product1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_a =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum5 *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_d;

  /* Sum: '<S160>/Sum6' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6_n =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_a +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[3];

  /* Outputs for Atomic SubSystem: '<S23>/Two inputs CRL' */
  /* Product: '<S157>/acos' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.acos_e =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_k *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6_n;

  /* Product: '<S157>/bsin' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.bsin =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_d *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_n;

  /* Sum: '<S157>/sum_Ds' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.sum_Ds =
    mcb_pmsm_foc_dual_cpu1_f28379_B.acos_e +
    mcb_pmsm_foc_dual_cpu1_f28379_B.bsin;

  /* Product: '<S157>/bcos' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.bcos =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_d *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6_n;

  /* Product: '<S157>/asin' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.asin_j =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_k *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_n;

  /* Sum: '<S157>/sum_Qs' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.sum_Qs = mcb_pmsm_foc_dual_cpu1_f28379_B.bcos
    - mcb_pmsm_foc_dual_cpu1_f28379_B.asin_j;

  /* Switch: '<S158>/Switch' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g1[0] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_Ds;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g1[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_Qs;

  /* AlgorithmDescriptorDelegate generated from: '<S157>/a16' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g1[0];

  /* AlgorithmDescriptorDelegate generated from: '<S157>/a16' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g1[1];

  /* End of Outputs for SubSystem: '<S23>/Two inputs CRL' */

  /* Sum: '<S30>/Sum' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_cj = mcb_pmsm_foc_dual_cpu1_f28379_B.RT2[1]
    - mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2;

  /* Product: '<S142>/PProd Out' incorporates:
   *  Constant: '<S30>/Kp'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PProdOut =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_cj * 4.94871664F;

  /* Logic: '<S30>/Logical Operator' incorporates:
   *  Logic: '<S29>/Logical Operator'
   */
  LogicalOperator_n_tmp = !mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_l;

  /* Logic: '<S30>/Logical Operator' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_n = LogicalOperator_n_tmp;

  /* UnitDelay: '<S30>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_n =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_cr;

  /* DiscreteIntegrator: '<S137>/Integrator' */
  if (mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_IC_LOADING != 0U) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE =
      mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_n;
  }

  if (mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_n ||
      (mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_PrevResetState != 0)) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE =
      mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_n;
  }

  /* DiscreteIntegrator: '<S137>/Integrator' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Integrator =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE;

  /* Sum: '<S146>/Sum' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o =
    mcb_pmsm_foc_dual_cpu1_f28379_B.PProdOut +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Integrator;

  /* Switch: '<S30>/Switch' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_l) {
    /* Saturate: '<S144>/Saturation' */
    u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o;
    if (u0 > 1.0F) {
      /* Saturate: '<S144>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation = 1.0F;
    } else if (u0 < -1.0F) {
      /* Saturate: '<S144>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation = -1.0F;
    } else {
      /* Saturate: '<S144>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation = u0;
    }

    /* End of Saturate: '<S144>/Saturation' */

    /* Switch: '<S30>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation;
  } else {
    /* Switch: '<S30>/Switch' incorporates:
     *  Constant: '<S30>/Vq_OpenLoop'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c = 0.0F;
  }

  /* End of Switch: '<S30>/Switch' */

  /* Sum: '<S29>/Sum' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_m = mcb_pmsm_foc_dual_cpu1_f28379_B.RT2[0]
    - mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1;

  /* Product: '<S87>/PProd Out' incorporates:
   *  Constant: '<S29>/Kp'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PProdOut_d =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_m * 4.94871664F;

  /* Logic: '<S29>/Logical Operator' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_h = LogicalOperator_n_tmp;

  /* UnitDelay: '<S29>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_j =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_l;

  /* DiscreteIntegrator: '<S82>/Integrator' */
  if (mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_IC_LOADING_b != 0U) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE_n =
      mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_j;
  }

  if (mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_h ||
      (mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_PrevResetState_e != 0)) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE_n =
      mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_j;
  }

  /* DiscreteIntegrator: '<S82>/Integrator' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Integrator_a =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE_n;

  /* Sum: '<S91>/Sum' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx =
    mcb_pmsm_foc_dual_cpu1_f28379_B.PProdOut_d +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Integrator_a;

  /* Switch: '<S29>/Switch' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_l) {
    /* Saturate: '<S89>/Saturation' */
    u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx;
    if (u0 > 1.0F) {
      /* Saturate: '<S89>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_o = 1.0F;
    } else if (u0 < -1.0F) {
      /* Saturate: '<S89>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_o = -1.0F;
    } else {
      /* Saturate: '<S89>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_o = u0;
    }

    /* End of Saturate: '<S89>/Saturation' */

    /* Switch: '<S29>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_o;
  } else {
    /* Abs: '<S29>/Abs' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Abs_d = fabsf
      (mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedRef);

    /* Saturate: '<S29>/Saturation' */
    u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.Abs_d;
    if (u0 > 0.5F) {
      /* Saturate: '<S29>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_e = 0.5F;
    } else if (u0 < 0.15F) {
      /* Saturate: '<S29>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_e = 0.15F;
    } else {
      /* Saturate: '<S29>/Saturation' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_e = u0;
    }

    /* End of Saturate: '<S29>/Saturation' */

    /* Switch: '<S29>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_e;
  }

  /* End of Switch: '<S29>/Switch' */

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S33>/Constant3'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gt = 0.95F;

  /* Product: '<S33>/Product' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_m = 0.9025F;

  /* Product: '<S34>/Product' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_b4 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl;

  /* Product: '<S34>/Product1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_m =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c;

  /* Sum: '<S34>/Sum1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_bt =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_b4 +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_m;

  /* Outputs for IfAction SubSystem: '<S28>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S31>/Action Port'
   */
  /* If: '<S28>/If' incorporates:
   *  DataTypeConversion: '<S31>/Data Type Conversion'
   *  RelationalOperator: '<S31>/Relational Operator'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RelationalOperator_b =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_bt > 0.9025F);
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_er =
    mcb_pmsm_foc_dual_cpu1_f28379_B.RelationalOperator_b;

  /* If: '<S31>/If' incorporates:
   *  If: '<S28>/If'
   */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_er != 0U) {
    /* Outputs for IfAction SubSystem: '<S31>/Limiter' incorporates:
     *  ActionPort: '<S35>/Action Port'
     */
    /* Product: '<S35>/Product' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_lc[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl * 0.95F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_lc[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c * 0.95F;

    /* Sqrt: '<S35>/Square Root' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SquareRoot = (real32_T)sqrt
      (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_bt);

    /* Switch: '<S35>/Switch' */
    if (mcb_pmsm_foc_dual_cpu1_f28379_B.SquareRoot != 0.0F) {
      /* Switch: '<S35>/Switch' */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_b4 =
        mcb_pmsm_foc_dual_cpu1_f28379_B.SquareRoot;
    } else {
      /* Switch: '<S35>/Switch' incorporates:
       *  Constant: '<S35>/Constant'
       */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_b4 = 1.0F;
    }

    /* End of Switch: '<S35>/Switch' */

    /* Merge: '<S28>/Merge' incorporates:
     *  Product: '<S35>/Divide'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Product_lc[0] /
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_b4;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Product_lc[1] /
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_b4;

    /* End of Outputs for SubSystem: '<S31>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S31>/Passthrough' incorporates:
     *  ActionPort: '<S36>/Action Port'
     */
    /* Merge: '<S28>/Merge' incorporates:
     *  SignalConversion generated from: '<S36>/dqRef'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c;

    /* End of Outputs for SubSystem: '<S31>/Passthrough' */
  }

  /* End of If: '<S31>/If' */
  /* End of Outputs for SubSystem: '<S28>/D-Q Equivalence' */

  /* DeadZone: '<S74>/DeadZone' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx > 1.0F) {
    /* DeadZone: '<S74>/DeadZone' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx - 1.0F;
  } else if (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx >= -1.0F) {
    /* DeadZone: '<S74>/DeadZone' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S74>/DeadZone' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx - -1.0F;
  }

  /* End of DeadZone: '<S74>/DeadZone' */

  /* RelationalOperator: '<S72>/Relational Operator' incorporates:
   *  Constant: '<S72>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RelationalOperator =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone != 0.0F);

  /* RelationalOperator: '<S72>/fix for DT propagation issue' incorporates:
   *  Constant: '<S72>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone > 0.0F);

  /* Switch: '<S72>/Switch1' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue) {
    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/Constant'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_ck = 1;
  } else {
    /* Switch: '<S72>/Switch1' incorporates:
     *  Constant: '<S72>/Constant2'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_ck = -1;
  }

  /* End of Switch: '<S72>/Switch1' */

  /* Product: '<S79>/IProd Out' incorporates:
   *  Constant: '<S29>/Ki'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_m * 0.345765799F;

  /* RelationalOperator: '<S72>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S72>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue1 =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut > 0.0F);

  /* Switch: '<S72>/Switch2' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue1) {
    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S72>/Constant3'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_k = 1;
  } else {
    /* Switch: '<S72>/Switch2' incorporates:
     *  Constant: '<S72>/Constant4'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_k = -1;
  }

  /* End of Switch: '<S72>/Switch2' */

  /* RelationalOperator: '<S72>/Equal1' incorporates:
   *  Switch: '<S72>/Switch1'
   *  Switch: '<S72>/Switch2'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Equal1 =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_ck ==
     mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_k);

  /* Logic: '<S72>/AND3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.AND3 =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.RelationalOperator &&
     mcb_pmsm_foc_dual_cpu1_f28379_B.Equal1);

  /* Switch: '<S72>/Switch' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.AND3) {
    /* Switch: '<S72>/Switch' incorporates:
     *  Constant: '<S72>/Constant1'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_i = 0.0F;
  } else {
    /* Switch: '<S72>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_i =
      mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut;
  }

  /* End of Switch: '<S72>/Switch' */

  /* DeadZone: '<S129>/DeadZone' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o > 1.0F) {
    /* DeadZone: '<S129>/DeadZone' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone_o =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o - 1.0F;
  } else if (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o >= -1.0F) {
    /* DeadZone: '<S129>/DeadZone' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone_o = 0.0F;
  } else {
    /* DeadZone: '<S129>/DeadZone' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone_o =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o - -1.0F;
  }

  /* End of DeadZone: '<S129>/DeadZone' */

  /* RelationalOperator: '<S127>/Relational Operator' incorporates:
   *  Constant: '<S127>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RelationalOperator_d =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone_o != 0.0F);

  /* RelationalOperator: '<S127>/fix for DT propagation issue' incorporates:
   *  Constant: '<S127>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue_m =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone_o > 0.0F);

  /* Switch: '<S127>/Switch1' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue_m) {
    /* Switch: '<S127>/Switch1' incorporates:
     *  Constant: '<S127>/Constant'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_bk = 1;
  } else {
    /* Switch: '<S127>/Switch1' incorporates:
     *  Constant: '<S127>/Constant2'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_bk = -1;
  }

  /* End of Switch: '<S127>/Switch1' */

  /* Product: '<S134>/IProd Out' incorporates:
   *  Constant: '<S30>/Ki'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut_m =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_cj * 0.345765799F;

  /* RelationalOperator: '<S127>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S127>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue1_a =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut_m > 0.0F);

  /* Switch: '<S127>/Switch2' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.fixforDTpropagationissue1_a) {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Constant: '<S127>/Constant3'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_lt = 1;
  } else {
    /* Switch: '<S127>/Switch2' incorporates:
     *  Constant: '<S127>/Constant4'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_lt = -1;
  }

  /* End of Switch: '<S127>/Switch2' */

  /* RelationalOperator: '<S127>/Equal1' incorporates:
   *  Switch: '<S127>/Switch1'
   *  Switch: '<S127>/Switch2'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Equal1_n =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_bk ==
     mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_lt);

  /* Logic: '<S127>/AND3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.AND3_h =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.RelationalOperator_d &&
     mcb_pmsm_foc_dual_cpu1_f28379_B.Equal1_n);

  /* Switch: '<S127>/Switch' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.AND3_h) {
    /* Switch: '<S127>/Switch' incorporates:
     *  Constant: '<S127>/Constant1'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_m = 0.0F;
  } else {
    /* Switch: '<S127>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut_m;
  }

  /* End of Switch: '<S127>/Switch' */

  /* Outputs for Atomic SubSystem: '<S22>/Two inputs CRL' */
  /* Product: '<S155>/qcos' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.qcos =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[1] *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6_n;

  /* Product: '<S155>/dsin' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.dsin =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[0] *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_n;

  /* Sum: '<S155>/sum_beta' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.sum_beta =
    mcb_pmsm_foc_dual_cpu1_f28379_B.qcos + mcb_pmsm_foc_dual_cpu1_f28379_B.dsin;

  /* Product: '<S155>/dcos' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.dcos =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[0] *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6_n;

  /* Product: '<S155>/qsin' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.qsin =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[1] *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_n;

  /* Sum: '<S155>/sum_alpha' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.sum_alpha =
    mcb_pmsm_foc_dual_cpu1_f28379_B.dcos - mcb_pmsm_foc_dual_cpu1_f28379_B.qsin;

  /* Switch: '<S156>/Switch' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mw[0] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_alpha;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mw[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S155>/a16' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mw[0];

  /* AlgorithmDescriptorDelegate generated from: '<S155>/a16' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_b =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mw[1];

  /* End of Outputs for SubSystem: '<S22>/Two inputs CRL' */

  /* Gain: '<S173>/one_by_two' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two = 0.5F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m;

  /* Gain: '<S173>/sqrt3_by_two' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.sqrt3_by_two = 0.866025388F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_b;

  /* Sum: '<S173>/add_b' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.add_b =
    mcb_pmsm_foc_dual_cpu1_f28379_B.sqrt3_by_two -
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two;

  /* Sum: '<S173>/add_c' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.add_c = (0.0F -
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two) -
    mcb_pmsm_foc_dual_cpu1_f28379_B.sqrt3_by_two;

  /* MinMax: '<S170>/Max' incorporates:
   *  MinMax: '<S170>/Min'
   */
  u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m;
  Bias = mcb_pmsm_foc_dual_cpu1_f28379_B.add_b;
  LogicalOperator_n_tmp = rtIsNaNF(Bias);
  if ((u0 >= Bias) || LogicalOperator_n_tmp) {
    Bias = u0;
  }

  u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.add_c;
  tmp = rtIsNaNF(u0);
  if ((!(Bias >= u0)) && (!tmp)) {
    Bias = u0;
  }

  /* MinMax: '<S170>/Max' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Max = Bias;

  /* MinMax: '<S170>/Min' */
  u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m;
  Bias = mcb_pmsm_foc_dual_cpu1_f28379_B.add_b;
  if ((u0 <= Bias) || LogicalOperator_n_tmp) {
    Bias = u0;
  }

  u0 = mcb_pmsm_foc_dual_cpu1_f28379_B.add_c;
  if ((!(Bias <= u0)) && (!tmp)) {
    Bias = u0;
  }

  /* MinMax: '<S170>/Min' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Min = Bias;

  /* Sum: '<S170>/Add' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add_j = mcb_pmsm_foc_dual_cpu1_f28379_B.Max +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Min;

  /* Gain: '<S170>/one_by_two' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two_i = -0.5F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_j;

  /* Sum: '<S169>/Add1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_m = mcb_pmsm_foc_dual_cpu1_f28379_B.add_b
    + mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two_i;

  /* Sum: '<S169>/Add2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add2 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two_i +
    mcb_pmsm_foc_dual_cpu1_f28379_B.add_c;

  /* Sum: '<S169>/Add3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add3 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m +
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two_i;

  /* Gain: '<S169>/Gain' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[0] = 1.15470052F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add3;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[1] = 1.15470052F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_m;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[2] = 1.15470052F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add2;

  /* Gain: '<S19>/Gain' */
  Bias = 0.5F * mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[0];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_h[0] = Bias;

  /* Sum: '<S19>/Sum' incorporates:
   *  Constant: '<S19>/Constant'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[0] = Bias + 0.5F;

  /* Gain: '<S19>/Gain' */
  Bias = 0.5F * mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[1];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_h[1] = Bias;

  /* Sum: '<S19>/Sum' incorporates:
   *  Constant: '<S19>/Constant'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[1] = Bias + 0.5F;

  /* Gain: '<S19>/Gain' */
  Bias = 0.5F * mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[2];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_h[2] = Bias;

  /* Sum: '<S19>/Sum' incorporates:
   *  Constant: '<S19>/Constant'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[2] = Bias + 0.5F;

  /* DataTypeConversion: '<S19>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion =
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateTransition1;

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_cr =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c;

  /* Update for DiscreteIntegrator: '<S137>/Integrator' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_IC_LOADING = 0U;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE +=
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_m;
  Integrator_PrevResetState_tmp = (int16_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_n;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_PrevResetState =
    Integrator_PrevResetState_tmp;

  /* Update for UnitDelay: '<S29>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_l =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl;

  /* Update for DiscreteIntegrator: '<S82>/Integrator' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_IC_LOADING_b = 0U;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE_n +=
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_i;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_PrevResetState_e =
    Integrator_PrevResetState_tmp;
}

/* Output and update for atomic system: '<S2>/Open_Loop_Control' */
#pragma CODE_SECTION (mcb_pmsm__Open_Loop_Control, "ramfuncs")

void mcb_pmsm__Open_Loop_Control(void)
{
  /* Abs: '<S16>/Abs' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Abs = fabsf
    (mcb_pmsm_foc_dual_cpu1_f28379_B.RateTransition4);

  /* Switch: '<S16>/Switch2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_h = (uint16_T)
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Abs > 0.1F);

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_l =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_h != 0U);

  /* Gain: '<S16>/Gain' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_f = 0.0120333331F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateTransition4;

  /* UnitDelay: '<S174>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_kj =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_f;

  /* Logic: '<S174>/NOT' incorporates:
   *  Constant: '<S174>/Constant_Reset'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.NOT_p = true;

  /* Outputs for Enabled SubSystem: '<S174>/Accumulate' incorporates:
   *  EnablePort: '<S175>/Enable'
   */
  /* Delay: '<S175>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_l =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_l;

  /* Outputs for Enabled SubSystem: '<S175>/Subsystem' incorporates:
   *  EnablePort: '<S176>/Enable'
   */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_l) {
    /* SignalConversion generated from: '<S176>/Input' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Input =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_f;
  }

  /* End of Outputs for SubSystem: '<S175>/Subsystem' */

  /* Sum: '<S175>/Add' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add_h = mcb_pmsm_foc_dual_cpu1_f28379_B.Input
    + mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_kj;

  /* DataTypeConversion: '<S175>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_j = (int16_T)(real32_T)
    floor(mcb_pmsm_foc_dual_cpu1_f28379_B.Add_h);

  /* DataTypeConversion: '<S175>/Data Type Conversion1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_j;

  /* Sum: '<S175>/Add1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_f = mcb_pmsm_foc_dual_cpu1_f28379_B.Add_h
    - mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1;

  /* Update for Delay: '<S175>/Delay' incorporates:
   *  Constant: '<S175>/Constant'
   */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_l = true;

  /* End of Outputs for SubSystem: '<S174>/Accumulate' */

  /* Switch: '<S16>/Switch' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_h != 0U) {
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[0];
  } else {
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_f;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Update for UnitDelay: '<S174>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_f =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_f;
}

/* System initialize for atomic system: '<S2>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(rtB_SpeedControl_mcb_pmsm_foc_d *localB,
  rtDW_SpeedControl_mcb_pmsm_foc_ *localDW)
{
  /* Start for Constant: '<S177>/Ki2' */
  localB->Ki2 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S217>/Integrator' */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<S2>/Speed Control' */
void mcb_pmsm_foc_d_SpeedControl(boolean_T rtu_EnClosedLoop, boolean_T
  rtu_EnablePWM, real32_T rtu_Speed_Ref_PU, real32_T rtu_Speed_Meas_PU,
  rtB_SpeedControl_mcb_pmsm_foc_d *localB, rtDW_SpeedControl_mcb_pmsm_foc_
  *localDW)
{
  real32_T u0;

  /* Constant: '<S17>/Id_Ref' */
  localB->Id_Ref = 0.0F;

  /* Logic: '<S177>/AND' */
  localB->AND = (rtu_EnablePWM && rtu_EnClosedLoop);

  /* Switch: '<S178>/Switch' incorporates:
   *  Switch: '<S178>/Switch1'
   */
  if (rtu_EnClosedLoop) {
    /* Switch: '<S178>/Switch' */
    localB->Speed_Ref = rtu_Speed_Ref_PU;
  } else {
    if (rtu_Speed_Ref_PU > 0.0F) {
      /* Switch: '<S178>/Switch1' incorporates:
       *  Constant: '<S178>/Constant'
       */
      localB->Switch1_d = 0.1F;
    } else {
      /* Switch: '<S178>/Switch1' incorporates:
       *  Constant: '<S178>/Constant1'
       */
      localB->Switch1_d = -0.1F;
    }

    /* Switch: '<S178>/Switch' */
    localB->Speed_Ref = localB->Switch1_d;
  }

  /* End of Switch: '<S178>/Switch' */

  /* Switch: '<S180>/Switch1' incorporates:
   *  Constant: '<S180>/FilterConstant'
   *  Constant: '<S180>/OneMinusFilterConstant'
   */
  localB->Switch1[0] = 0.2F;
  localB->Switch1[1] = 0.8F;

  /* Product: '<S237>/Product' */
  localB->Product = localB->Speed_Ref * 0.2F;

  /* UnitDelay: '<S237>/Unit Delay' */
  localB->UnitDelay = localDW->UnitDelay_DSTATE;

  /* Product: '<S237>/Product1' */
  localB->Product1 = 0.8F * localB->UnitDelay;

  /* Sum: '<S237>/Add1' */
  localB->Add1 = localB->Product + localB->Product1;

  /* Sum: '<S177>/Sum' */
  localB->Sum = localB->Add1 - rtu_Speed_Meas_PU;

  /* Product: '<S222>/PProd Out' incorporates:
   *  Constant: '<S177>/Kp1'
   */
  localB->PProdOut = localB->Sum * 1.60139418F;

  /* Logic: '<S177>/Logical Operator' */
  localB->LogicalOperator = !localB->AND;

  /* Constant: '<S177>/Ki2' */
  localB->Ki2 = 0.0F;

  /* DiscreteIntegrator: '<S217>/Integrator' */
  if (localB->LogicalOperator || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S217>/Integrator' */
  localB->Integrator = localDW->Integrator_DSTATE;

  /* Sum: '<S226>/Sum' */
  localB->Sum_b = localB->PProdOut + localB->Integrator;

  /* DeadZone: '<S209>/DeadZone' */
  if (localB->Sum_b > 1.0F) {
    /* DeadZone: '<S209>/DeadZone' */
    localB->DeadZone = localB->Sum_b - 1.0F;
  } else if (localB->Sum_b >= -1.0F) {
    /* DeadZone: '<S209>/DeadZone' */
    localB->DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S209>/DeadZone' */
    localB->DeadZone = localB->Sum_b - -1.0F;
  }

  /* End of DeadZone: '<S209>/DeadZone' */

  /* RelationalOperator: '<S207>/Relational Operator' incorporates:
   *  Constant: '<S207>/Clamping_zero'
   */
  localB->RelationalOperator = (localB->DeadZone != 0.0F);

  /* RelationalOperator: '<S207>/fix for DT propagation issue' incorporates:
   *  Constant: '<S207>/Clamping_zero'
   */
  localB->fixforDTpropagationissue = (localB->DeadZone > 0.0F);

  /* Switch: '<S207>/Switch1' */
  if (localB->fixforDTpropagationissue) {
    /* Switch: '<S207>/Switch1' incorporates:
     *  Constant: '<S207>/Constant'
     */
    localB->Switch1_a = 1;
  } else {
    /* Switch: '<S207>/Switch1' incorporates:
     *  Constant: '<S207>/Constant2'
     */
    localB->Switch1_a = -1;
  }

  /* End of Switch: '<S207>/Switch1' */

  /* Product: '<S214>/IProd Out' incorporates:
   *  Constant: '<S177>/Ki1'
   */
  localB->IProdOut = localB->Sum * 0.0211421922F;

  /* RelationalOperator: '<S207>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S207>/Clamping_zero'
   */
  localB->fixforDTpropagationissue1 = (localB->IProdOut > 0.0F);

  /* Switch: '<S207>/Switch2' */
  if (localB->fixforDTpropagationissue1) {
    /* Switch: '<S207>/Switch2' incorporates:
     *  Constant: '<S207>/Constant3'
     */
    localB->Switch2 = 1;
  } else {
    /* Switch: '<S207>/Switch2' incorporates:
     *  Constant: '<S207>/Constant4'
     */
    localB->Switch2 = -1;
  }

  /* End of Switch: '<S207>/Switch2' */

  /* RelationalOperator: '<S207>/Equal1' incorporates:
   *  Switch: '<S207>/Switch1'
   *  Switch: '<S207>/Switch2'
   */
  localB->Equal1 = (localB->Switch1_a == localB->Switch2);

  /* Logic: '<S207>/AND3' */
  localB->AND3 = (localB->RelationalOperator && localB->Equal1);

  /* Switch: '<S207>/Switch' */
  if (localB->AND3) {
    /* Switch: '<S207>/Switch' incorporates:
     *  Constant: '<S207>/Constant1'
     */
    localB->Switch = 0.0F;
  } else {
    /* Switch: '<S207>/Switch' */
    localB->Switch = localB->IProdOut;
  }

  /* End of Switch: '<S207>/Switch' */

  /* Saturate: '<S224>/Saturation' */
  u0 = localB->Sum_b;
  if (u0 > 1.0F) {
    /* Saturate: '<S224>/Saturation' */
    localB->Saturation = 1.0F;
  } else if (u0 < -1.0F) {
    /* Saturate: '<S224>/Saturation' */
    localB->Saturation = -1.0F;
  } else {
    /* Saturate: '<S224>/Saturation' */
    localB->Saturation = u0;
  }

  /* End of Saturate: '<S224>/Saturation' */

  /* Update for UnitDelay: '<S237>/Unit Delay' */
  localDW->UnitDelay_DSTATE = localB->Add1;

  /* Update for DiscreteIntegrator: '<S217>/Integrator' */
  localDW->Integrator_DSTATE += localB->Switch;
  localDW->Integrator_PrevResetState = (int16_T)localB->LogicalOperator;
}

static void mcb_pmsm_foc_d_SystemCore_setup(soc_blocks_IPCRead_mcb_pmsm_foc *obj)
{
  uint32_T dataTypeVarLoc;
  uint16_T dataTypeSize;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S271>/IPC Read' */
  obj->isInitialized = 1L;
  dataTypeSize = sizeof(dataTypeVarLoc);
  if (dataTypeSize > 32767U) {
    dataTypeSize = MAX_uint16_T;
  } else {
    dataTypeSize <<= 1U;
  }

  /* Start for MATLABSystem: '<S271>/IPC Read' */
  obj->IpcParams.NumOfBuffers = 1.0;
  obj->IpcParams.ChNum = 2.0;
  obj->IpcParams.BufferSize = 1.0;
  obj->IpcParams.DataTypeInBytes = dataTypeSize;
  obj->IpcParams.IsIntEnabled = 0.0;
  obj->IpcParams.IPCBetween = 0.0;
  obj->IpcHandle = MW_IPC_Init(&obj->IpcParams);
  obj->isSetupComplete = true;
}

/* System initialize for atomic system: '<Root>/Inverter Driver Peripherals' */
void InverterDriverPeripher_Init(void)
{
  uint16_T dataTypeVarLoc;

  /* Start for S-Function (c280xgpio_do): '<S251>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S251>/ePWM1' */
  real32_T tbprdValue1 = (real32_T)EPwm1Regs.TBPRD;

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S251>/ePWM2' */
  real32_T tbprdValue2 = (real32_T)EPwm2Regs.TBPRD;

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S251>/ePWM3' */
  real32_T tbprdValue3 = (real32_T)EPwm3Regs.TBPRD;

  /*** Initialize ePWM3 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for MATLABSystem: '<S271>/IPC Read' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.isInitialized = 0L;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.objisempty = true;
  mcb_pmsm_foc_d_SystemCore_setup(&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f);

  /* Start for MATLABSystem: '<S255>/IPC Write' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.Overwritten = 0ULL;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.NumBufUsed = 0U;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.objisempty_k = true;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.isInitialized = 1L;
  dataTypeVarLoc = sizeof(dataTypeVarLoc);
  if (dataTypeVarLoc > 32767U) {
    dataTypeVarLoc = MAX_uint16_T;
  } else {
    dataTypeVarLoc <<= 1U;
  }

  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams.NumOfBuffers = 4.0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams.ChNum = 4.0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams.BufferSize = 1.0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams.DataTypeInBytes = dataTypeVarLoc;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams.IsIntEnabled = 0.0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams.IPCBetween = 0.0;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcHandle = MW_IPC_Init
    (&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcParams);
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S255>/IPC Write' */
}

/* Output and update for atomic system: '<Root>/Inverter Driver Peripherals' */
#pragma CODE_SECTION (m_InverterDriverPeripherals, "ramfuncs")

void m_InverterDriverPeripherals(void)
{
  MW_IPC_Diag_T diagDataOut;
  uint64_T q0;
  uint64_T qY;
  uint32_T b_varargout_1;
  int16_T s262_iter;
  uint16_T Scale_to_PWM_Counter_PRD;

  /* Switch: '<S251>/Switch' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_bs =
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion;

  /* S-Function (c280xgpio_do): '<S251>/DRV830x Enable' */
  {
    if (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_bs) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S251>/Switch1' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion >= 0.5F) {
    /* Gain: '<S251>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F *
      mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[0]);
    mcb_pmsm_foc_dual_cpu1_f28379_B.Scale_to_PWM_Counter_PRD[0] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S251>/Switch1' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[0] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S251>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F *
      mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[1]);
    mcb_pmsm_foc_dual_cpu1_f28379_B.Scale_to_PWM_Counter_PRD[1] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S251>/Switch1' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[1] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S251>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F *
      mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[2]);
    mcb_pmsm_foc_dual_cpu1_f28379_B.Scale_to_PWM_Counter_PRD[2] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S251>/Switch1' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[2] = Scale_to_PWM_Counter_PRD;
  } else {
    /* Switch: '<S251>/Switch1' incorporates:
     *  Constant: '<S251>/stop'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[0] = 0U;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[1] = 0U;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[2] = 0U;
  }

  /* End of Switch: '<S251>/Switch1' */

  /* S-Function (c2802xpwm): '<S251>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[0]);
  }

  /* S-Function (c2802xpwm): '<S251>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[1]);
  }

  /* S-Function (c2802xpwm): '<S251>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_pj[2]);
  }

  /* UnitDelay: '<S264>/Output' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Output =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Output_DSTATE;

  /* MATLABSystem: '<S271>/IPC Read' */
  s262_iter = 0;
  MW_IPC_Read(&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.IpcHandle, 0.0,
              &b_varargout_1, &s262_iter);

  /* MATLABSystem: '<S271>/IPC Read' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.IPCRead_o1 = b_varargout_1;

  /* MATLABSystem: '<S271>/IPC Read' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.IPCRead_o2 = s262_iter;

  /* DataStoreRead: '<S6>/Data Store Read' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead_g =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.SignalSelect1;

  /* Product: '<S257>/Product1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.id_Ld_Lq =
    mcb_pmsm_foc_dual_cpu1_f_ConstB.Ld_Lq *
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1;

  /* Sum: '<S257>/Add' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add_b =
    mcb_pmsm_foc_dual_cpu1_f28379_B.id_Ld_Lq +
    mcb_pmsm_foc_dual_cpu1_f_ConstB.Switch2;

  /* Product: '<S257>/Product3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product3_m =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_b *
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2;

  /* Gain: '<S257>/1_5_Pp' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.u_5_Pp = 6.0F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product3_m;

  /* MultiPortSwitch: '<S253>/Index Vector' */
  switch (mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead_g) {
   case 0:
    /* MultiPortSwitch: '<S253>/Index Vector' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Ia;
    break;

   case 1:
    /* MultiPortSwitch: '<S253>/Index Vector' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[0];
    break;

   case 2:
    /* MultiPortSwitch: '<S253>/Index Vector' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Speedfb;
    break;

   case 3:
    /* MultiPortSwitch: '<S253>/Index Vector' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Pos_pu;
    break;

   case 4:
    /* MultiPortSwitch: '<S253>/Index Vector' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.u_5_Pp;
    break;

   default:
    /* Product: '<S257>/Product' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_n =
      mcb_pmsm_foc_dual_cpu1_f28379_B.u_5_Pp *
      mcb_pmsm_foc_dual_cpu1_f28379_B.Speedfb;

    /* Gain: '<S257>/P_si2pu' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.P_output = 0.601666689F *
      mcb_pmsm_foc_dual_cpu1_f28379_B.Product_n;

    /* MultiPortSwitch: '<S253>/Index Vector' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m =
      mcb_pmsm_foc_dual_cpu1_f28379_B.P_output;
    break;
  }

  /* End of MultiPortSwitch: '<S253>/Index Vector' */

  /* S-Function (any2byte_svd): '<S263>/Byte Pack' */

  /* Pack: <S263>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &mcb_pmsm_foc_dual_cpu1_f28379_B.BytePack;

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m, MW_inputPortWidth);
    }
  }

  /* If: '<S260>/If' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.Output == 0U) {
    /* Outputs for IfAction SubSystem: '<S260>/Start' incorporates:
     *  ActionPort: '<S267>/Action Port'
     */
    /* SignalConversion generated from: '<S267>/Data' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Data_fw[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.BytePack;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Data_fw[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.IPCRead_o1;

    /* Merge: '<S260>/Merge' incorporates:
     *  Constant: '<S267>/Start'
     *  SignalConversion generated from: '<S267>/Data_out'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[0] = 1397969747UL;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Data_fw[0];
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[2] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Data_fw[1];

    /* Merge: '<S260>/Merge1' incorporates:
     *  Bias: '<S267>/Bias'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_dual_cpu1_f_ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S260>/Start' */
  } else if (mcb_pmsm_foc_dual_cpu1_f28379_B.Output == 599U) {
    /* Outputs for IfAction SubSystem: '<S260>/End' incorporates:
     *  ActionPort: '<S266>/Action Port'
     */
    /* SignalConversion generated from: '<S266>/Data' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Data_f[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.BytePack;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Data_f[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.IPCRead_o1;

    /* Merge: '<S260>/Merge' incorporates:
     *  Constant: '<S266>/End'
     *  SignalConversion generated from: '<S266>/Data_out'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Data_f[0];
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Data_f[1];
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[2] = 1162167621UL;

    /* Merge: '<S260>/Merge1' incorporates:
     *  Bias: '<S266>/Bias'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_dual_cpu1_f_ConstB.Width + 1UL;

    /* End of Outputs for SubSystem: '<S260>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S260>/Data' incorporates:
     *  ActionPort: '<S265>/Action Port'
     */
    /* SignalConversion generated from: '<S265>/Data' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Data[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.BytePack;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Data[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.IPCRead_o1;

    /* Merge: '<S260>/Merge' incorporates:
     *  Constant: '<S265>/Dummy'
     *  SignalConversion generated from: '<S265>/Data_out'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[0] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Data[0];
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[1] =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Data[1];
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[2] = 0UL;

    /* Merge: '<S260>/Merge1' incorporates:
     *  SignalConversion generated from: '<S265>/Data_width'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Iteration =
      mcb_pmsm_foc_dual_cpu1_f_ConstB.Width;

    /* End of Outputs for SubSystem: '<S260>/Data' */
  }

  /* End of If: '<S260>/If' */

  /* Outputs for Iterator SubSystem: '<S253>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S262>/While Iterator'
   */
  s262_iter = 1;
  do {
    mcb_pmsm_foc_dual_cpu1_f28379_B.WhileIterator = s262_iter;
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Data[mcb_pmsm_foc_dual_cpu1_f28379_B.WhileIterator
      - 1];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)
          &mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector, 4, 4);
        checkSCITransmitInProgressA = 0U;
      }
    }

    mcb_pmsm_foc_dual_cpu1_f28379_B.Add =
      mcb_pmsm_foc_dual_cpu1_f28379_B.SCI_Tx_Iteration - (uint32_T)
      mcb_pmsm_foc_dual_cpu1_f28379_B.WhileIterator;
    s262_iter++;
  } while (mcb_pmsm_foc_dual_cpu1_f28379_B.Add != 0UL);

  /* End of Outputs for SubSystem: '<S253>/While Iterator Subsystem' */

  /* Sum: '<S268>/FixPt Sum1' incorporates:
   *  Constant: '<S268>/FixPt Constant'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.FixPtSum1 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Output + 1U;

  /* Switch: '<S269>/FixPt Switch' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.FixPtSum1 > 599U) {
    /* Switch: '<S269>/FixPt Switch' incorporates:
     *  Constant: '<S269>/Constant'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.FixPtSwitch = 0U;
  } else {
    /* Switch: '<S269>/FixPt Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.FixPtSwitch =
      mcb_pmsm_foc_dual_cpu1_f28379_B.FixPtSum1;
  }

  /* End of Switch: '<S269>/FixPt Switch' */

  /* DataStoreRead: '<S6>/Data Store Read2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead2 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.EnMtr2Ctrl;

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion2 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead2;

  /* MATLABSystem: '<S255>/IPC Write' */
  diagDataOut.OverwriteDiag = 0U;
  diagDataOut.NumBuffUsedDiag = 0U;
  MW_IPC_Write(&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcHandle, 0.0,
               &mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion2,
               &diagDataOut);

  /* Start for MATLABSystem: '<S255>/IPC Write' */
  q0 = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.Overwritten;
  qY = q0 + diagDataOut.OverwriteDiag;
  if (qY < q0) {
    qY = MAX_uint64_T;
  }

  /* MATLABSystem: '<S255>/IPC Write' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.Overwritten = qY;
  if (diagDataOut.NumBuffUsedDiag <= 4U) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.NumBufUsed = diagDataOut.NumBuffUsedDiag;
  }

  q0 = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.Overwritten;
  Scale_to_PWM_Counter_PRD = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.NumBufUsed;

  /* MATLABSystem: '<S255>/IPC Write' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.IPCChannelNumberofoverwrites = q0;

  /* MATLABSystem: '<S255>/IPC Write' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.IPCChannelNumberofbuffersused =
    Scale_to_PWM_Counter_PRD;

  /* Update for UnitDelay: '<S264>/Output' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Output_DSTATE =
    mcb_pmsm_foc_dual_cpu1_f28379_B.FixPtSwitch;
}

/* Termination for atomic system: '<Root>/Inverter Driver Peripherals' */
void InverterDriverPeripher_Term(void)
{
  /* Terminate for MATLABSystem: '<S271>/IPC Read' */
  if (!mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_f.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S271>/IPC Read' */

  /* Terminate for MATLABSystem: '<S255>/IPC Write' */
  if (!mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu1_f2_DWork.obj.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S255>/IPC Write' */
}

/* System initialize for atomic system: '<Root>/Sensor Driver Blocks ' */
void mcb_SensorDriverBlocks_Init(void)
{
  /* Start for S-Function (c2802xadc): '<S9>/ADC_A_IN0' */
  if (MW_adcCInitFlag == 0U) {
    InitAdcC();
    MW_adcCInitFlag = 1U;
  }

  config_ADCC_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S9>/ADC_B_IN0' */
  if (MW_adcBInitFlag == 0U) {
    InitAdcB();
    MW_adcBInitFlag = 1U;
  }

  config_ADCB_SOC0 ();
}

/* Output and update for atomic system: '<Root>/Sensor Driver Blocks ' */
#pragma CODE_SECTION (mcb_pmsm_SensorDriverBlocks, "ramfuncs")

void mcb_pmsm_SensorDriverBlocks(void)
{
  /* S-Function (c2802xadc): '<S9>/ADC_A_IN0' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S9>/ADC_B_IN0' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT0);
  }
}

/* System initialize for atomic system: '<Root>/Sensorless Algorithm' */
void mc_SensorlessAlgorithm_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S276>/Flux Observer' */
  /* InitializeConditions for Delay: '<S310>/Delay1' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S310>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S302>/Delay1' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_o = 0.0F;

  /* InitializeConditions for Delay: '<S302>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_b = 0.0F;

  /* InitializeConditions for Delay: '<S284>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx = 0U;

  /* End of SystemInitialize for SubSystem: '<S276>/Flux Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S276>/Sliding Mode Observer' */
  /* InitializeConditions for Delay: '<S322>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_h = 0.0F;

  /* InitializeConditions for Delay: '<S332>/Delay1' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_j = 0.0F;

  /* InitializeConditions for Delay: '<S323>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_k = 0.0F;

  /* InitializeConditions for Delay: '<S333>/Delay1' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_p = 0.0F;

  /* InitializeConditions for Delay: '<S320>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_a = 0.0F;

  /* InitializeConditions for Delay: '<S327>/Delay' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx_j = 0U;

  /* End of SystemInitialize for SubSystem: '<S276>/Sliding Mode Observer' */

  /* SystemInitialize for Merge: '<S276>/Merge' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[1] = 0.0F;
}

/* Output and update for atomic system: '<Root>/Sensorless Algorithm' */
#pragma CODE_SECTION (mcb_pms_SensorlessAlgorithm, "ramfuncs")

void mcb_pms_SensorlessAlgorithm(void)
{
  real32_T GetADCVoltage;
  ZCSigState Delay_Reset_ZCE_h_tmp;
  boolean_T zcEvent;

  /* DataStoreRead: '<S275>/Data Store Read' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead_o =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.IaOffset;

  /* DataStoreRead: '<S275>/Data Store Read1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead1 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.IbOffset;

  /* DataTypeConversion: '<S275>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_f[0] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_A_IN0;
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_f[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_B_IN0;

  /* Sum: '<S275>/Add' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add_p[0] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_f[0] -
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead_o;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add_p[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_f[1] -
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead1;

  /* Gain: '<S278>/Get ADC Voltage' */
  GetADCVoltage = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_p[0];
  mcb_pmsm_foc_dual_cpu1_f28379_B.GetADCVoltage[0] = GetADCVoltage;

  /* Gain: '<S278>/Get Currents' */
  GetADCVoltage *= 14.2857141F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.GetCurrents[0] = GetADCVoltage;

  /* Gain: '<S278>/PU_Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[0] = 0.0466666669F *
    GetADCVoltage;

  /* Gain: '<S278>/Get ADC Voltage' */
  GetADCVoltage = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_p[1];
  mcb_pmsm_foc_dual_cpu1_f28379_B.GetADCVoltage[1] = GetADCVoltage;

  /* Gain: '<S278>/Get Currents' */
  GetADCVoltage *= 14.2857141F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.GetCurrents[1] = GetADCVoltage;

  /* Gain: '<S278>/PU_Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[1] = 0.0466666669F *
    GetADCVoltage;

  /* Outputs for IfAction SubSystem: '<S276>/Sliding Mode Observer' incorporates:
   *  ActionPort: '<S280>/Action Port'
   */
  /* SwitchCase: '<S276>/Switch Case' incorporates:
   *  Constant: '<S324>/FilterConstant'
   *  Constant: '<S324>/OneMinusFilterConstant'
   *  Constant: '<S325>/FilterConstant'
   *  Constant: '<S325>/OneMinusFilterConstant'
   *  DataStoreRead: '<S280>/Data Store Read1'
   *  Delay: '<S322>/Delay'
   *  Delay: '<S323>/Delay'
   *  Delay: '<S332>/Delay1'
   *  Delay: '<S333>/Delay1'
   *  Gain: '<S332>/a'
   *  Gain: '<S332>/b_inv*g'
   *  Gain: '<S333>/a'
   *  Gain: '<S333>/b_inv*g'
   *  Logic: '<S280>/Logical Operator'
   *  Product: '<S336>/Product'
   *  Product: '<S336>/Product1'
   *  Product: '<S339>/Product'
   *  Product: '<S339>/Product1'
   *  Relay: '<S321>/AlphaRelay'
   *  Relay: '<S321>/BetaRelay'
   *  Sum: '<S322>/Sum2'
   *  Sum: '<S323>/Sum2'
   *  Sum: '<S332>/Sum3'
   *  Sum: '<S332>/Sum4'
   *  Sum: '<S333>/Sum3'
   *  Sum: '<S333>/Sum4'
   *  Sum: '<S336>/Add1'
   *  Sum: '<S339>/Add1'
   *  Switch: '<S324>/Switch1'
   *  Switch: '<S325>/Switch1'
   *  UnitDelay: '<S332>/Unit Delay'
   *  UnitDelay: '<S332>/Unit Delay1'
   *  UnitDelay: '<S333>/Unit Delay'
   *  UnitDelay: '<S333>/Unit Delay1'
   *  UnitDelay: '<S336>/Unit Delay'
   *  UnitDelay: '<S339>/Unit Delay'
   */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead1_d =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Enable;
  mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f =
    !mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead1_d;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay1 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay1_DSTATE;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_cs =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_j;
  mcb_pmsm_foc_dual_cpu1_f28379_B.a = 0.932831F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_cs;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_h == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_h !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_h = 0.0F;
  }

  Delay_Reset_ZCE_h_tmp = mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f;
  mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_h = Delay_Reset_ZCE_h_tmp;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_m =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_h;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2 = mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_m
    - mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[2];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_o =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay1 -
     mcb_pmsm_foc_dual_cpu1_f28379_B.a) + mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2;
  mcb_pmsm_foc_dual_cpu1_f28379_B.b_invg = 18.4419193F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_o;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_n == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_n !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_j = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_n = Delay_Reset_ZCE_h_tmp;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_d =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_j;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4 = mcb_pmsm_foc_dual_cpu1_f28379_B.b_invg
    + mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_d;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_f[0] = 0.184886485F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_f[1] = 0.815113544F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_l =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4 * 0.184886485F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_d =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_c;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_j = 0.815113544F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_d;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_e =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_l +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_j;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_e;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.AlphaRelay_Mode = ((GetADCVoltage >= 0.02F) ||
    ((!(GetADCVoltage <= -0.02F)) &&
     mcb_pmsm_foc_dual_cpu1_f2_DWork.AlphaRelay_Mode));
  mcb_pmsm_foc_dual_cpu1_f28379_B.AlphaRelay =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.AlphaRelay_Mode;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay1_g =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay1_DSTATE_n;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_m =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_m;
  mcb_pmsm_foc_dual_cpu1_f28379_B.a_l = 0.932831F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_m;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_l == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_l !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_k = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_l = Delay_Reset_ZCE_h_tmp;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_a =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_k;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_p =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_a -
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[3];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_l =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay1_g -
     mcb_pmsm_foc_dual_cpu1_f28379_B.a_l) +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_p;
  mcb_pmsm_foc_dual_cpu1_f28379_B.b_invg_e = 18.4419193F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_l;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_p == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_p !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_p = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_p = Delay_Reset_ZCE_h_tmp;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_o =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_p;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_d =
    mcb_pmsm_foc_dual_cpu1_f28379_B.b_invg_e +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_o;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_a[0] = 0.184886485F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_a[1] = 0.815113544F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_f =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_d * 0.184886485F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_k =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_n;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_d = 0.815113544F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_k;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_l =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_f +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_d;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_l;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.BetaRelay_Mode = ((GetADCVoltage >= 0.02F) ||
    ((!(GetADCVoltage <= -0.02F)) &&
     mcb_pmsm_foc_dual_cpu1_f2_DWork.BetaRelay_Mode));
  mcb_pmsm_foc_dual_cpu1_f28379_B.BetaRelay =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.BetaRelay_Mode;

  /* Outputs for Triggered SubSystem: '<S321>/Dir_Sense' incorporates:
   *  TriggerPort: '<S329>/Trigger'
   */
  zcEvent = (mcb_pmsm_foc_dual_cpu1_f28379_B.AlphaRelay &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Dir_Sense_Trig_ZCE != POS_ZCSIG));
  if (zcEvent) {
    /* Logic: '<S329>/Logical Operator' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_k =
      (mcb_pmsm_foc_dual_cpu1_f28379_B.AlphaRelay &&
       mcb_pmsm_foc_dual_cpu1_f28379_B.BetaRelay);

    /* Switch: '<S329>/Switch' */
    if (mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_k) {
      /* Switch: '<S329>/Switch' incorporates:
       *  Constant: '<S329>/Constant'
       */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_a = -1;
    } else {
      /* Switch: '<S329>/Switch' incorporates:
       *  Constant: '<S329>/Constant1'
       */
      mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_a = 1;
    }

    /* End of Switch: '<S329>/Switch' */
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Dir_Sense_Trig_ZCE =
    mcb_pmsm_foc_dual_cpu1_f28379_B.AlphaRelay;

  /* End of Outputs for SubSystem: '<S321>/Dir_Sense' */

  /* If: '<S321>/If' incorporates:
   *  SwitchCase: '<S276>/Switch Case'
   */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_a > 0) {
    /* Outputs for IfAction SubSystem: '<S321>/Subsystem2' incorporates:
     *  ActionPort: '<S330>/Action Port'
     */
    /* Merge: '<S321>/Merge' incorporates:
     *  UnaryMinus: '<S330>/Unary Minus'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_h =
      -mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_e;

    /* Merge: '<S321>/Merge1' incorporates:
     *  SignalConversion generated from: '<S330>/SigmaBeta'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge1 =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_l;

    /* End of Outputs for SubSystem: '<S321>/Subsystem2' */
  } else {
    /* Outputs for IfAction SubSystem: '<S321>/Subsystem3' incorporates:
     *  ActionPort: '<S331>/Action Port'
     */
    /* Merge: '<S321>/Merge1' incorporates:
     *  UnaryMinus: '<S331>/Unary Minus'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge1 =
      -mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_l;

    /* Merge: '<S321>/Merge' incorporates:
     *  SignalConversion generated from: '<S331>/SigmaAlpha'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_h =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_e;

    /* End of Outputs for SubSystem: '<S321>/Subsystem3' */
  }

  /* End of If: '<S321>/If' */

  /* SwitchCase: '<S276>/Switch Case' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S345>/a16'
   *  Constant: '<S320>/PhaseDelay'
   *  Constant: '<S326>/FilterConstant'
   *  Constant: '<S326>/OneMinusFilterConstant'
   *  DataTypeConversion: '<S344>/DTC'
   *  Delay: '<S320>/Delay'
   *  Delay: '<S322>/Delay'
   *  Delay: '<S323>/Delay'
   *  Delay: '<S327>/Delay'
   *  Delay: '<S332>/Delay1'
   *  Delay: '<S333>/Delay1'
   *  Gain: '<S320>/AngleConversion'
   *  Gain: '<S320>/SpeedConversion'
   *  Gain: '<S322>/Eta'
   *  Gain: '<S322>/a'
   *  Gain: '<S322>/b'
   *  Gain: '<S323>/Eta'
   *  Gain: '<S323>/a'
   *  Gain: '<S323>/b'
   *  Gain: '<S327>/PositionToCount'
   *  Gain: '<S327>/SpeedGain'
   *  Product: '<S328>/Product'
   *  Product: '<S328>/Product1'
   *  Product: '<S328>/Product2'
   *  Product: '<S328>/Product3'
   *  Product: '<S342>/Product'
   *  Product: '<S342>/Product1'
   *  Signum: '<S322>/Sign'
   *  Signum: '<S323>/Sign'
   *  Sum: '<S322>/Sum'
   *  Sum: '<S322>/Sum1'
   *  Sum: '<S323>/Sum'
   *  Sum: '<S323>/Sum1'
   *  Sum: '<S327>/SpeedCount'
   *  Sum: '<S328>/Sum1'
   *  Sum: '<S328>/Sum2'
   *  Sum: '<S342>/Add1'
   *  Switch: '<S326>/Switch1'
   *  Switch: '<S328>/Switch'
   *  Switch: '<S345>/Switch'
   *  Trigonometry: '<S345>/Atan2'
   *  UnitDelay: '<S332>/Unit Delay'
   *  UnitDelay: '<S332>/Unit Delay1'
   *  UnitDelay: '<S333>/Unit Delay'
   *  UnitDelay: '<S333>/Unit Delay1'
   *  UnitDelay: '<S336>/Unit Delay'
   *  UnitDelay: '<S339>/Unit Delay'
   *  UnitDelay: '<S342>/Unit Delay'
   * */
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_n == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_n !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu1_f28379_B.LogicalOperator_f) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_a = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_n = Delay_Reset_ZCE_h_tmp;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_g =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_a;

  /* Outputs for Atomic SubSystem: '<S320>/angleCompensation' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_h5 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_h * 3.0F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product2_h =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge1 *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_g;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_n =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_h5 +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product2_h;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_ns =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge1 * 3.0F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product3 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_h *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_g;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_c =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_ns -
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product3;

  /* Outputs for Atomic SubSystem: '<S328>/atan1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Atan2_o = atan2f
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_n,
     mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_c);
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_e =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Atan2_o;
  mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_e;

  /* End of Outputs for SubSystem: '<S328>/atan1' */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o > 0.0F) {
    /* Switch: '<S328>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g =
      mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o;
  } else {
    /* Bias: '<S328>/Bias' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Bias_l =
      mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o + 6.28318548F;

    /* Switch: '<S328>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Bias_l;
  }

  /* End of Outputs for SubSystem: '<S320>/angleCompensation' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[0] = 0.159154937F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2;
  if (rtIsNaNF(GetADCVoltage)) {
    /* Signum: '<S322>/Sign' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign = (rtNaNF);
  } else if (GetADCVoltage < 0.0F) {
    /* Signum: '<S322>/Sign' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign = -1.0F;
  } else {
    /* Signum: '<S322>/Sign' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign = (GetADCVoltage > 0.0F);
  }

  mcb_pmsm_foc_dual_cpu1_f28379_B.Eta = 0.00901949778F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_bb =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[0] -
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4;
  mcb_pmsm_foc_dual_cpu1_f28379_B.b = 0.0488018617F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_bb;
  mcb_pmsm_foc_dual_cpu1_f28379_B.a_i = 0.932831F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_m;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_k = (mcb_pmsm_foc_dual_cpu1_f28379_B.b -
    mcb_pmsm_foc_dual_cpu1_f28379_B.Eta) + mcb_pmsm_foc_dual_cpu1_f28379_B.a_i;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_p;
  if (rtIsNaNF(GetADCVoltage)) {
    /* Signum: '<S323>/Sign' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign_n = (rtNaNF);
  } else if (GetADCVoltage < 0.0F) {
    /* Signum: '<S323>/Sign' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign_n = -1.0F;
  } else {
    /* Signum: '<S323>/Sign' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign_n = (GetADCVoltage > 0.0F);
  }

  mcb_pmsm_foc_dual_cpu1_f28379_B.Eta_e = 0.00901949778F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign_n;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_bo =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[1] -
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_d;
  mcb_pmsm_foc_dual_cpu1_f28379_B.b_j = 0.0488018617F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_bo;
  mcb_pmsm_foc_dual_cpu1_f28379_B.a_d = 0.932831F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_a;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_b = (mcb_pmsm_foc_dual_cpu1_f28379_B.b_j
    - mcb_pmsm_foc_dual_cpu1_f28379_B.Eta_e) +
    mcb_pmsm_foc_dual_cpu1_f28379_B.a_d;
  mcb_pmsm_foc_dual_cpu1_f28379_B.PositionToCount_f = (uint32_T)(6.83563648E+8F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g);
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_b =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_g[mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx_j];
  mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedCount_g = (int32_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.PositionToCount_f - (int32_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_b;
  mcb_pmsm_foc_dual_cpu1_f28379_B.DTC_j = (real32_T)
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedCount_g;
  mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedGain_a = 4.83720175E-10F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.DTC_j;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_m[0] = 0.00300833327F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_m[1] = 0.996991694F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product_fr =
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedGain_a * 0.00300833327F;
  mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_f =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gl;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_p = 0.996991694F *
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_f;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_ey =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_fr +
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_p;
  mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_ey;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay1_DSTATE =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Eta;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_j =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_h =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_k;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_j =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_c =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_e;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay1_DSTATE_n =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Eta_e;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_m =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_p;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_k =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_b;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_p =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_d;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_n =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_l;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_a =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_ey;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_g[mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx_j]
    = mcb_pmsm_foc_dual_cpu1_f28379_B.PositionToCount_f;
  if (mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx_j < 39U) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx_j++;
  } else {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.CircBufIdx_j = 0U;
  }

  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gl =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_ey;

  /* End of Outputs for SubSystem: '<S276>/Sliding Mode Observer' */
}

/* Model step function for TID0 */
void mcb_pmsm_foc_dual_cpu1_f28379d_step0(void) /* Sample time: [5.0E-5s, 0.0s] */
{
  int16_T tmp;

  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Outputs for Atomic SubSystem: '<Root>/Sensor Driver Blocks ' */
  mcb_pmsm_SensorDriverBlocks();

  /* End of Outputs for SubSystem: '<Root>/Sensor Driver Blocks ' */

  /* Delay: '<Root>/Delay5' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[0] =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[0];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[1] =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[1];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[2] =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[2];
  mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[3] =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[3];

  /* Outputs for Atomic SubSystem: '<Root>/Sensorless Algorithm' */
  mcb_pms_SensorlessAlgorithm();

  /* End of Outputs for SubSystem: '<Root>/Sensorless Algorithm' */

  /* RateTransition: '<S2>/Rate Transition4' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RateTransition4 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_Buffer[mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<S2>/Open_Loop_Control' */
  mcb_pmsm__Open_Loop_Control();

  /* End of Outputs for SubSystem: '<S2>/Open_Loop_Control' */

  /* RateTransition: '<S2>/Rate Transition1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RateTransition1 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition1_Buffer0;

  /* RateTransition: '<S2>/RT2' */
  tmp = mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_ActiveBufIdx << 1U;
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT2[0] =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[tmp];
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT2[1] =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[tmp + 1];

  /* RateTransition generated from: '<S2>/Rate Transition2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedRef =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_Buffer[mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<S2>/Current Control' */
  mcb_pmsm_foc_CurrentControl();

  /* End of Outputs for SubSystem: '<S2>/Current Control' */

  /* Outputs for Atomic SubSystem: '<Root>/Inverter Driver Peripherals' */
  m_InverterDriverPeripherals();

  /* End of Outputs for SubSystem: '<Root>/Inverter Driver Peripherals' */

  /* RateTransition: '<S2>/RT1' */
  if (mcb_pmsm_foc_dual_cpu1_f2_DWork.RT1_semaphoreTaken == 0) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RT1_Buffer0 =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[1];
  }

  /* End of RateTransition: '<S2>/RT1' */

  /* SignalConversion generated from: '<Root>/Delay5' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[0] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m;
  mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_b;
  mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[2] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_k;
  mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[3] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_d;

  /* Outputs for Atomic SubSystem: '<Root>/Delay to start motor2' */
  /* DataStoreRead: '<S1>/Data Store Read' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedRef;

  /* Abs: '<S1>/Abs' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Abs_d3 = fabsf
    (mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead);

  /* Switch: '<S1>/Switch2' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_l = (uint16_T)
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Abs_d3 > 0.1F);

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_ev =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2_l != 0U);

  /* DataStoreRead: '<S1>/Data Store Read1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead1_n =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Enable;

  /* Logic: '<S1>/AND' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.AND =
    (mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_ev &&
     mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead1_n);

  /* Logic: '<S1>/NOT' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.NOT_j = !mcb_pmsm_foc_dual_cpu1_f28379_B.AND;

  /* Outputs for Enabled SubSystem: '<S1>/Disable EnMtr2TrqCtrl' incorporates:
   *  EnablePort: '<S12>/Enable'
   */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.NOT_j) {
    /* DataStoreWrite: '<S12>/Data Store Write' incorporates:
     *  Constant: '<S12>/Constant'
     */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.EnMtr2Ctrl = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Disable EnMtr2TrqCtrl' */

  /* Outputs for Enabled SubSystem: '<S1>/Enable EnMtr2TrqCtrl after 2 sec delay' incorporates:
   *  EnablePort: '<S13>/Enable'
   */
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.AND) {
    if (!mcb_pmsm_foc_dual_cpu1_f2_DWork.EnableEnMtr2TrqCtrlafter2secdel) {
      /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gv = 0.0F;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.EnableEnMtr2TrqCtrlafter2secdel = true;
    }

    /* UnitDelay: '<S13>/Unit Delay' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_jv =
      mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gv;

    /* Sum: '<S13>/Add' incorporates:
     *  Constant: '<S13>/Constant2'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_e =
      mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_jv + 1.0F;

    /* Switch: '<S13>/Switch' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mo =
      (mcb_pmsm_foc_dual_cpu1_f28379_B.Add_e > 40000.0F);

    /* Outputs for Enabled SubSystem: '<S13>/Enable EnMtr2TrqCtrl' incorporates:
     *  EnablePort: '<S14>/Enable'
     */
    if (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mo) {
      /* DataStoreWrite: '<S14>/Data Store Write' incorporates:
       *  Constant: '<S14>/Constant'
       */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.EnMtr2Ctrl = true;
    }

    /* End of Outputs for SubSystem: '<S13>/Enable EnMtr2TrqCtrl' */

    /* Update for UnitDelay: '<S13>/Unit Delay' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gv =
      mcb_pmsm_foc_dual_cpu1_f28379_B.Add_e;
  } else {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.EnableEnMtr2TrqCtrlafter2secdel = false;
  }

  /* End of Outputs for SubSystem: '<S1>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  /* End of Outputs for SubSystem: '<Root>/Delay to start motor2' */

  /* Update for Delay: '<Root>/Delay5' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[0] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[0];
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[1] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[1];
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[2] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[2];
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[3] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[3];
}

/* Model step function for TID1 */
void mcb_pmsm_foc_dual_cpu1_f28379d_step1(void) /* Sample time: [0.001s, 0.0s] */
{
  real32_T rateLimiterRate;

  /* RateTransition: '<S2>/RT1' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT1_semaphoreTaken = 1;

  /* RateTransition: '<S2>/RT1' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT1 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RT1_Buffer0;

  /* RateTransition: '<S2>/RT1' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT1_semaphoreTaken = 0;

  /* RateTransition: '<S2>/RT6' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT6 =
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion_l;

  /* RateTransition: '<S2>/RT5' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT5 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RT5_Buffer0;

  /* RateTransition: '<S7>/RT3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT3 =
    mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_Buffer[mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_ActiveBufIdx];

  /* Outputs for Atomic SubSystem: '<S7>/Slew Rate' */
  /* Outputs for IfAction SubSystem: '<S272>/Rate Limiter for SMO' incorporates:
   *  ActionPort: '<S274>/Action Port'
   */
  /* SwitchCase: '<S272>/Switch Case' incorporates:
   *  RateLimiter: '<S274>/Rate Limiter'
   *  RateLimiter: '<S274>/Rate Limiter1'
   *  Switch: '<S274>/Switch'
   */
  rateLimiterRate = mcb_pmsm_foc_dual_cpu1_f28379_B.RT3 -
    mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY;
  if (rateLimiterRate > 0.00554016605F) {
    /* RateLimiter: '<S274>/Rate Limiter' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter =
      mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY + 0.00554016605F;
  } else if (rateLimiterRate < -0.00554016605F) {
    /* RateLimiter: '<S274>/Rate Limiter' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter =
      mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY - 0.00554016605F;
  } else {
    /* RateLimiter: '<S274>/Rate Limiter' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter =
      mcb_pmsm_foc_dual_cpu1_f28379_B.RT3;
  }

  mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY =
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter;
  rateLimiterRate = mcb_pmsm_foc_dual_cpu1_f28379_B.RT3 -
    mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY_i;
  if (rateLimiterRate > 0.00554016605F) {
    /* RateLimiter: '<S274>/Rate Limiter1' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter1 =
      mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY_i + 0.00554016605F;
  } else if (rateLimiterRate < -0.00554016605F) {
    /* RateLimiter: '<S274>/Rate Limiter1' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter1 =
      mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY_i - 0.00554016605F;
  } else {
    /* RateLimiter: '<S274>/Rate Limiter1' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter1 =
      mcb_pmsm_foc_dual_cpu1_f28379_B.RT3;
  }

  mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY_i =
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter1;
  if (mcb_pmsm_foc_dual_cpu1_f28379_B.RT3 >= 0.0F) {
    /* Merge: '<S272>/Merge' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c =
      mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter;
  } else {
    /* Merge: '<S272>/Merge' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c =
      mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter1;
  }

  /* End of SwitchCase: '<S272>/Switch Case' */
  /* End of Outputs for SubSystem: '<S272>/Rate Limiter for SMO' */
  /* End of Outputs for SubSystem: '<S7>/Slew Rate' */

  /* RateTransition: '<S2>/RT3' */
  mcb_pmsm_foc_dual_cpu1_f28379_B.RT3_g =
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c;

  /* Outputs for Atomic SubSystem: '<S2>/Speed Control' */
  mcb_pmsm_foc_d_SpeedControl(mcb_pmsm_foc_dual_cpu1_f28379_B.RT6,
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT5, mcb_pmsm_foc_dual_cpu1_f28379_B.RT3_g,
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT1,
    &mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl,
    &mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedControl);

  /* End of Outputs for SubSystem: '<S2>/Speed Control' */

  /* RateTransition: '<S2>/RT2' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer
    [(mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_ActiveBufIdx == 0) << 1U] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Id_Ref;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[1 +
    ((mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_ActiveBufIdx == 0) << 1U)] =
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Saturation;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_ActiveBufIdx == 0);

  /* RateTransition generated from: '<S2>/Rate Transition2' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_Buffer[mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_ActiveBufIdx
    == 0] = mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_ActiveBufIdx =
    (mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_ActiveBufIdx == 0);

  /* RateTransition: '<S2>/Rate Transition4' */
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_Buffer[mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_ActiveBufIdx
    == 0] = mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_ActiveBufIdx =
    (mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_ActiveBufIdx == 0);
}

/* Model step function for TID2 */
void mcb_pmsm_foc_dual_cpu1_f28379d_step2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (c280xgpio_do): '<S8>/Grounding the SPI clockfor the DRV830x' incorporates:
   *  Constant: '<S8>/Constant'
   */
  {
    if ((0U)) {
      GpioDataRegs.GPBSET.bit.GPIO60 = 1U;
    } else {
      GpioDataRegs.GPBCLEAR.bit.GPIO60 = 1U;
    }
  }
}

/* Model step function for TID3 */
void mcb_pmsm_foc_dual_cpu1_f28379d_step3(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S5>/Digital Output' incorporates:
   *  Constant: '<S5>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_dual_cpu1_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_dual_cpu1_f2837_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_dual_cpu1));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_dual_cpu1_f28379_B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_dual_cpu1_));

  {
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay5[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateTransition4 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT2[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT2[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedRef = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RT3_g = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.GetADCVoltage[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.GetADCVoltage[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.GetCurrents[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.GetCurrents[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PU_Conversion[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_b[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_b[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_ls = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_h3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_f = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product2_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_bo[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_bo[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_oc = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_p = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DTC = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_p[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_p[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_ob = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_bz = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.elect2mech = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jg = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_g = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Atan2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_f = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Bias = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_cs = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.a = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.b_invg = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_f[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_f[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay1_g = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.a_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_a = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_p = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.b_invg_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay1_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_a[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_a[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_f = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Delay_g = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Eta = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_bb = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.a_i = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sign_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Eta_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_bo = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.b_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.a_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DTC_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedGain_a = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_m[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_m[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_fr = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_f = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_p = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_ey = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_h5 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product2_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_ns = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Atan2_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Bias_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Bias_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.RateLimiter1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_bs = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.id_Ld_Lq = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product3_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.u_5_Pp = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.IndexVector_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.P_output = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Abs = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_f = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_kj = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_eq = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_f = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Input = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Ia = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Speedfb = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Pos_pu = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.indexing = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum3_lv = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1_a = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum2_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum4_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum5 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_a = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum6_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_cj = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PProdOut = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_n = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Integrator = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PProdOut_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Integrator_a = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_jx = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gl = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_gt = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_b4 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product1_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_bt = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_l[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_i = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DeadZone_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.IProdOut_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.add_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.add_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Max = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Min = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_two_i = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add1_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_fq[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_h[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_h[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_h[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_back = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Convert_back_h = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.acos_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.bsin = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_Ds = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.bcos = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.asin_j = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_Qs = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_g1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.qcos = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.dsin = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_beta = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.dcos = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.qsin = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.sum_alpha = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mw[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mw[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_m = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Abs_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Saturation_o = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_lc[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_lc[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SquareRoot = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_b4 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_id[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_id[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product_m2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_l = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Product2_k2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_ld = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_i = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_mf = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch1_c = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Sqrt = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Gain_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.a_plus_2b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o1_k = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.algDD_o2_d = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.DataStoreRead = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Abs_d3 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.UnitDelay_jv = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.Add_e = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Id_Ref = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Speed_Ref = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Switch1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Switch1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Product = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.UnitDelay = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Product1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Add1 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Sum = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.PProdOut = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Ki2 = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Integrator = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Sum_b = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.DeadZone = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.IProdOut = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Switch = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Saturation = 0.0F;
    mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl.Switch1_d = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_dual_cpu1_f2_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_dual_cpu1_f));
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay5_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_o = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_b = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay1_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_j = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_h = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_j = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_c = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay1_DSTATE_n = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_m = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_k = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay1_DSTATE_p = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_n = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Delay_DSTATE_a = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gl = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_f = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_cr = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_l = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Integrator_DSTATE_n = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gv = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_Buffer[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition4_Buffer[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[2] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT2_Buffer[3] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_Buffer[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition2_1_Buffer[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT1_Buffer0 = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedRef = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_Buffer[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_Buffer[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY_i = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.Add_DWORK1 = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedControl.UnitDelay_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedControl.Integrator_DSTATE = 0.0F;

  {
    uint16_T s244_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory29' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.Enable = true;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.IaOffset = 2295U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.IbOffset = 2286U;

    /* Start for S-Function (c280xgpio_do): '<S8>/Grounding the SPI clockfor the DRV830x' */
    EALLOW;
    GpioCtrlRegs.GPBMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPBDIR.all |= 0x10000000U;
    EDIS;
    mcb_pmsm_foc_dua_PrevZCSigState.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_p = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_n = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_h = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Inverter Driver Peripherals' */
    InverterDriverPeripher_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Inverter Driver Peripherals' */

    /* SystemInitialize for Atomic SubSystem: '<S2>/Current Control' */
    mcb_pms_CurrentControl_Init();

    /* End of SystemInitialize for SubSystem: '<S2>/Current Control' */

    /* SystemInitialize for Atomic SubSystem: '<S2>/Speed Control' */
    mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_dual_cpu1_f28379_B.SpeedControl,
      &mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<S2>/Speed Control' */

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */
    {
      uint32_T dataTypeVarLoc;
      uint16_T dataTypeSize;

      /* Start for S-Function (c28xsci_rx): '<S352>/SCI Receive' */

      /* Initialize out port */
      {
        mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[0] = (real32_T)0.0;
        mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[1] = (real32_T)0.0;
        mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[2] = (real32_T)0.0;
        mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[3] = (real32_T)0.0;
      }

      /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
      {
        /* InitCpuTimers() - CPU Timers are also initialized in
         * MW_c28xx_board.c in the generated code.
         */
        CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
        CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
        CpuTimer2Regs.TPR.all = 0x00U; /* no prescaler    */
        StartCpuTimer2();
      }

      /* Start for MATLABSystem: '<S355>/IPC Write' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.Overwritten = 0ULL;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.NumBufUsed = 0U;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.matlabCodegenIsDeleted = false;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.objisempty_c = true;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.isInitialized = 1L;
      dataTypeSize = sizeof(dataTypeVarLoc);
      if (dataTypeSize > 32767U) {
        dataTypeSize = MAX_uint16_T;
      } else {
        dataTypeSize <<= 1U;
      }

      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams.NumOfBuffers = 4.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams.ChNum = 0.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams.BufferSize = 1.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams.DataTypeInBytes =
        dataTypeSize;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams.IsIntEnabled = 0.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams.IPCBetween = 0.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcHandle = MW_IPC_Init
        (&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcParams);
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.isSetupComplete = true;

      /* End of Start for MATLABSystem: '<S355>/IPC Write' */

      /* Start for MATLABSystem: '<S357>/IPC Write' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.Overwritten = 0ULL;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.NumBufUsed = 0U;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.matlabCodegenIsDeleted = false;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.objisempty_n = true;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.isInitialized = 1L;
      dataTypeSize = sizeof(dataTypeSize);
      if (dataTypeSize > 32767U) {
        dataTypeSize = MAX_uint16_T;
      } else {
        dataTypeSize <<= 1U;
      }

      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams.NumOfBuffers = 4.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams.ChNum = 1.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams.BufferSize = 1.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams.DataTypeInBytes =
        dataTypeSize;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams.IsIntEnabled = 0.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams.IPCBetween = 0.0;
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcHandle = MW_IPC_Init
        (&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcParams);
      mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.isSetupComplete = true;

      /* End of Start for MATLABSystem: '<S357>/IPC Write' */
    }

    /* SystemInitialize for Atomic SubSystem: '<S7>/Slew Rate' */
    /* SystemInitialize for IfAction SubSystem: '<S272>/Rate Limiter for SMO' */
    /* InitializeConditions for RateLimiter: '<S274>/Rate Limiter' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY = 0.1F;

    /* InitializeConditions for RateLimiter: '<S274>/Rate Limiter1' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.PrevY_i = -0.1F;

    /* End of SystemInitialize for SubSystem: '<S272>/Rate Limiter for SMO' */

    /* SystemInitialize for Merge: '<S272>/Merge' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Merge_c = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S7>/Slew Rate' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensor Driver Blocks ' */
    mcb_SensorDriverBlocks_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Sensor Driver Blocks ' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensorless Algorithm' */
    mc_SensorlessAlgorithm_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Sensorless Algorithm' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Delay to start motor2' */
    /* SystemInitialize for Enabled SubSystem: '<S1>/Enable EnMtr2TrqCtrl after 2 sec delay' */
    /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
    mcb_pmsm_foc_dual_cpu1_f2_DWork.UnitDelay_DSTATE_gv = 0.0F;

    /* End of SystemInitialize for SubSystem: '<S1>/Enable EnMtr2TrqCtrl after 2 sec delay' */
    /* End of SystemInitialize for SubSystem: '<Root>/Delay to start motor2' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S5>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S242>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S242>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFCFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x400000U;
    EDIS;

    /* Start for S-Function (c2802xadc): '<S240>/ADC' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC1 ();

    /* Start for S-Function (c2802xadc): '<S240>/ADC1' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC1 ();

    /* SystemInitialize for Enabled SubSystem: '<S4>/Calculate ADC Offset ' */
    /* SystemInitialize for Iterator SubSystem: '<S241>/For Iterator Subsystem' */
    /* Start for S-Function (c2802xadc): '<S244>/ADC_A_IN0' */
    if (MW_adcCInitFlag == 0U) {
      InitAdcC();
      MW_adcCInitFlag = 1U;
    }

    config_ADCC_SOC2 ();

    /* Start for S-Function (c2802xadc): '<S244>/ADC_B_IN0' */
    if (MW_adcBInitFlag == 0U) {
      InitAdcB();
      MW_adcBInitFlag = 1U;
    }

    config_ADCB_SOC2 ();

    /* End of SystemInitialize for SubSystem: '<S241>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S4>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Switch: '<S242>/Switch' incorporates:
     *  Constant: '<S242>/Inverter Enable'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_kx = 1U;

    /* S-Function (c280xgpio_do): '<S242>/Digital Output' */
    {
      if (mcb_pmsm_foc_dual_cpu1_f28379_B.Switch_kx) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* S-Function (c280xgpio_do): '<S242>/Digital Output1' incorporates:
     *  Constant: '<S242>/RunTimeMeasurement'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPASET.bit.GPIO22 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S4>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S241>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S241>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S244>/For Iterator'
     */
    for (s244_iter = 1U; s244_iter < 17U; s244_iter++) {
      /* Outputs for Iterator SubSystem: '<S241>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S244>/For Iterator'
       */
      mcb_pmsm_foc_dual_cpu1_f28379_B.ForIterator = s244_iter;

      /* S-Function (c2802xadc): '<S244>/ADC_A_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_A_IN0_h = (AdccResultRegs.ADCRESULT2);
      }

      /* S-Function (c2802xadc): '<S244>/ADC_B_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcbRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_B_IN0_g = (AdcbResultRegs.ADCRESULT2);
      }

      /* If: '<S244>/If' */
      if (mcb_pmsm_foc_dual_cpu1_f28379_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S244>/If Action Subsystem' incorporates:
         *  ActionPort: '<S249>/Action Port'
         */
        /* Memory: '<S249>/Memory' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.Memory =
          mcb_pmsm_foc_dual_cpu1_f2_DWork.Memory_PreviousInput;

        /* Sum: '<S249>/Sum' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_k =
          mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_A_IN0_h +
          mcb_pmsm_foc_dual_cpu1_f28379_B.Memory;

        /* Memory: '<S249>/Memory1' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.Memory1 =
          mcb_pmsm_foc_dual_cpu1_f2_DWork.Memory1_PreviousInput;

        /* Sum: '<S249>/Sum1' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_k5 =
          mcb_pmsm_foc_dual_cpu1_f28379_B.ADC_B_IN0_g +
          mcb_pmsm_foc_dual_cpu1_f28379_B.Memory1;

        /* Update for Memory: '<S249>/Memory' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.Memory_PreviousInput =
          mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_k;

        /* Update for Memory: '<S249>/Memory1' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.Memory1_PreviousInput =
          mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_k5;

        /* End of Outputs for SubSystem: '<S244>/If Action Subsystem' */
      }

      /* End of If: '<S244>/If' */
    }

    /* End of Outputs for SubSystem: '<S241>/For Iterator Subsystem' */

    /* Product: '<S241>/Divide' incorporates:
     *  Constant: '<S241>/Constant'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Divide = (uint16_T)((real_T)
      mcb_pmsm_foc_dual_cpu1_f28379_B.Sum_k / 8.0);

    /* If: '<S241>/If' incorporates:
     *  Constant: '<S241>/Constant1'
     *  Constant: '<S241>/Constant2'
     */
    if ((mcb_pmsm_foc_dual_cpu1_f28379_B.Divide > 1500U) &&
        (mcb_pmsm_foc_dual_cpu1_f28379_B.Divide < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S241>/If Action Subsystem' incorporates:
       *  ActionPort: '<S245>/Action Port'
       */
      /* DataStoreWrite: '<S245>/Data Store Write1' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.IaOffset =
        mcb_pmsm_foc_dual_cpu1_f28379_B.Divide;

      /* End of Outputs for SubSystem: '<S241>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S241>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S246>/Action Port'
       */
      /* DataStoreWrite: '<S246>/Data Store Write1' incorporates:
       *  Constant: '<S246>/Constant'
       */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.IaOffset = 2295U;

      /* End of Outputs for SubSystem: '<S241>/If Action Subsystem1' */
    }

    /* End of If: '<S241>/If' */

    /* Product: '<S241>/Divide1' incorporates:
     *  Constant: '<S241>/Constant'
     */
    mcb_pmsm_foc_dual_cpu1_f28379_B.Divide1 = (uint16_T)((real_T)
      mcb_pmsm_foc_dual_cpu1_f28379_B.Sum1_k5 / 8.0);

    /* If: '<S241>/If1' incorporates:
     *  Constant: '<S241>/Constant1'
     *  Constant: '<S241>/Constant2'
     */
    if ((mcb_pmsm_foc_dual_cpu1_f28379_B.Divide1 > 1500U) &&
        (mcb_pmsm_foc_dual_cpu1_f28379_B.Divide1 < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S241>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S247>/Action Port'
       */
      /* DataStoreWrite: '<S247>/Data Store Write2' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.IbOffset =
        mcb_pmsm_foc_dual_cpu1_f28379_B.Divide1;

      /* End of Outputs for SubSystem: '<S241>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S241>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S248>/Action Port'
       */
      /* DataStoreWrite: '<S248>/Data Store Write2' incorporates:
       *  Constant: '<S248>/Constant1'
       */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.IbOffset = 2286U;

      /* End of Outputs for SubSystem: '<S241>/If Action Subsystem3' */
    }

    /* End of If: '<S241>/If1' */
    /* End of Outputs for SubSystem: '<S4>/Calculate ADC Offset ' */

    /* Logic: '<S4>/NOT' */
    mcb_pmsm_foc_dual_cpu1_f28379_B.NOT = false;

    /* Outputs for Enabled SubSystem: '<S4>/Default ADC Offset' incorporates:
     *  EnablePort: '<S243>/Enable'
     */
    if (mcb_pmsm_foc_dual_cpu1_f28379_B.NOT) {
      /* DataStoreWrite: '<S243>/Data Store Write1' incorporates:
       *  Constant: '<S243>/Constant'
       */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.IaOffset = 2295U;

      /* DataStoreWrite: '<S243>/Data Store Write2' incorporates:
       *  Constant: '<S243>/Constant1'
       */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.IbOffset = 2286U;
    }

    /* End of Outputs for SubSystem: '<S4>/Default ADC Offset' */

    /* S-Function (c2802xadc): '<S240>/ADC' */
    {
      /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
      /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
      mcb_pmsm_foc_dual_cpu1_f28379_B.ADC = (AdccResultRegs.ADCRESULT1);
    }

    /* S-Function (c2802xadc): '<S240>/ADC1' */
    {
      /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
      /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
      mcb_pmsm_foc_dual_cpu1_f28379_B.ADC1 = (AdcbResultRegs.ADCRESULT1);
    }

    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_dual_cpu1_f28379d_terminate(void)
{
  /* Terminate for S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/Serial Receive'
   */

  /* Termination for function-call system: '<Root>/Serial Receive' */

  /* Terminate for MATLABSystem: '<S355>/IPC Write' */
  if (!mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S355>/IPC Write' */

  /* Terminate for MATLABSystem: '<S357>/IPC Write' */
  if (!mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S357>/IPC Write' */

  /* End of Terminate for S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' */

  /* Terminate for Atomic SubSystem: '<Root>/Inverter Driver Peripherals' */
  InverterDriverPeripher_Term();

  /* End of Terminate for SubSystem: '<Root>/Inverter Driver Peripherals' */
}

void mcb_pmsm_foc_dual_cpu1_f28379d_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,1);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S239>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */
      {
        MW_IPC_Diag_T diagDataOut;
        MW_IPC_Diag_T diagDataOut_p;
        uint64_T q0;
        uint64_T qY;
        uint16_T tmp;

        /* S-Function (c28xsci_rx): '<S352>/SCI Receive' */
        {
          int16_T i;
          int16_T errFlg = NOERROR;
          uint16_T isHeadReceived = 1U;

          //get data as uint16 in recBuff
          uint16_T recbuff[8];
          for (i = 0; i < 8; i++) {
            recbuff[i] = 0U;
          }

          errFlg = NOERROR;

          /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
          if (isHeadReceived) {
            errFlg = scia_rcv(recbuff, 16, 4);
            asm(" NOP");
            if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
              memcpy( &mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[0], recbuff,8);
            }
          }
        }

        /* DataTypeConversion: '<S353>/Data Type Conversion2' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion2_b = (uint16_T)
          mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[1];

        /* S-Function (sfix_bitop): '<S351>/Bitwise Operator' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.BitwiseOperator =
          mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion2_b & 1U;

        /* DataTypeConversion: '<S351>/Data Type Conversion3' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion3_o =
          (mcb_pmsm_foc_dual_cpu1_f28379_B.BitwiseOperator != 0U);

        /* DataStoreWrite: '<S11>/Data Store Write' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.Enable =
          mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion3_o;

        /* DataStoreWrite: '<S11>/Data Store Write1' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.SpeedRef =
          mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[0];

        /* S-Function (sfix_bitop): '<S351>/Bitwise Operator1' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.BitwiseOperator1 =
          mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion2_b & 240U;

        /* ArithShift: '<S351>/Shift Arithmetic1' incorporates:
         *  S-Function (sfix_bitop): '<S351>/Bitwise Operator1'
         */
        mcb_pmsm_foc_dual_cpu1_f28379_B.ShiftArithmetic1 =
          mcb_pmsm_foc_dual_cpu1_f28379_B.BitwiseOperator1 >> 4U;

        /* DataStoreWrite: '<S11>/Data Store Write2' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.SignalSelect1 =
          mcb_pmsm_foc_dual_cpu1_f28379_B.ShiftArithmetic1;

        /* DataTypeConversion: '<S353>/Data Type Conversion4' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion4 = (int32_T)
          (mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[3] * 2.68435456E+8F);

        /* DataTypeConversion: '<S353>/Data Type Conversion3' incorporates:
         *  DataTypeConversion: '<S353>/Data Type Conversion4'
         */
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion3 = (uint32_T)
          mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion4;

        /* MATLABSystem: '<S355>/IPC Write' */
        diagDataOut.OverwriteDiag = 0U;
        diagDataOut.NumBuffUsedDiag = 0U;
        MW_IPC_Write(&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.IpcHandle, 0.0,
                     &mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion3,
                     &diagDataOut);

        /* Start for MATLABSystem: '<S355>/IPC Write' */
        q0 = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.Overwritten;
        qY = q0 + diagDataOut.OverwriteDiag;
        if (qY < q0) {
          qY = MAX_uint64_T;
        }

        /* MATLABSystem: '<S355>/IPC Write' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.Overwritten = qY;
        if (diagDataOut.NumBuffUsedDiag <= 4U) {
          mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.NumBufUsed =
            diagDataOut.NumBuffUsedDiag;
        }

        q0 = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.Overwritten;
        tmp = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_jw.NumBufUsed;

        /* MATLABSystem: '<S355>/IPC Write' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.IPCChannelNumberofoverwrites_o = q0;

        /* MATLABSystem: '<S355>/IPC Write' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.IPCChannelNumberofbuffersused_c = tmp;

        /* DataTypeConversion: '<S353>/Data Type Conversion1' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1_g = (uint16_T)
          mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[2];

        /* MATLABSystem: '<S357>/IPC Write' */
        diagDataOut_p.OverwriteDiag = 0U;
        diagDataOut_p.NumBuffUsedDiag = 0U;
        MW_IPC_Write(&mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.IpcHandle, 0.0,
                     &mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion1_g,
                     &diagDataOut_p);

        /* Start for MATLABSystem: '<S357>/IPC Write' */
        q0 = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.Overwritten;
        qY = q0 + diagDataOut_p.OverwriteDiag;
        if (qY < q0) {
          qY = MAX_uint64_T;
        }

        /* MATLABSystem: '<S357>/IPC Write' */
        mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.Overwritten = qY;
        if (diagDataOut_p.NumBuffUsedDiag <= 4U) {
          mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.NumBufUsed =
            diagDataOut_p.NumBuffUsedDiag;
        }

        q0 = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.Overwritten;
        tmp = mcb_pmsm_foc_dual_cpu1_f2_DWork.obj_j.NumBufUsed;

        /* MATLABSystem: '<S357>/IPC Write' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.IPCChannelNumberofoverwrites_k = q0;

        /* MATLABSystem: '<S357>/IPC Write' */
        mcb_pmsm_foc_dual_cpu1_f28379_B.IPCChannelNumberofbuffersused_d = tmp;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S239>/Hardware Interrupt' */

      /* RateTransition: '<S2>/RT5' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.RT5_Buffer0 =
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion3_o;

      /* RateTransition: '<S2>/Rate Transition1' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.RateTransition1_Buffer0 =
        mcb_pmsm_foc_dual_cpu1_f28379_B.DataTypeConversion3_o;

      /* RateTransition: '<S7>/RT3' */
      mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_Buffer[mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_ActiveBufIdx
        == 0] = mcb_pmsm_foc_dual_cpu1_f28379_B.SCIReceive[0];
      mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_ActiveBufIdx =
        (mcb_pmsm_foc_dual_cpu1_f2_DWork.RT3_ActiveBufIdx == 0);
    }
  }

  /* Clear occurred Rx FIFO complete event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_foc_dual_cpu1_f28379d_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
