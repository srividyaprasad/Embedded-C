/*************************************************************************/
/*  File name: 	main.c
*
*  Purpose:	Main application in which the end user can invoke the
*              services provided to get RPM, Pulse per second, Speed
*              using the Hall Sensor and blink LED in ISR if required.
*
*  Owner:  	Srividya Prasad, Siddharth D Srinivas, Gaurav Sai Palasari
*
*  Department:   ECE, ECE, EEE
*
*  Version History:
*  V4.0  30 July, 2023        Final version created
*/
/******************************************************************************/

#include "hal.h"
#include "io430.h"
#include <stdio.h>

void AppCB();

/********************************************

  Name: main
  Parameters: None
  Return: None
  Description: The main application of the program. Initializes the LED and Hall effect sensor, sets the wheel diameter,
              enables global interrupts, and sets the callback function for Hall effect sensor events.
              Enters an infinite loop to process the Hall effect sensor and display the output continuously.*/
                
void main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  //LED port is 0 set in drv 
  //Hall Sensor port is 3 set in drv
  hal_initialise();
  
  hal_setWheelDiameter(0.06); // Set the diameter in metres.
  
  __enable_interrupt(); // Enable global interrupts
  
  hal_setCallback(AppCB);
  
  while (1)
  {
    hal_process();
    
    hal_printRPM();
    hal_printPPS();
    hal_printSpeed_mps();
    
    /* More usecases:

      if(getRPM()>120)
        printf("Speed limit exceeded.");

      printf("Speed in kmph: %f", hal_getSpeed_mps()*3.6); */
  }
}

/*************************************

  Name: AppCB
  Parameters: None
  Return: None
  Description: Callback function called by the Hall effect sensor interrupt. Blinks the LED.*/

void AppCB()
{
  // Blink the LED
  hal_blinkLED();  
}
