/****************************************************************************
* Title                 :   DMA  
* Filename              :   DMA_Private.h
* Author                :   Mohamed Reda
* Origin Date           :   30/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :Private header file for DMA driver contains Registers address definitions
*						 and enums and preprocessors 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/
// GUARD 
#ifndef DMA_PRIVATE_H_
#define DMA_PRIVATE_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/
typedef struct
{
	volatile uint32 CR;
	volatile uint32 NDTR;
	volatile uint32 PAR;
	volatile uint32 M0AR;
	volatile uint32 M1AR;
	volatile uint32 FCR;
}DMA_Stream_t;

typedef struct
{
	volatile uint32 LISR;
	volatile uint32 HISR;
	volatile uint32 LIFCR;
	volatile uint32 HIFCR;
	DMA_Stream_t StreamID[8];
}DMA_Cfg_t;


/******************************************************************************
* Configuration Constants
*******************************************************************************/
// Base Address for DMA2 0x4002 6400 
// pointer to structre of type DMA_Cfg_t 
#define DMA_Instant         ((volatile DMA_Cfg_t *) 0x40026400 ) 

#endif