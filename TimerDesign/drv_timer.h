#ifndef _DRV_TIMER_H 
#define _DRV_TIMER_H

#include "datatypes.h"
typedef void (* pf_updateOnTick)();

void drv_timerInit(pf_updateOnTick p_fTimerUpdate);
UINT16 drv_getTimerTick_ms(void);
void simulateInterrupt();

#endif
