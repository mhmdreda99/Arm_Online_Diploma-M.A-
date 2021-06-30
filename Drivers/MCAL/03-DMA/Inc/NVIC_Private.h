/****************************************************************************
* Title                 :   NVIC   
* Filename              :   NVIC_Private.h
* Author                :   Mohamed Reda
* Origin Date           :   14/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :Private header file for NVIC driver contains Registers address definitions 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/


#include "STD_TYPES.h"


#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define NVIC_BASE_ADDRESSE 					    0xE000E100
#define SCB_BASE_ADDRESSE						0xE000ED00

/******************************* Registers Addresses *****************************/
#define NVIC_ISER0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x100)))
#define NVIC_ISER1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x104)))
																			
#define NVIC_ICER0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x180)))
#define NVIC_ICER1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x184)))
																				
#define NVIC_ISPR0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x200)))
#define NVIC_ISPR1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x204)))
																				
#define NVIC_ICPR0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x280)))
#define NVIC_ICPR1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x284)))
																				
#define NVIC_IABR0									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x300)))
#define NVIC_IABR1									(*((volatile uint32*)(NVIC_BASE_ADDRESSE+0x304)))
																				
/* (IPR) interrupt priority register address definition (offset address of IPR ->0x400)                                           */
/* As the IPR register is 32 bits and divided into 4 bytes, each byte is responsible for specific interrupt                                                 */
/* so we cast this pointer to (u8) to be able to access each byte     */

#define NVIC_IPR										((volatile uint8*)(NVIC_BASE_ADDRESSE+0x400))  // we used NVIC_BASE_ADDRESSE as a address not a value casted to a pointer of u8 to access each byte

#define SCB_AIRCR									  (*(volatile uint32*) (SCB_BASE_ADDRESSE+0x0C))

#define GROUPPRI_CFG0 	0
#define GROUPPRI_CFG1 	1
#define GROUPPRI_CFG2 	2
#define GROUPPRI_CFG3 	3
#define GROUPPRI_CFG4 	4





#endif
