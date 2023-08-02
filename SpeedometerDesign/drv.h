/*************************************************************************/
/*  File name: 	drv.h
*
*  Purpose:	Header file for the Hardware Driver.
*
*  Owner:  	Srividya Prasad, Siddharth D Srinivas, Gaurav Sai Palasari
*
*  Department:   ECE, ECE, EEE
*
*  Version History:
*  V4.0  30 July, 2023        Final version created
*/
/******************************************************************************/

#ifndef _DRV_H
#define _DRV_H

#include "datatypes.h"
#include "io430.h"

#define LED_PIN BIT0
#define HALL_SENSOR_PIN BIT3

void drv_ledInit();
void drv_hallInit();
void drv_blinkLED();

__interrupt void Port_1_ISR(void);

#endif