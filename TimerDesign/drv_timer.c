#include <io430.h>
#include "drv_timer.h"

//void drv_timer_init()
#define MS_COUNT        100

// 1MHz clock /2 => 0.5 MHz.
// Count for 100ms = 100ms/Clock Period
//                 = (100x10^-3)/(1/(0.5x10^6))
//                  = 100x1000/2
#define COUNT_VALUE     (MS_COUNT/2)*1000

static pf_updateOnTick isrTimerCB;

void drv_timerInit(pf_updateOnTick p_fTimerUpdate)
{
  // Setting DCO clock to 1MHz
  DCOCTL = CALDCO_1MHZ;
  BCSCTL1 = CALBC1_1MHZ;
  // Timer: Mode: Up, SMCLK, Division: /2
  TACTL = TACLR + TASSEL_2 + MC_1 + ID_1;
  // Count value for Timer interrupt
  CCR0 = COUNT_VALUE;
  CCTL0 = CCIE;
  isrTimerCB = p_fTimerUpdate;
}
UINT16 drv_getTimerTick_ms(void)
{
  return(MS_COUNT);
}

void simulateInterrupt()
{
  isrTimerCB();
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void BasicTimer_IRQHandler(void)
{
  isrTimerCB();
}


