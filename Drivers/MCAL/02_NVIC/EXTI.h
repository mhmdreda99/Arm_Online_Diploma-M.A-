/****************************************************************************
* Title                 :   EXTI   
* Filename              :   EXTI.h
* Author                :   Mohamed Reda
* Origin Date           :   16/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            : header file for EXTI driver contains Function Prototypes 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/
#ifndef EXTI_H_
#define EXTI_H_

#include "STD_TYPES.h"
#include "STD_MACROS.h"

#define RiSING_EVENT 0
#define FALLING_EVENT 1

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void vEXTI_Enable(uint8 u8Line_num); //not masked
void vEXTI_Disable(uint8 u8Line_num); //  masked 
void vEXTI_EventType(uint8 u8Line_num , uint8 u8EventType );
void vEXTI_SWTrigger(uint8 u8Line_num);
void vEXTI_SetPort(uint8 u8Line_num , uint8 Port_ID ); 

#endif 