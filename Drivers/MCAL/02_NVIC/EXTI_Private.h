/****************************************************************************
* Title                 :   EXTI   
* Filename              :   EXTI_Private.h
* Author                :   Mohamed Reda
* Origin Date           :   16/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :Private header file for EXTI driver contains Registers address definitions 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/
#include "STD_TYPES.h"


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define EXTI_BASE_ADDRESSE 					0x40013C00
#define SYSCFG_BASE_ADDRESSE				0x40013800 

/******************************* EXTI Registers Addresses *****************************/
#define EXTI_IMR									(*((volatile uint32*)(EXTI_BASE_ADDRESSE+0x00)))
#define EXTI_EMR									(*((volatile uint32*)(EXTI_BASE_ADDRESSE+0x04)))
#define EXTI_RTSR									(*((volatile uint32*)(EXTI_BASE_ADDRESSE+0x08)))
#define EXTI_FTSR								  (*((volatile uint32*)(EXTI_BASE_ADDRESSE+0x0C)))
#define EXTI_SWIER							  (*((volatile uint32*)(EXTI_BASE_ADDRESSE+0x10)))
#define EXTI_PR							      (*((volatile uint32*)(EXTI_BASE_ADDRESSE+0x14)))
/******************************* SYSCFG Registers Addresses *****************************/
#define SYSCFG_EXTICR1						(*((volatile uint32*)(SYSCFG_BASE_ADDRESSE+0x08)))
#define SYSCFG_EXTICR2						(*((volatile uint32*)(SYSCFG_BASE_ADDRESSE+0x0C)))
#define SYSCFG_EXTICR3						(*((volatile uint32*)(SYSCFG_BASE_ADDRESSE+0x10)))
#define SYSCFG_EXTICR4						(*((volatile uint32*)(SYSCFG_BASE_ADDRESSE+0x14)))
	

				






#endif