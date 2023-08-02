/*************************************************************************/
/*  File name: 	hal.c
*
*  Purpose:	Hardware Abstraction Layer where the services are
*              defined, acting as an interface between Hardware 
*              Driver Layer and Application.
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
#include "drv.h"

static volatile UINT16 pulse_count = 0; // Number of pulses detected by the hall sensor and updated with interrupts
static UINT16 rpm = 0; // Calculated RPM (Revolutions Per Minute)
static FLOAT32 circumference; // Circumference of the wheel
static p_fCallback_t additional_CB; // Function pointer for additional callback function 

static void hal_ledInit();
static void hal_hallInit();
static void resetPulseCount();
static void incPulseCount();

/***********************************

  Name: hal_setWheelDia
  Parameters: float wd (wheel diameter in meters)
  Return: void
  Description: Sets the wheel diameter to calculate the circumference, required for speed calculations. */

void hal_setWheelDiameter(float wd)
{
  circumference = 3.14 * wd;
}

/***********************************

  Name: hal_ledInit
  Parameters: None
  Return: void
  Description: Initializes the LED module for controlling the status LED.*/


void hal_ledInit()
{
  drv_ledInit();
}

/***********************************

  Name: hal_hallInit
  Parameters: None
  Return: void
  Description: Initializes the hall sensor module to detect pulses from the sensor. */

void hal_hallInit()
{
  drv_hallInit();
}

/***********************************

  Name: hal_initialise()
  Parameters: None
  Return: void
  Description: Calls both initialise functions. */

void hal_initialise()
{
  hal_ledInit();
  hal_hallInit();
}

/***********************************

  Name: resetPulseCount
  Parameters: None
  Return: void
  Description: Resets the pulse count variable to zero, used to track the number of pulses from the hall sensor. */

void resetPulseCount()
{
  pulse_count = 0;   // Reset pulse count
}

/***********************************

Name: getPPS
Parameters: None
Return: UINT16 (Pulses Per Second)
Description: Calculates and returns the number of pulses detected per second based on the pulse count and sample period. */

UINT16 getPPS()
{
  // Calculate pulses/sec
  return (int)((float)pulse_count * 1000 / (SAMPLE_PERIOD*1000));
}

/***********************************

  Name: getRPM
  Parameters: None
  Return: UINT16 (Revolutions Per Minute)
  Description: Calculates and returns the RPM (Revolutions Per Minute) based on the pulse count and sample period. */

UINT16 getRPM()
{
  // Calculate RPM
  rpm = (int)((float)pulse_count * 60000 / (SAMPLE_PERIOD*1000));
  return rpm;
}

/***********************************

  Name: getSpeed_mps
  Parameters: None
  Return: FLOAT32 (Speed in meters per second)
  Description: Calculates and returns the speed of the wheel in meters per second using the circumference and RPM values. */

FLOAT32 getSpeed_mps()
{
  // Calculate Speed in m/s
  return ((circumference*rpm)/60);
}

/***********************************

  Name: hal_printRPM
  Parameters: None
  Return: void
  Description: Prints the RPM value to the console using printf. */

void hal_printRPM()
{
  printf("RPM: %d\n",getRPM()); 
}

/***********************************

  Name: hal_printPPS
  Parameters: None
  Return: void
  Description: Prints the PPS value to the console using printf. */

void hal_printPPS()
{
printf("PPS: %d\n",getPPS()); 
}

/***********************************

  Name: hal_printSpeed_mps
  Parameters: None
  Return: void
  Description: Prints the speed value in meters per second to the console using printf. */

void hal_printSpeed_mps()
{
  printf("Speed (m/s): %f\n",getSpeed_mps());
}

/***********************************

Name: hal_blinkLED
Parameters: None
Return: void
Description: Blinks the status LED using the LED driver module. */

void hal_blinkLED()
{
  drv_blinkLED();
}

/***********************************

  Name: incPulseCount
  Parameters: None
  Return: void
  Description: Increments the pulse count variable to keep track of detected pulses from the hall sensor. */

void incPulseCount()
{
  pulse_count++;
}

/***********************************

  Name: hal_process
  Parameters: None
  Return: void
  Description: Processes the hall sensor data by resetting the pulse count and waiting for the desired interval using a delay. */

void hal_process()
{
  #ifdef _DEBUG
  printf("Interval started.\n");
  #endif
  // Start interval measurement
  resetPulseCount();
  
  // Wait for the desired interval
  __delay_cycles(SAMPLE_PERIOD*1000000); // Interval cycles
  
  #ifdef _DEBUG
  printf("Interval ended.\n");
  #endif
}

/***********************************

  Name: hal_setCallback
  Parameters: p_fCallback_t p_fCallback_t_in (Function pointer to additional CB)
  Return: void
  Description: Sets an additional callback function related to the hall sensor,
  allowing customization of behavior when the sensor is triggered. */

void hal_setCallback(p_fCallback_t p_fCallback_t_in)
{
  additional_CB = p_fCallback_t_in;
}

/***********************************
  Name: hal_isr_hallsensorCB
  Parameters: None
  Return: void
  Description: Interrupt Service Routine (ISR) for the hall sensor callback.
  Calls the additional callback function, increments the pulse count. */

void hal_isr_hallsensorCB()
{
  #ifdef _DEBUG
  printf("Magnet detected.\n");
  #endif
  additional_CB();
  incPulseCount();
}
