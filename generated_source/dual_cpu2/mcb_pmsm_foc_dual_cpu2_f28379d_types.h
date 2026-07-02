/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu2_f28379d_types.h
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

#ifndef mcb_pmsm_foc_dual_cpu2_f28379d_types_h_
#define mcb_pmsm_foc_dual_cpu2_f28379d_types_h_
#include "rtwtypes.h"
#include "mw_soc_ipc.h"
#include "mw_soc_c2000_ipc.h"

/* Custom Type definition for MATLABSystem: '<S181>/IPC Write' */
#include "mw_soc_ipc.h"
#include "mw_soc_c2000_ipc.h"
#include "mw_soc_ipc.h"
#ifndef struct_tag_r8oIyYm4oPAMO6WFmhubcB
#define struct_tag_r8oIyYm4oPAMO6WFmhubcB

struct tag_r8oIyYm4oPAMO6WFmhubcB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_IPC_Params_T IpcParams;
  MW_IPC_Handle IpcHandle;
  uint64_T Overwritten;
  uint16_T NumBufUsed;
};

#endif                                 /* struct_tag_r8oIyYm4oPAMO6WFmhubcB */

#ifndef typedef_soc_blocks_IPCWrite_mcb_pmsm_fo
#define typedef_soc_blocks_IPCWrite_mcb_pmsm_fo

typedef struct tag_r8oIyYm4oPAMO6WFmhubcB soc_blocks_IPCWrite_mcb_pmsm_fo;

#endif                             /* typedef_soc_blocks_IPCWrite_mcb_pmsm_fo */

#ifndef struct_tag_kIMAP1tg9kyzXjx3AcFoiG
#define struct_tag_kIMAP1tg9kyzXjx3AcFoiG

struct tag_kIMAP1tg9kyzXjx3AcFoiG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_IPC_Params_T IpcParams;
  MW_IPC_Handle IpcHandle;
};

#endif                                 /* struct_tag_kIMAP1tg9kyzXjx3AcFoiG */

#ifndef typedef_soc_blocks_IPCRead_mcb_pmsm_foc
#define typedef_soc_blocks_IPCRead_mcb_pmsm_foc

typedef struct tag_kIMAP1tg9kyzXjx3AcFoiG soc_blocks_IPCRead_mcb_pmsm_foc;

#endif                             /* typedef_soc_blocks_IPCRead_mcb_pmsm_foc */

/* Forward declaration for rtModel */
typedef struct tag_RTM_mcb_pmsm_foc_dual_cpu2_ RT_MODEL_mcb_pmsm_foc_dual_cpu2;

#endif                             /* mcb_pmsm_foc_dual_cpu2_f28379d_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
