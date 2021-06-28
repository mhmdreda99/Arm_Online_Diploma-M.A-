/****************************************************************************
* Title                 :   NVIC   
* Filename              :   EXTI.c
* Author                :   Mohamed Reda
* Origin Date           :   14/06/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :Source file for EXTI driver contains Function definitions
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/

#include "EXTI_Private.h"
#include "EXTI.h"


void vEXTI_Enable(uint8 u8Line_num) 
{
    SET_BIT(EXTI_IMR,u8Line_num);

} 
void vEXTI_Disable(uint8 u8Line_num)
{

    CLEAR_BIT(EXTI_IMR,u8Line_num);
} 

void vEXTI_EventType(uint8 u8Line_num , uint8 u8EventType )
{
    switch (u8EventType)
    {
        case RiSING_EVENT:
        SET_BIT(EXTI_RTSR,u8Line_num);
        
         break;
        case FALLING_EVENT:
        SET_BIT(EXTI_FTSR,u8Line_num);
         break;
        default: break;

    }
}

void vEXTI_SWTrigger(uint8 u8Line_num)
{
    SET_BIT(EXTI_SWIER, u8Line_num);
}

void vEXTI_SetPort(uint8 u8Line_num , uint8 Port_ID )
{
    if (u8Line_num<= 3)
    {
        SYSCFG_EXTICR1 &= ~((0x0F)<<(u8Line_num *4))
        SYSCFG_EXTICR1 |= ((Port_ID)<<(u8Line_num *4))

    }
    else if (u8Line_num<=7)
    {
        u8Line_num -=4;
        SYSCFG_EXTICR2 &= ~((0x0F)<<(u8Line_num *4))
        SYSCFG_EXTICR2 |= ((Port_ID)<<(u8Line_num *4))

    }
    else if (u8Line_num<=11)
    {
        u8Line_num -=8;
        SYSCFG_EXTICR3 &= ~((0x0F)<<(u8Line_num *4))
        SYSCFG_EXTICR3 |= ((Port_ID)<<(u8Line_num *4))

    }
    else if (u8Line_num<=15)
    {
        u8Line_num -=12;
        SYSCFG_EXTICR4 &= ~((0x0F)<<(u8Line_num *4))
        SYSCFG_EXTICR4 |= ((Port_ID)<<(u8Line_num *4))

    }
}