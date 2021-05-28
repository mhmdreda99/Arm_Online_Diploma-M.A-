/****************************************************************************
* Title                 :   GPIO   
* Filename              :   GPIO.h
* Author                :   Mohamed Reda
* Origin Date           :   28/05/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            : Interface file forGPIO driver includes APIs' prototypes 
*                          And MACROS.                                          
*                          
*                                                            
*                         
*****************************************************************************/
#include "..\..\..\M.A_Diploma\STM32F42XXX_Device_Drivers\LIB\STD_TYPES.h"

#ifndef GPIO_H_
#define GPIO_H_
/**********************************Bits Definitions************************/
#define GPIO_LCK_LCKK      16


/******************************************************************************
* Macros
*******************************************************************************/
/**********************************GPIO MODES************************/
#define GPIO_INPUT_MODE  			  ((uint8)0x00)
#define GPIO_OUTPUT_MODE  			((uint8)0x01)
#define GPIO_ALTFN_MODE  			  ((uint8)0x10)
#define GPIO_ANALOG_MODE  			((uint8)0x1S1)

/**********************************GPIO OUTPUT TYPES MODES************************/
#define GPIO_OUTPUT_PUSHPULL  	((uint8)0x00)
#define GPIO_OUTPUT_OPDRAIN  	  ((uint8)0x01)

/**********************************GPIO SPEED MODES************************/
#define GPIO_OUTPUT_LSPEED			((uint8)0x00)
#define GPIO_OUTPUT_MSPEED     ((uint8)0x01)
#define GPIO_OUTPUT_HSPEED			((uint8)0x10)
#define GPIO_OUTPUT_VHSPEED			((uint8)0x11)
/**********************************PORTS Definitions************************/
#define GPIOA				0
#define GPIOB				1
#define GPIOC				2
#define GPIOD				3
#define GPIOE				4
#define GPIOF				5
#define GPIOG 		  6
#define GPIOH				7
/**********************************PINS Definitions************************/
#define PIN0 				0
#define PIN1 				1
#define PIN2 				2
#define PIN3 				3
#define PIN4 				4
#define PIN5 				5
#define PIN6 				6
#define PIN7 				7
#define PIN8 				8
#define PIN9 				9
#define PIN10				10
#define PIN11				11
#define PIN12				12
#define PIN13				13
#define PIN14				14
#define PIN15				15

/******************************************************************************
* Function Prototypes
*******************************************************************************/
void vGPIO_PinSetMode(uint8 Port_Name, uint8 Pin_Number, uint8 Mode);
void vGPIO_PinSetOutType(uint8 Port_Name, uint8 Pin_Number, uint8 Output_Type);
void vGPIO_PinSetOutSpeed(uint8 Port_Name, uint8 Pin_Number, uint8 Speed);
void vGPIO_PinSetPull_UP_DOWN(uint8 Port_Name, uint8 Pin_Number, uint8 Pull_Type);
uint8 u8GPIO_PinReadData(uint8 Port_Name, uint8 Pin_Number);
void vGPIO_PinWriteData(uint8 Port_Name, uint8 Pin_Number, uint8 Value);
void vGPIO_PinLock(uint8 Port_Name, uint8 Pin_Number);
void vGPIO_PinSetAltFn(uint8 Port_Name, uint8 Pin_Number, uint8 Alt_Value);


#endif