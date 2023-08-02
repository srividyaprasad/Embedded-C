#ifndef HAL_TIMER_H
#define HAL_TIMER_H
#include "datatypes.h"
  typedef void(* p_fTimerCallback_t)(UBYTE timerId);

  /***********************************
    Name: hal_timerInit()
    Parameters: None
    Return: None
    Description:
    This function will initialise for timer related
    functionality
  **/
  void hal_timerInit();

 /***********************************
    Name: hal_createTimer
    Parameters: 
      BOOL bPeriodic_in: 
        1: Periodic, 
        0: Single Shot 
      UINT16 uiTime_in: 
        Timer value in ms
    Return: 
      BYTE: Timer id of the timer created. 
      This id is to be used for other timer functions 
      as appropriate.
    
    Description:
      This function will only create the time by performing 
      all the initialisations needed in HAL. 
      The timer status will be INITIALISED. 
      Note: If the time elapsed cannot meet the exact timing, 
      it will be rounded up to nearest higher elapse possible. 
      Eg: If the request is 1024 ms and the basic timer tick 
      from driver is only 100ms, then the timer elapse met 
      will be rounded off to 1100ms */
  BYTE hal_createTimer(BOOL bPeriodic_in, UINT32 uiTime_in, 
                       p_fTimerCallback_t p_fTimerCallback_t_in);


  BYTE hal_startTimer(BYTE Timer_id_in);
  BYTE hal_stopTimer(BYTE Timer_id_in);
  void hal_processTimers();
#endif