#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d_private.h"

extern void configureEpwmXBar(uint32_T xbar , uint32_T mux, uint32_T muxVal,
  uint32_T invert);
extern void configureSyncSocRegsInCPU2(uint32_T syncSelectVal , uint32_T
  syncSelectPosition);
void config_ePWM_GPIO (void)
{
  uint32_T *pulMsgRam = (void *)CPU01_TO_CPU02_PASSMSG;
  uint32_T ulRWord32 = 0;
  uint32_T gpioData = 0x00000000;
  EALLOW;

  // Provide ownership of clock configuration registers to CPU2
  ClkCfgRegs.CLKSEM.all = 0xA5A50001U;
  ClkCfgRegs.PERCLKDIVSEL.bit.EPWMCLKDIV = 1U;

  // Provide ownership of clock configuration registers back to CPU1
  ClkCfgRegs.CLKSEM.all = 0xA5A50000U;
  EDIS;
  EALLOW;

  /*-- Configure pin assignments for ePWM4 --*/
  gpioData = 0x00010000U;
  gpioData = gpioData|6U;
  gpioData = gpioData|(1U << 8U);
  gpioData = gpioData|(0U<<10U);

#ifdef MW_F2837XD

  IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
  while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
          IPC_FLAG31) != STATUS_PASS) {
  }

#else

  MW_IPC_sendCommand(IPC_CPU2_L_CPU1_R, (IPC_FLAG0 | IPC_FLAG31),
                     IPC_ADDR_CORRECTION_DISABLE, IPC_FUNC_CALL, pulMsgRam[0],
                     gpioData);
  IPC_waitForAck(IPC_CPU2_L_CPU1_R, IPC_FLAG31);
  IPC_getResponse(IPC_CPU2_L_CPU1_R);

#endif                                 //MW_F2837XD

  gpioData = 0x00010000U;
  gpioData = gpioData|7U;
  gpioData = gpioData|(1 << 8U);
  gpioData = gpioData|(0<<10U);
  IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
  while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
          IPC_FLAG31) != STATUS_PASS) {
  }

  /*-- Configure pin assignments for ePWM5 --*/
  gpioData = 0x00010000U;
  gpioData = gpioData|8U;
  gpioData = gpioData|(1U << 8U);
  gpioData = gpioData|(0U<<10U);

#ifdef MW_F2837XD

  IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
  while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
          IPC_FLAG31) != STATUS_PASS) {
  }

#else

  MW_IPC_sendCommand(IPC_CPU2_L_CPU1_R, (IPC_FLAG0 | IPC_FLAG31),
                     IPC_ADDR_CORRECTION_DISABLE, IPC_FUNC_CALL, pulMsgRam[0],
                     gpioData);
  IPC_waitForAck(IPC_CPU2_L_CPU1_R, IPC_FLAG31);
  IPC_getResponse(IPC_CPU2_L_CPU1_R);

#endif                                 //MW_F2837XD

  gpioData = 0x00010000U;
  gpioData = gpioData|9U;
  gpioData = gpioData|(1 << 8U);
  gpioData = gpioData|(0<<10U);
  IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
  while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
          IPC_FLAG31) != STATUS_PASS) {
  }

  /*-- Configure pin assignments for ePWM6 --*/
  gpioData = 0x00010000U;
  gpioData = gpioData|10U;
  gpioData = gpioData|(1U << 8U);
  gpioData = gpioData|(0U<<10U);

#ifdef MW_F2837XD

  IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
  while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
          IPC_FLAG31) != STATUS_PASS) {
  }

#else

  MW_IPC_sendCommand(IPC_CPU2_L_CPU1_R, (IPC_FLAG0 | IPC_FLAG31),
                     IPC_ADDR_CORRECTION_DISABLE, IPC_FUNC_CALL, pulMsgRam[0],
                     gpioData);
  IPC_waitForAck(IPC_CPU2_L_CPU1_R, IPC_FLAG31);
  IPC_getResponse(IPC_CPU2_L_CPU1_R);

#endif                                 //MW_F2837XD

  gpioData = 0x00010000U;
  gpioData = gpioData|11U;
  gpioData = gpioData|(1 << 8U);
  gpioData = gpioData|(0<<10U);
  IPCLiteLtoRFunctionCall(IPC_FLAG0, pulMsgRam[0], gpioData, IPC_FLAG31);
  while (IPCLiteLtoRGetResult(&ulRWord32,IPC_LENGTH_32_BITS,
          IPC_FLAG31) != STATUS_PASS) {
  }

  EDIS;
}

void config_ePWM_TBSync (void)
{
  /* Enable TBCLK within the EPWM*/
  EALLOW;

  /* Enable TBCLK after the ePWM configurations */
  CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1U;
  EDIS;
}

void config_ePWMSyncSource (void)
{
  /* Configuring EXTSYNCOUT source selection */
  EALLOW;
  configureSyncSocRegsInCPU2((uint32_T)0U , (uint32_T)9);

  /* Configuring ePWM Sync in source selection */
  configureSyncSocRegsInCPU2((uint32_T)0U , (uint32_T)0);
  configureSyncSocRegsInCPU2((uint32_T)0U , (uint32_T)1);
  configureSyncSocRegsInCPU2((uint32_T)0U , (uint32_T)2);
  EDIS;
}
