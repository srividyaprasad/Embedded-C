#include "haltimer.h"
#include "drvtimer.h"

void timerCB()
{
  P1OUT^=BIT0; //
}
void hal_timerInit()
{
  drv_timerInit(timerCB);
}