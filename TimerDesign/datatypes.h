/*************************************************************************/
/*  File name: 	datatypes.h
 *
 *  Purpose:	Header file to have a definition for dataypes
 *              that clearly shows by name the datatypes including
 *              the size of the variables
 *
 *  Owner:  	Rangan
 *
 *  Department:   EE Engineering
 *
 *  Copyright (C) 2015 PES University
 *  All rights reserved.
 *
 *
 *  Version History:
 *  V1.0  10th Sept, 2019	Rangan 	  Initial version created
 */
/******************************************************************************/

#ifndef DATATYPES_H

#define DATATYPES_H

typedef enum
{
  FALSE,
  TRUE
} BOOL;

typedef unsigned char UCHAR;
//typedef signed char CHAR;

typedef unsigned char UBYTE;
typedef signed char BYTE;

typedef unsigned short int UINT16;
typedef signed short int INT16;

typedef unsigned long int UINT32;
typedef signed long int INT32;

typedef float FLOAT32;

typedef double FLOAT64;

#endif
