/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI.c
* Author                :   Mohamed Reda
* Origin Date           :   1/07/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :Source file for SPI driver contains Function definitions
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/


/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include  "SPI.h"
#include  "SPI_Private.h"
#include  "SPI_Cfg.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Functions Definitions
*******************************************************************************/
void SPI_Init(
    uint8 u8SPI_Num,
    uint8 u8Device_MODE,
    uint8 u8CPOL,
    uint8 u8CPHA,
    uint8 u8Data_Size,
    uint8 u8Frame_Format,
    uint8 u8NSS_MODE, 
    uint8 u8BuadRate,
    uint8 u8BIDIRMODE
)
{
    switch(u8SPI_Num)
    {
        case SPI1:
        /* Configure the spi device mode */ 
        if (u8Device_MODE == SPI_MASTER_MODE)    {SET_BIT(SPI1_CR1_REG,MSTR) ;}
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI2_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI1_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI1_CR1_REG,CPOL)}
        
        if(u8CPHA)  { SET_BIT(SPI1_CR1_REG, CPHA) ; }
        else{ CLEAR_BIT(SPI1_CR1_REG,CPHA);}

        /* Configure the spi Data FRAME Size and Data FRAME Format  */
        if (u8Data_Size == DATASIZE_8 ) {CLEAR_BIT(SPI1_CR1_REG,DFF);}
        else if(u8Data_Size == DATASIZE_16){SET_BIT(SPI1_CR1_REG,DFF);}
        else {/*MISRA*/ }

        if(u8Frame_Format== FRAMEFORMAT_LSB) {SET_BIT(SPI1_CR1_REG,LSBFIRST);}
        else if(u8Frame_Format==FRAMEFORMAT_MSB){CLEAR_BIT(SPI1_CR1_REG,LSBFIRST);}
        else{/*MISRA*/}

        
        /* Configure the slave select line NSS Master and Slave*/
        if (u8Device_MODE == SPI_MASTER_MODE &&  u8NSS_MODE == NSS_MODE_SW )
        {
            SET_BIT(SPI1_CR1_REG,SSI);
            SET_BIT(SPI1_CR1_REG,SSM);
        }
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE =NSS_MODE_HW) {CLEAR_BIT(SPI1_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_SW ){SET_BIT(SPI1_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI1_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI1_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

/* Configure the SPI device direction */

        case SPI2: break ;
        case SPI3: break ;
        case SPI4: break ;
        case SPI5: break ;
        case SPI6: break ;

    }
}