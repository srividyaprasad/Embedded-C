/*************************************************************************/
/*  File name: 	drv.c
*
*  Purpose:	Hardware Driver Layer which defines ports, directly
*               interacts with the Hall Sensor, LED and Timer and
*               defines Interrupt Service Routines.
*
*  Owner:  	Srividya Prasad, Siddharth D Srinivas, Gaurav Sai Palasari
*
*  Department:   ECE, ECE, EEE
*
*  Version History:
*  V4.0  30 July, 2023        Final version created
*/
/******************************************************************************/

#include "drv.h"
#include "hal.h"

/*******************************************

  Name: drv_ledInit
  Parameters: None
  Return: None
  Description: Initializes the LED pin as an output and turns off the LED.*/

void drv_ledInit() 
{
  // Configure LED pin as output
  P1DIR |= LED_PIN;
  P1OUT &= ~LED_PIN;
}

/*******************************************

  Name: drv_hallInit
  Parameters: None
  Return: None
  Description: Initializes the Hall effect sensor pin as an input with 
  interrupt on rising edge.*/

void drv_hallInit()
{
  // Configure Hall effect sensor pin as input with interrupt
  P1DIR &= ~HALL_SENSOR_PIN;
  // P1IES |= HALL_SENSOR_PIN; // Interrupt on falling edge
  P1IES &= ~HALL_SENSOR_PIN; //Interrupt on rising edge 
  P1IE |= HALL_SENSOR_PIN;  // Enable interrupt for the pin
}

/*******************************************

  Name: drv_blinkLED
  Parameters: None
  Return: None
  Description: Toggles the state of the LED, creating a blinking effect.*/

void drv_blinkLED()
{
  P1OUT ^= LED_PIN; // Toggle the LED
  for(int i=0;i<=200;i++);
  P1OUT ^= LED_PIN; // Toggle the LED
}

/*******************************************

  Name: Port_1_ISR
  Parameters: None
  Return: None
  Description: Interrupt service routine for Port 1. Handles the interrupt
  from the Hall effect sensor pin, clears the interrupt flag, 
  and calls the hal_isr_hallsensorCB() function. */

// Port 1 interrupt service routine
#pragma vector = PORT1_VECTOR
__interrupt void Port_1_ISR(void)
{
  if (P1IFG & HALL_SENSOR_PIN) // Check if the interrupt is from the Hall effect sensor pin
  {
    P1IFG &= ~HALL_SENSOR_PIN; // Clear the interrupt flag
    
    hal_isr_hallsensorCB();
    // Handle the Hall effect sensor interrupt (if needed)
  }
}

