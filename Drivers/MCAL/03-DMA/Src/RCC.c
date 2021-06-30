 /******************************************************************************
 *
 * Layer: MCAL
 *
 * File Name: RCC.c
 *
 * Description: contains all the functions definations for RCC
 *
 * Author: Mina Armia
 *******************************************************************************/
#include "RCC.h"


void vRCC_SetSYSCLK(ClKSrcName_t ClkSrc, HSESrcName_t HSESRC, PLLSrcName_t PLLSrc, AHBPreName_t AHB_Prescaler, APB1PreName_t APB1_Prescaler, APB2PreName_t APB2_Prescaler)
{

	switch(ClkSrc)
	{
		//HSE
		case 0:
			switch(HSESRC)
			{
				//HSE_Crystal
				case 0: 
				RCC_CR |=(1U<<16); //Enable HSE
				RCC_CR &=~(1U<<18); // Disable BYP
				RCC_CFGR |=(1U<<0); // SYSCLK equal to HSE
				RCC_CFGR &=~(1U<<1);
				break; 
				//HSE_RC
				case 1: 
				RCC_CR |=(1U<<16); //Enable HSE
				RCC_CR |=(1U<<18); //Enable BYP
				RCC_CFGR |=(1U<<0); // SYSCLK equal to HSE
				RCC_CFGR &=~(1U<<1);
				break;
				default: break;
				
			}
		break;
		
		//HSI
		case 1:
			RCC_CR |=(1U<<0); //Enable HSI
			RCC_CFGR &=~(1U<<0); // SYSCLK equal to HSI
			RCC_CFGR &=~(1U<<1);
		break;
		
		//PLL
		case 2:
			switch(PLLSrc)
			{
				//PLL_HSE
				case 0: 
				RCC_CR |=(1U<<24); //Enable PLL
				RCC_CR |=(1U<<16); //Enable HSE
				RCC_PLLCFGR |=(1U<<22); //Select PLL source equal to HSE
				RCC_CFGR &=~(1U<<0); // SYSCLK equal to PLL
				RCC_CFGR |=(1U<<1);
				break;
				
				//PLL_HSI
				case 1: 
				RCC_CR |=(1U<<24); //Enable PLL
				RCC_CR &=~(1U<<16); //Enable HSI
				RCC_PLLCFGR &=~(1U<<22); //Select PLL source equal to HSI
				RCC_CFGR &=~(1U<<0); // SYSCLK equal to PLL
				RCC_CFGR |=(1U<<1);
				break;
				default: break;
			}
		break;
		default: break;
		
	}
	
	
	
	//Task Prescalers
	
}


void vRCC_EnPerClk(BusName_t BusName, uint8 PerName)
{
	switch(BusName)
	{
		//AHB1
		case 0: RCC_AHB1ENR |=(1U<<PerName); break;
		
		//AHB2
		case 1: RCC_AHB2ENR |=(1U<<PerName); break;
		
		//AHB3
		case 2: RCC_AHB3ENR |=(1U<<PerName); break;
		
		//APB1
		case 3: RCC_APB1ENR |=(1U<<PerName); break;
		
		//APB2
		case 4: RCC_APB2ENR |=(1U<<PerName); break;
		
		default:break;
			
	}
	
	
}