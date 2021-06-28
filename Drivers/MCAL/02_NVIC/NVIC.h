/****************************************************************************
* Title                 :   NVIC   
* Filename              :   NVIC.h
* Author                :   Mohamed Reda
* Origin Date           :   14/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            : header file for NVIC driver contains Function Prototypes 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/


#ifndef NVIC_H_
#define NVIC_H_

#include "STD_TYPES.h"



/******************************************************************************
* Function Prototypes
*******************************************************************************/
void vNVIC_SetEnable(uint8 u8Intrupt_num);
void vNVIC_ClearEnable(uint8 u8Intrupt_num);
void vNVIC_SetPending(uint8 u8Intrupt_num);
void vNVIC_ClearPending(uint8 u8Intrupt_num);
uint8 u8NVIC_GetActiveFlag(uint8 u8Intrupt_num);

void vNVIC_setIPR(uint8 u8Intrupt_num ,uint8 u8Group_PRI,uint8 u8SubGroup_PRI ,uint8 u8GROUPPRI_CFG);

#endif