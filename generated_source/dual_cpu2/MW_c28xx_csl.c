#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d.h"
#include "mcb_pmsm_foc_dual_cpu2_f28379d_private.h"

extern void configureInputXBar(uint32_T gpioNumber, uint32_T inputXbarNumber);
void enableExtInterrupt (void);
void configureGPIOExtInterrupt(void);

#include <stdint.h>

void disableWatchdog(void)
{
  int *WatchdogWDCR = (int *)(uintptr_t)0x7029;
  asm(" EALLOW ");
  *WatchdogWDCR = 0x0068;
  asm(" EDIS ");
}
