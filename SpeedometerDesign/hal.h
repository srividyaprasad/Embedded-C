/*************************************************************************/
/*  File name: 	hal.h
*
*  Purpose:	Header file for the Hardware Abstraction Layer.
*               Constants used for application are set here.
*
*  Owner:  	Srividya Prasad, Siddharth D Srinivas, Gaurav Sai Palasari
*
*  Department:   ECE, ECE, EEE
*
*  Version History:
*  V4.0  30 July, 2023        Final version created
*/
/******************************************************************************/

#ifndef _HAL_H
#define _HAL_H

#include "datatypes.h"
#include <stdio.h>
#include "io430.h"

#define FREQUENCY 1000000 //1 MHz
#define SAMPLE_PERIOD 3 //3 sec

void hal_setWheelDiameter(float wd);
void hal_initialise();

UINT16 getPPS();
UINT16 getRPM();
FLOAT32 getSpeed_mps();

void hal_printRPM();
void hal_printPPS();
void hal_printSpeed_mps();

void hal_blinkLED();

void hal_process();

typedef void(* p_fCallback_t)();
void hal_setCallback(p_fCallback_t p_fCallback_t_in);

void hal_isr_hallsensorCB();

#endif

