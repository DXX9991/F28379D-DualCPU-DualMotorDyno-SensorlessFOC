/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_dual_cpu1_f28379d.h
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

#ifndef mcb_pmsm_foc_dual_cpu1_f28379d_h_
#define mcb_pmsm_foc_dual_cpu1_f28379d_h_
#ifndef mcb_pmsm_foc_dual_cpu1_f28379d_COMMON_INCLUDES_
#define mcb_pmsm_foc_dual_cpu1_f28379d_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "string.h"
#include "DSP28xx_SciUtil.h"
#include "IQmathLib.h"
#include "mw_soc_ipc.h"
#endif                     /* mcb_pmsm_foc_dual_cpu1_f28379d_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_dual_cpu1_f28379d_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
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

#define mcb_pmsm_foc_dual_cpu1_f28379d_M (mcb_pmsm_foc_dual_cpu1_f2837_M)

extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);

/* Block signals for system '<S2>/Speed Control' */
typedef struct {
  real32_T Id_Ref;                     /* '<S17>/Id_Ref' */
  real32_T Speed_Ref;                  /* '<S178>/Switch' */
  real32_T Switch1[2];                 /* '<S180>/Switch1' */
  real32_T Product;                    /* '<S237>/Product' */
  real32_T UnitDelay;                  /* '<S237>/Unit Delay' */
  real32_T Product1;                   /* '<S237>/Product1' */
  real32_T Add1;                       /* '<S237>/Add1' */
  real32_T Sum;                        /* '<S177>/Sum' */
  real32_T PProdOut;                   /* '<S222>/PProd Out' */
  real32_T Ki2;                        /* '<S177>/Ki2' */
  real32_T Integrator;                 /* '<S217>/Integrator' */
  real32_T Sum_b;                      /* '<S226>/Sum' */
  real32_T DeadZone;                   /* '<S209>/DeadZone' */
  real32_T IProdOut;                   /* '<S214>/IProd Out' */
  real32_T Switch;                     /* '<S207>/Switch' */
  real32_T Saturation;                 /* '<S224>/Saturation' */
  real32_T Switch1_d;                  /* '<S178>/Switch1' */
  int16_T Switch1_a;                   /* '<S207>/Switch1' */
  int16_T Switch2;                     /* '<S207>/Switch2' */
  boolean_T AND;                       /* '<S177>/AND' */
  boolean_T LogicalOperator;           /* '<S177>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S207>/Relational Operator' */
  boolean_T fixforDTpropagationissue;/* '<S207>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                    /* '<S207>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S207>/Equal1' */
  boolean_T AND3;                      /* '<S207>/AND3' */
} rtB_SpeedControl_mcb_pmsm_foc_d;

/* Block states (default storage) for system '<S2>/Speed Control' */
typedef struct {
  real32_T UnitDelay_DSTATE;           /* '<S237>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S217>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S217>/Integrator' */
} rtDW_SpeedControl_mcb_pmsm_foc_;

/* Block signals (default storage) */
typedef struct {
  uint64_T IPCChannelNumberofoverwrites;/* '<S255>/IPC Write' */
  uint64_T IPCChannelNumberofoverwrites_k;/* '<S357>/IPC Write' */
  uint64_T IPCChannelNumberofoverwrites_o;/* '<S355>/IPC Write' */
  uint32_T PositionToCount;            /* '<S284>/PositionToCount' */
  uint32_T Delay;                      /* '<S284>/Delay' */
  uint32_T PositionToCount_f;          /* '<S327>/PositionToCount' */
  uint32_T Delay_b;                    /* '<S327>/Delay' */
  uint32_T BytePack;                   /* '<S263>/Byte Pack' */
  uint32_T SCI_Tx_Data[3];             /* '<S260>/Merge' */
  uint32_T SCI_Tx_Iteration;           /* '<S260>/Merge1' */
  uint32_T IndexVector;                /* '<S262>/Index Vector' */
  uint32_T Add;                        /* '<S262>/Add' */
  uint32_T IPCRead_o1;                 /* '<S271>/IPC Read' */
  uint32_T Data[2];                    /* '<S265>/Data' */
  uint32_T Data_f[2];                  /* '<S266>/Data' */
  uint32_T Data_fw[2];                 /* '<S267>/Data' */
  uint32_T DataTypeConversion3;        /* '<S353>/Data Type Conversion3' */
  uint32_T Sum[4];                     /* '<S159>/Sum' */
  real32_T Delay5[4];                  /* '<Root>/Delay5' */
  real32_T RateTransition4;            /* '<S2>/Rate Transition4' */
  real32_T RT2[2];                     /* '<S2>/RT2' */
  real32_T SpeedRef;                   /* '<S2>/Rate Transition2' */
  real32_T TmpSignalConversionAtDelay5Inpo[4];
  real32_T RT1;                        /* '<S2>/RT1' */
  real32_T RT3;                        /* '<S7>/RT3' */
  real32_T RT3_g;                      /* '<S2>/RT3' */
  real32_T GetADCVoltage[2];           /* '<S278>/Get ADC Voltage' */
  real32_T GetCurrents[2];             /* '<S278>/Get Currents' */
  real32_T PU_Conversion[2];           /* '<S278>/PU_Conversion' */
  real32_T Merge[2];                   /* '<S276>/Merge' */
  real32_T Switch1[2];                 /* '<S285>/Switch1' */
  real32_T Product[4];                 /* '<S288>/Product' */
  real32_T UnitDelay[4];               /* '<S288>/Unit Delay' */
  real32_T Product1[4];                /* '<S288>/Product1' */
  real32_T Add1[4];                    /* '<S288>/Add1' */
  real32_T Sum6[4];                    /* '<S281>/Sum6' */
  real32_T Product_b;                  /* '<S311>/Product' */
  real32_T Sum3;                       /* '<S308>/Sum3' */
  real32_T Delay1;                     /* '<S310>/Delay1' */
  real32_T Sum_j;                      /* '<S310>/Sum' */
  real32_T Product_h;                  /* '<S310>/Product' */
  real32_T Delay_o;                    /* '<S310>/Delay' */
  real32_T Product1_l;                 /* '<S310>/Product1' */
  real32_T Sum1;                       /* '<S310>/Sum1' */
  real32_T Product2;                   /* '<S311>/Product2' */
  real32_T Sum1_m;                     /* '<S308>/Sum1' */
  real32_T Sum_h;                      /* '<S309>/Sum' */
  real32_T Switch1_b[2];               /* '<S309>/Switch1' */
  real32_T Product_o;                  /* '<S314>/Product' */
  real32_T UnitDelay_b;                /* '<S314>/Unit Delay' */
  real32_T Product1_ls;                /* '<S314>/Product1' */
  real32_T Add1_o;                     /* '<S314>/Add1' */
  real32_T Switch;                     /* '<S307>/Switch' */
  real32_T Product_d;                  /* '<S303>/Product' */
  real32_T Sum3_h;                     /* '<S300>/Sum3' */
  real32_T Delay1_e;                   /* '<S302>/Delay1' */
  real32_T Sum_c;                      /* '<S302>/Sum' */
  real32_T Product_h3;                 /* '<S302>/Product' */
  real32_T Delay_h;                    /* '<S302>/Delay' */
  real32_T Product1_f;                 /* '<S302>/Product1' */
  real32_T Sum1_h;                     /* '<S302>/Sum1' */
  real32_T Product2_k;                 /* '<S303>/Product2' */
  real32_T Sum1_l;                     /* '<S300>/Sum1' */
  real32_T Sum_b;                      /* '<S301>/Sum' */
  real32_T Switch1_bo[2];              /* '<S301>/Switch1' */
  real32_T Product_oc;                 /* '<S306>/Product' */
  real32_T UnitDelay_c;                /* '<S306>/Unit Delay' */
  real32_T Product1_n;                 /* '<S306>/Product1' */
  real32_T Add1_p;                     /* '<S306>/Add1' */
  real32_T Switch_j;                   /* '<S299>/Switch' */
  real32_T DTC;                        /* '<S319>/DTC' */
  real32_T SpeedGain;                  /* '<S284>/SpeedGain' */
  real32_T Switch1_p[2];               /* '<S283>/Switch1' */
  real32_T Product_ob;                 /* '<S317>/Product' */
  real32_T UnitDelay_bz;               /* '<S317>/Unit Delay' */
  real32_T Product1_k;                 /* '<S317>/Product1' */
  real32_T Add1_j;                     /* '<S317>/Add1' */
  real32_T elect2mech;                 /* '<S279>/elect2mech' */
  real32_T Sum_jg;                     /* '<S313>/Sum' */
  real32_T Sum_g;                      /* '<S305>/Sum' */
  real32_T Atan2;                      /* '<S297>/Atan2' */
  real32_T Switch_f;                   /* '<S297>/Switch' */
  real32_T algDD;
  real32_T Gain;                       /* '<S298>/Gain' */
  real32_T Switch_b;                   /* '<S298>/Switch' */
  real32_T Bias;                       /* '<S298>/Bias' */
  real32_T UnitDelay1;                 /* '<S332>/Unit Delay1' */
  real32_T UnitDelay_cs;               /* '<S332>/Unit Delay' */
  real32_T a;                          /* '<S332>/a' */
  real32_T Delay_m;                    /* '<S322>/Delay' */
  real32_T Sum2;                       /* '<S322>/Sum2' */
  real32_T Sum3_o;                     /* '<S332>/Sum3' */
  real32_T b_invg;                     /* '<S332>/b_inv*g' */
  real32_T Delay1_d;                   /* '<S332>/Delay1' */
  real32_T Sum4;                       /* '<S332>/Sum4' */
  real32_T Switch1_f[2];               /* '<S324>/Switch1' */
  real32_T Product_l;                  /* '<S336>/Product' */
  real32_T UnitDelay_d;                /* '<S336>/Unit Delay' */
  real32_T Product1_j;                 /* '<S336>/Product1' */
  real32_T Add1_e;                     /* '<S336>/Add1' */
  real32_T UnitDelay1_g;               /* '<S333>/Unit Delay1' */
  real32_T UnitDelay_m;                /* '<S333>/Unit Delay' */
  real32_T a_l;                        /* '<S333>/a' */
  real32_T Delay_a;                    /* '<S323>/Delay' */
  real32_T Sum2_p;                     /* '<S323>/Sum2' */
  real32_T Sum3_l;                     /* '<S333>/Sum3' */
  real32_T b_invg_e;                   /* '<S333>/b_inv*g' */
  real32_T Delay1_o;                   /* '<S333>/Delay1' */
  real32_T Sum4_d;                     /* '<S333>/Sum4' */
  real32_T Switch1_a[2];               /* '<S325>/Switch1' */
  real32_T Product_f;                  /* '<S339>/Product' */
  real32_T UnitDelay_k;                /* '<S339>/Unit Delay' */
  real32_T Product1_d;                 /* '<S339>/Product1' */
  real32_T Add1_l;                     /* '<S339>/Add1' */
  real32_T Merge_h;                    /* '<S321>/Merge' */
  real32_T Merge1;                     /* '<S321>/Merge1' */
  real32_T Delay_g;                    /* '<S320>/Delay' */
  real32_T Sign;                       /* '<S322>/Sign' */
  real32_T Eta;                        /* '<S322>/Eta' */
  real32_T Sum_bb;                     /* '<S322>/Sum' */
  real32_T b;                          /* '<S322>/b' */
  real32_T a_i;                        /* '<S322>/a' */
  real32_T Sum1_k;                     /* '<S322>/Sum1' */
  real32_T Sign_n;                     /* '<S323>/Sign' */
  real32_T Eta_e;                      /* '<S323>/Eta' */
  real32_T Sum_bo;                     /* '<S323>/Sum' */
  real32_T b_j;                        /* '<S323>/b' */
  real32_T a_d;                        /* '<S323>/a' */
  real32_T Sum1_b;                     /* '<S323>/Sum1' */
  real32_T DTC_j;                      /* '<S344>/DTC' */
  real32_T SpeedGain_a;                /* '<S327>/SpeedGain' */
  real32_T Switch1_m[2];               /* '<S326>/Switch1' */
  real32_T Product_fr;                 /* '<S342>/Product' */
  real32_T UnitDelay_f;                /* '<S342>/Unit Delay' */
  real32_T Product1_p;                 /* '<S342>/Product1' */
  real32_T Add1_ey;                    /* '<S342>/Add1' */
  real32_T Product_h5;                 /* '<S328>/Product' */
  real32_T Product2_h;                 /* '<S328>/Product2' */
  real32_T Sum1_n;                     /* '<S328>/Sum1' */
  real32_T Product1_ns;                /* '<S328>/Product1' */
  real32_T Product3;                   /* '<S328>/Product3' */
  real32_T Sum2_c;                     /* '<S328>/Sum2' */
  real32_T Switch_g;                   /* '<S328>/Switch' */
  real32_T Atan2_o;                    /* '<S345>/Atan2' */
  real32_T Switch_e;                   /* '<S345>/Switch' */
  real32_T algDD_o;
  real32_T Gain_k;                     /* '<S346>/Gain' */
  real32_T Switch_k;                   /* '<S346>/Switch' */
  real32_T Bias_d;                     /* '<S346>/Bias' */
  real32_T Bias_l;                     /* '<S328>/Bias' */
  real32_T Merge_c;                    /* '<S272>/Merge' */
  real32_T RateLimiter;                /* '<S274>/Rate Limiter' */
  real32_T RateLimiter1;               /* '<S274>/Rate Limiter1' */
  real32_T Switch_bs;                  /* '<S251>/Switch' */
  real32_T id_Ld_Lq;                   /* '<S257>/Product1' */
  real32_T Add_b;                      /* '<S257>/Add' */
  real32_T Product3_m;                 /* '<S257>/Product3' */
  real32_T u_5_Pp;                     /* '<S257>/1_5_Pp' */
  real32_T IndexVector_m;              /* '<S253>/Index Vector' */
  real32_T Product_n;                  /* '<S257>/Product' */
  real32_T P_output;                   /* '<S257>/P_si2pu' */
  real32_T SCIReceive[4];              /* '<S352>/SCI Receive' */
  real32_T Abs;                        /* '<S16>/Abs' */
  real32_T Gain_f;                     /* '<S16>/Gain' */
  real32_T UnitDelay_kj;               /* '<S174>/Unit Delay' */
  real32_T Switch_eq;                  /* '<S16>/Switch' */
  real32_T Add_h;                      /* '<S175>/Add' */
  real32_T DataTypeConversion1;        /* '<S175>/Data Type Conversion1' */
  real32_T Add1_f;                     /* '<S175>/Add1' */
  real32_T Input;                      /* '<S176>/Input' */
  real32_T Ia;        /* '<S15>/BusConversion_InsertedFor_SCI_Tx_at_inport_0' */
  real32_T Speedfb;   /* '<S15>/BusConversion_InsertedFor_SCI_Tx_at_inport_0' */
  real32_T Pos_pu;    /* '<S15>/BusConversion_InsertedFor_SCI_Tx_at_inport_0' */
  real32_T Merge_m;                    /* '<S161>/Merge' */
  real32_T indexing;                   /* '<S159>/indexing' */
  real32_T Lookup[4];                  /* '<S159>/Lookup' */
  real32_T Sum3_lv;                    /* '<S160>/Sum3' */
  real32_T DataTypeConversion1_a;      /* '<S159>/Data Type Conversion1' */
  real32_T Sum2_d;                     /* '<S159>/Sum2' */
  real32_T Product_c;                  /* '<S160>/Product' */
  real32_T Sum4_n;                     /* '<S160>/Sum4' */
  real32_T Sum5;                       /* '<S160>/Sum5' */
  real32_T Product1_a;                 /* '<S160>/Product1' */
  real32_T Sum6_n;                     /* '<S160>/Sum6' */
  real32_T Sum_cj;                     /* '<S30>/Sum' */
  real32_T PProdOut;                   /* '<S142>/PProd Out' */
  real32_T UnitDelay_n;                /* '<S30>/Unit Delay' */
  real32_T Integrator;                 /* '<S137>/Integrator' */
  real32_T Sum_o;                      /* '<S146>/Sum' */
  real32_T Switch_c;                   /* '<S30>/Switch' */
  real32_T Sum_m;                      /* '<S29>/Sum' */
  real32_T PProdOut_d;                 /* '<S87>/PProd Out' */
  real32_T UnitDelay_j;                /* '<S29>/Unit Delay' */
  real32_T Integrator_a;               /* '<S82>/Integrator' */
  real32_T Sum_jx;                     /* '<S91>/Sum' */
  real32_T Switch_gl;                  /* '<S29>/Switch' */
  real32_T Switch_gt;                  /* '<S33>/Switch' */
  real32_T Product_m;                  /* '<S33>/Product' */
  real32_T Product_b4;                 /* '<S34>/Product' */
  real32_T Product1_m;                 /* '<S34>/Product1' */
  real32_T Sum1_bt;                    /* '<S34>/Sum1' */
  real32_T Merge_l[2];                 /* '<S28>/Merge' */
  real32_T DeadZone;                   /* '<S74>/DeadZone' */
  real32_T IProdOut;                   /* '<S79>/IProd Out' */
  real32_T Switch_i;                   /* '<S72>/Switch' */
  real32_T DeadZone_o;                 /* '<S129>/DeadZone' */
  real32_T IProdOut_m;                 /* '<S134>/IProd Out' */
  real32_T Switch_m;                   /* '<S127>/Switch' */
  real32_T one_by_two;                 /* '<S173>/one_by_two' */
  real32_T sqrt3_by_two;               /* '<S173>/sqrt3_by_two' */
  real32_T add_b;                      /* '<S173>/add_b' */
  real32_T add_c;                      /* '<S173>/add_c' */
  real32_T Max;                        /* '<S170>/Max' */
  real32_T Min;                        /* '<S170>/Min' */
  real32_T Add_j;                      /* '<S170>/Add' */
  real32_T one_by_two_i;               /* '<S170>/one_by_two' */
  real32_T Add1_m;                     /* '<S169>/Add1' */
  real32_T Add2;                       /* '<S169>/Add2' */
  real32_T Add3;                       /* '<S169>/Add3' */
  real32_T Gain_fq[3];                 /* '<S169>/Gain' */
  real32_T Gain_h[3];                  /* '<S19>/Gain' */
  real32_T PWM_Duty_Cycles[3];         /* '<S19>/Sum' */
  real32_T DataTypeConversion;         /* '<S19>/Data Type Conversion' */
  real32_T Convert_back;               /* '<S165>/Convert_back' */
  real32_T Convert_back_h;             /* '<S164>/Convert_back' */
  real32_T acos_e;                     /* '<S157>/acos' */
  real32_T bsin;                       /* '<S157>/bsin' */
  real32_T sum_Ds;                     /* '<S157>/sum_Ds' */
  real32_T bcos;                       /* '<S157>/bcos' */
  real32_T asin_j;                     /* '<S157>/asin' */
  real32_T sum_Qs;                     /* '<S157>/sum_Qs' */
  real32_T Switch_g1[2];               /* '<S158>/Switch' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  real32_T qcos;                       /* '<S155>/qcos' */
  real32_T dsin;                       /* '<S155>/dsin' */
  real32_T sum_beta;                   /* '<S155>/sum_beta' */
  real32_T dcos;                       /* '<S155>/dcos' */
  real32_T qsin;                       /* '<S155>/qsin' */
  real32_T sum_alpha;                  /* '<S155>/sum_alpha' */
  real32_T Switch_mw[2];               /* '<S156>/Switch' */
  real32_T algDD_o1_m;
  real32_T algDD_o2_b;
  real32_T Saturation;                 /* '<S144>/Saturation' */
  real32_T Abs_d;                      /* '<S29>/Abs' */
  real32_T Saturation_e;               /* '<S29>/Saturation' */
  real32_T Saturation_o;               /* '<S89>/Saturation' */
  real32_T Product_lc[2];              /* '<S35>/Product' */
  real32_T SquareRoot;                 /* '<S35>/Square Root' */
  real32_T Switch_b4;                  /* '<S35>/Switch' */
  real32_T Switch_id[2];               /* '<S32>/Switch' */
  real32_T Switch2;                    /* '<S42>/Switch2' */
  real32_T Product_m2;                 /* '<S41>/Product' */
  real32_T Sum_l;                      /* '<S41>/Sum' */
  real32_T Product2_k2;                /* '<S41>/Product2' */
  real32_T Merge_ld;                   /* '<S41>/Merge' */
  real32_T Gain_i;                     /* '<S41>/Gain' */
  real32_T Switch_mf;                  /* '<S42>/Switch' */
  real32_T Switch1_c;                  /* '<S43>/Switch1' */
  real32_T Sqrt;                       /* '<S43>/Sqrt' */
  real32_T Gain_d;                     /* '<S43>/Gain' */
  real32_T a_plus_2b;                  /* '<S27>/a_plus_2b' */
  real32_T one_by_sqrt3;               /* '<S27>/one_by_sqrt3' */
  real32_T algDD_o1_k;
  real32_T algDD_o2_d;
  real32_T DataStoreRead;              /* '<S1>/Data Store Read' */
  real32_T Abs_d3;                     /* '<S1>/Abs' */
  real32_T UnitDelay_jv;               /* '<S13>/Unit Delay' */
  real32_T Add_e;                      /* '<S13>/Add' */
  int32_T DataTypeConversion4;         /* '<S353>/Data Type Conversion4' */
  int32_T DataTypeConversion_f[2];     /* '<S275>/Data Type Conversion' */
  int32_T Add_p[2];                    /* '<S275>/Add' */
  int32_T SpeedCount;                  /* '<S284>/SpeedCount' */
  int32_T SpeedCount_g;                /* '<S327>/SpeedCount' */
  uint16_T DataStoreRead_o;            /* '<S275>/Data Store Read' */
  uint16_T DataStoreRead1;             /* '<S275>/Data Store Read1' */
  uint16_T ADC_A_IN0;                  /* '<S9>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S9>/ADC_B_IN0' */
  uint16_T Switch1_pj[3];              /* '<S251>/Switch1' */
  uint16_T Output;                     /* '<S264>/Output' */
  uint16_T DataStoreRead_g;            /* '<S6>/Data Store Read' */
  uint16_T FixPtSum1;                  /* '<S268>/FixPt Sum1' */
  uint16_T FixPtSwitch;                /* '<S269>/FixPt Switch' */
  uint16_T DataTypeConversion2;        /* '<S6>/Data Type Conversion2' */
  uint16_T Scale_to_PWM_Counter_PRD[3];/* '<S251>/Scale_to_PWM_Counter_PRD' */
  uint16_T IPCChannelNumberofbuffersused;/* '<S255>/IPC Write' */
  uint16_T Switch_kx;                  /* '<S242>/Switch' */
  uint16_T ADC;                        /* '<S240>/ADC' */
  uint16_T ADC1;                       /* '<S240>/ADC1' */
  uint16_T Divide;                     /* '<S241>/Divide' */
  uint16_T Divide1;                    /* '<S241>/Divide1' */
  uint16_T ForIterator;                /* '<S244>/For Iterator' */
  uint16_T ADC_A_IN0_h;                /* '<S244>/ADC_A_IN0' */
  uint16_T ADC_B_IN0_g;                /* '<S244>/ADC_B_IN0' */
  uint16_T Memory;                     /* '<S249>/Memory' */
  uint16_T Sum_k;                      /* '<S249>/Sum' */
  uint16_T Memory1;                    /* '<S249>/Memory1' */
  uint16_T Sum1_k5;                    /* '<S249>/Sum1' */
  uint16_T DataTypeConversion2_b;      /* '<S353>/Data Type Conversion2' */
  uint16_T BitwiseOperator;            /* '<S351>/Bitwise Operator' */
  uint16_T BitwiseOperator1;           /* '<S351>/Bitwise Operator1' */
  uint16_T ShiftArithmetic1;           /* '<S351>/Shift Arithmetic1' */
  uint16_T DataTypeConversion1_g;      /* '<S353>/Data Type Conversion1' */
  uint16_T IPCChannelNumberofbuffersused_d;/* '<S357>/IPC Write' */
  uint16_T IPCChannelNumberofbuffersused_c;/* '<S355>/IPC Write' */
  uint16_T Switch2_h;                  /* '<S16>/Switch2' */
  uint16_T Switch1_e;                  /* '<S33>/Switch1' */
  uint16_T DataTypeConversion_e;       /* '<S161>/Data Type Conversion' */
  uint16_T Get_Integer;                /* '<S159>/Get_Integer' */
  uint16_T DataTypeConversion_er;      /* '<S31>/Data Type Conversion' */
  uint16_T DataTypeConversion_c;       /* '<S41>/Data Type Conversion' */
  uint16_T Switch2_l;                  /* '<S1>/Switch2' */
  int16_T Switch_a;                    /* '<S329>/Switch' */
  int16_T WhileIterator;               /* '<S262>/While Iterator' */
  int16_T DataTypeConversion_j;        /* '<S175>/Data Type Conversion' */
  int16_T Convert_uint16;              /* '<S165>/Convert_uint16' */
  int16_T Convert_uint16_e;            /* '<S164>/Convert_uint16' */
  int16_T IPCRead_o2;                  /* '<S271>/IPC Read' */
  int16_T Switch1_ck;                  /* '<S72>/Switch1' */
  int16_T Switch2_k;                   /* '<S72>/Switch2' */
  int16_T Switch1_bk;                  /* '<S127>/Switch1' */
  int16_T Switch2_lt;                  /* '<S127>/Switch2' */
  boolean_T RateTransition1;           /* '<S2>/Rate Transition1' */
  boolean_T RT6;                       /* '<S2>/RT6' */
  boolean_T RT5;                       /* '<S2>/RT5' */
  boolean_T DataStoreRead1_p;          /* '<S279>/Data Store Read1' */
  boolean_T LogicalOperator;           /* '<S279>/Logical Operator' */
  boolean_T DataStoreRead1_d;          /* '<S280>/Data Store Read1' */
  boolean_T LogicalOperator_f;         /* '<S280>/Logical Operator' */
  boolean_T AlphaRelay;                /* '<S321>/AlphaRelay' */
  boolean_T BetaRelay;                 /* '<S321>/BetaRelay' */
  boolean_T LogicalOperator_k;         /* '<S329>/Logical Operator' */
  boolean_T DataStoreRead2;            /* '<S6>/Data Store Read2' */
  boolean_T NOT;                       /* '<S4>/NOT' */
  boolean_T DataTypeConversion3_o;     /* '<S351>/Data Type Conversion3' */
  boolean_T DataTypeConversion_l;      /* '<S16>/Data Type Conversion' */
  boolean_T NOT_p;                     /* '<S174>/NOT' */
  boolean_T Delay_l;                   /* '<S175>/Delay' */
  boolean_T Compare;                   /* '<S163>/Compare' */
  boolean_T LogicalOperator_n;         /* '<S30>/Logical Operator' */
  boolean_T LogicalOperator_h;         /* '<S29>/Logical Operator' */
  boolean_T RelationalOperator;        /* '<S72>/Relational Operator' */
  boolean_T fixforDTpropagationissue; /* '<S72>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1;
                                     /* '<S72>/fix for DT propagation issue1' */
  boolean_T Equal1;                    /* '<S72>/Equal1' */
  boolean_T AND3;                      /* '<S72>/AND3' */
  boolean_T RelationalOperator_d;      /* '<S127>/Relational Operator' */
  boolean_T fixforDTpropagationissue_m;
                                     /* '<S127>/fix for DT propagation issue' */
  boolean_T fixforDTpropagationissue1_a;
                                    /* '<S127>/fix for DT propagation issue1' */
  boolean_T Equal1_n;                  /* '<S127>/Equal1' */
  boolean_T AND3_h;                    /* '<S127>/AND3' */
  boolean_T RelationalOperator_b;      /* '<S31>/Relational Operator' */
  boolean_T Compare_m;                 /* '<S37>/Compare' */
  boolean_T Compare_h;                 /* '<S38>/Compare' */
  boolean_T LowerRelop1;               /* '<S42>/LowerRelop1' */
  boolean_T RelationalOperator_j;      /* '<S41>/Relational Operator' */
  boolean_T UpperRelop;                /* '<S42>/UpperRelop' */
  boolean_T DataTypeConversion_ev;     /* '<S1>/Data Type Conversion' */
  boolean_T DataStoreRead1_n;          /* '<S1>/Data Store Read1' */
  boolean_T AND;                       /* '<S1>/AND' */
  boolean_T NOT_j;                     /* '<S1>/NOT' */
  boolean_T Switch_mo;                 /* '<S13>/Switch' */
  rtB_SpeedControl_mcb_pmsm_foc_d SpeedControl;/* '<S2>/Speed Control' */
} BlockIO_mcb_pmsm_foc_dual_cpu1_;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  soc_blocks_IPCWrite_mcb_pmsm_fo obj; /* '<S255>/IPC Write' */
  soc_blocks_IPCWrite_mcb_pmsm_fo obj_j;/* '<S357>/IPC Write' */
  soc_blocks_IPCWrite_mcb_pmsm_fo obj_jw;/* '<S355>/IPC Write' */
  soc_blocks_IPCRead_mcb_pmsm_foc obj_f;/* '<S271>/IPC Read' */
  real32_T Delay5_DSTATE[4];           /* '<Root>/Delay5' */
  real32_T Delay1_DSTATE;              /* '<S310>/Delay1' */
  real32_T Delay_DSTATE;               /* '<S310>/Delay' */
  real32_T Delay1_DSTATE_o;            /* '<S302>/Delay1' */
  real32_T Delay_DSTATE_b;             /* '<S302>/Delay' */
  real32_T UnitDelay1_DSTATE;          /* '<S332>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_j;         /* '<S332>/Unit Delay' */
  real32_T Delay_DSTATE_h;             /* '<S322>/Delay' */
  real32_T Delay1_DSTATE_j;            /* '<S332>/Delay1' */
  real32_T UnitDelay_DSTATE_c;         /* '<S336>/Unit Delay' */
  real32_T UnitDelay1_DSTATE_n;        /* '<S333>/Unit Delay1' */
  real32_T UnitDelay_DSTATE_m;         /* '<S333>/Unit Delay' */
  real32_T Delay_DSTATE_k;             /* '<S323>/Delay' */
  real32_T Delay1_DSTATE_p;            /* '<S333>/Delay1' */
  real32_T UnitDelay_DSTATE_n;         /* '<S339>/Unit Delay' */
  real32_T Delay_DSTATE_a;             /* '<S320>/Delay' */
  real32_T UnitDelay_DSTATE_gl;        /* '<S342>/Unit Delay' */
  real32_T UnitDelay_DSTATE_f;         /* '<S174>/Unit Delay' */
  real32_T UnitDelay_DSTATE_cr;        /* '<S30>/Unit Delay' */
  real32_T Integrator_DSTATE;          /* '<S137>/Integrator' */
  real32_T UnitDelay_DSTATE_l;         /* '<S29>/Unit Delay' */
  real32_T Integrator_DSTATE_n;        /* '<S82>/Integrator' */
  real32_T UnitDelay_DSTATE_gv;        /* '<S13>/Unit Delay' */
  uint32_T Delay_DSTATE_g[40];         /* '<S327>/Delay' */
  volatile real32_T RateTransition4_Buffer[2];/* '<S2>/Rate Transition4' */
  volatile real32_T RT2_Buffer[4];     /* '<S2>/RT2' */
  volatile real32_T RateTransition2_1_Buffer[2];/* '<S2>/Rate Transition2' */
  volatile real32_T RT1_Buffer0;       /* '<S2>/RT1' */
  real32_T SpeedRef;                   /* '<Root>/Data Store Memory' */
  volatile real32_T RT3_Buffer[2];     /* '<S7>/RT3' */
  real32_T PrevY;                      /* '<S274>/Rate Limiter' */
  real32_T PrevY_i;                    /* '<S274>/Rate Limiter1' */
  real32_T Add_DWORK1;                 /* '<S13>/Add' */
  int32_T GroundingtheSPIclockfortheDRV83;
                             /* '<S8>/Grounding the SPI clockfor the DRV830x' */
  int32_T Add_DWORK1_e[2];             /* '<S275>/Add' */
  int32_T SpeedCount_DWORK1;           /* '<S284>/SpeedCount' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S251>/DRV830x Enable' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S5>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_j;    /* '<S242>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S242>/Digital Output1' */
  uint32_T Add_DWORK1_g;               /* '<S262>/Add' */
  uint32_T Sum_DWORK1[4];              /* '<S159>/Sum' */
  uint16_T Output_DSTATE;              /* '<S264>/Output' */
  volatile int16_T RateTransition4_ActiveBufIdx;/* '<S2>/Rate Transition4' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<S2>/RT2' */
  volatile int16_T RateTransition2_1_ActiveBufIdx;/* '<S2>/Rate Transition2' */
  volatile int16_T RT1_semaphoreTaken; /* '<S2>/RT1' */
  volatile int16_T RT3_ActiveBufIdx;   /* '<S7>/RT3' */
  uint16_T SignalSelect1;              /* '<Root>/Data Store Memory1' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory5' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory6' */
  uint16_T CircBufIdx;                 /* '<S284>/Delay' */
  uint16_T CircBufIdx_j;               /* '<S327>/Delay' */
  uint16_T Memory_PreviousInput;       /* '<S249>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S249>/Memory1' */
  boolean_T Delay_DSTATE_l;            /* '<S175>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S137>/Integrator' */
  int16_T Integrator_PrevResetState_e; /* '<S82>/Integrator' */
  uint16_T Integrator_IC_LOADING;      /* '<S137>/Integrator' */
  uint16_T Integrator_IC_LOADING_b;    /* '<S82>/Integrator' */
  volatile boolean_T RateTransition1_Buffer0;/* '<S2>/Rate Transition1' */
  boolean_T EnMtr2Ctrl;                /* '<Root>/Data Store Memory2' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  volatile boolean_T RT5_Buffer0;      /* '<S2>/RT5' */
  boolean_T AlphaRelay_Mode;           /* '<S321>/AlphaRelay' */
  boolean_T BetaRelay_Mode;            /* '<S321>/BetaRelay' */
  boolean_T objisempty;                /* '<S271>/IPC Read' */
  boolean_T objisempty_k;              /* '<S255>/IPC Write' */
  boolean_T objisempty_n;              /* '<S357>/IPC Write' */
  boolean_T objisempty_c;              /* '<S355>/IPC Write' */
  boolean_T EnableEnMtr2TrqCtrlafter2secdel;
                             /* '<S1>/Enable EnMtr2TrqCtrl after 2 sec delay' */
  rtDW_SpeedControl_mcb_pmsm_foc_ SpeedControl;/* '<S2>/Speed Control' */
} D_Work_mcb_pmsm_foc_dual_cpu1_f;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Delay1_Reset_ZCE;         /* '<S310>/Delay1' */
  ZCSigState Delay_Reset_ZCE;          /* '<S310>/Delay' */
  ZCSigState Delay1_Reset_ZCE_h;       /* '<S302>/Delay1' */
  ZCSigState Delay_Reset_ZCE_a;        /* '<S302>/Delay' */
  ZCSigState Delay_Reset_ZCE_h;        /* '<S322>/Delay' */
  ZCSigState Delay1_Reset_ZCE_n;       /* '<S332>/Delay1' */
  ZCSigState Delay_Reset_ZCE_l;        /* '<S323>/Delay' */
  ZCSigState Delay1_Reset_ZCE_p;       /* '<S333>/Delay1' */
  ZCSigState Delay_Reset_ZCE_n;        /* '<S320>/Delay' */
  ZCSigState Dir_Sense_Trig_ZCE;       /* '<S321>/Dir_Sense' */
} PrevZCSigStates_mcb_pmsm_foc_du;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S260>/Width' */
  const real32_T Ld_Port;              /* '<S258>/Gain' */
  const real32_T Switch;               /* '<S258>/Switch' */
  const real32_T Lq_Port;              /* '<S258>/Gain1' */
  const real32_T Switch1;              /* '<S258>/Switch1' */
  const real32_T FluxPM_Port;          /* '<S258>/Gain2' */
  const real32_T Switch2;              /* '<S258>/Switch2' */
  const real32_T Ld_Lq;                /* '<S257>/Subtract' */
} ConstBlockIO_mcb_pmsm_foc_dual_;

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: sine_table_values_Value
   * Referenced by: '<S159>/sine_table_values'
   */
  real32_T sine_table_values_Value[1002];
} ConstParam_mcb_pmsm_foc_dual_cp;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_dual_cpu1_ {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[4];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern BlockIO_mcb_pmsm_foc_dual_cpu1_ mcb_pmsm_foc_dual_cpu1_f28379_B;

/* Block states (default storage) */
extern D_Work_mcb_pmsm_foc_dual_cpu1_f mcb_pmsm_foc_dual_cpu1_f2_DWork;

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_mcb_pmsm_foc_du mcb_pmsm_foc_dua_PrevZCSigState;
extern const ConstBlockIO_mcb_pmsm_foc_dual_ mcb_pmsm_foc_dual_cpu1_f_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstParam_mcb_pmsm_foc_dual_cp mcb_pmsm_foc_dual_cpu1_f_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_dual_cpu1_f28379d_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_dual_cpu1_f28379d_initialize(void);
extern void mcb_pmsm_foc_dual_cpu1_f28379d_step0(void);/* Sample time: [5.0E-5s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu1_f28379d_step1(void);/* Sample time: [0.001s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu1_f28379d_step2(void);/* Sample time: [0.01s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu1_f28379d_step3(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_dual_cpu1_f28379d_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_dual_cpu1 *const mcb_pmsm_foc_dual_cpu1_f2837_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_dual_cpu1_f28379d_configure_interrupts (void);
  void mcb_pmsm_foc_dual_cpu1_f28379d_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

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
 * '<Root>' : 'mcb_pmsm_foc_dual_cpu1_f28379d'
 * '<S1>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Delay to start motor2'
 * '<S2>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm'
 * '<S3>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/HWI_SCIA_RX_INT'
 * '<S4>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init'
 * '<S5>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Heartbeat LED'
 * '<S6>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals'
 * '<S7>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Rate Limiter'
 * '<S8>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Resetting SPI clock drive'
 * '<S9>'   : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensor Driver Blocks '
 * '<S10>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm'
 * '<S11>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive'
 * '<S12>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Delay to start motor2/Disable EnMtr2TrqCtrl'
 * '<S13>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Delay to start motor2/Enable EnMtr2TrqCtrl after 2 sec delay'
 * '<S14>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Delay to start motor2/Enable EnMtr2TrqCtrl after 2 sec delay/Enable EnMtr2TrqCtrl'
 * '<S15>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control'
 * '<S16>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Open_Loop_Control'
 * '<S17>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control'
 * '<S18>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop'
 * '<S19>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Output Scaling'
 * '<S20>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Clarke Transform'
 * '<S21>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers'
 * '<S22>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Inverse Park Transform'
 * '<S23>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Park Transform'
 * '<S24>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup'
 * '<S25>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator'
 * '<S26>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Clarke Transform/Two phase input'
 * '<S27>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S28>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter'
 * '<S29>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id'
 * '<S30>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq'
 * '<S31>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S32>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority'
 * '<S33>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Inport//Dialog Selection'
 * '<S34>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S35>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S36>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S37>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant'
 * '<S38>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/Compare To Constant1'
 * '<S39>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs'
 * '<S40>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/flipInputs1'
 * '<S41>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter'
 * '<S42>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef1'
 * '<S43>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/limitRef2'
 * '<S44>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/DQ Limiter/D//Q Axis Priority/limiter/passThrough'
 * '<S45>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S46>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S47>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S48>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S49>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S50>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S51>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S52>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S53>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S54>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S55>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S56>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S57>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S58>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S59>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S60>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S61>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S62>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S63>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S64>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S65>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S66>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S67>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S68>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S69>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S70>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S71>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S72>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S73>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S74>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S75>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S76>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S77>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S78>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S79>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S80>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S81>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S82>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S83>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S84>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S85>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S86>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S87>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S88>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S89>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S90>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S91>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S92>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S93>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S94>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S95>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S96>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S97>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S98>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S99>'  : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S100>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S101>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S102>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S103>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S104>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S105>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S106>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S107>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S108>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S109>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S110>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S111>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S112>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S113>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S114>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S115>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S116>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S117>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S118>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S119>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S120>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S121>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S122>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S123>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S124>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S125>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S126>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S127>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S128>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S129>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S130>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S131>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S132>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S133>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S134>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S135>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S136>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S137>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S138>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S139>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S140>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S141>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S142>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S143>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S144>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S145>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S146>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S147>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S148>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S149>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S150>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S151>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S152>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S153>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S154>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S155>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL'
 * '<S156>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S157>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Park Transform/Two inputs CRL'
 * '<S158>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S159>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S160>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S161>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S162>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S163>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S164>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S165>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S166>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S167>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Modulation method'
 * '<S168>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Voltage Input'
 * '<S169>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM'
 * '<S170>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S171>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S172>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S173>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Current Control/Closed Loop/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Two phase input'
 * '<S174>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Open_Loop_Control/Position Generator'
 * '<S175>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Open_Loop_Control/Position Generator/Accumulate'
 * '<S176>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Open_Loop_Control/Position Generator/Accumulate/Subsystem'
 * '<S177>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed'
 * '<S178>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/Speed_Ref_Selector'
 * '<S179>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S180>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S181>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S182>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S183>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S184>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S185>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S186>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S187>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S188>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S189>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S190>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S191>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S192>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S193>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S194>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S195>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S196>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S197>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S198>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S199>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S200>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S201>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S202>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S203>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S204>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S205>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S206>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S207>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S208>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S209>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S210>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S211>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S212>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S213>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S214>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S215>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S216>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S217>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S218>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S219>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S220>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S221>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S222>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S223>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S224>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S225>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S226>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S227>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S228>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S229>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S230>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S231>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S232>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S233>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S234>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S235>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S236>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S237>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Foc  Algorithm/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S238>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/HWI_SCIA_RX_INT/ECSoC'
 * '<S239>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S240>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/ADC for inverter in cpu2'
 * '<S241>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset '
 * '<S242>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/DRV Enable'
 * '<S243>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Default ADC Offset'
 * '<S244>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset /For Iterator Subsystem'
 * '<S245>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem'
 * '<S246>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem1'
 * '<S247>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem2'
 * '<S248>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset /If Action Subsystem3'
 * '<S249>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Hardware Init/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S250>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/Enable Motor2'
 * '<S251>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/Inverter'
 * '<S252>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1'
 * '<S253>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission'
 * '<S254>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/Enable Motor2/Variant'
 * '<S255>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/Enable Motor2/Variant/CODEGEN'
 * '<S256>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1/Variant Subsystem'
 * '<S257>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort'
 * '<S258>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/PMSM Torque Estimator1/Variant Subsystem/Torque Estimator_LumpedParameters_InputPort/LumpedParams_InputPorts'
 * '<S259>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Conditioning_Tx'
 * '<S260>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging'
 * '<S261>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/IPC Receive1'
 * '<S262>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/While Iterator Subsystem'
 * '<S263>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Conditioning_Tx/Data_Type_Float'
 * '<S264>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging/Counter Limited'
 * '<S265>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging/Data'
 * '<S266>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging/End'
 * '<S267>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging/Start'
 * '<S268>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging/Counter Limited/Increment Real World'
 * '<S269>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S270>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/IPC Receive1/Variant'
 * '<S271>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Inverter Driver Peripherals/SCI Data Transmission/IPC Receive1/Variant/CODEGEN'
 * '<S272>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Rate Limiter/Slew Rate'
 * '<S273>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Rate Limiter/Slew Rate/Rate Limiter for FO'
 * '<S274>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Rate Limiter/Slew Rate/Rate Limiter for SMO'
 * '<S275>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate Phase Currents'
 * '<S276>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed'
 * '<S277>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate Phase Currents/Data_Type'
 * '<S278>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate Phase Currents/Data_Type/Data_Type_Float'
 * '<S279>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer'
 * '<S280>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer'
 * '<S281>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal'
 * '<S282>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer'
 * '<S283>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter'
 * '<S284>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Speed Measurement'
 * '<S285>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter'
 * '<S286>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter'
 * '<S287>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass'
 * '<S288>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/DC component removal/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S289>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2'
 * '<S290>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Data type Handling'
 * '<S291>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Flux Calculation'
 * '<S292>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/ParamBus'
 * '<S293>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/passthrough'
 * '<S294>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha'
 * '<S295>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta'
 * '<S296>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default'
 * '<S297>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2'
 * '<S298>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/Atan2/Default/atan2/Per Unit'
 * '<S299>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default'
 * '<S300>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc'
 * '<S301>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter'
 * '<S302>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Integrator'
 * '<S303>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/Scaling'
 * '<S304>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S305>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S306>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiAlpha/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S307>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default'
 * '<S308>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc'
 * '<S309>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter'
 * '<S310>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Integrator'
 * '<S311>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/Scaling'
 * '<S312>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter'
 * '<S313>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass'
 * '<S314>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Flux Observer/psiBeta/Default/FluxCalc/IIR Filter/IIR Filter/High-pass/IIR Low Pass Filter'
 * '<S315>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter'
 * '<S316>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S317>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S318>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle'
 * '<S319>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Flux Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S320>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer'
 * '<S321>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch'
 * '<S322>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est'
 * '<S323>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est'
 * '<S324>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha'
 * '<S325>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta'
 * '<S326>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter'
 * '<S327>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement'
 * '<S328>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation'
 * '<S329>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Dir_Sense'
 * '<S330>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem2'
 * '<S331>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Direction_Latch/Subsystem3'
 * '<S332>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ealpha_est/DisturbanceObserver'
 * '<S333>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Ebeta_est/DisturbanceObserver'
 * '<S334>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter'
 * '<S335>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass'
 * '<S336>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ealpha/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S337>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter'
 * '<S338>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass'
 * '<S339>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Filter_Ebeta/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S340>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter'
 * '<S341>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass'
 * '<S342>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S343>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle'
 * '<S344>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/Speed Measurement/DT_Handle/floating-point'
 * '<S345>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1'
 * '<S346>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Sensorless Algorithm/Calculate position and speed/Sliding Mode Observer/Sliding Mode Observer/angleCompensation/atan1/Per Unit'
 * '<S347>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Data Receive'
 * '<S348>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Data_Conditioning_Rx1'
 * '<S349>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Load Torque'
 * '<S350>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Signal Select'
 * '<S351>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/unParse'
 * '<S352>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Data Receive/Data_Type_Float'
 * '<S353>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Data_Conditioning_Rx1/Data_Type_Float'
 * '<S354>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Load Torque/Variant'
 * '<S355>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Load Torque/Variant/CODEGEN'
 * '<S356>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Signal Select/Variant'
 * '<S357>' : 'mcb_pmsm_foc_dual_cpu1_f28379d/Serial Receive/Signal Select/Variant/CODEGEN'
 */
#endif                                 /* mcb_pmsm_foc_dual_cpu1_f28379d_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
