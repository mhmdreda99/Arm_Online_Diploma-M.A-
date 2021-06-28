/****************************************************************************
* Title                 :   NVIC   
* Filename              :   NVIC.c
* Author                :   Mohamed Reda
* Origin Date           :   14/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :Source file for NVIC driver contains Function definitions
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/

#include "NVIC.h"
#include "NVIC_Private.h"

void vNVIC_SetEnable(uint8 u8Intrupt_num)
{
	if (u8Intrupt_num<=31 )
	{
		NVIC_ISER0= (1U<<u8Intrupt_num);
	}
		else if(u8Intrupt_num <=63){							
		NVIC_ISER1=(1U<<(u8Intrupt_num%32));
	}

}

void vNVIC_ClearEnable(uint8 u8Intrupt_num)
{
	if (u8Intrupt_num<=31 )
	{
		NVIC_ICER0= (1U<<u8Intrupt_num);
	}
		else if(u8Intrupt_num <=63){							
		NVIC_ICER1=(1U<<(u8Intrupt_num%32));
	}


}

void vNVIC_SetPending(uint8 u8Intrupt_num)
{
		if (u8Intrupt_num<=31 )
	{
		NVIC_ISPR0= (1U<<u8Intrupt_num);
	}
		else if(u8Intrupt_num <=63){							
		NVIC_ISPR1=(1U<<(u8Intrupt_num%32));
	}
}
	
void vNVIC_ClearPending(uint8 u8Intrupt_num)
{
		if (u8Intrupt_num<=31 )
	{
		NVIC_ICPR0= (1U<<u8Intrupt_num);
	}
		else if(u8Intrupt_num <=63){							
		NVIC_ICPR1=(1U<<(u8Intrupt_num%32));
	}
}

uint8 u8NVIC_GetActiveFlag(uint8 u8Intrupt_num)
{
	uint8 u8ActiveState=0 ;
	
		if (u8Intrupt_num<=31 )
	{
		u8ActiveState= (NVIC_IABR0 & (1U<<u8Intrupt_num));
	}
		else if(u8Intrupt_num <=63){							
		u8ActiveState= (NVIC_IABR1 & (1U<<u8Intrupt_num));
	}
		return u8ActiveState;
	
}
void vNVIC_setIPR(uint8 u8Intrupt_num ,uint8 u8Group_PRI,uint8 u8SubGroup_PRI ,uint8 u8GROUPPRI_CFG)
{
	SCB_AIRCR =0x05FA0000; // key 
	switch (u8GROUPPRI_CFG)
		{
			
		case GROUPPRI_CFG0:
			//in case of (0b0xx) group --> 4 bits [7:4] & 	subgroup --> none
			SCB_AIRCR =0x05FA0300;
			NVIC_IPR[u8Intrupt_num]=(u8Group_PRI<<4U);
			break;
		case GROUPPRI_CFG1:
			//in case of (0b0100) group--> 3 bits [7:5] &  	subgroup --> 1 bit [4]
			SCB_AIRCR =0x05FA0400;
		  NVIC_IPR[u8Intrupt_num]=(u8Group_PRI<<5U)|(u8SubGroup_PRI<<4U);
			break;
		case GROUPPRI_CFG2:
			//in case of (0b0101) group--> 2 bits [7:6] &  	subgroup --> 2 bits [5:4]
			SCB_AIRCR =0x05FA0500;
		NVIC_IPR[u8Intrupt_num]=(u8Group_PRI<<6U)|(u8SubGroup_PRI<<4U);
		  break;
		case GROUPPRI_CFG3:
			//in case of (0b0110) group--> 1 bits [7]   &  	subgroup --> 3 bits [6:4]
			SCB_AIRCR =0x05FA0600;
		NVIC_IPR[u8Intrupt_num]=(u8Group_PRI<<7U)|(u8SubGroup_PRI<<4U);
			break;
		case GROUPPRI_CFG4:
			//in case of (0b0111) group--> None  & 	subgroup --> 4 bit [7:4]
			SCB_AIRCR =0x05FA0700;
		NVIC_IPR[u8Intrupt_num]=(u8SubGroup_PRI<<4U);
		  break;
		
		default: break ;
	 }		
	
			
/*
*	 Note that 
* Periority=xxyy 0000 
xx for GRP_PRI = may be take (00,10,01,11)
yy for Sub_PRI =	(00,10,01,11) 
* let we have a group = 01
*	 and a sub =11
*	 pRI=0111 0000
*	 
*	 so we need to shift sub by 4 and grp by 6
*
*/	 
}