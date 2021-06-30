/****************************************************************************
* Title                 :   DMA  
* Filename              :   DMA.h
* Author                :   Mohamed Reda
* Origin Date           :   30/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            : header file for DMA driver contains Function Prototypes 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/

#ifndef NVIC_H_
#define NVIC_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"



/******************************************************************************
* Function Prototypes
*******************************************************************************/

uint8 u8DMA_StreamInit(void) ;
void vDMA_SetAddresses(uint32* Pu32SrcAdd, uint32* Pu32DstAdd, uint32 u32Size);
void vDMA_Enable(void) ;











#endif 