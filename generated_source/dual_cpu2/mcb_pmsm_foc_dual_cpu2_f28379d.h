/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu2_f28379d.h
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

#ifndef mcb_pmsm_foc_dual_cpu2_f28379d_h_
#define mcb_pmsm_foc_dual_cpu2_f28379d_h_
#ifndef mcb_pmsm_foc_dual_cpu2_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_foc_dual_cpu2_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "string.h"
#include "IQmathLib.h"
#include "mw_soc_ipc.h"
#endif                     /* mcb_pmsm_foc_dual_cpu2_f28379d_COMMON_INCLUDES_ */

#include "mcb_pmsm_foc_dual_cpu2_f28379d_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "zero_crossing_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define mcb_pmsm_foc_dual_cpu2_f28379d_M (mcb_pmsm_foc_dual_cpu2_f2837_M)

extern void configureCPU2Peripherals(uint32_T gpioNumber, uint32_T gpGRegValA,
  uint32_T gpRegValA, uint32_T gpPullUp);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals (default storage) */
typedef struct {
  uint64_T IPCChannelNumberofoverwrites;/* '<S181>/IPC Write' */
  uint32_T PositionToCount;            /* '<S208>/PositionToCount' */
  uint32_T Delay;                      /* '<S208>/Delay' */
  uint32_T PositionToCount_i;          /* '<S251>/PositionToCount' */
  uint32_T Delay_c;                    /* '<S251>/Delay' */
  uint32_T IPCRead_o1;                 /* '<S194>/IPC Read' */
  uint32_T BytePack;                   /* '<S179>/Byte Pack' */
  uint32_T Sum[4];                     /* '<S150>/Sum' */
  real32_T Delay5[4];                  /* '<Root>/Delay5' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T DataTypeConversion4;        /* '<S185>/Data Type Conversion4' */
  real32_T Switch1[2];                 /* '<S186>/Switch1' */
  real32_T Product[2];                 /* '<S192>/Product' */
  real32_T UnitDelay[2];               /* '<S192>/Unit Delay' */
  real32_T Product1[2];                /* '<S192>/Product1' */
  real32_T Add1[2];                    /* '<S192>/Add1' */
  real32_T GetADCVoltage[2];           /* '<S202>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S202>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S202>/PU_Conversion' */
  real32_T Merge[2];                   /* '<S200>/Merge' */
  real32_T Switch1_k[2];               /* '<S209>/Switch1' */
  real32_T Product_g[4];               /* '<S212>/Product' */
  real32_T UnitDelay_c[4];             /* '<S212>/Unit Delay' */
  real32_T Product1_e[4];              /* '<S212>/Product1' */
  real32_T Add1_o[4];                  /* '<S212>/Add1' */
  real32_T Sum6[4];                    /* '<S205>/Sum6' */
  real32_T Product_o;                  /* '<S235>/Product' */
  real32_T Sum3;                       /* '<S232>/Sum3' */
  real32_T Delay1;                     /* '<S234>/Delay1' */
  real32_T Sum_i;                      /* '<S234>/Sum' */
  real32_T Product_oh;                 /* '<S234>/Product' */
  real32_T Delay_o;                    /* '<S234>/Delay' */
  real32_T Product1_c;                 /* '<S234>/Product1' */
  real32_T Sum1;                       /* '<S234>/Sum1' */
  real32_T Product2;                   /* '<S235>/Product2' */
  real32_T Sum1_m;                     /* '<S232>/Sum1' */
  real32_T Sum_h;                      /* '<S233>/Sum' */
  real32_T Switch1_a[2];               /* '<S233>/Switch1' */
  real32_T Product_c;                  /* '<S238>/Product' */
  real32_T UnitDelay_i;                /* '<S238>/Unit Delay' */
  real32_T Product1_p;                 /* '<S238>/Product1' */
  real32_T Add1_a;                     /* '<S238>/Add1' */
  real32_T Switch;                     /* '<S231>/Switch' */
  real32_T Product_d;                  /* '<S227>/Product' */
  real32_T Sum3_a;                     /* '<S224>/Sum3' */
  real32_T Delay1_o;                   /* '<S226>/Delay1' */
  real32_T Sum_b;                      /* '<S226>/Sum' */
  real32_T Product_h;                  /* '<S226>/Product' */
  real32_T Delay_f;                    /* '<S226>/Delay' */
  real32_T Product1_h;                 /* '<S226>/Product1' */
  real32_T Sum1_p;                     /* '<S226>/Sum1' */
  real32_T Product2_a;                 /* '<S227>/Product2' */
  real32_T Sum1_l;                     /* '<S224>/Sum1' */
  real32_T Sum_l;                      /* '<S225>/Sum' */
  real32_T Switch1_m[2];               /* '<S225>/Switch1' */
  real32_T Product_i;                  /* '<S230>/Product' */
  real32_T UnitDelay_b;                /* '<S230>/Unit Delay' */
  real32_T Product1_f;                 /* '<S230>/Product1' */
  real32_T Add1_c;                     /* '<S230>/Add1' */
  real32_T Switch_g;                   /* '<S223>/Switch' */
  real32_T DTC;                        /* '<S243>/DTC' */
  real32_T SpeedGain;                  /* '<S208>/SpeedGain' */
  real32_T Switch1_f[2];               /* '<S207>/Switch1' */
  real32_T Product_cl;                 /* '<S241>/Product' */
  real32_T UnitDelay_i1;               /* '<S241>/Unit Delay' */
  real32_T Product1_o;                 /* '<S241>/Product1' */
  real32_T Add1_j;                     /* '<S241>/Add1' */
  real32_T elect2mech;                 /* '<S203>/elect2mech' */
  real32_T Sum_n;                      /* '<S237>/Sum' */
  real32_T Sum_f;                      /* '<S229>/Sum' */
  real32_T Atan2;                      /* '<S221>/Atan2' */
  real32_T Switch_l;                   /* '<S221>/Switch' */
  real32_T algDD;
  real32_T Gain;                       /* '<S222>/Gain' */
  real32_T Switch_e;                   /* '<S222>/Switch' */
  real32_T Bias;                       /* '<S222>/Bias' */
  real32_T UnitDelay1;                 /* '<S256>/Unit Delay1' */
  real32_T UnitDelay_d;                /* '<S256>/Unit Delay' */
  real32_T a;                          /* '<S256>/a' */
  real32_T Delay_g;                    /* '<S246>/Delay' */
  real32_T Sum2;                       /* '<S246>/Sum2' */
  real32_T Sum3_l;                     /* '<S256>/Sum3' */
  real32_T b_invg;                     /* '<S256>/b_inv*g' */
  real32_T Delay1_m;                   /* '<S256>/Delay1' */
  real32_T Sum4;                       /* '<S256>/Sum4' */
  real32_T Switch1_c[2];               /* '<S248>/Switch1' */
  real32_T Product_o1;                 /* '<S260>/Product' */
  real32_T UnitDelay_g;                /* '<S260>/Unit Delay' */
  real32_T Product1_j;                 /* '<S260>/Product1' */
  real32_T Add1_cy;                    /* '<S260>/Add1' */
  real32_T UnitDelay1_e;               /* '<S257>/Unit Delay1' */
  real32_T UnitDelay_e;                /* '<S257>/Unit Delay' */
  real32_T a_l;                        /* '<S257>/a' */
  real32_T Delay_f1;                   /* '<S247>/Delay' */
  real32_T Sum2_o;                     /* '<S247>/Sum2' */
  real32_T Sum3_f;                     /* '<S257>/Sum3' */
  real32_T b_invg_f;                   /* '<S257>/b_inv*g' */
  real32_T Delay1_k;                   /* '<S257>/Delay1' */
  real32_T Sum4_p;                     /* '<S257>/Sum4' */
  real32_T Switch1_g[2];               /* '<S249>/Switch1' */
  real32_T Product_iw;                 /* '<S263>/Product' */
  real32_T UnitDelay_a;                /* '<S263>/Unit Delay' */
  real32_T Product1_hr;                /* '<S263>/Product1' */
  real32_T Add1_i;                     /* '<S263>/Add1' */
  real32_T Merge_f;                    /* '<S245>/Merge' */
  real32_T Merge1;                     /* '<S245>/Merge1' */
  real32_T Delay_ob;                   /* '<S244>/Delay' */
  real32_T Sign;                       /* '<S246>/Sign' */
  real32_T Eta;                        /* '<S246>/Eta' */
  real32_T Sum_c;                      /* '<S246>/Sum' */
  real32_T b;                          /* '<S246>/b' */
  real32_T a_p;                        /* '<S246>/a' */
  real32_T Sum1_m4;                    /* '<S246>/Sum1' */
  real32_T Sign_a;                     /* '<S247>/Sign' */
  real32_T Eta_d;                      /* '<S247>/Eta' */
  real32_T Sum_p;                      /* '<S247>/Sum' */
  real32_T b_k;                        /* '<S247>/b' */
  real32_T a_f;                        /* '<S247>/a' */
  real32_T Sum1_o;                     /* '<S247>/Sum1' */
  real32_T DTC_n;                      /* '<S268>/DTC' */
  real32_T SpeedGain_g;                /* '<S251>/SpeedGain' */
  real32_T Switch1_j[2];               /* '<S250>/Switch1' */
  real32_T Product_k;                  /* '<S266>/Product' */
  real32_T UnitDelay_m;                /* '<S266>/Unit Delay' */
  real32_T Product1_on;                /* '<S266>/Product1' */
  real32_T Add1_ow;                    /* '<S266>/Add1' */
  real32_T Product_n;                  /* '<S252>/Product' */
  real32_T Product2_i;                 /* '<S252>/Product2' */
  real32_T Sum1_d;                     /* '<S252>/Sum1' */
  real32_T Product1_eh;                /* '<S252>/Product1' */
  real32_T Product3;                   /* '<S252>/Product3' */
  real32_T Sum2_b;                     /* '<S252>/Sum2' */
  real32_T Switch_lg;                  /* '<S252>/Switch' */
  real32_T Atan2_i;                    /* '<S269>/Atan2' */
  real32_T Switch_b;                   /* '<S269>/Switch' */
  real32_T algDD_e;
  real32_T Gain_b;                     /* '<S270>/Gain' */
  real32_T Switch_k;                   /* '<S270>/Switch' */
  real32_T Bias_l;                     /* '<S270>/Bias' */
  real32_T Bias_h;                     /* '<S252>/Bias' */
  real32_T id_Ld_Lq;                   /* '<S183>/Product1' */
  real32_T Add;                        /* '<S183>/Add' */
  real32_T Product3_g;                 /* '<S183>/Product3' */
  real32_T u_5_Pp;                     /* '<S183>/1_5_Pp' */
  real32_T IndexVector;                /* '<S174>/Index Vector' */
  real32_T Switch_m;                   /* '<S175>/Switch' */
  real32_T Product_m;                  /* '<S183>/Product' */
  real32_T P_output;                   /* '<S183>/P_si2pu' */
  real32_T Ia;         /* '<S2>/BusConversion_InsertedFor_SCI_Tx_at_inport_0' */
  real32_T pos;        /* '<S2>/BusConversion_InsertedFor_SCI_Tx_at_inport_0' */
  real32_T Speed_fb;   /* '<S2>/BusConversion_InsertedFor_SCI_Tx_at_inport_0' */
  real32_T Merge_g;                    /* '<S152>/Merge' */
  real32_T indexing;                   /* '<S150>/indexing' */
  real32_T Lookup[4];                  /* '<S150>/Lookup' */
  real32_T Sum3_h;                     /* '<S151>/Sum3' */
  real32_T DataTypeConversion1;        /* '<S150>/Data Type Conversion1' */
  real32_T Sum2_a;                     /* '<S150>/Sum2' */
  real32_T Product_a;                  /* '<S151>/Product' */
  real32_T Sum4_l;                     /* '<S151>/Sum4' */
  real32_T Sum5;                       /* '<S151>/Sum5' */
  real32_T Product1_k;                 /* '<S151>/Product1' */
  real32_T Sum6_o;                     /* '<S151>/Sum6' */
  real32_T Sum_g;                      /* '<S21>/Sum' */
  real32_T PProdOut;                   /* '<S133>/PProd Out' */
  real32_T Kp1;                        /* '<S21>/Kp1' */
  real32_T Integrator;                 /* '<S128>/Integrator' */
  real32_T Sum_cq;                     /* '<S137>/Sum' */
  real32_T Saturation;                 /* '<S135>/Saturation' */
  real32_T Sum_j;                      /* '<S20>/Sum' */
  real32_T PProdOut_o;                 /* '<S78>/PProd Out' */
  real32_T Ki1;                        /* '<S20>/Ki1' */
  real32_T Integrator_e;               /* '<S73>/Integrator' */
  real32_T Sum_m;                      /* '<S82>/Sum' */
  real32_T Saturation_h;               /* '<S80>/Saturation' */
  real32_T Switch_d;                   /* '<S24>/Switch' */
  real32_T Product_f;                  /* '<S24>/Product' */
  real32_T Product_iz;                 /* '<S25>/Product' */
  real32_T Product1_n;                 /* '<S25>/Product1' */
  real32_T Sum1_b;                     /* '<S25>/Sum1' */
  real32_T Merge_o[2];                 /* '<S19>/Merge' */
  real32_T DeadZone;                   /* '<S65>/DeadZone' */
  real32_T IProdOut;                   /* '<S70>/IProd Out' */
  real32_T Switch_f;                   /* '<S63>/Switch' */
  real32_T DeadZone_j;                 /* '<S120>/DeadZone' */
  real32_T IProdOut_a;                 /* '<S125>/IProd Out' */
  real32_T Switch_n;                   /* '<S118>/Switch' */
  real32_T one_by_two;                 /* '<S164>/one_by_two' */
  real32_T sqrt3_by_two;               /* '<S164>/sqrt3_by_two' */
  real32_T add_b;                      /* '<S164>/add_b' */
  real32_T add_c;                      /* '<S164>/add_c' */
  real32_T Max;                        /* '<S161>/Max' */
  real32_T Min;                        /* '<S161>/Min' */
  real32_T Add_o;                      /* '<S161>/Add' */
  real32_T one_by_two_n;               /* '<S161>/one_by_two' */
  real32_T Add1_e;                     /* '<S160>/Add1' */
  real32_T Add2;                       /* '<S160>/Add2' */
  real32_T Add3;                       /* '<S160>/Add3' */
  real32_T Gain_k[3];                  /* '<S160>/Gain' */
  real32_T One_by_Two[3];              /* '<S10>/One_by_Two' */
  real32_T PWM_Duty_Cycles[3];         /* '<S10>/Sum' */
  real32_T DataTypeConversion;         /* '<S10>/Data Type Conversion' */
  real32_T Convert_back;               /* '<S156>/Convert_back' */
  real32_T Convert_back_o;             /* '<S155>/Convert_back' */
  real32_T acos_i;                     /* '<S148>/acos' */
  real32_T bsin;                       /* '<S148>/bsin' */
  real32_T sum_Ds;                     /* '<S148>/sum_Ds' */
  real32_T bcos;                       /* '<S148>/bcos' */
  real32_T asin_p;                     /* '<S148>/asin' */
  real32_T sum_Qs;                     /* '<S148>/sum_Qs' */
  real32_T Switch_mn[2];               /* '<S149>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T qcos;                       /* '<S146>/qcos' */
  real32_T dsin;                       /* '<S146>/dsin' */
  real32_T sum_beta;                   /* '<S146>/sum_beta' */
  real32_T dcos;                       /* '<S146>/dcos' */
  real32_T qsin;                       /* '<S146>/qsin' */
  real32_T sum_alpha;                  /* '<S146>/sum_alpha' */
  real32_T Switch_p[2];                /* '<S147>/Switch' */
  real32_T algDD_o1_a;
  real32_T algDD_o2_j;
  real32_T Product_j[2];               /* '<S26>/Product' */
  real32_T SquareRoot;                 /* '<S26>/Square Root' */
  real32_T Switch_ke;                  /* '<S26>/Switch' */
  real32_T Switch_o[2];                /* '<S23>/Switch' */
  real32_T Switch2;                    /* '<S33>/Switch2' */
  real32_T Product_ai;                 /* '<S32>/Product' */
  real32_T Sum_ik;                     /* '<S32>/Sum' */
  real32_T Product2_h;                 /* '<S32>/Product2' */
  real32_T Merge_b;                    /* '<S32>/Merge' */
  real32_T Gain_f;                     /* '<S32>/Gain' */
  real32_T Switch_of;                  /* '<S33>/Switch' */
  real32_T Switch1_kd;                 /* '<S34>/Switch1' */
  real32_T Sqrt;                       /* '<S34>/Sqrt' */
  real32_T Gain_d;                     /* '<S34>/Gain' */
  real32_T a_plus_2b;                  /* '<S18>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S18>/one_by_sqrt3' */
  real32_T algDD_o1_d;
  real32_T algDD_o2_k;
  int32_T DataTypeConversion5;         /* '<S185>/Data Type Conversion5' */
  int32_T DataTypeConversion_m[2];     /* '<S199>/Data Type Conversion' */
  int32_T Add_k[2];                    /* '<S199>/Add' */
  int32_T SpeedCount;                  /* '<S208>/SpeedCount' */
  int32_T SpeedCount_c;                /* '<S251>/SpeedCount' */
  uint16_T DataStoreRead;              /* '<S199>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S199>/Data Store Read1' */
  uint16_T IPCRead_o1_f;               /* '<S198>/IPC Read' */
  uint16_T IPCRead_o1_i;               /* '<S196>/IPC Read' */
  uint16_T DataStoreRead_c;            /* '<S5>/Data Store Read' */
  uint16_T Switch1_cy[3];              /* '<S175>/Switch1' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S175>/Scale_to_PWM_Counter_PRD' */
  uint16_T IPCChannelNumberofbuffersused;/* '<S181>/IPC Write' */
  uint16_T Switch_fo;                  /* '<S166>/Switch' */
  uint16_T Divide;                     /* '<S165>/Divide' */
  uint16_T Divide1;                    /* '<S165>/Divide1' */
  uint16_T ForIterator;                /* '<S168>/For Iterator' */
  uint16_T MemoryCopy;                 /* '<S168>/Memory Copy' */
  uint16_T MemoryCopy1;                /* '<S168>/Memory Copy1' */
  uint16_T Memory;                     /* '<S173>/Memory' */
  uint16_T Sum_k;                      /* '<S173>/Sum' */
  uint16_T Memory1;                    /* '<S173>/Memory1' */
  uint16_T Sum1_n;                     /* '<S173>/Sum1' */
  uint16_T Switch1_a4;                 /* '<S24>/Switch1' */
  uint16_T DataTypeConversion_o;       /* '<S152>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S150>/Get_Integer' */
  uint16_T DataTypeConversion_k;       /* '<S22>/Data Type Conversion' */
  uint16_T DataTypeConversion_g;       /* '<S32>/Data Type Conversion' */
  uint16_T MemoryCopy_p;               /* '<S1>/Memory Copy' */
  uint16_T MemoryCopy1_l;              /* '<S1>/Memory Copy1' */
  int16_T Switch_c;                    /* '<S253>/Switch' */
  int16_T Convert_uint16;              /* '<S156>/Convert_uint16' */
  int16_T Convert_uint16_f;            /* '<S155>/Convert_uint16' */
  int16_T IPCRead_o2;                  /* '<S198>/IPC Read' */
  int16_T IPCRead_o2_l;                /* '<S196>/IPC Read' */
  int16_T IPCRead_o2_p;                /* '<S194>/IPC Read' */
  int16_T Switch1_ck;                  /* '<S63>/Switch1' */
  int16_T Switch2_g;                   /* '<S63>/Switch2' */
  int16_T Switch1_n;                   /* '<S118>/Switch1' */
  int16_T Switch2_n;                   /* '<S118>/Switch2' */
  boolean_T RateTransition;            /* '<S6>/Rate Transition' */
  boolean_T DataTypeConversion2;       /* '<S6>/Data Type Conversion2' */
  boolean_T DataStoreRead1_m;          /* '<S203>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S203>/Logical Operator' */
  boolean_T DataStoreRead1_g;          /* '<S204>/Data Store Read1' */
  boolean_T LogicalOperator_l;         /* '<S204>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S245>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S245>/BetaRelay' */
  boolean_T LogicalOperator_p;         /* '<S253>/Logical Operator' */
  boolean_T NOT;                       /* '<S3>/NOT' */
  boolean_T Compare;                   /* '<S154>/Compare' */
  boolean_T LogicalOperator_c;         /* '<S21>/Logical Operator' */
  boolean_T LogicalOperator_pg;        /* '<S20>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S63>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S63>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S63>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S63>/Equal1' */
  boolean_T AND3;                      /* '<S63>/AND3' */
  boolean_T RelationalOperator_j;      /* '<S118>/Relational Operator' */
  boolean_T fixforDTpropagationissue_p;
                                     /* '<S118>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_e;
                                    /* '<S118>/fix for DT propagation issue1' */
  boolean_T Equal1_f;                  /* '<S118>/Equal1' */
  boolean_T AND3_c;                    /* '<S118>/AND3' */
  boolean_T Enable;                    /* '<S10>/Enable' */
  boolean_T RelationalOperator_k;      /* '<S22>/Relational Operator' */
  boolean_T Compare_f;                 /* '<S28>/Compare' */
  boolean_T Compare_e;                 /* '<S29>/Compare' */
  boolean_T LowerRelop1;               /* '<S33>/LowerRelop1' */
  boolean_T RelationalOperator_o;      /* '<S32>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S33>/UpperRelop' */
} BlockIO_mcb_pmsm_foc_dual_cpu2_;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  soc_blocks_IPCWrite_mcb_pmsm_fo obj; /* '<S181>/IPC Write' */
  soc_blocks_IPCRead_mcb_pmsm_foc obj_i;/* '<S198>/IPC Read' */
  soc_blocks_IPCRead_mcb_pmsm_foc obj_c;/* '<S196>/IPC Read' */
  soc_blocks_IPCRead_mcb_pmsm_foc obj_p;/* '<S194>/IPC Read' */
  real32_T Delay5_DSTATE[4];           /* '<Root>/Delay5' */
  real32_T UnitDelay_DSTATE[2];        /* '<S192>/Unit Delay' */
  real32_T UnitDelay_DSTATE_b[4];      /* '<S212>/Unit Delay' */
  real32_T Delay1_DSTATE;              /* '<S234>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S234>/Delay' */
  real32_T UnitDelay_DSTATE_l;         /* '<S238>/Unit Delay' */
  real32_T Delay1_DSTATE_k;            /* '<S226>/Delay1' */
  real32_T Delay_DSTATE_f;             /* '<S226>/Delay' */
  real32_T UnitDelay_DSTATE_d;         /* '<S230>/Unit Delay' */
  real32_T UnitDelay_DSTATE_c;         /* '<S241>/Unit Delay' */
  real32_T Delay_DSTATE_d;             /* '<S246>/Delay' */
  real32_T Delay1_DSTATE_b;            /* '<S256>/Delay1' */
  real32_T Delay_DSTATE_h;             /* '<S247>/Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S257>/Delay1' */
  real32_T Delay_DSTATE_b;             /* '<S244>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S128>/Integrator' */
  real32_T Integrator_DSTATE_i;        /* '<S73>/Integrator' */
  uint32_T Delay_DSTATE_e[10];         /* '<S208>/Delay' */
  int32_T GroundingtheSPIclockfortheDRV83;
                             /* '<S7>/Grounding the SPI clockfor the DRV830x' */
  int32_T Add_DWORK1[2];               /* '<S199>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S208>/SpeedCount' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S175>/Digital Output' */
  int32_T BlinkBlueLED_FRAC_LEN;       /* '<S4>/Blink Blue LED' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S4>/Digital Output1' */
  int32_T DigitalOutput2_FRAC_LEN;     /* '<S166>/Digital Output2' */
  uint32_T Sum_DWORK1[4];              /* '<S150>/Sum' */
  uint16_T SignalSelect2;              /* '<Root>/Data Store Memory1' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory5' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory6' */
  uint16_T CircBufIdx;                 /* '<S208>/Delay' */
  uint16_T CircBufIdx_a;               /* '<S251>/Delay' */
  uint16_T Memory_PreviousInput;       /* '<S173>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S173>/Memory1' */
  int16_T Integrator_PrevResetState;   /* '<S128>/Integrator' */
  int16_T Integrator_PrevResetState_h; /* '<S73>/Integrator' */
  volatile boolean_T RateTransition_Buffer0;/* '<S6>/Rate Transition' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T AlphaRelay_Mode;           /* '<S245>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S245>/BetaRelay' */
  boolean_T objisempty;                /* '<S198>/IPC Read' */
  boolean_T objisempty_l;              /* '<S196>/IPC Read' */
  boolean_T objisempty_e;              /* '<S194>/IPC Read' */
  boolean_T objisempty_p;              /* '<S181>/IPC Write' */
} D_Work_mcb_pmsm_foc_dual_cpu2_f;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S234>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S234>/Delay' */
  ZCSigState Delay1_Reset_ZCE_i;       /* '<S226>/Delay1' */
  ZCSigState Delay_Reset_ZCE_k;        /* '<S226>/Delay' */
  ZCSigState Delay_Reset_ZCE_e;        /* '<S246>/Delay' */
  ZCSigState Delay1_Reset_ZCE_l;       /* '<S256>/Delay1' */
  ZCSigState Delay_Reset_ZCE_m;        /* '<S247>/Delay' */
  ZCSigState Delay1_Reset_ZCE_f;       /* '<S257>/Delay1' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S244>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S245>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_du;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Ld_Port;              /* '<S184>/Gain' */
  const real32_T Switch;               /* '<S184>/Switch' */
  const real32_T Lq_Port;              /* '<S184>/Gain1' */
  const real32_T Switch1;              /* '<S184>/Switch1' */
  const real32_T FluxPM_Port;          /* '<S184>/Gain2' */
  const real32_T Switch2;              /* '<S184>/Switch2' */
  const real32_T Ld_Lq;                /* '<S183>/Subtract' */
} ConstBlockIO_mcb_pmsm_foc_dual_;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S150>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_foc_dual_cp;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_dual_cpu2_ {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[3];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_dual_cpu2_ mcb_pmsm_foc_dual_cpu2_f28379_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_dual_cpu2_f mcb_pmsm_foc_dual_cpu2_f2_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_mcb_pmsm_foc_du mcb_pmsm_foc_dua_PrevZCSigState;
extern const ConstBlockIO_mcb_pmsm_foc_dual_ mcb_pmsm_foc_dual_cpu2_f_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_dual_cp mcb_pmsm_foc_dual_cpu2_f_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_dual_cpu2_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_dual_cpu2_f28379d_initialize(void);
extern void mcb_pmsm_foc_dual_cpu2_f28379d_step0(void);/* Sample time: [5.0E-5s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu2_f28379d_step1(void);/* Sample time: [0.01s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu2_f28379d_step2(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu2_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_dual_cpu2 *const mcb_pmsm_foc_dual_cpu2_f2837_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'mcb_pmsm_foc_dual_cpu2_f28379d'
 * '<S1>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Current Sensing'
 * '<S2>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm'
 * '<S3>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init'
 * '<S4>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Heartbeat LED'
 * '<S5>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals'
 * '<S6>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands'
 * '<S7>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Resetting SPI clock drive '
 * '<S8>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm'
 * '<S9>'   : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control'
 * '<S10>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Output Scaling'
 * '<S11>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Clarke Transform'
 * '<S12>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers'
 * '<S13>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Inverse Park Transform'
 * '<S14>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Park Transform'
 * '<S15>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup'
 * '<S16>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator'
 * '<S17>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Clarke Transform/Two phase input'
 * '<S18>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S19>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter'
 * '<S20>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id'
 * '<S21>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq'
 * '<S22>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S23>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S24>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S25>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S26>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S27>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S28>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S29>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S30>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S31>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S32>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S33>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S34>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S35>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S36>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S37>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S38>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S39>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S40>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S41>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S42>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S43>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S44>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S45>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S46>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S47>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S48>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S49>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S50>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S51>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S52>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S53>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S54>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S55>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S56>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S57>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S58>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S59>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S60>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S61>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S62>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S63>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S64>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S65>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S66>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S67>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S68>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S69>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S70>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S71>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S72>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S73>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S74>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S75>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S76>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S77>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S78>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S79>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S80>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S81>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S82>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S83>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S84>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S85>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S86>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S87>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S88>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S89>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S90>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S91>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S92>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S93>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S94>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S95>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S96>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S97>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S98>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S99>'  : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S100>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S101>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S102>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S103>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S104>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S105>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S106>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S107>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S108>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S109>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S110>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S111>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S112>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S113>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S114>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S115>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S116>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S117>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S118>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S119>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S120>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S121>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S122>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S123>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S124>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S125>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S126>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S127>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S128>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S129>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S130>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S131>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S132>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S133>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S134>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S135>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S136>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S137>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S138>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S139>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S140>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S141>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S142>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S143>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S144>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S145>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S146>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Inverse Park Transform/Two inputs CRL'
 * '<S147>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S148>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Park Transform/Two inputs CRL'
 * '<S149>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S150>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S151>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S152>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S153>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S154>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S155>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S156>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S157>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S158>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Modulation method'
 * '<S159>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Voltage Input'
 * '<S160>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Modulation method/SVPWM'
 * '<S161>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S162>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S163>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S164>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Foc Algorithm/Current Control/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S165>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset '
 * '<S166>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/DRV Enable'
 * '<S167>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Default ADC Offset'
 * '<S168>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset /For Iterator Subsystem'
 * '<S169>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem'
 * '<S170>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem1'
 * '<S171>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem2'
 * '<S172>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem3'
 * '<S173>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Hardware Init/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S174>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/IPC Data Transmission'
 * '<S175>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/Inverter'
 * '<S176>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1'
 * '<S177>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/IPC Data Transmission/Data_Conditioning_Tx'
 * '<S178>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/IPC Data Transmission/Signal_To_Log'
 * '<S179>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/IPC Data Transmission/Data_Conditioning_Tx/Data_Type_Float'
 * '<S180>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/IPC Data Transmission/Signal_To_Log/Variant'
 * '<S181>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/IPC Data Transmission/Signal_To_Log/Variant/CODEGEN'
 * '<S182>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1/Variant Subsystem'
 * '<S183>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S184>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S185>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/Data_Conditioning'
 * '<S186>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IIR Filter'
 * '<S187>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive'
 * '<S188>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive1'
 * '<S189>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive2'
 * '<S190>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IIR Filter/IIR Filter'
 * '<S191>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IIR Filter/IIR Filter/Low-pass'
 * '<S192>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S193>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive/Variant'
 * '<S194>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive/Variant/CODEGEN'
 * '<S195>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive1/Variant'
 * '<S196>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive1/Variant/CODEGEN'
 * '<S197>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive2/Variant'
 * '<S198>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Reference Commands/IPC Receive2/Variant/CODEGEN'
 * '<S199>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate Phase Currents'
 * '<S200>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed'
 * '<S201>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate Phase Currents/Data_Type'
 * '<S202>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S203>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer'
 * '<S204>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer'
 * '<S205>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal'
 * '<S206>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S207>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S208>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S209>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter'
 * '<S210>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter'
 * '<S211>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass'
 * '<S212>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S213>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S214>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S215>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S216>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S217>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S218>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S219>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S220>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S221>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S222>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S223>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S224>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S225>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S226>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S227>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S228>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S229>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S230>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S231>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S232>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S233>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S234>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S235>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S236>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S237>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S238>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S239>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S240>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S241>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S242>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S243>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S244>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer'
 * '<S245>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch'
 * '<S246>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est'
 * '<S247>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est'
 * '<S248>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha'
 * '<S249>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta'
 * '<S250>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter'
 * '<S251>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement'
 * '<S252>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation'
 * '<S253>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S254>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S255>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S256>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S257>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S258>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S259>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S260>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S261>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S262>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S263>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S264>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S265>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S266>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S267>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S268>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S269>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1'
 * '<S270>' : 'mcb_pmsm_foc_dual_cpu2_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 */
#endif                                 /* mcb_pmsm_foc_dual_cpu2_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
