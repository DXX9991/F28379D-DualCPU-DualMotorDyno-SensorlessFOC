/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu2_f28379d.c
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

#include "mcb_pmsm_foc_dual_cpu2_f28379d.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d_types.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "mw_soc_ipc.h"
#include "zero_crossing_types.h"
#include <string.h>

/* Block signals (default storage) */
BlockIO_mcb_pmsm_foc_dual_cpu2_ mcb_pmsm_foc_dual_cpu2_f28379_B;

/* Block states (default storage) */
D_Work_mcb_pmsm_foc_dual_cpu2_f mcb_pmsm_foc_dual_cpu2_f2_DWork;

/* Previous zero-crossings (trigger) states */
PrevZCSigStates_mcb_pmsm_foc_du mcb_pmsm_foc_dua_PrevZCSigState;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_dual_cpu2 mcb_pmsm_foc_dual_cpu2_f2837_M_;
RT_MODEL_mcb_pmsm_foc_dual_cpu2 *const mcb_pmsm_foc_dual_cpu2_f2837_M =
  &mcb_pmsm_foc_dual_cpu2_f2837_M_;

/* Forward declaration for local functions */
static void mcb_pmsm_fo_SystemCore_setup_kc(soc_blocks_IPCRead_mcb_pmsm_foc *obj);
static void mcb_pmsm_foc_SystemCore_setup_k(soc_blocks_IPCRead_mcb_pmsm_foc *obj);
static void mcb_pmsm_foc_d_SystemCore_setup(soc_blocks_IPCRead_mcb_pmsm_foc *obj);
static void rate_monotonic_scheduler(void);

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_dual_cpu2_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_dual_cpu2_f2837_M, 1));
  eventFlags[2] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_dual_cpu2_f2837_M, 2));
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
  (mcb_pmsm_foc_dual_cpu2_f2837_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_dual_cpu2_f2837_M->Timing.TaskCounters.TID[1]) > 199) {/* Sample time: [0.01s, 0.0s] */
    mcb_pmsm_foc_dual_cpu2_f2837_M->Timing.TaskCounters.TID[1] = 0;
  }

  (mcb_pmsm_foc_dual_cpu2_f2837_M->Timing.TaskCounters.TID[2])++;
  if ((mcb_pmsm_foc_dual_cpu2_f2837_M->Timing.TaskCounters.TID[2]) > 9999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_dual_cpu2_f2837_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/* Output and update for atomic system: '<Root>/Current Sensing' */
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentSensing, "ramfuncs")

void mcb_pmsm_foc_CurrentSensing(void)
{
  /* S-Function (memorycopy): '<S1>/Memory Copy' */
  {
    uint16_T *memindsrc1 = (uint16_T *) (&AdccResultRegs.ADCRESULT1);
    uint16_T *meminddst1 = (uint16_T *)
      (&mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy_p);
    *(uint16_T *) (meminddst1) = *(uint16_T *) (memindsrc1);
  }

  /* S-Function (memorycopy): '<S1>/Memory Copy1' */
  {
    uint16_T *memindsrc2 = (uint16_T *) (&AdcbResultRegs.ADCRESULT1);
    uint16_T *meminddst2 = (uint16_T *)
      (&mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy1_l);
    *(uint16_T *) (meminddst2) = *(uint16_T *) (memindsrc2);
  }
}

/* System initialize for atomic system: '<Root>/Foc Algorithm' */
void mcb_pmsm__FocAlgorithm_Init(void)
{
  /* Start for Constant: '<S21>/Kp1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Kp1 = 0.0F;

  /* Start for Constant: '<S20>/Ki1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Ki1 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S73>/Integrator' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE_i = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_PrevResetState_h = 0;
}

/* Output and update for atomic system: '<Root>/Foc Algorithm' */
#pragma CODE_SECTION (mcb_pmsm_foc_d_FocAlgorithm, "ramfuncs")

void mcb_pmsm_foc_d_FocAlgorithm(void)
{
  real32_T Bias;
  real32_T u0;
  uint32_T Sum;
  int16_T Integrator_PrevResetState_tmp;
  boolean_T LogicalOperator_c_tmp;
  boolean_T tmp;

  /* SignalConversion generated from: '<S2>/SCI_Tx' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Ia =
    mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[0];

  /* SignalConversion generated from: '<S2>/SCI_Tx' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.pos = mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0];

  /* SignalConversion generated from: '<S2>/SCI_Tx' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Speed_fb =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[1];

  /* Outputs for Atomic SubSystem: '<S17>/Two phase CRL wrap' */
  /* Sum: '<S18>/a_plus_2b' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.a_plus_2b =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[0] +
     mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[1]) +
    mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[1];

  /* Gain: '<S18>/one_by_sqrt3' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_sqrt3 = 0.577350259F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.a_plus_2b;

  /* AlgorithmDescriptorDelegate generated from: '<S18>/a16' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_d =
    mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[0];

  /* AlgorithmDescriptorDelegate generated from: '<S18>/a16' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_k =
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_sqrt3;

  /* End of Outputs for SubSystem: '<S17>/Two phase CRL wrap' */

  /* Switch: '<S24>/Switch1' incorporates:
   *  Constant: '<S24>/ChosenMethod'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_a4 = 3U;

  /* RelationalOperator: '<S154>/Compare' incorporates:
   *  Constant: '<S154>/Constant'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Compare =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0] < 0.0F);

  /* DataTypeConversion: '<S152>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_o =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Compare;

  /* If: '<S152>/If' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_o > 0U) {
    /* Outputs for IfAction SubSystem: '<S152>/If Action Subsystem' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* DataTypeConversion: '<S155>/Convert_uint16' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_uint16_f = (int16_T)(real32_T)floor
      (mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0]);

    /* DataTypeConversion: '<S155>/Convert_back' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_back_o =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_uint16_f;

    /* Merge: '<S152>/Merge' incorporates:
     *  Sum: '<S155>/Sum'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_g =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0] -
      mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_back_o;

    /* End of Outputs for SubSystem: '<S152>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S152>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S156>/Action Port'
     */
    /* DataTypeConversion: '<S156>/Convert_uint16' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_uint16 = (int16_T)
      mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0];

    /* DataTypeConversion: '<S156>/Convert_back' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_back =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_uint16;

    /* Merge: '<S152>/Merge' incorporates:
     *  Sum: '<S156>/Sum'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_g =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0] -
      mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_back;

    /* End of Outputs for SubSystem: '<S152>/If Action Subsystem1' */
  }

  /* End of If: '<S152>/If' */

  /* Gain: '<S150>/indexing' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.indexing = 800.0F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_g;

  /* DataTypeConversion: '<S150>/Get_Integer' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Get_Integer = (uint16_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.indexing;

  /* Sum: '<S150>/Sum' incorporates:
   *  Constant: '<S150>/offset'
   */
  Sum = mcb_pmsm_foc_dual_cpu2_f28379_B.Get_Integer + 1UL;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum[0] = Sum;

  /* Selector: '<S150>/Lookup' incorporates:
   *  Constant: '<S150>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[0] =
    mcb_pmsm_foc_dual_cpu2_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S150>/Sum' */
  Sum = mcb_pmsm_foc_dual_cpu2_f28379_B.Get_Integer;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum[1] = Sum;

  /* Selector: '<S150>/Lookup' incorporates:
   *  Constant: '<S150>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[1] =
    mcb_pmsm_foc_dual_cpu2_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S150>/Sum' incorporates:
   *  Constant: '<S150>/offset'
   */
  Sum = mcb_pmsm_foc_dual_cpu2_f28379_B.Get_Integer + 201UL;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum[2] = Sum;

  /* Selector: '<S150>/Lookup' incorporates:
   *  Constant: '<S150>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[2] =
    mcb_pmsm_foc_dual_cpu2_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S150>/Sum' incorporates:
   *  Constant: '<S150>/offset'
   */
  Sum = mcb_pmsm_foc_dual_cpu2_f28379_B.Get_Integer + 200UL;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum[3] = Sum;

  /* Selector: '<S150>/Lookup' incorporates:
   *  Constant: '<S150>/sine_table_values'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[3] =
    mcb_pmsm_foc_dual_cpu2_f_ConstP.sine_table_values_Value[(int16_T)Sum];

  /* Sum: '<S151>/Sum3' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_h =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[0] -
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[1];

  /* DataTypeConversion: '<S150>/Data Type Conversion1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion1 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Get_Integer;

  /* Sum: '<S150>/Sum2' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2_a =
    mcb_pmsm_foc_dual_cpu2_f28379_B.indexing -
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion1;

  /* Product: '<S151>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_a =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_h *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2_a;

  /* Sum: '<S151>/Sum4' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_l =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_a +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[1];

  /* Sum: '<S151>/Sum5' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum5 = mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup
    [2] - mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[3];

  /* Product: '<S151>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_k =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum5 *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2_a;

  /* Sum: '<S151>/Sum6' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6_o =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_k +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[3];

  /* Outputs for Atomic SubSystem: '<S14>/Two inputs CRL' */
  /* Product: '<S148>/acos' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.acos_i =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_d *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6_o;

  /* Product: '<S148>/bsin' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.bsin =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_k *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_l;

  /* Sum: '<S148>/sum_Ds' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.sum_Ds =
    mcb_pmsm_foc_dual_cpu2_f28379_B.acos_i +
    mcb_pmsm_foc_dual_cpu2_f28379_B.bsin;

  /* Product: '<S148>/bcos' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.bcos =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_k *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6_o;

  /* Product: '<S148>/asin' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.asin_p =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_d *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_l;

  /* Sum: '<S148>/sum_Qs' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.sum_Qs = mcb_pmsm_foc_dual_cpu2_f28379_B.bcos
    - mcb_pmsm_foc_dual_cpu2_f28379_B.asin_p;

  /* Switch: '<S149>/Switch' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_mn[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_Ds;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_mn[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_Qs;

  /* AlgorithmDescriptorDelegate generated from: '<S148>/a16' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_mn[0];

  /* AlgorithmDescriptorDelegate generated from: '<S148>/a16' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_mn[1];

  /* End of Outputs for SubSystem: '<S14>/Two inputs CRL' */

  /* Sum: '<S21>/Sum' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_g = mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[1]
    - mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2;

  /* Product: '<S133>/PProd Out' incorporates:
   *  Constant: '<S21>/Kp'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PProdOut =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_g * 4.94871664F;

  /* Logic: '<S21>/Logical Operator' incorporates:
   *  Logic: '<S20>/Logical Operator'
   */
  LogicalOperator_c_tmp = !mcb_pmsm_foc_dual_cpu2_f28379_B.RateTransition;

  /* Logic: '<S21>/Logical Operator' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator_c = LogicalOperator_c_tmp;

  /* Constant: '<S21>/Kp1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Kp1 = 0.0F;

  /* DiscreteIntegrator: '<S128>/Integrator' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator_c ||
      (mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_PrevResetState != 0)) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE = 0.0F;
  }

  /* DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Integrator =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE;

  /* Sum: '<S137>/Sum' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq =
    mcb_pmsm_foc_dual_cpu2_f28379_B.PProdOut +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Integrator;

  /* Saturate: '<S135>/Saturation' */
  u0 = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq;
  if (u0 > 1.0F) {
    /* Saturate: '<S135>/Saturation' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation = 1.0F;
  } else if (u0 < -1.0F) {
    /* Saturate: '<S135>/Saturation' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation = -1.0F;
  } else {
    /* Saturate: '<S135>/Saturation' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation = u0;
  }

  /* End of Saturate: '<S135>/Saturation' */

  /* Sum: '<S20>/Sum' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_j = mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[0]
    - mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1;

  /* Product: '<S78>/PProd Out' incorporates:
   *  Constant: '<S20>/Kp'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PProdOut_o =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_j * 4.94871664F;

  /* Logic: '<S20>/Logical Operator' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator_pg = LogicalOperator_c_tmp;

  /* Constant: '<S20>/Ki1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Ki1 = 0.0F;

  /* DiscreteIntegrator: '<S73>/Integrator' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator_pg ||
      (mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_PrevResetState_h != 0)) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE_i = 0.0F;
  }

  /* DiscreteIntegrator: '<S73>/Integrator' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Integrator_e =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE_i;

  /* Sum: '<S82>/Sum' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m =
    mcb_pmsm_foc_dual_cpu2_f28379_B.PProdOut_o +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Integrator_e;

  /* Saturate: '<S80>/Saturation' */
  u0 = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m;
  if (u0 > 1.0F) {
    /* Saturate: '<S80>/Saturation' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h = 1.0F;
  } else if (u0 < -1.0F) {
    /* Saturate: '<S80>/Saturation' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h = -1.0F;
  } else {
    /* Saturate: '<S80>/Saturation' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h = u0;
  }

  /* End of Saturate: '<S80>/Saturation' */

  /* Switch: '<S24>/Switch' incorporates:
   *  Constant: '<S24>/Constant3'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_d = 0.95F;

  /* Product: '<S24>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_f = 0.9025F;

  /* Product: '<S25>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_iz =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h;

  /* Product: '<S25>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_n =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation;

  /* Sum: '<S25>/Sum1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_b =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_iz +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_n;

  /* Outputs for IfAction SubSystem: '<S19>/D-Q Equivalence' incorporates:
   *  ActionPort: '<S22>/Action Port'
   */
  /* If: '<S19>/If' incorporates:
   *  DataTypeConversion: '<S22>/Data Type Conversion'
   *  RelationalOperator: '<S22>/Relational Operator'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.RelationalOperator_k =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_b > 0.9025F);
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_k =
    mcb_pmsm_foc_dual_cpu2_f28379_B.RelationalOperator_k;

  /* If: '<S22>/If' incorporates:
   *  If: '<S19>/If'
   */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_k != 0U) {
    /* Outputs for IfAction SubSystem: '<S22>/Limiter' incorporates:
     *  ActionPort: '<S26>/Action Port'
     */
    /* Product: '<S26>/Product' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_j[0] =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h * 0.95F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_j[1] =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation * 0.95F;

    /* Sqrt: '<S26>/Square Root' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.SquareRoot = (real32_T)sqrt
      (mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_b);

    /* Switch: '<S26>/Switch' */
    if (mcb_pmsm_foc_dual_cpu2_f28379_B.SquareRoot != 0.0F) {
      /* Switch: '<S26>/Switch' */
      mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_ke =
        mcb_pmsm_foc_dual_cpu2_f28379_B.SquareRoot;
    } else {
      /* Switch: '<S26>/Switch' incorporates:
       *  Constant: '<S26>/Constant'
       */
      mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_ke = 1.0F;
    }

    /* End of Switch: '<S26>/Switch' */

    /* Merge: '<S19>/Merge' incorporates:
     *  Product: '<S26>/Divide'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[0] =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Product_j[0] /
      mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_ke;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[1] =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Product_j[1] /
      mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_ke;

    /* End of Outputs for SubSystem: '<S22>/Limiter' */
  } else {
    /* Outputs for IfAction SubSystem: '<S22>/Passthrough' incorporates:
     *  ActionPort: '<S27>/Action Port'
     */
    /* Merge: '<S19>/Merge' incorporates:
     *  SignalConversion generated from: '<S27>/dqRef'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[0] =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[1] =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation;

    /* End of Outputs for SubSystem: '<S22>/Passthrough' */
  }

  /* End of If: '<S22>/If' */
  /* End of Outputs for SubSystem: '<S19>/D-Q Equivalence' */

  /* DeadZone: '<S65>/DeadZone' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m > 1.0F) {
    /* DeadZone: '<S65>/DeadZone' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m - 1.0F;
  } else if (mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m >= -1.0F) {
    /* DeadZone: '<S65>/DeadZone' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone = 0.0F;
  } else {
    /* DeadZone: '<S65>/DeadZone' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m - -1.0F;
  }

  /* End of DeadZone: '<S65>/DeadZone' */

  /* RelationalOperator: '<S63>/Relational Operator' incorporates:
   *  Constant: '<S63>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.RelationalOperator =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone != 0.0F);

  /* RelationalOperator: '<S63>/fix for DT propagation issue' incorporates:
   *  Constant: '<S63>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone > 0.0F);

  /* Switch: '<S63>/Switch1' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue) {
    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S63>/Constant'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_ck = 1;
  } else {
    /* Switch: '<S63>/Switch1' incorporates:
     *  Constant: '<S63>/Constant2'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_ck = -1;
  }

  /* End of Switch: '<S63>/Switch1' */

  /* Product: '<S70>/IProd Out' incorporates:
   *  Constant: '<S20>/Ki'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_j * 0.345765799F;

  /* RelationalOperator: '<S63>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S63>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue1 =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut > 0.0F);

  /* Switch: '<S63>/Switch2' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue1) {
    /* Switch: '<S63>/Switch2' incorporates:
     *  Constant: '<S63>/Constant3'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2_g = 1;
  } else {
    /* Switch: '<S63>/Switch2' incorporates:
     *  Constant: '<S63>/Constant4'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2_g = -1;
  }

  /* End of Switch: '<S63>/Switch2' */

  /* RelationalOperator: '<S63>/Equal1' incorporates:
   *  Switch: '<S63>/Switch1'
   *  Switch: '<S63>/Switch2'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Equal1 =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_ck ==
     mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2_g);

  /* Logic: '<S63>/AND3' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.AND3 =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.RelationalOperator &&
     mcb_pmsm_foc_dual_cpu2_f28379_B.Equal1);

  /* Switch: '<S63>/Switch' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.AND3) {
    /* Switch: '<S63>/Switch' incorporates:
     *  Constant: '<S63>/Constant1'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_f = 0.0F;
  } else {
    /* Switch: '<S63>/Switch' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_f =
      mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut;
  }

  /* End of Switch: '<S63>/Switch' */

  /* DeadZone: '<S120>/DeadZone' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq > 1.0F) {
    /* DeadZone: '<S120>/DeadZone' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone_j =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq - 1.0F;
  } else if (mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq >= -1.0F) {
    /* DeadZone: '<S120>/DeadZone' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone_j = 0.0F;
  } else {
    /* DeadZone: '<S120>/DeadZone' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone_j =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq - -1.0F;
  }

  /* End of DeadZone: '<S120>/DeadZone' */

  /* RelationalOperator: '<S118>/Relational Operator' incorporates:
   *  Constant: '<S118>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.RelationalOperator_j =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone_j != 0.0F);

  /* RelationalOperator: '<S118>/fix for DT propagation issue' incorporates:
   *  Constant: '<S118>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue_p =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone_j > 0.0F);

  /* Switch: '<S118>/Switch1' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue_p) {
    /* Switch: '<S118>/Switch1' incorporates:
     *  Constant: '<S118>/Constant'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_n = 1;
  } else {
    /* Switch: '<S118>/Switch1' incorporates:
     *  Constant: '<S118>/Constant2'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_n = -1;
  }

  /* End of Switch: '<S118>/Switch1' */

  /* Product: '<S125>/IProd Out' incorporates:
   *  Constant: '<S21>/Ki'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut_a =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_g * 0.345765799F;

  /* RelationalOperator: '<S118>/fix for DT propagation issue1' incorporates:
   *  Constant: '<S118>/Clamping_zero'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue1_e =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut_a > 0.0F);

  /* Switch: '<S118>/Switch2' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.fixforDTpropagationissue1_e) {
    /* Switch: '<S118>/Switch2' incorporates:
     *  Constant: '<S118>/Constant3'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2_n = 1;
  } else {
    /* Switch: '<S118>/Switch2' incorporates:
     *  Constant: '<S118>/Constant4'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2_n = -1;
  }

  /* End of Switch: '<S118>/Switch2' */

  /* RelationalOperator: '<S118>/Equal1' incorporates:
   *  Switch: '<S118>/Switch1'
   *  Switch: '<S118>/Switch2'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Equal1_f =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_n ==
     mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2_n);

  /* Logic: '<S118>/AND3' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.AND3_c =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.RelationalOperator_j &&
     mcb_pmsm_foc_dual_cpu2_f28379_B.Equal1_f);

  /* Switch: '<S118>/Switch' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.AND3_c) {
    /* Switch: '<S118>/Switch' incorporates:
     *  Constant: '<S118>/Constant1'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_n = 0.0F;
  } else {
    /* Switch: '<S118>/Switch' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_n =
      mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut_a;
  }

  /* End of Switch: '<S118>/Switch' */

  /* Outputs for Atomic SubSystem: '<S13>/Two inputs CRL' */
  /* Product: '<S146>/qcos' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.qcos =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[1] *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6_o;

  /* Product: '<S146>/dsin' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.dsin =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[0] *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_l;

  /* Sum: '<S146>/sum_beta' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.sum_beta =
    mcb_pmsm_foc_dual_cpu2_f28379_B.qcos + mcb_pmsm_foc_dual_cpu2_f28379_B.dsin;

  /* Product: '<S146>/dcos' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.dcos =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[0] *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6_o;

  /* Product: '<S146>/qsin' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.qsin =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[1] *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_l;

  /* Sum: '<S146>/sum_alpha' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.sum_alpha =
    mcb_pmsm_foc_dual_cpu2_f28379_B.dcos - mcb_pmsm_foc_dual_cpu2_f28379_B.qsin;

  /* Switch: '<S147>/Switch' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_p[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_alpha;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_p[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_beta;

  /* AlgorithmDescriptorDelegate generated from: '<S146>/a16' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_p[0];

  /* AlgorithmDescriptorDelegate generated from: '<S146>/a16' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_j =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_p[1];

  /* End of Outputs for SubSystem: '<S13>/Two inputs CRL' */

  /* Gain: '<S164>/one_by_two' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two = 0.5F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a;

  /* Gain: '<S164>/sqrt3_by_two' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.sqrt3_by_two = 0.866025388F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_j;

  /* Sum: '<S164>/add_b' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.add_b =
    mcb_pmsm_foc_dual_cpu2_f28379_B.sqrt3_by_two -
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two;

  /* Sum: '<S164>/add_c' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.add_c = (0.0F -
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two) -
    mcb_pmsm_foc_dual_cpu2_f28379_B.sqrt3_by_two;

  /* MinMax: '<S161>/Max' incorporates:
   *  MinMax: '<S161>/Min'
   */
  u0 = mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a;
  Bias = mcb_pmsm_foc_dual_cpu2_f28379_B.add_b;
  LogicalOperator_c_tmp = rtIsNaNF(Bias);
  if ((u0 >= Bias) || LogicalOperator_c_tmp) {
    Bias = u0;
  }

  u0 = mcb_pmsm_foc_dual_cpu2_f28379_B.add_c;
  tmp = rtIsNaNF(u0);
  if ((!(Bias >= u0)) && (!tmp)) {
    Bias = u0;
  }

  /* MinMax: '<S161>/Max' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Max = Bias;

  /* MinMax: '<S161>/Min' */
  u0 = mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a;
  Bias = mcb_pmsm_foc_dual_cpu2_f28379_B.add_b;
  if ((u0 <= Bias) || LogicalOperator_c_tmp) {
    Bias = u0;
  }

  u0 = mcb_pmsm_foc_dual_cpu2_f28379_B.add_c;
  if ((!(Bias <= u0)) && (!tmp)) {
    Bias = u0;
  }

  /* MinMax: '<S161>/Min' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Min = Bias;

  /* Sum: '<S161>/Add' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add_o = mcb_pmsm_foc_dual_cpu2_f28379_B.Max +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Min;

  /* Gain: '<S161>/one_by_two' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two_n = -0.5F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add_o;

  /* Sum: '<S160>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_e = mcb_pmsm_foc_dual_cpu2_f28379_B.add_b
    + mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two_n;

  /* Sum: '<S160>/Add2' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add2 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two_n +
    mcb_pmsm_foc_dual_cpu2_f28379_B.add_c;

  /* Sum: '<S160>/Add3' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add3 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a +
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two_n;

  /* Gain: '<S160>/Gain' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[0] = 1.15470052F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add3;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[1] = 1.15470052F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_e;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[2] = 1.15470052F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add2;

  /* Gain: '<S10>/One_by_Two' */
  Bias = 0.5F * mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[0];
  mcb_pmsm_foc_dual_cpu2_f28379_B.One_by_Two[0] = Bias;

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[0] = Bias + 0.5F;

  /* Gain: '<S10>/One_by_Two' */
  Bias = 0.5F * mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[1];
  mcb_pmsm_foc_dual_cpu2_f28379_B.One_by_Two[1] = Bias;

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[1] = Bias + 0.5F;

  /* Gain: '<S10>/One_by_Two' */
  Bias = 0.5F * mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[2];
  mcb_pmsm_foc_dual_cpu2_f28379_B.One_by_Two[2] = Bias;

  /* Sum: '<S10>/Sum' incorporates:
   *  Constant: '<S10>/Constant'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[2] = Bias + 0.5F;

  /* DataStoreRead: '<S10>/Enable' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Enable =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Enable;

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Enable;

  /* Update for DiscreteIntegrator: '<S128>/Integrator' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE +=
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_n;
  Integrator_PrevResetState_tmp = (int16_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator_c;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_PrevResetState =
    Integrator_PrevResetState_tmp;

  /* Update for DiscreteIntegrator: '<S73>/Integrator' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE_i +=
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_f;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_PrevResetState_h =
    Integrator_PrevResetState_tmp;
}

/* System initialize for atomic system: '<Root>/Inverter Driver Peripherals' */
void InverterDriverPeripher_Init(void)
{
  uint32_T dataTypeVarLoc;
  uint16_T dataTypeSize;

  /* Start for S-Function (c280xgpio_do): '<S175>/Digital Output' */
  {
    Uint32 *pulMsgRam = (void *)CPU01_TO_CPU02_PASSMSG;
    Uint32 ulRWord32 = 0;
    Uint32 gpioData = 0x00010000;
    gpioData = gpioData|26;

#ifndef GPIO26UsedByCLA

    {
      IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
      while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
              IPC_FLAG31) != STATUS_PASS) {
      }
    }

#else

    //Removes the warning if the variable is unused.
    (void)pulMsgRam;
    (void)ulRWord32;

#endif

  }

  /* Start for S-Function (c2802xpwm): '<S175>/ePWM4' */
  real32_T tbprdValue4 = (real32_T)EPwm4Regs.TBPRD;

  /*** Initialize ePWM4 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm4Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 5001U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm4Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm4Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm4Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm4Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm4Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3U;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S175>/ePWM5' */
  real32_T tbprdValue5 = (real32_T)EPwm5Regs.TBPRD;

  /*** Initialize ePWM5 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm5Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm5Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm5Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm5Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm5Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm5Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm5Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm5Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm5Regs.TBCTL.all = (EPwm5Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm5Regs.TBCTL2.all = (EPwm5Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm5Regs.TBPRD = 5001U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm5Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm5Regs.TBPHS.all = (EPwm5Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm5Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm5Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm5Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm5Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm5Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm5Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm5Regs.CMPCTL.all = (EPwm5Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm5Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm5Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm5Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm5Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm5Regs.CMPCTL2.all = (EPwm5Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm5Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm5Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm5Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm5Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm5Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm5Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm5Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm5Regs.AQSFRC.all = (EPwm5Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm5Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm5Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm5Regs.AQCSFRC.all = (EPwm5Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm5Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm5Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm5Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm5Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm5Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm5Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm5Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm5Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm5Regs.DBCTL.all = (EPwm5Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm5Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm5Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm5Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm5Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm5Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM5SOC Period Select
       EPwm5Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm5Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm5Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm5Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM5SOCB Period Select
       EPwm5Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm5Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM5INTn Enable
       EPwm5Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm5Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm5Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM5INTn Period Select
       EPwm5Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm5Regs.ETSEL.all = (EPwm5Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm5Regs.ETPS.all = (EPwm5Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm5Regs.ETSOCPS.all = (EPwm5Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm5Regs.ETINTPS.all = (EPwm5Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm5Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm5Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm5Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm5Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm5Regs.PCCTL.all = (EPwm5Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm5Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm5Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM5A
       EPwm5Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM5B
       EPwm5Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM5A action on DCAEVT1
       EPwm5Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM5A action on DCAEVT2
       EPwm5Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM5B action on DCBEVT1
       EPwm5Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM5B action on DCBEVT2
     */
    EPwm5Regs.TZCTL.all = (EPwm5Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm5Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm5Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm5Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm5Regs.TZEINT.all = (EPwm5Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm5Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm5Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm5Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm5Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm5Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm5Regs.DCACTL.all = (EPwm5Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm5Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm5Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm5Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm5Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm5Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm5Regs.DCBCTL.all = (EPwm5Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm5Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm5Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm5Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm5Regs.DCTRIPSEL.all = (EPwm5Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm5Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm5Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm5Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm5Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm5Regs.TZDCSEL.all = (EPwm5Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm5Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm5Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm5Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm5Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm5Regs.DCFCTL.all = (EPwm5Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm5Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm5Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm5Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm5Regs.DCCAPCTL.all = (EPwm5Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm5Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm5Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm5Regs.HRCNFG.all = (EPwm5Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm5Regs.EPWMXLINK.bit.TBPRDLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPALINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPBLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPCLINK = 4U;
    EPwm5Regs.EPWMXLINK.bit.CMPDLINK = 4U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm5Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm5Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm5Regs.HRPCTL.all = (EPwm5Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S175>/ePWM6' */
  real32_T tbprdValue6 = (real32_T)EPwm6Regs.TBPRD;

  /*** Initialize ePWM6 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm6Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm6Regs.TBCTL.bit.SYNCOSEL             = 3U;          -- Sync Output Select
       EPwm6Regs.TBCTL2.bit.SYNCOSELX           = 0U;          -- Sync Output Select - additional options

       EPwm6Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm6Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm6Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm6Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm6Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm6Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm6Regs.TBCTL.all = (EPwm6Regs.TBCTL.all & ~0x3FFFU) | 0x2036U;
    EPwm6Regs.TBCTL2.all = (EPwm6Regs.TBCTL2.all & ~0xF000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm6Regs.TBPRD = 5001U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm6Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm6Regs.TBPHS.all = (EPwm6Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm6Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm6Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm6Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm6Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm6Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm6Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm6Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm6Regs.CMPCTL.all = (EPwm6Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm6Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm6Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm6Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm6Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm6Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm6Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm6Regs.CMPCTL2.all = (EPwm6Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm6Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm6Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm6Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm6Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm6Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm6Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm6Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm6Regs.AQSFRC.all = (EPwm6Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm6Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm6Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm6Regs.AQCSFRC.all = (EPwm6Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm6Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm6Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm6Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm6Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm6Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm6Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm6Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm6Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm6Regs.DBCTL.all = (EPwm6Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm6Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm6Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm6Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm6Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm6Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm6Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM6SOC Period Select
       EPwm6Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm6Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm6Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm6Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm6Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM6SOCB Period Select
       EPwm6Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm6Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM6INTn Enable
       EPwm6Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm6Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm6Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM6INTn Period Select
       EPwm6Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm6Regs.ETSEL.all = (EPwm6Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm6Regs.ETPS.all = (EPwm6Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm6Regs.ETSOCPS.all = (EPwm6Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm6Regs.ETINTPS.all = (EPwm6Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm6Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm6Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm6Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm6Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm6Regs.PCCTL.all = (EPwm6Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm6Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm6Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM6A
       EPwm6Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM6B
       EPwm6Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM6A action on DCAEVT1
       EPwm6Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM6A action on DCAEVT2
       EPwm6Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM6B action on DCBEVT1
       EPwm6Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM6B action on DCBEVT2
     */
    EPwm6Regs.TZCTL.all = (EPwm6Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm6Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm6Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm6Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm6Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm6Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm6Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm6Regs.TZEINT.all = (EPwm6Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm6Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm6Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm6Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm6Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm6Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm6Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm6Regs.DCACTL.all = (EPwm6Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm6Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm6Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm6Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm6Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm6Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm6Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm6Regs.DCBCTL.all = (EPwm6Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm6Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm6Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm6Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm6Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm6Regs.DCTRIPSEL.all = (EPwm6Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm6Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm6Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm6Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm6Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm6Regs.TZDCSEL.all = (EPwm6Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm6Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm6Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm6Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm6Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm6Regs.DCFCTL.all = (EPwm6Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm6Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm6Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm6Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm6Regs.DCCAPCTL.all = (EPwm6Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm6Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm6Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm6Regs.HRCNFG.all = (EPwm6Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm6Regs.EPWMXLINK.bit.TBPRDLINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPALINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPBLINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPCLINK = 5U;
    EPwm6Regs.EPWMXLINK.bit.CMPDLINK = 5U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm6Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm6Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm6Regs.HRPCTL.all = (EPwm6Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for MATLABSystem: '<S181>/IPC Write' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.Overwritten = 0ULL;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.NumBufUsed = 0U;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.matlabCodegenIsDeleted = false;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.objisempty_p = true;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.isInitialized = 1L;
  dataTypeSize = sizeof(dataTypeVarLoc);
  if (dataTypeSize > 32767U) {
    dataTypeSize = MAX_uint16_T;
  } else {
    dataTypeSize <<= 1U;
  }

  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams.NumOfBuffers = 4.0;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams.ChNum = 2.0;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams.BufferSize = 1.0;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams.DataTypeInBytes = dataTypeSize;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams.IsIntEnabled = 0.0;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams.IPCBetween = 0.0;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcHandle = MW_IPC_Init
    (&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcParams);
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.isSetupComplete = true;

  /* End of Start for MATLABSystem: '<S181>/IPC Write' */
}

/* Output and update for atomic system: '<Root>/Inverter Driver Peripherals' */
#pragma CODE_SECTION (m_InverterDriverPeripherals, "ramfuncs")

void m_InverterDriverPeripherals(void)
{
  MW_IPC_Diag_T diagDataOut;
  uint64_T q0;
  uint64_T qY;
  uint16_T Scale_to_PWM_Counter_PRD;

  /* DataStoreRead: '<S5>/Data Store Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead_c =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.SignalSelect2;

  /* Product: '<S183>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.id_Ld_Lq =
    mcb_pmsm_foc_dual_cpu2_f_ConstB.Ld_Lq *
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1;

  /* Sum: '<S183>/Add' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add = mcb_pmsm_foc_dual_cpu2_f28379_B.id_Ld_Lq
    + mcb_pmsm_foc_dual_cpu2_f_ConstB.Switch2;

  /* Product: '<S183>/Product3' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product3_g =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add *
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2;

  /* Gain: '<S183>/1_5_Pp' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.u_5_Pp = 6.0F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product3_g;

  /* MultiPortSwitch: '<S174>/Index Vector' */
  switch (mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead_c) {
   case 0:
    /* MultiPortSwitch: '<S174>/Index Vector' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Ia;
    break;

   case 1:
    /* MultiPortSwitch: '<S174>/Index Vector' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[0];
    break;

   case 2:
    /* MultiPortSwitch: '<S174>/Index Vector' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Speed_fb;
    break;

   case 3:
    /* MultiPortSwitch: '<S174>/Index Vector' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu2_f28379_B.pos;
    break;

   case 4:
    /* MultiPortSwitch: '<S174>/Index Vector' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu2_f28379_B.u_5_Pp;
    break;

   default:
    /* Product: '<S183>/Product' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_m =
      mcb_pmsm_foc_dual_cpu2_f28379_B.u_5_Pp *
      mcb_pmsm_foc_dual_cpu2_f28379_B.Speed_fb;

    /* Gain: '<S183>/P_si2pu' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.P_output = 0.601666689F *
      mcb_pmsm_foc_dual_cpu2_f28379_B.Product_m;

    /* MultiPortSwitch: '<S174>/Index Vector' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector =
      mcb_pmsm_foc_dual_cpu2_f28379_B.P_output;
    break;
  }

  /* End of MultiPortSwitch: '<S174>/Index Vector' */

  /* S-Function (any2byte_svd): '<S179>/Byte Pack' */

  /* Pack: <S179>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &mcb_pmsm_foc_dual_cpu2_f28379_B.BytePack;

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 1 */
    {
      MW_inputPortWidth = sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector, MW_inputPortWidth);
    }
  }

  /* MATLABSystem: '<S181>/IPC Write' */
  diagDataOut.OverwriteDiag = 0U;
  diagDataOut.NumBuffUsedDiag = 0U;
  MW_IPC_Write(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcHandle, 1.0,
               &mcb_pmsm_foc_dual_cpu2_f28379_B.BytePack, &diagDataOut);

  /* Start for MATLABSystem: '<S181>/IPC Write' */
  q0 = mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.Overwritten;
  qY = q0 + diagDataOut.OverwriteDiag;
  if (qY < q0) {
    qY = MAX_uint64_T;
  }

  /* MATLABSystem: '<S181>/IPC Write' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.Overwritten = qY;
  if (diagDataOut.NumBuffUsedDiag <= 4U) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.NumBufUsed = diagDataOut.NumBuffUsedDiag;
  }

  q0 = mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.Overwritten;
  Scale_to_PWM_Counter_PRD = mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.NumBufUsed;

  /* MATLABSystem: '<S181>/IPC Write' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCChannelNumberofoverwrites = q0;

  /* MATLABSystem: '<S181>/IPC Write' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCChannelNumberofbuffersused =
    Scale_to_PWM_Counter_PRD;

  /* Switch: '<S175>/Switch' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_m =
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion;

  /* S-Function (c280xgpio_do): '<S175>/Digital Output' */
  {
    if (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_m) {
      GpioDataRegs.GPASET.bit.GPIO26 = 1U;
    } else {
      GpioDataRegs.GPACLEAR.bit.GPIO26 = 1U;
    }
  }

  /* Switch: '<S175>/Switch1' */
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion >= 0.5F) {
    /* Gain: '<S175>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F *
      mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[0]);
    mcb_pmsm_foc_dual_cpu2_f28379_B.Scale_to_PWM_Counter_PRD[0] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S175>/Switch1' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[0] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S175>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F *
      mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[1]);
    mcb_pmsm_foc_dual_cpu2_f28379_B.Scale_to_PWM_Counter_PRD[1] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S175>/Switch1' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[1] = Scale_to_PWM_Counter_PRD;

    /* Gain: '<S175>/Scale_to_PWM_Counter_PRD' */
    Scale_to_PWM_Counter_PRD = (uint16_T)(5000.0F *
      mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[2]);
    mcb_pmsm_foc_dual_cpu2_f28379_B.Scale_to_PWM_Counter_PRD[2] =
      Scale_to_PWM_Counter_PRD;

    /* Switch: '<S175>/Switch1' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[2] = Scale_to_PWM_Counter_PRD;
  } else {
    /* Switch: '<S175>/Switch1' incorporates:
     *  Constant: '<S175>/stop'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[0] = 0U;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[1] = 0U;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[2] = 0U;
  }

  /* End of Switch: '<S175>/Switch1' */

  /* S-Function (c2802xpwm): '<S175>/ePWM4' */
  uint16_T tbprdValue4Outputs = EPwm4Regs.TBPRD;

  /*-- Update CMPA value for ePWM4 --*/
  {
    EPwm4Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[0]);
  }

  /* S-Function (c2802xpwm): '<S175>/ePWM5' */
  uint16_T tbprdValue5Outputs = EPwm5Regs.TBPRD;

  /*-- Update CMPA value for ePWM5 --*/
  {
    EPwm5Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[1]);
  }

  /* S-Function (c2802xpwm): '<S175>/ePWM6' */
  uint16_T tbprdValue6Outputs = EPwm6Regs.TBPRD;

  /*-- Update CMPA value for ePWM6 --*/
  {
    EPwm6Regs.CMPA.bit.CMPA = (uint16_T)
      (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_cy[2]);
  }
}

/* Termination for atomic system: '<Root>/Inverter Driver Peripherals' */
void InverterDriverPeripher_Term(void)
{
  /* Terminate for MATLABSystem: '<S181>/IPC Write' */
  if (!mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu2_f2_DWork.obj.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S181>/IPC Write' */
}

/* System initialize for atomic system: '<Root>/Sensorless Algorithm' */
void mc_SensorlessAlgorithm_Init(void)
{
  /* SystemInitialize for IfAction SubSystem: '<S200>/Flux Observer' */
  /* InitializeConditions for Delay: '<S234>/Delay1' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S234>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S226>/Delay1' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_k = 0.0F;

  /* InitializeConditions for Delay: '<S226>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_f = 0.0F;

  /* InitializeConditions for Delay: '<S208>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx = 0U;

  /* End of SystemInitialize for SubSystem: '<S200>/Flux Observer' */

  /* SystemInitialize for IfAction SubSystem: '<S200>/Sliding Mode Observer' */
  /* InitializeConditions for Delay: '<S246>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_d = 0.0F;

  /* InitializeConditions for Delay: '<S256>/Delay1' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_b = 0.0F;

  /* InitializeConditions for Delay: '<S247>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_h = 0.0F;

  /* InitializeConditions for Delay: '<S257>/Delay1' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_o = 0.0F;

  /* InitializeConditions for Delay: '<S244>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_b = 0.0F;

  /* InitializeConditions for Delay: '<S251>/Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx_a = 0U;

  /* End of SystemInitialize for SubSystem: '<S200>/Sliding Mode Observer' */

  /* SystemInitialize for Merge: '<S200>/Merge' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[1] = 0.0F;
}

/* Output and update for atomic system: '<Root>/Sensorless Algorithm' */
#pragma CODE_SECTION (mcb_pms_SensorlessAlgorithm, "ramfuncs")

void mcb_pms_SensorlessAlgorithm(void)
{
  real32_T GetADCVoltage;
  real32_T Product_g;
  real32_T UnitDelay_c;
  ZCSigState Delay1_Reset_ZCE_tmp;
  boolean_T zcEvent;

  /* DataStoreRead: '<S199>/Data Store Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.IaOffset;

  /* DataStoreRead: '<S199>/Data Store Read1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead1 =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.IbOffset;

  /* DataTypeConversion: '<S199>/Data Type Conversion' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_m[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy_p;
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_m[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy1_l;

  /* Sum: '<S199>/Add' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add_k[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_m[0] -
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add_k[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion_m[1] -
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead1;

  /* Gain: '<S202>/Get ADC Voltage' */
  GetADCVoltage = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add_k[0];
  mcb_pmsm_foc_dual_cpu2_f28379_B.GetADCVoltage[0] = GetADCVoltage;

  /* Gain: '<S202>/Get Currents' */
  GetADCVoltage *= 14.2857141F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.GetCurrents[0] = GetADCVoltage;

  /* Gain: '<S202>/PU_Conversion' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[0] = 0.0466666669F *
    GetADCVoltage;

  /* Gain: '<S202>/Get ADC Voltage' */
  GetADCVoltage = 0.000732600747F * (real32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add_k[1];
  mcb_pmsm_foc_dual_cpu2_f28379_B.GetADCVoltage[1] = GetADCVoltage;

  /* Gain: '<S202>/Get Currents' */
  GetADCVoltage *= 14.2857141F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.GetCurrents[1] = GetADCVoltage;

  /* Gain: '<S202>/PU_Conversion' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[1] = 0.0466666669F *
    GetADCVoltage;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Constant: '<S209>/FilterConstant'
   *  Constant: '<S209>/OneMinusFilterConstant'
   *  Product: '<S212>/Product'
   *  Switch: '<S209>/Switch1'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_k[0] = 0.005F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_k[1] = 0.995F;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[0];
  Product_g = GetADCVoltage * 0.005F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[0] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  UnitDelay: '<S212>/Unit Delay'
   */
  UnitDelay_c = mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[0];

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* UnitDelay: '<S212>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[0] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product1'
   */
  UnitDelay_c *= 0.995F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[0] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Sum: '<S212>/Add1'
   */
  Product_g += UnitDelay_c;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Sum: '<S212>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[0] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product'
   *  Sum: '<S205>/Sum6'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[0] = GetADCVoltage - Product_g;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[1];
  Product_g = GetADCVoltage * 0.005F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[1] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  UnitDelay: '<S212>/Unit Delay'
   */
  UnitDelay_c = mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[1];

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* UnitDelay: '<S212>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[1] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product1'
   */
  UnitDelay_c *= 0.995F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[1] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Sum: '<S212>/Add1'
   */
  Product_g += UnitDelay_c;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Sum: '<S212>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[1] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product'
   *  Sum: '<S205>/Sum6'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[1] = GetADCVoltage - Product_g;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[2];
  Product_g = GetADCVoltage * 0.005F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[2] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  UnitDelay: '<S212>/Unit Delay'
   */
  UnitDelay_c = mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[2];

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* UnitDelay: '<S212>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[2] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product1'
   */
  UnitDelay_c *= 0.995F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[2] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Sum: '<S212>/Add1'
   */
  Product_g += UnitDelay_c;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Sum: '<S212>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[2] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product'
   *  Sum: '<S205>/Sum6'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[2] = GetADCVoltage - Product_g;
  GetADCVoltage = mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[3];
  Product_g = GetADCVoltage * 0.005F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[3] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  UnitDelay: '<S212>/Unit Delay'
   */
  UnitDelay_c = mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[3];

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* UnitDelay: '<S212>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[3] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Product: '<S212>/Product1'
   */
  UnitDelay_c *= 0.995F;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Product: '<S212>/Product1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[3] = UnitDelay_c;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  Sum: '<S212>/Add1'
   */
  Product_g += UnitDelay_c;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */

  /* Sum: '<S212>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[3] = Product_g;

  /* Outputs for IfAction SubSystem: '<S200>/Flux Observer' incorporates:
   *  ActionPort: '<S203>/Action Port'
   */
  /* SwitchCase: '<S200>/Switch Case' incorporates:
   *  AlgorithmDescriptorDelegate generated from: '<S221>/a16'
   *  Constant: '<S207>/FilterConstant'
   *  Constant: '<S207>/OneMinusFilterConstant'
   *  Constant: '<S216>/p1'
   *  Constant: '<S216>/p2'
   *  Constant: '<S216>/p3'
   *  Constant: '<S216>/p4'
   *  Constant: '<S216>/p5'
   *  Constant: '<S225>/One'
   *  Constant: '<S233>/One'
   *  DataStoreRead: '<S203>/Data Store Read1'
   *  DataTypeConversion: '<S243>/DTC'
   *  Delay: '<S208>/Delay'
   *  Delay: '<S226>/Delay'
   *  Delay: '<S226>/Delay1'
   *  Delay: '<S234>/Delay'
   *  Delay: '<S234>/Delay1'
   *  Gain: '<S203>/elect2mech'
   *  Gain: '<S208>/PositionToCount'
   *  Gain: '<S208>/SpeedGain'
   *  Gain: '<S222>/Gain'
   *  Logic: '<S203>/Logical Operator'
   *  Product: '<S226>/Product'
   *  Product: '<S226>/Product1'
   *  Product: '<S227>/Product'
   *  Product: '<S227>/Product2'
   *  Product: '<S230>/Product'
   *  Product: '<S230>/Product1'
   *  Product: '<S234>/Product'
   *  Product: '<S234>/Product1'
   *  Product: '<S235>/Product'
   *  Product: '<S235>/Product2'
   *  Product: '<S238>/Product'
   *  Product: '<S238>/Product1'
   *  Product: '<S241>/Product'
   *  Product: '<S241>/Product1'
   *  SignalConversion generated from: '<S203>/Position//Speed'
   *  Sum: '<S205>/Sum6'
   *  Sum: '<S208>/SpeedCount'
   *  Sum: '<S224>/Sum1'
   *  Sum: '<S224>/Sum3'
   *  Sum: '<S225>/Sum'
   *  Sum: '<S226>/Sum'
   *  Sum: '<S226>/Sum1'
   *  Sum: '<S230>/Add1'
   *  Sum: '<S232>/Sum1'
   *  Sum: '<S232>/Sum3'
   *  Sum: '<S233>/Sum'
   *  Sum: '<S234>/Sum'
   *  Sum: '<S234>/Sum1'
   *  Sum: '<S238>/Add1'
   *  Sum: '<S241>/Add1'
   *  Switch: '<S207>/Switch1'
   *  Switch: '<S221>/Switch'
   *  Switch: '<S222>/Switch'
   *  Switch: '<S223>/Switch'
   *  Switch: '<S225>/Switch1'
   *  Switch: '<S231>/Switch'
   *  Switch: '<S233>/Switch1'
   *  Trigonometry: '<S221>/Atan2'
   *  UnitDelay: '<S212>/Unit Delay'
   *  UnitDelay: '<S230>/Unit Delay'
   *  UnitDelay: '<S238>/Unit Delay'
   *  UnitDelay: '<S241>/Unit Delay'
   * */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[3] = GetADCVoltage - Product_g;
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead1_m =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Enable;
  mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator =
    !mcb_pmsm_foc_dual_cpu2_f28379_B.DataStoreRead1_m;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_o =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[3] * 1.37636185F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3 = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[1]
    - mcb_pmsm_foc_dual_cpu2_f28379_B.Product_o;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE == POS_ZCSIG) !=
              (int16_T)mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE = 0.0F;
  }

  Delay1_Reset_ZCE_tmp = mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator;
  mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE = Delay1_Reset_ZCE_tmp;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1 =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_i = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3 +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_oh =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_i * 2.49998757E-5F;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE == POS_ZCSIG) !=
              (int16_T)mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE = Delay1_Reset_ZCE_tmp;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_o =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_c =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_o * 0.99999F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_oh +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_c;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product2 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[3] * 0.000989743276F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_m = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1
    - mcb_pmsm_foc_dual_cpu2_f28379_B.Product2;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_h = 0.999F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_a[0] = 0.0010000047F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_a[1] = 0.999F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_c =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_m * 0.0010000047F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_i =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_l;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_p = 0.999F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_i;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_a =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_c +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_p;
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) {
    /* Switch: '<S231>/Switch' incorporates:
     *  Constant: '<S231>/Constant'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch = 0.0F;
  } else {
    /* Sum: '<S237>/Sum' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_n =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_m -
      mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_a;

    /* Switch: '<S231>/Switch' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_n;
  }

  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_d =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[2] * 1.37636185F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_a = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6
    [0] - mcb_pmsm_foc_dual_cpu2_f28379_B.Product_d;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_i == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_i !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_k = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_i = Delay1_Reset_ZCE_tmp;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1_o =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_k;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_b = mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_a
    + mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1_o;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_h =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_b * 2.49998757E-5F;
  zcEvent = (((mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_k == POS_ZCSIG)
              != (int16_T)mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) &&
             (mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_k !=
              UNINITIALIZED_ZCSIG));
  if (zcEvent || mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_f = 0.0F;
  }

  mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_k = Delay1_Reset_ZCE_tmp;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_f =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_f;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_h =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_f * 0.99999F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_p =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_h +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_h;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product2_a =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[2] * 0.000989743276F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_l =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_p -
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product2_a;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_l = 0.999F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_m[0] = 0.0010000047F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_m[1] = 0.999F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_i =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_l * 0.0010000047F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_b =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_d;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_f = 0.999F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_b;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_c =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_i +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_f;
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.LogicalOperator) {
    /* Switch: '<S223>/Switch' incorporates:
     *  Constant: '<S223>/Constant'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_g = 1.0E-6F;
  } else {
    /* Sum: '<S229>/Sum' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_f =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_l -
      mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_c;

    /* Switch: '<S223>/Switch' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_g =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_f;
  }

  /* Outputs for Atomic SubSystem: '<S220>/atan2' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Atan2 = atan2f
    (mcb_pmsm_foc_dual_cpu2_f28379_B.Switch,
     mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_g);

  /* Outputs for Atomic SubSystem: '<S221>/Per Unit' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Gain = 0.159154937F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Atan2;
  if (mcb_pmsm_foc_dual_cpu2_f28379_B.Gain >= 0.0F) {
    /* Switch: '<S222>/Switch' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_e =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Gain;
  } else {
    /* Bias: '<S222>/Bias' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Bias = mcb_pmsm_foc_dual_cpu2_f28379_B.Gain
      + 1.0F;

    /* Switch: '<S222>/Switch' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_e =
      mcb_pmsm_foc_dual_cpu2_f28379_B.Bias;
  }

  /* End of Outputs for SubSystem: '<S221>/Per Unit' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_l =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_e;
  mcb_pmsm_foc_dual_cpu2_f28379_B.algDD =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_l;

  /* End of Outputs for SubSystem: '<S220>/atan2' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.PositionToCount = (uint32_T)(4.2949673E+9F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD);
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_e[mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx];
  mcb_pmsm_foc_dual_cpu2_f28379_B.SpeedCount = (int32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.PositionToCount - (int32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay;
  mcb_pmsm_foc_dual_cpu2_f28379_B.DTC = (real32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.SpeedCount;
  mcb_pmsm_foc_dual_cpu2_f28379_B.SpeedGain = 7.7395228E-9F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.DTC;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_f[0] = 0.01F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_f[1] = 0.99F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product_cl =
    mcb_pmsm_foc_dual_cpu2_f28379_B.SpeedGain * 0.01F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_i1 =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_c;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_o = 0.99F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_i1;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_j =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_cl +
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_o;
  mcb_pmsm_foc_dual_cpu2_f28379_B.elect2mech = 0.25F *
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_j;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.elect2mech;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[0];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[1];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[2] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[2];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[3] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[3];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_l =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_a;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_k =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_a;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_f =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_p;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_d =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_c;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_e[mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx]
    = mcb_pmsm_foc_dual_cpu2_f28379_B.PositionToCount;
  if (mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx < 9U) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx++;
  } else {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.CircBufIdx = 0U;
  }

  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_c =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_j;

  /* End of Outputs for SubSystem: '<S200>/Flux Observer' */
}

static void mcb_pmsm_fo_SystemCore_setup_kc(soc_blocks_IPCRead_mcb_pmsm_foc *obj)
{
  uint16_T dataTypeVarLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S198>/IPC Read' */
  obj->isInitialized = 1L;
  dataTypeVarLoc = sizeof(dataTypeVarLoc);
  if (dataTypeVarLoc > 32767U) {
    dataTypeVarLoc = MAX_uint16_T;
  } else {
    dataTypeVarLoc <<= 1U;
  }

  /* Start for MATLABSystem: '<S198>/IPC Read' */
  obj->IpcParams.NumOfBuffers = 1.0;
  obj->IpcParams.ChNum = 4.0;
  obj->IpcParams.BufferSize = 1.0;
  obj->IpcParams.DataTypeInBytes = dataTypeVarLoc;
  obj->IpcParams.IsIntEnabled = 0.0;
  obj->IpcParams.IPCBetween = 0.0;
  obj->IpcHandle = MW_IPC_Init(&obj->IpcParams);
  obj->isSetupComplete = true;
}

static void mcb_pmsm_foc_SystemCore_setup_k(soc_blocks_IPCRead_mcb_pmsm_foc *obj)
{
  uint16_T dataTypeVarLoc;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S196>/IPC Read' */
  obj->isInitialized = 1L;
  dataTypeVarLoc = sizeof(dataTypeVarLoc);
  if (dataTypeVarLoc > 32767U) {
    dataTypeVarLoc = MAX_uint16_T;
  } else {
    dataTypeVarLoc <<= 1U;
  }

  /* Start for MATLABSystem: '<S196>/IPC Read' */
  obj->IpcParams.NumOfBuffers = 1.0;
  obj->IpcParams.ChNum = 1.0;
  obj->IpcParams.BufferSize = 1.0;
  obj->IpcParams.DataTypeInBytes = dataTypeVarLoc;
  obj->IpcParams.IsIntEnabled = 0.0;
  obj->IpcParams.IPCBetween = 0.0;
  obj->IpcHandle = MW_IPC_Init(&obj->IpcParams);
  obj->isSetupComplete = true;
}

static void mcb_pmsm_foc_d_SystemCore_setup(soc_blocks_IPCRead_mcb_pmsm_foc *obj)
{
  uint32_T dataTypeVarLoc;
  uint16_T dataTypeSize;
  obj->isSetupComplete = false;

  /* Start for MATLABSystem: '<S194>/IPC Read' */
  obj->isInitialized = 1L;
  dataTypeSize = sizeof(dataTypeVarLoc);
  if (dataTypeSize > 32767U) {
    dataTypeSize = MAX_uint16_T;
  } else {
    dataTypeSize <<= 1U;
  }

  /* Start for MATLABSystem: '<S194>/IPC Read' */
  obj->IpcParams.NumOfBuffers = 1.0;
  obj->IpcParams.ChNum = 0.0;
  obj->IpcParams.BufferSize = 1.0;
  obj->IpcParams.DataTypeInBytes = dataTypeSize;
  obj->IpcParams.IsIntEnabled = 0.0;
  obj->IpcParams.IPCBetween = 0.0;
  obj->IpcHandle = MW_IPC_Init(&obj->IpcParams);
  obj->isSetupComplete = true;
}

/* Model step function for TID0 */
void mcb_pmsm_foc_dual_cpu2_f28379d_step0(void) /* Sample time: [5.0E-5s, 0.0s] */
{
  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<S6>/Rate Transition' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.RateTransition =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.RateTransition_Buffer0;

  /* Outputs for Atomic SubSystem: '<Root>/Current Sensing' */
  mcb_pmsm_foc_CurrentSensing();

  /* End of Outputs for SubSystem: '<Root>/Current Sensing' */

  /* Delay: '<Root>/Delay5' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[0] =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[0];
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[1] =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[1];
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[2] =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[2];
  mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[3] =
    mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[3];

  /* Outputs for Atomic SubSystem: '<Root>/Sensorless Algorithm' */
  mcb_pms_SensorlessAlgorithm();

  /* End of Outputs for SubSystem: '<Root>/Sensorless Algorithm' */

  /* Outputs for Atomic SubSystem: '<Root>/Foc Algorithm' */
  mcb_pmsm_foc_d_FocAlgorithm();

  /* End of Outputs for SubSystem: '<Root>/Foc Algorithm' */

  /* Outputs for Atomic SubSystem: '<Root>/Inverter Driver Peripherals' */
  m_InverterDriverPeripherals();

  /* End of Outputs for SubSystem: '<Root>/Inverter Driver Peripherals' */

  /* SignalConversion generated from: '<Root>/Delay5' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a;
  mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_j;
  mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[2] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_d;
  mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[3] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_k;

  /* Update for Delay: '<Root>/Delay5' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[0];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[1];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[2] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[2];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[3] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[3];
}

/* Model step function for TID1 */
void mcb_pmsm_foc_dual_cpu2_f28379d_step1(void) /* Sample time: [0.01s, 0.0s] */
{
  real32_T UnitDelay;
  uint32_T b_varargout_1_0;
  int16_T b_varargout_2;
  uint16_T b_varargout_1;

  /* MATLABSystem: '<S198>/IPC Read' */
  b_varargout_2 = 0;
  MW_IPC_Read(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.IpcHandle, 1.0,
              &b_varargout_1, &b_varargout_2);

  /* MATLABSystem: '<S198>/IPC Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o1_f = b_varargout_1;

  /* MATLABSystem: '<S198>/IPC Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o2 = b_varargout_2;

  /* DataTypeConversion: '<S6>/Data Type Conversion2' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion2 =
    (mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o1_f != 0U);

  /* DataStoreWrite: '<S6>/Data Store Write' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Enable =
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion2;

  /* MATLABSystem: '<S196>/IPC Read' */
  b_varargout_2 = 0;
  MW_IPC_Read(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.IpcHandle, 1.0,
              &b_varargout_1, &b_varargout_2);

  /* MATLABSystem: '<S196>/IPC Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o1_i = b_varargout_1;

  /* MATLABSystem: '<S196>/IPC Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o2_l = b_varargout_2;

  /* DataStoreWrite: '<S6>/Data Store Write1' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.SignalSelect2 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o1_i;

  /* MATLABSystem: '<S194>/IPC Read' */
  b_varargout_2 = 0;
  MW_IPC_Read(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.IpcHandle, 1.0,
              &b_varargout_1_0, &b_varargout_2);

  /* MATLABSystem: '<S194>/IPC Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o1 = b_varargout_1_0;

  /* MATLABSystem: '<S194>/IPC Read' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o2_p = b_varargout_2;

  /* DataTypeConversion: '<S185>/Data Type Conversion5' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion5 = (int32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.IPCRead_o1;

  /* DataTypeConversion: '<S185>/Data Type Conversion4' incorporates:
   *  DataTypeConversion: '<S185>/Data Type Conversion5'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion4 = (real32_T)
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion5 * 3.7252903E-9F;

  /* Switch: '<S186>/Switch1' incorporates:
   *  Constant: '<S186>/FilterConstant'
   *  Constant: '<S186>/OneMinusFilterConstant'
   */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1[0] = 0.2F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1[1] = 0.8F;

  /* Product: '<S192>/Product' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion4 * 0.2F;

  /* UnitDelay: '<S192>/Unit Delay' */
  UnitDelay = mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE[0];
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay[0] = UnitDelay;

  /* Product: '<S192>/Product1' */
  UnitDelay *= 0.8F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1[0] = UnitDelay;

  /* Sum: '<S192>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[0] = UnitDelay;

  /* UnitDelay: '<S192>/Unit Delay' */
  UnitDelay = mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE[1];
  mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay[1] = UnitDelay;

  /* Product: '<S192>/Product1' */
  UnitDelay *= 0.8F;
  mcb_pmsm_foc_dual_cpu2_f28379_B.Product1[1] = UnitDelay;

  /* Sum: '<S192>/Add1' */
  mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product[1] + UnitDelay;

  /* RateTransition: '<S6>/Rate Transition' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.RateTransition_Buffer0 =
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion2;

  /* S-Function (c280xgpio_do): '<S7>/Grounding the SPI clockfor the DRV830x' incorporates:
   *  Constant: '<S7>/Constant'
   */
  {
    if ((0U)) {
      GpioDataRegs.GPCSET.bit.GPIO65 = 1U;
    } else {
      GpioDataRegs.GPCCLEAR.bit.GPIO65 = 1U;
    }
  }

  /* Update for UnitDelay: '<S192>/Unit Delay' */
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE[0] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[0];
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE[1] =
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[1];
}

/* Model step function for TID2 */
void mcb_pmsm_foc_dual_cpu2_f28379d_step2(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S4>/Blink Blue LED' incorporates:
   *  Constant: '<S4>/ '
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO31 = (uint16_T)((1U) != 0);
  }

  /* S-Function (c280xgpio_do): '<S4>/Digital Output1' incorporates:
   *  Constant: '<S4>/LED'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO14 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_dual_cpu2_f28379d_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_dual_cpu2_f2837_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_dual_cpu2));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_dual_cpu2_f28379_B), 0,
                sizeof(BlockIO_mcb_pmsm_foc_dual_cpu2_));

  {
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay5[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.TmpSignalConversionAtDelay5Inpo[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion4 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.GetADCVoltage[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.GetADCVoltage[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.GetCurrents[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.GetCurrents[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PU_Conversion[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_k[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_k[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_g[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_c[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_e[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_o[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_oh = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_c = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product2 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_m = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_a[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_a[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_c = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_p = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_p = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product2_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_m[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_m[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_c = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DTC = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.SpeedGain = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_f[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_f[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_cl = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_i1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_j = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.elect2mech = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_n = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Atan2 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_e = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Bias = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.b_invg = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1_m = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_c[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_c[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_o1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_j = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_cy = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay1_e = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_e = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.a_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_f1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.b_invg_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay1_k = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_p = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_g[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_g[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_iw = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_hr = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Delay_ob = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sign = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Eta = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_c = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.a_p = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_m4 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sign_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Eta_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_p = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.b_k = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.a_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DTC_n = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.SpeedGain_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_j[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_j[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_k = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.UnitDelay_m = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_on = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_ow = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_n = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product2_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_eh = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product3 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_lg = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Atan2_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_e = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_k = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Bias_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Bias_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.id_Ld_Lq = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product3_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.u_5_Pp = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.IndexVector = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_m = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_m = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.P_output = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Ia = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.pos = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Speed_fb = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.indexing = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Lookup[3] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum3_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum2_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum4_l = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum5 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_k = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum6_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_g = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PProdOut = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Kp1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Integrator = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_cq = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_j = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PProdOut_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Ki1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Integrator_e = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_m = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Saturation_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_iz = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product1_n = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_o[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DeadZone_j = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.IProdOut_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_n = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.sqrt3_by_two = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.add_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.add_c = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Max = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Min = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_two_n = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add1_e = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add2 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Add3 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_k[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.One_by_Two[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.One_by_Two[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.One_by_Two[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.PWM_Duty_Cycles[2] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.DataTypeConversion = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_back = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Convert_back_o = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.acos_i = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.bsin = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_Ds = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.bcos = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.asin_p = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_Qs = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_mn[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_mn[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.qcos = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.dsin = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_beta = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.dcos = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.qsin = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.sum_alpha = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_p[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_p[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_a = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_j = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_j[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_j[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.SquareRoot = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_ke = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_o[0] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_o[1] = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch2 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product_ai = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_ik = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Product2_h = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Merge_b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_f = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_of = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch1_kd = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Sqrt = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.Gain_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.a_plus_2b = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.one_by_sqrt3 = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o1_d = 0.0F;
    mcb_pmsm_foc_dual_cpu2_f28379_B.algDD_o2_k = 0.0F;
  }

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_dual_cpu2_f2_DWork, 0,
                sizeof(D_Work_mcb_pmsm_foc_dual_cpu2_f));
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[2] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay5_DSTATE[3] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[0] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[1] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[2] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_b[3] = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_l = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_k = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_f = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_d = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.UnitDelay_DSTATE_c = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_d = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_b = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_h = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay1_DSTATE_o = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Delay_DSTATE_b = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_dual_cpu2_f2_DWork.Integrator_DSTATE_i = 0.0F;

  {
    uint16_T s168_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory5' */
    mcb_pmsm_foc_dual_cpu2_f2_DWork.IaOffset = 2295U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory6' */
    mcb_pmsm_foc_dual_cpu2_f2_DWork.IbOffset = 2286U;

    /* Start for S-Function (c280xgpio_do): '<S7>/Grounding the SPI clockfor the DRV830x' */
    {
      Uint32 *pulMsgRam = (void *)CPU01_TO_CPU02_PASSMSG;
      Uint32 ulRWord32 = 0;
      Uint32 gpioData = 0x00010000;
      gpioData = gpioData|65;

#ifndef GPIO65UsedByCLA

      {
        IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
        while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
                IPC_FLAG31) != STATUS_PASS) {
        }
      }

#else

      //Removes the warning if the variable is unused.
      (void)pulMsgRam;
      (void)ulRWord32;

#endif

    }

    mcb_pmsm_foc_dua_PrevZCSigState.Dir_Sense_Trig_ZCE = POS_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_e = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_l = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_m = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_f = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_a = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay1_Reset_ZCE_i = UNINITIALIZED_ZCSIG;
    mcb_pmsm_foc_dua_PrevZCSigState.Delay_Reset_ZCE_k = UNINITIALIZED_ZCSIG;

    /* SystemInitialize for Atomic SubSystem: '<Root>/Inverter Driver Peripherals' */
    InverterDriverPeripher_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Inverter Driver Peripherals' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Foc Algorithm' */
    mcb_pmsm__FocAlgorithm_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Foc Algorithm' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Sensorless Algorithm' */
    mc_SensorlessAlgorithm_Init();

    /* End of SystemInitialize for SubSystem: '<Root>/Sensorless Algorithm' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S4>/Blink Blue LED' */
    {
      Uint32 *pulMsgRam = (void *)CPU01_TO_CPU02_PASSMSG;
      Uint32 ulRWord32 = 0;
      Uint32 gpioData = 0x00010000;
      gpioData = gpioData|31;

#ifndef GPIO31UsedByCLA

      {
        IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
        while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
                IPC_FLAG31) != STATUS_PASS) {
        }
      }

#else

      //Removes the warning if the variable is unused.
      (void)pulMsgRam;
      (void)ulRWord32;

#endif

    }

    /* Start for S-Function (c280xgpio_do): '<S4>/Digital Output1' */
    {
      Uint32 *pulMsgRam = (void *)CPU01_TO_CPU02_PASSMSG;
      Uint32 ulRWord32 = 0;
      Uint32 gpioData = 0x00010000;
      gpioData = gpioData|14;

#ifndef GPIO14UsedByCLA

      {
        IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
        while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
                IPC_FLAG31) != STATUS_PASS) {
        }
      }

#else

      //Removes the warning if the variable is unused.
      (void)pulMsgRam;
      (void)ulRWord32;

#endif

    }

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S166>/Digital Output2' */
    {
      Uint32 *pulMsgRam = (void *)CPU01_TO_CPU02_PASSMSG;
      Uint32 ulRWord32 = 0;
      Uint32 gpioData = 0x00010000;
      gpioData = gpioData|26;

#ifndef GPIO26UsedByCLA

      {
        IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
        while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
                IPC_FLAG31) != STATUS_PASS) {
        }
      }

#else

      //Removes the warning if the variable is unused.
      (void)pulMsgRam;
      (void)ulRWord32;

#endif

    }

    /* Start for MATLABSystem: '<S198>/IPC Read' */
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.isInitialized = 0L;
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.matlabCodegenIsDeleted = false;
    mcb_pmsm_foc_dual_cpu2_f2_DWork.objisempty = true;
    mcb_pmsm_fo_SystemCore_setup_kc(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i);

    /* Start for MATLABSystem: '<S196>/IPC Read' */
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.isInitialized = 0L;
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.matlabCodegenIsDeleted = false;
    mcb_pmsm_foc_dual_cpu2_f2_DWork.objisempty_l = true;
    mcb_pmsm_foc_SystemCore_setup_k(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c);

    /* Start for MATLABSystem: '<S194>/IPC Read' */
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.isInitialized = 0L;
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.matlabCodegenIsDeleted = false;
    mcb_pmsm_foc_dual_cpu2_f2_DWork.objisempty_e = true;
    mcb_pmsm_foc_d_SystemCore_setup(&mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p);

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Switch: '<S166>/Switch' incorporates:
     *  Constant: '<S166>/Inverter Enable'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Switch_fo = 1U;

    /* S-Function (c280xgpio_do): '<S166>/Digital Output2' */
    {
      if ((1U)) {
        GpioDataRegs.GPASET.bit.GPIO26 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO26 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S3>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S165>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S165>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S168>/For Iterator'
     */
    for (s168_iter = 1U; s168_iter < 17U; s168_iter++) {
      /* Outputs for Iterator SubSystem: '<S165>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S168>/For Iterator'
       */
      mcb_pmsm_foc_dual_cpu2_f28379_B.ForIterator = s168_iter;

      /* S-Function (memorycopy): '<S168>/Memory Copy' */
      {
        uint16_T *memindsrc3 = (uint16_T *) (&AdccResultRegs.ADCRESULT1);
        uint16_T *meminddst3 = (uint16_T *)
          (&mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy);
        *(uint16_T *) (meminddst3) = *(uint16_T *) (memindsrc3);
      }

      /* S-Function (memorycopy): '<S168>/Memory Copy1' */
      {
        uint16_T *memindsrc4 = (uint16_T *) (&AdcbResultRegs.ADCRESULT1);
        uint16_T *meminddst4 = (uint16_T *)
          (&mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy1);
        *(uint16_T *) (meminddst4) = *(uint16_T *) (memindsrc4);
      }

      /* If: '<S168>/If' */
      if (mcb_pmsm_foc_dual_cpu2_f28379_B.ForIterator > 8U) {
        /* Outputs for IfAction SubSystem: '<S168>/If Action Subsystem' incorporates:
         *  ActionPort: '<S173>/Action Port'
         */
        /* Memory: '<S173>/Memory' */
        mcb_pmsm_foc_dual_cpu2_f28379_B.Memory =
          mcb_pmsm_foc_dual_cpu2_f2_DWork.Memory_PreviousInput;

        /* Sum: '<S173>/Sum' */
        mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_k =
          mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy +
          mcb_pmsm_foc_dual_cpu2_f28379_B.Memory;

        /* Memory: '<S173>/Memory1' */
        mcb_pmsm_foc_dual_cpu2_f28379_B.Memory1 =
          mcb_pmsm_foc_dual_cpu2_f2_DWork.Memory1_PreviousInput;

        /* Sum: '<S173>/Sum1' */
        mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_n =
          mcb_pmsm_foc_dual_cpu2_f28379_B.MemoryCopy1 +
          mcb_pmsm_foc_dual_cpu2_f28379_B.Memory1;

        /* Update for Memory: '<S173>/Memory' */
        mcb_pmsm_foc_dual_cpu2_f2_DWork.Memory_PreviousInput =
          mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_k;

        /* Update for Memory: '<S173>/Memory1' */
        mcb_pmsm_foc_dual_cpu2_f2_DWork.Memory1_PreviousInput =
          mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_n;

        /* End of Outputs for SubSystem: '<S168>/If Action Subsystem' */
      }

      /* End of If: '<S168>/If' */
    }

    /* End of Outputs for SubSystem: '<S165>/For Iterator Subsystem' */

    /* Product: '<S165>/Divide' incorporates:
     *  Constant: '<S165>/Constant'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Divide = (uint16_T)((real_T)
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum_k / 8.0);

    /* If: '<S165>/If' incorporates:
     *  Constant: '<S165>/Constant1'
     *  Constant: '<S165>/Constant2'
     */
    if ((mcb_pmsm_foc_dual_cpu2_f28379_B.Divide > 1500U) &&
        (mcb_pmsm_foc_dual_cpu2_f28379_B.Divide < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem' incorporates:
       *  ActionPort: '<S169>/Action Port'
       */
      /* DataStoreWrite: '<S169>/Data Store Write1' */
      mcb_pmsm_foc_dual_cpu2_f2_DWork.IaOffset =
        mcb_pmsm_foc_dual_cpu2_f28379_B.Divide;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S170>/Action Port'
       */
      /* DataStoreWrite: '<S170>/Data Store Write1' incorporates:
       *  Constant: '<S170>/Constant'
       */
      mcb_pmsm_foc_dual_cpu2_f2_DWork.IaOffset = 2295U;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem1' */
    }

    /* End of If: '<S165>/If' */

    /* Product: '<S165>/Divide1' incorporates:
     *  Constant: '<S165>/Constant'
     */
    mcb_pmsm_foc_dual_cpu2_f28379_B.Divide1 = (uint16_T)((real_T)
      mcb_pmsm_foc_dual_cpu2_f28379_B.Sum1_n / 8.0);

    /* If: '<S165>/If1' incorporates:
     *  Constant: '<S165>/Constant1'
     *  Constant: '<S165>/Constant2'
     */
    if ((mcb_pmsm_foc_dual_cpu2_f28379_B.Divide1 > 1500U) &&
        (mcb_pmsm_foc_dual_cpu2_f28379_B.Divide1 < 2500U)) {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S171>/Action Port'
       */
      /* DataStoreWrite: '<S171>/Data Store Write2' */
      mcb_pmsm_foc_dual_cpu2_f2_DWork.IbOffset =
        mcb_pmsm_foc_dual_cpu2_f28379_B.Divide1;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S165>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S172>/Action Port'
       */
      /* DataStoreWrite: '<S172>/Data Store Write2' incorporates:
       *  Constant: '<S172>/Constant1'
       */
      mcb_pmsm_foc_dual_cpu2_f2_DWork.IbOffset = 2286U;

      /* End of Outputs for SubSystem: '<S165>/If Action Subsystem3' */
    }

    /* End of If: '<S165>/If1' */
    /* End of Outputs for SubSystem: '<S3>/Calculate ADC Offset ' */

    /* Logic: '<S3>/NOT' */
    mcb_pmsm_foc_dual_cpu2_f28379_B.NOT = false;

    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_dual_cpu2_f28379d_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Inverter Driver Peripherals' */
  InverterDriverPeripher_Term();

  /* End of Terminate for SubSystem: '<Root>/Inverter Driver Peripherals' */

  /* Terminate for MATLABSystem: '<S198>/IPC Read' */
  if (!mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_i.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S198>/IPC Read' */

  /* Terminate for MATLABSystem: '<S196>/IPC Read' */
  if (!mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_c.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S196>/IPC Read' */

  /* Terminate for MATLABSystem: '<S194>/IPC Read' */
  if (!mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.matlabCodegenIsDeleted) {
    mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.matlabCodegenIsDeleted = true;
    if ((mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.isInitialized == 1L) &&
        mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.isSetupComplete) {
      MW_IPC_Terminate(mcb_pmsm_foc_dual_cpu2_f2_DWork.obj_p.IpcHandle);
    }
  }

  /* End of Terminate for MATLABSystem: '<S194>/IPC Read' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
