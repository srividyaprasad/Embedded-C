
#include "hal_timer.h"
#include "drv_timer.h"
#include "io430.h"
#include <stdio.h>

#define MAX_TIMERS 25

#define DEBUG   1

typedef struct {
  BOOL periodic;
  UINT32 count_Ticks;
  UINT32 cur_Count;
  BOOL running;
  p_fTimerCallback_t app_cb;
  BOOL used;
  BOOL timeElapsed;
} timer_t;

static timer_t timers[MAX_TIMERS];

static UBYTE timersActive;

void hal_processTimers()
{

  simulateInterrupt();
#ifdef DEBUG
    printf("hal_processTimers() enter\n");
#endif

  for (UBYTE i=0; i<MAX_TIMERS; i++)
  {
      if ((timers[i].used==TRUE) && (timers[i].timeElapsed==TRUE))
      {
          timers[i].timeElapsed = FALSE;
          timers[i].app_cb(i);
      }

  }
#ifdef DEBUG
    printf("hal_processTimers() exit\n");
#endif

}


void timerCB()
{

#ifdef DEBUG
    printf("timerCB() enter\n");
#endif
  P1OUT ^= BIT0; // Toggle P1.0 LED
  for (UBYTE i=0; i<MAX_TIMERS; i++)
  {
      if ( (timers[i].used==1) && (timers[i].running == 1))
      {
        if (timers[i].cur_Count == 0)
        {
          if (timers[i].periodic==TRUE)
            timers[i].cur_Count = timers[i].count_Ticks;
          else
            timers[i].running = FALSE;
        }
        else
        {
            timers[i].cur_Count--;
            if (timers[i].cur_Count == 0)
                timers[i].timeElapsed = TRUE;
        }
      } 
  }

#ifdef DEBUG
    printf("timerCB() exit\n");
#endif
}

void hal_timerInit()
{

#ifdef DEBUG
    printf("hal_timerInit() enter\n");
#endif
  drv_timerInit(timerCB);
#ifdef DEBUG
    printf("hal_timerInit() exit\n");
#endif

}

BYTE hal_createTimer(BOOL bPeriodic_in, UINT32 uiTime_in, 
                       p_fTimerCallback_t p_fTimerCallback_t_in)
{

#ifdef DEBUG
    printf("hal_createTimer() enter\n");
#endif

   BYTE timerId_out = 0;
   BYTE timerTick_ms = drv_getTimerTick_ms();
   BOOL timerAssigned = FALSE;
   
   if (timersActive <= MAX_TIMERS)
   {
     for (UBYTE i=0; (i<MAX_TIMERS)&&(timerAssigned ==FALSE); i++)
     {
          if (timers[i].used == FALSE)
          {  
             timers[i].used = TRUE;
             timers[i].periodic = bPeriodic_in;
             timers[i].cur_Count = uiTime_in/timerTick_ms;
             timers[i].count_Ticks = timers[i].cur_Count;
             timers[i].running = FALSE;
             timers[i].app_cb=p_fTimerCallback_t_in;
             timers[i].timeElapsed = FALSE;
             timerId_out = i;
             timerAssigned = TRUE;
          }
     }
   }

#ifdef DEBUG
    printf("hal_createTimer() exit\n");
#endif
    return(timerId_out);
}

BYTE hal_startTimer(BYTE Timer_id_in)
{

#ifdef DEBUG
    printf("hal_startTimer() enter\n");
#endif
  timers[Timer_id_in].running=TRUE;

#ifdef DEBUG
    printf("hal_startTimer() exit\n");
#endif
  return (1);
}

BYTE hal_stopTimer(BYTE Timer_id_in)
{

#ifdef DEBUG
    printf("hal_stopTimer() enter\n");
#endif
  timers[Timer_id_in].running=FALSE;
#ifdef DEBUG
    printf("hal_stopTimer() exit\n");
#endif

  return(1);
}