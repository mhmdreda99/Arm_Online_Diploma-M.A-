/*******************************************************************************
* Title                 :   GPIO 
* Filename              :   GPIO_program.c
* Author                :   Mohamed Hafez
* Origin Date           :   10/8/2020
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None 
*
*
****************************************************************************/
/******************************************************************************
* Includes
*******************************************************************************/
#include "GPIO_Private.h"
#include "GPIO.h"
#include "..\..\..\M.A_Diploma\Drivers\RCC_FILES\RCC.h"

int main(void)
{
	//SETTING RCC CLOCK AND ENABLING GPIOG PERIPHERAL
	vRCC_SetSYSCLK(PLL, HSE_RC, PLL_HSI, AHB_Pre1, APB1_Pre1, APB2_Pre1); 
	vRCC_EnPerClk(AHB1, GPIOG);
	
	//Set Mode of PIN13 & PIN14 to output mode	
	vGPIO_PinSetMode(GPIOG,PIN13,GPIO_OUTPUT_MODE);	
	vGPIO_PinSetMode(GPIOG,PIN14,GPIO_OUTPUT_MODE);	
	
	//Set OUTPUT Type of PIN13 & PIN14 to PushPull
	vGPIO_PinSetOutType(GPIOG,PIN13,GPIO_OUTPUT_PUSHPULL);
	vGPIO_PinSetOutType(GPIOG,PIN14,GPIO_OUTPUT_PUSHPULL);
	
	//Set OUTPUT Speed of PIN13 & PIN14 to Low
	vGPIO_PinSetOutSpeed(GPIOG,PIN13,GPIO_OUTPUT_LSPEED);
	vGPIO_PinSetOutSpeed(GPIOG,PIN14,GPIO_OUTPUT_LSPEED);
	
	
	while(1)
	{
		vGPIO_PinWriteData(GPIOG,PIN13,1);
		vGPIO_PinWriteData(GPIOG,PIN14,1);
		for(int i=0; i<500000; i++);
		vGPIO_PinWriteData(GPIOG,PIN13,0);
		vGPIO_PinWriteData(GPIOG,PIN14,0);
		for(int i=0; i<500000; i++);
	}
	
	
}