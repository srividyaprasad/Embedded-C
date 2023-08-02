#include "io430.h"
#include "hal_timer.h"
#include <stdio.h>

void AppCB_500ms(UBYTE timerId_in);
void AppCB_800ms(UBYTE timerId_in);

void main()
{
  P1DIR |= BIT0; // P1.0 is output
  P1OUT |= BIT0; // P1.0 = 1
  // P1.4 - Outputs as SMCLK for testing
  P1DIR |= BIT4;
  P1SEL |= BIT4;
  P1SEL2 &= ~BIT4;
  
  hal_timerInit();
  // Global interrupt Enable
  __bis_SR_register(GIE);
  
  // create Periodic Timer for 500ms
  BYTE timerId1 = hal_createTimer(TRUE, 500, AppCB_500ms);
  BYTE timerId2 = hal_createTimer(TRUE, 800, AppCB_800ms);

  hal_startTimer(timerId1);
  hal_startTimer(timerId2);
  
  while(1)
  {
    hal_processTimers();
  }
}

void AppCB_500ms(UBYTE timerId_in)
{
  printf("AppCB_500ms()\n");
}

void AppCB_800ms(UBYTE timerId_in)
{
  printf("AppCB_800ms()\n");
  
}
