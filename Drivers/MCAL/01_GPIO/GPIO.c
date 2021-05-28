/****************************************************************************
* Title                 :   GPIO   
* Filename              :   GPIO.c
* Author                :   Mohamed Reda
* Origin Date           :   28/05/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            : TODO:                                          
*                          
*                                                            
*                         
*****************************************************************************/
/******************************************************************************
* Includes
*******************************************************************************/	
#include "GPIO_Private.h"
#include "GPIO.h"




/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/
/******************************************************************************
* Function Definitions
*******************************************************************************/
void vGPIO_PinSetMode(uint8 Port_Name, uint8 Pin_Number, uint8 Mode)
{	
	switch(Port_Name)
	{
		case GPIOA: GPIOA_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOB: GPIOB_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOC: GPIOC_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOD: GPIOD_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOE: GPIOE_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOF: GPIOF_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOG: GPIOG_MODER |= (Mode << (2*Pin_Number)); break;
		case GPIOH: GPIOH_MODER |= (Mode << (2*Pin_Number)); break;		
		default: break;			
	}
}

void vGPIO_PinSetOutType(uint8 Port_Name, uint8 Pin_Number, uint8 Output_Type)
{
	switch (Port_Name)
	{	
			case GPIOA: GPIOA_MODER |=(Output_Type << (2*Pin_Number)); break;
		case GPIOB: GPIOB_OTYPER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOC: GPIOC_OTYPER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOD: GPIOD_OTYPER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOE: GPIOE_OTYPER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOF: GPIOF_OTYPER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOG: GPIOG_OTYPER |= (Output_Type << (2*Pin_Number)); break;
		case GPIOH: GPIOH_OTYPER |= (Output_Type << (2*Pin_Number)); break;		
		default: break;		
			
	}
	
	
}

void vGPIO_PinSetOutSpeed(uint8 Port_Name, uint8 Pin_Number, uint8 Speed)
{
	switch(Port_Name)
	{
		case GPIOA: GPIOA_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOB: GPIOB_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOC: GPIOC_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOD: GPIOD_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOE: GPIOE_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOF: GPIOF_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOG: GPIOG_OSPEEDR |= (Speed << (2*Pin_Number)); break;
		case GPIOH: GPIOH_OSPEEDR |= (Speed << (2*Pin_Number)); break;		
		default: break;			
	}
	
}

void vGPIO_PinSetPull_UP_DOWN(uint8 Port_Name, uint8 Pin_Number, uint8 Pull_Type)
{
 switch(Port_Name)
	{
		case GPIOA: GPIOA_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOB: GPIOB_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOC: GPIOC_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOD: GPIOD_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOE: GPIOE_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOF: GPIOF_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOG: GPIOG_PUPDR |= (Pull_Type << (2*Pin_Number)); break;
		case GPIOH: GPIOH_PUPDR |= (Pull_Type << (2*Pin_Number)); break;		
		default: break;			
	}
	
}

uint8 u8GPIO_PinReadData(uint8 Port_Name, uint8 Pin_Number)
{
	uint8 Read_Value=0; //store read bit 
	
	switch(Port_Name)
	{
		case GPIOA: Read_Value = (GPIOA_IDR &(1U<<Pin_Number)); break;
		case GPIOB: Read_Value = (GPIOB_IDR &(1U<<Pin_Number)); break;
		case GPIOC: Read_Value = (GPIOC_IDR &(1U<<Pin_Number)); break;
		case GPIOD: Read_Value = (GPIOD_IDR &(1U<<Pin_Number)); break;
		case GPIOE: Read_Value = (GPIOE_IDR &(1U<<Pin_Number)); break;
		case GPIOF: Read_Value = (GPIOF_IDR &(1U<<Pin_Number)); break;
		case GPIOG: Read_Value = (GPIOG_IDR &(1U<<Pin_Number)); break;
		case GPIOH: Read_Value = (GPIOH_IDR &(1U<<Pin_Number)); break;		
		default: break;			
	}
	return Read_Value;
}


void vGPIO_PinWriteData(uint8 Port_Name, uint8 Pin_Number, uint8 Value)
{
	if (Value ==1)
		{
			 switch(Port_Name)
				{
					case GPIOA: GPIOA_ODR |= (1U << Pin_Number); break;
					case GPIOB: GPIOB_ODR |= (1U << Pin_Number); break;
					case GPIOC: GPIOC_ODR |= (1U << Pin_Number); break;
					case GPIOD: GPIOD_ODR |= (1U << Pin_Number); break;
					case GPIOE: GPIOE_ODR |= (1U << Pin_Number); break;
					case GPIOF: GPIOF_ODR |= (1U << Pin_Number); break;
					case GPIOG: GPIOG_ODR |= (1U << Pin_Number); break;
					case GPIOH: GPIOH_ODR |= (1U << Pin_Number); break;		
					default: break;			
				}
		}
	else
	{
		switch(Port_Name)
				{
					case GPIOA: GPIOA_ODR &=~ (1U << Pin_Number); break;
					case GPIOB: GPIOB_ODR &=~ (1U << Pin_Number); break;
					case GPIOC: GPIOC_ODR &=~ (1U << Pin_Number); break;
					case GPIOD: GPIOD_ODR &=~ (1U << Pin_Number); break;
					case GPIOE: GPIOE_ODR &=~ (1U << Pin_Number); break;
					case GPIOF: GPIOF_ODR &=~ (1U << Pin_Number); break;
					case GPIOG: GPIOG_ODR &=~ (1U << Pin_Number); break;
					case GPIOH: GPIOH_ODR &=~ (1U << Pin_Number); break;		
					default: break;			
				}	
		
	}

}

void vGPIO_PinLock(uint8 Port_Name, uint8 Pin_Number)
{
	switch(Port_Name)
	{
		case GPIOA: 
				GPIOA_LCKR |= (1U << Pin_Number); 
				GPIOA_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOA_LCKR & (1U << GPIO_LCK_LCKK)));
				break;
		case GPIOB:
				GPIOB_LCKR |= (1U << Pin_Number); 
				GPIOB_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOB_LCKR & (1U << GPIO_LCK_LCKK)));	
				break;
		case GPIOC:
				GPIOC_LCKR |= (1U << Pin_Number); 
				GPIOC_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOC_LCKR & (1U << GPIO_LCK_LCKK)));			
				break;
		case GPIOD:  
			  GPIOD_LCKR |= (1U << Pin_Number); 
				GPIOD_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOD_LCKR & (1U << GPIO_LCK_LCKK)));
				break;
		case GPIOE:  
			  GPIOE_LCKR |= (1U << Pin_Number); 
				GPIOE_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOE_LCKR & (1U << GPIO_LCK_LCKK)));
				break;
		case GPIOF:  
			  GPIOF_LCKR |= (1U << Pin_Number); 
				GPIOF_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOF_LCKR & (1U << GPIO_LCK_LCKK)));
				break;
		case GPIOG:  
			  GPIOG_LCKR |= (1U << Pin_Number); 
				GPIOG_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOG_LCKR & (1U << GPIO_LCK_LCKK)));
				break;
		case GPIOH:  
			  GPIOH_LCKR |= (1U << Pin_Number); 
				GPIOH_LCKR |= (1U << GPIO_LCK_LCKK);
				while(!(GPIOH_LCKR & (1U << GPIO_LCK_LCKK)));
				break;		
		default: break;			
	}
	
}


void vGPIO_PinSetAltFn(uint8 Port_Name, uint8 Pin_Number, uint8 Alt_Value)
{
	/* From Pin0 to Pin7 */
	if(Pin_Number <=7)
	{
		switch(Port_Name)
		{
			case GPIOA: GPIOA_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOB: GPIOB_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOC: GPIOC_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOD: GPIOD_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOE: GPIOE_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOF: GPIOF_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOG: GPIOG_AFRL |= (Alt_Value << (4*Pin_Number)); break;
			case GPIOH: GPIOH_AFRL |= (Alt_Value << (4*Pin_Number)); break;		
			default: break;			
		}
		
	}
	/* From Pin8 to Pin15 */
	else
	{
		switch(Port_Name)
		{
			case GPIOA: GPIOA_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOB: GPIOB_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOC: GPIOC_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOD: GPIOD_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOE: GPIOE_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOF: GPIOF_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOG: GPIOG_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;
			case GPIOH: GPIOH_AFRH |= (Alt_Value << (4*(Pin_Number % 8))); break;		
			default: break;			
		}
		
		
	}
	
	
	
}


/*************** END OF FUNCTIONS ***************************************************************************/