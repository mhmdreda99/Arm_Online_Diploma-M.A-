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
#include "SPI.h"
#include "STD_TYPES.h"
#include "STD_MACROS.h"
#include "SPI_Private.h"
#include "SPI_Cfg.h"

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
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI1_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI1_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI1_CR1_REG,CPOL);}
        
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
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE == NSS_MODE_HW) {CLEAR_BIT(SPI1_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_SW ){SET_BIT(SPI1_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI1_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI1_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

        /* TODO: Configure the SPI device direction */


        break ;/**********END OF CASE 1*****/
    
        case SPI2:
        /* Configure the spi device mode */ 
        if (u8Device_MODE == SPI_MASTER_MODE)    {SET_BIT(SPI2_CR1_REG,MSTR) ;}
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI2_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI2_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI2_CR1_REG,CPOL);}
        
        if(u8CPHA)  { SET_BIT(SPI2_CR1_REG, CPHA) ; }
        else{ CLEAR_BIT(SPI2_CR1_REG,CPHA);}

        /* Configure the spi Data FRAME Size and Data FRAME Format  */
        if (u8Data_Size == DATASIZE_8 ) {CLEAR_BIT(SPI2_CR1_REG,DFF);}
        else if(u8Data_Size == DATASIZE_16){SET_BIT(SPI2_CR1_REG,DFF);}
        else {/*MISRA*/ }

        if(u8Frame_Format== FRAMEFORMAT_LSB) {SET_BIT(SPI2_CR1_REG,LSBFIRST);}
        else if(u8Frame_Format==FRAMEFORMAT_MSB){CLEAR_BIT(SPI2_CR1_REG,LSBFIRST);}
        else{/*MISRA*/}

        
        /* Configure the slave select line NSS Master and Slave*/
        if (u8Device_MODE == SPI_MASTER_MODE &&  u8NSS_MODE == NSS_MODE_SW )
        {
            SET_BIT(SPI2_CR1_REG,SSI);
            SET_BIT(SPI2_CR1_REG,SSM);
        }
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE == NSS_MODE_HW) {CLEAR_BIT(SPI2_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_SW ){SET_BIT(SPI2_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI2_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI2_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

        /* TODO: Configure the SPI device direction */

          break ; /**********END OF CASE 2*****/
       
        case SPI3: 
        /* Configure the spi device mode */ 
        if (u8Device_MODE == SPI_MASTER_MODE)    {SET_BIT(SPI3_CR1_REG,MSTR) ;}
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI3_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI3_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI3_CR1_REG,CPOL);}
        
        if(u8CPHA)  { SET_BIT(SPI3_CR1_REG, CPHA) ; }
        else{ CLEAR_BIT(SPI3_CR1_REG,CPHA);}

        /* Configure the spi Data FRAME Size and Data FRAME Format  */
        if (u8Data_Size == DATASIZE_8 ) {CLEAR_BIT(SPI3_CR1_REG,DFF);}
        else if(u8Data_Size == DATASIZE_16){SET_BIT(SPI3_CR1_REG,DFF);}
        else {/*MISRA*/ }

        if(u8Frame_Format== FRAMEFORMAT_LSB) {SET_BIT(SPI3_CR1_REG,LSBFIRST);}
        else if(u8Frame_Format==FRAMEFORMAT_MSB){CLEAR_BIT(SPI3_CR1_REG,LSBFIRST);}
        else{/*MISRA*/}

        
        /* Configure the slave select line NSS Master and Slave*/
        if (u8Device_MODE == SPI_MASTER_MODE &&  u8NSS_MODE == NSS_MODE_SW )
        {
            SET_BIT(SPI3_CR1_REG,SSI);
            SET_BIT(SPI3_CR1_REG,SSM);
        }
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE == NSS_MODE_HW) {CLEAR_BIT(SPI3_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE  &&  u8NSS_MODE == NSS_MODE_SW){SET_BIT(SPI3_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE  &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI3_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI3_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

        /* TODO: Configure the SPI device direction */

        break ; /**********END OF CASE 3*****/
        
        case SPI4: 
        /* Configure the spi device mode */ 
        if (u8Device_MODE == SPI_MASTER_MODE)    {SET_BIT(SPI4_CR1_REG,MSTR) ;}
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI4_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI4_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI4_CR1_REG,CPOL);}
        
        if(u8CPHA)  { SET_BIT(SPI4_CR1_REG, CPHA) ; }
        else{ CLEAR_BIT(SPI4_CR1_REG,CPHA);}

        /* Configure the spi Data FRAME Size and Data FRAME Format  */
        if (u8Data_Size == DATASIZE_8 ) {CLEAR_BIT(SPI4_CR1_REG,DFF);}
        else if(u8Data_Size == DATASIZE_16){SET_BIT(SPI4_CR1_REG,DFF);}
        else {/*MISRA*/ }

        if(u8Frame_Format== FRAMEFORMAT_LSB) {SET_BIT(SPI4_CR1_REG,LSBFIRST);}
        else if(u8Frame_Format==FRAMEFORMAT_MSB){CLEAR_BIT(SPI4_CR1_REG,LSBFIRST);}
        else{/*MISRA*/}

        
        /* Configure the slave select line NSS Master and Slave*/
        if (u8Device_MODE == SPI_MASTER_MODE &&  u8NSS_MODE == NSS_MODE_SW )
        {
            SET_BIT(SPI4_CR1_REG,SSI);
            SET_BIT(SPI4_CR1_REG,SSM);
        }
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE == NSS_MODE_HW) {CLEAR_BIT(SPI4_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_SW ){SET_BIT(SPI4_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI4_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI4_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

        /* TODO: Configure the SPI device direction */
        
          break ; /**********END OF CASE 4*****/
        
        case SPI5:
        /* Configure the spi device mode */ 
        if (u8Device_MODE == SPI_MASTER_MODE)    {SET_BIT(SPI5_CR1_REG,MSTR) ;}
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI5_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI5_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI5_CR1_REG,CPOL);}
        
        if(u8CPHA)  { SET_BIT(SPI5_CR1_REG, CPHA) ; }
        else{ CLEAR_BIT(SPI5_CR1_REG,CPHA);}

        /* Configure the spi Data FRAME Size and Data FRAME Format  */
        if (u8Data_Size == DATASIZE_8 ) {CLEAR_BIT(SPI5_CR1_REG,DFF);}
        else if(u8Data_Size == DATASIZE_16){SET_BIT(SPI5_CR1_REG,DFF);}
        else {/*MISRA*/ }

        if(u8Frame_Format== FRAMEFORMAT_LSB) {SET_BIT(SPI5_CR1_REG,LSBFIRST);}
        else if(u8Frame_Format==FRAMEFORMAT_MSB){CLEAR_BIT(SPI5_CR1_REG,LSBFIRST);}
        else{/*MISRA*/}

        
        /* Configure the slave select line NSS Master and Slave*/
        if (u8Device_MODE == SPI_MASTER_MODE &&  u8NSS_MODE == NSS_MODE_SW )
        {
            SET_BIT(SPI5_CR1_REG,SSI);
            SET_BIT(SPI5_CR1_REG,SSM);
        }
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE == NSS_MODE_HW) {CLEAR_BIT(SPI5_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_SW ){SET_BIT(SPI5_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI5_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI5_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

        /* TODO: Configure the SPI device direction */
          break ; /**********END OF CASE 5*****/
        
        case SPI6:

        /* Configure the spi device mode */ 
        if (u8Device_MODE == SPI_MASTER_MODE)    {SET_BIT(SPI6_CR1_REG,MSTR) ;}
        else if (u8Device_MODE == SPI_SLAVE_MODE){CLEAR_BIT(SPI6_CR1_REG ,MSTR); }
        else { /*MISRA */}
        
        /*Configure CLOCK Polarity and Clock Phase */
        if(u8CPOL) { SET_BIT(SPI6_CR1_REG, CPOL) ; }
        else{ CLEAR_BIT(SPI6_CR1_REG,CPOL);}
        
        if(u8CPHA)  { SET_BIT(SPI6_CR1_REG, CPHA) ; }
        else{ CLEAR_BIT(SPI6_CR1_REG,CPHA);}

        /* Configure the spi Data FRAME Size and Data FRAME Format  */
        if (u8Data_Size == DATASIZE_8 ) {CLEAR_BIT(SPI6_CR1_REG,DFF);}
        else if(u8Data_Size == DATASIZE_16){SET_BIT(SPI6_CR1_REG,DFF);}
        else {/*MISRA*/ }

        if(u8Frame_Format== FRAMEFORMAT_LSB) {SET_BIT(SPI6_CR1_REG,LSBFIRST);}
        else if(u8Frame_Format==FRAMEFORMAT_MSB){CLEAR_BIT(SPI6_CR1_REG,LSBFIRST);}
        else{/*MISRA*/}

        
        /* Configure the slave select line NSS Master and Slave*/
        if (u8Device_MODE == SPI_MASTER_MODE &&  u8NSS_MODE == NSS_MODE_SW )
        {
            SET_BIT(SPI6_CR1_REG,SSI);
            SET_BIT(SPI6_CR1_REG,SSM);
        }
        else if (u8Device_MODE == SPI_MASTER_MODE && u8NSS_MODE == NSS_MODE_HW) {CLEAR_BIT(SPI6_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_SW ){SET_BIT(SPI6_CR1_REG,SSM);}
        else if (u8Device_MODE == SPI_SLAVE_MODE &&  u8NSS_MODE == NSS_MODE_HW ){CLEAR_BIT(SPI6_CR1_REG,SSM);}
        else{/*MISRA*/}

        /* Configure the  SPI deivce Baudrate */
        if (u8BuadRate <=7) {SPI6_CR1_REG |=(u8BuadRate<<3);} // the input value shifted by 3 bits
        else{/*MISRA*/}

        /* TODO: Configure the SPI device direction */
         
         
         break ; /**********END OF CASE 6*****/

        default:
        break;
    /*END OF SWITCH*/ 

    }
}
/**
 * @brief this function enable MCU SPI peripheral 
 * 
 * @param U8SPI_Num input the number os SPI to be used
 */
void SPI_Enable(uint8 U8SPI_Num) 
{
    switch(U8SPI_Num)
	{
		case SPI1: SET_BIT(SPI1_CR1_REG,SPE); break;
        case SPI2: SET_BIT(SPI2_CR1_REG,SPE); break;
        case SPI3: SET_BIT(SPI3_CR1_REG,SPE); break;
        case SPI4: SET_BIT(SPI4_CR1_REG,SPE); break;
        case SPI5: SET_BIT(SPI5_CR1_REG,SPE); break;
        case SPI6: SET_BIT(SPI6_CR1_REG,SPE); break;

	}
}
/**
 * @brief this function Disable MCU SPI peripheral 
 * 
 * @param U8SPI_Num input the number os SPI to be used 
 */
void SPI_Disable(uint8 U8SPI_Num)
{
        switch(U8SPI_Num)
	{
		case SPI1: CLEAR_BIT(SPI1_CR1_REG,SPE); break;
        case SPI2: CLEAR_BIT(SPI2_CR1_REG,SPE); break;
        case SPI3: CLEAR_BIT(SPI3_CR1_REG,SPE); break;
        case SPI4: CLEAR_BIT(SPI4_CR1_REG,SPE); break;
        case SPI5: CLEAR_BIT(SPI5_CR1_REG,SPE); break;
        case SPI6: CLEAR_BIT(SPI6_CR1_REG,SPE); break;

	}

}
/**
 * @brief 
 * 
 * @param u8SPI_Num 
 * @param u8DataOut 
 * @return uint8 
 */
uint8 u8SPI_Write8BitData(uint8 u8SPI_Num, uint8 u8DataOut)
{
    switch (u8SPI_Num)
    {
    case SPI1 :
     /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI1_CR1_REG,SPE)){SPI_Enable(SPI1);}
    
    /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI1_SR_REG,RXNE) | IS_BIT_SET(SPI1_SR_REG,TXE)==LOW || IS_BIT_SET(SPI1_SR_REG,BSY)) ;
     /* Fill output buffer with data */
	SPI1_DR_REG = u8DataOut;
    
    /* Wait for previous transmissions to complete */
	while(IS_BIT_SET(SPI1_SR_REG,RXNE) | IS_BIT_SET(SPI1_SR_REG,TXE)==LOW || IS_BIT_SET(SPI1_SR_REG,BSY)) ;
    /* Read data register */
	return(SPI1_DR_REG);
     break;

    case SPI2 :
       /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI2_CR1_REG,SPE)){SPI_Enable(SPI2);}
    
    /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI2_SR_REG,RXNE) | IS_BIT_SET(SPI2_SR_REG,TXE)==LOW || IS_BIT_SET(SPI2_SR_REG,BSY)) ;
     /* Fill output buffer with data */
	SPI2_DR_REG = u8DataOut;
    
    /* Wait for previous transmissions to complete */
	while(IS_BIT_SET(SPI2_SR_REG,RXNE) | IS_BIT_SET(SPI2_SR_REG,TXE)==LOW || IS_BIT_SET(SPI2_SR_REG,BSY)) ;
    /* Read data register */
	return(SPI2_DR_REG);
     break;
    
    case SPI3 :
       /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI3_CR1_REG,SPE)){SPI_Enable(SPI3);}
    
    /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI3_SR_REG,RXNE) | IS_BIT_SET(SPI3_SR_REG,TXE)==LOW || IS_BIT_SET(SPI3_SR_REG,BSY)) ;
     /* Fill output buffer with data */
	SPI3_DR_REG = u8DataOut;
    /* Wait for previous transmissions to complete */
	while(IS_BIT_SET(SPI3_SR_REG,RXNE) | IS_BIT_SET(SPI3_SR_REG,TXE)==LOW || IS_BIT_SET(SPI3_SR_REG,BSY)) ;
    /* Read data register */
	return(SPI3_DR_REG);
     break;

    case SPI4 :
       /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI4_CR1_REG,SPE)){SPI_Enable(SPI4);}
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI4_SR_REG,RXNE) | IS_BIT_SET(SPI4_SR_REG,TXE)==LOW || IS_BIT_SET(SPI4_SR_REG,BSY)) ;
     /* Fill output buffer with data */
	SPI4_DR_REG = u8DataOut;
        /* Wait for previous transmissions to complete */
	while(IS_BIT_SET(SPI4_SR_REG,RXNE) | IS_BIT_SET(SPI4_SR_REG,TXE)==LOW || IS_BIT_SET(SPI4_SR_REG,BSY)) ;
        /* Read data register */
	return(SPI4_DR_REG);
     break;
    
    case SPI5 :
       /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI5_CR1_REG,SPE)){SPI_Enable(SPI5);}
    /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI5_SR_REG,RXNE) | IS_BIT_SET(SPI5_SR_REG,TXE)==LOW || IS_BIT_SET(SPI5_SR_REG,BSY)) ;
    /* Fill output buffer with data */
	SPI5_DR_REG = u8DataOut;
    /* Wait for previous transmissions to complete */
	while(IS_BIT_SET(SPI5_SR_REG,RXNE) | IS_BIT_SET(SPI5_SR_REG,TXE)==LOW || IS_BIT_SET(SPI5_SR_REG,BSY)) ;
    /* Read data register */
	return(SPI5_DR_REG);
     break;
    
    case SPI6 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI6_CR1_REG,SPE)){SPI_Enable(SPI6);}
    /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI6_SR_REG,RXNE) | IS_BIT_SET(SPI6_SR_REG,TXE)==LOW || IS_BIT_SET(SPI6_SR_REG,BSY)) ;
    /* Fill output buffer with data */
	SPI6_DR_REG = u8DataOut;
    /* Wait for previous transmissions to complete */
	while(IS_BIT_SET(SPI6_SR_REG,RXNE) | IS_BIT_SET(SPI6_SR_REG,TXE)==LOW || IS_BIT_SET(SPI6_SR_REG,BSY)) ;
    /* Read data register */
	return(SPI6_DR_REG); 

     break;

    default:
        break;
    }/*END OF SWITCH*/

}/*END OF FUNCTION*/

/**
 * @brief 
 * 
 * @param u8SPI_Num 
 * @param u8DataOut 
 * @param u8DataIn 
 * @param u8Count 
 */
void vSPI_WriteMulti8BitData(uint8 u8SPI_Num, uint8 *u8DataOut, uint8 *u8DataIn, uint8 u8Count)
{
    uint8 index; // for loop index
    switch(u8SPI_Num)
    {
        case SPI1 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI1_CR1_REG,SPE)){SPI_Enable(SPI1);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI1_SR_REG,RXNE) | IS_BIT_SET(SPI1_SR_REG,TXE)==LOW || IS_BIT_SET(SPI1_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI1_DR_REG=u8DataOut[index];
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI1_SR_REG,RXNE) | IS_BIT_SET(SPI1_SR_REG,TXE)==LOW || IS_BIT_SET(SPI1_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI1_DR_REG ;
    }
     break; /**********END OF CASE 1*****/

        case SPI2 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI2_CR1_REG,SPE)){SPI_Enable(SPI2);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI2_SR_REG,RXNE) | IS_BIT_SET(SPI2_SR_REG,TXE)==LOW || IS_BIT_SET(SPI2_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI2_DR_REG=u8DataOut[index];
        /* Wait for  transmissions to complete */
    while(IS_BIT_SET(SPI2_SR_REG,RXNE) | IS_BIT_SET(SPI2_SR_REG,TXE)==LOW || IS_BIT_SET(SPI2_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI2_DR_REG ;
    }
     break; /**********END OF CASE 2*****/
        case SPI3 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI3_CR1_REG,SPE)){SPI_Enable(SPI3);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI3_SR_REG,RXNE) | IS_BIT_SET(SPI3_SR_REG,TXE)==LOW || IS_BIT_SET(SPI3_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI3_DR_REG=u8DataOut[index];
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI3_SR_REG,RXNE) | IS_BIT_SET(SPI3_SR_REG,TXE)==LOW || IS_BIT_SET(SPI3_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI3_DR_REG ;
    }
     break;/**********END OF CASE 3*****/
        case SPI4 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI4_CR1_REG,SPE)){SPI_Enable(SPI4);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI4_SR_REG,RXNE) | IS_BIT_SET(SPI4_SR_REG,TXE)==LOW || IS_BIT_SET(SPI4_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI4_DR_REG=u8DataOut[index];
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI4_SR_REG,RXNE) | IS_BIT_SET(SPI4_SR_REG,TXE)==LOW || IS_BIT_SET(SPI4_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI4_DR_REG ;
    }
     break;/**********END OF CASE 4*****/
        case SPI5 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI5_CR1_REG,SPE)){SPI_Enable(SPI5);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI5_SR_REG,RXNE) | IS_BIT_SET(SPI5_SR_REG,TXE)==LOW || IS_BIT_SET(SPI5_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI5_DR_REG=u8DataOut[index];
        /* Wait for previous transmissions to complete */
   while(IS_BIT_SET(SPI5_SR_REG,RXNE) | IS_BIT_SET(SPI5_SR_REG,TXE)==LOW || IS_BIT_SET(SPI5_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI5_DR_REG ;
    }
     break;/**********END OF CASE 5*****/
        case SPI6 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI6_CR1_REG,SPE)){SPI_Enable(SPI6);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI6_SR_REG,RXNE) | IS_BIT_SET(SPI6_SR_REG,TXE)==LOW || IS_BIT_SET(SPI6_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI6_DR_REG=u8DataOut[index];
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI6_SR_REG,RXNE) | IS_BIT_SET(SPI6_SR_REG,TXE)==LOW || IS_BIT_SET(SPI6_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI6_DR_REG ;
    }
     break;/**********END OF CASE 6*****/

    default:
        break;
    }/*END OF SWITCH*/

}/*END OF FUNCTION*/

/**
 * @brief 
 * 
 * @param u8SPI_Num 
 * @param u8DataIn 
 * @param u8dummy 
 * @param u8Count 
 */
void vSPI_ReadMulti8BitData(uint8 u8SPI_Num, uint8 *u8DataIn, uint8 u8dummy, uint8 u8Count)
{
    uint8 index; // for loop index
    switch(u8SPI_Num)
    {
        case SPI1 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI1_CR1_REG,SPE)){SPI_Enable(SPI1);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI1_SR_REG,RXNE) | IS_BIT_SET(SPI1_SR_REG,TXE)==LOW || IS_BIT_SET(SPI1_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI1_DR_REG=u8dummy;
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI1_SR_REG,RXNE) | IS_BIT_SET(SPI1_SR_REG,TXE)==LOW || IS_BIT_SET(SPI1_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI1_DR_REG ;
    }
     break; /**********END OF CASE 1*****/

        case SPI2 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI2_CR1_REG,SPE)){SPI_Enable(SPI2);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI2_SR_REG,RXNE) | IS_BIT_SET(SPI2_SR_REG,TXE)==LOW || IS_BIT_SET(SPI2_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI2_DR_REG=u8dummy;
        /* Wait for  transmissions to complete */
    while(IS_BIT_SET(SPI2_SR_REG,RXNE) | IS_BIT_SET(SPI2_SR_REG,TXE)==LOW || IS_BIT_SET(SPI2_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI2_DR_REG ;
    }
     break; /**********END OF CASE 2*****/
        case SPI3 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI3_CR1_REG,SPE)){SPI_Enable(SPI3);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI3_SR_REG,RXNE) | IS_BIT_SET(SPI3_SR_REG,TXE)==LOW || IS_BIT_SET(SPI3_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI3_DR_REG=u8dummy;
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI3_SR_REG,RXNE) | IS_BIT_SET(SPI3_SR_REG,TXE)==LOW || IS_BIT_SET(SPI3_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI3_DR_REG ;
    }
     break;/**********END OF CASE 3*****/
        case SPI4 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI4_CR1_REG,SPE)){SPI_Enable(SPI4);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI4_SR_REG,RXNE) | IS_BIT_SET(SPI4_SR_REG,TXE)==LOW || IS_BIT_SET(SPI4_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI4_DR_REG=u8dummy;
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI4_SR_REG,RXNE) | IS_BIT_SET(SPI4_SR_REG,TXE)==LOW || IS_BIT_SET(SPI4_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI4_DR_REG ;
    }
     break;/**********END OF CASE 4*****/
        case SPI5 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI5_CR1_REG,SPE)){SPI_Enable(SPI5);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI5_SR_REG,RXNE) | IS_BIT_SET(SPI5_SR_REG,TXE)==LOW || IS_BIT_SET(SPI5_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI5_DR_REG=u8dummy;
        /* Wait for previous transmissions to complete */
   while(IS_BIT_SET(SPI5_SR_REG,RXNE) | IS_BIT_SET(SPI5_SR_REG,TXE)==LOW || IS_BIT_SET(SPI5_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI5_DR_REG ;
    }
     break;/**********END OF CASE 5*****/
        case SPI6 :
        /* Check if SPI is enabled */
    if(IS_BIT_CLEAR(SPI6_CR1_REG,SPE)){SPI_Enable(SPI6);}
    
        /* Wait for previous transmissions to complete */
    while(IS_BIT_SET(SPI6_SR_REG,RXNE) | IS_BIT_SET(SPI6_SR_REG,TXE)==LOW || IS_BIT_SET(SPI6_SR_REG,BSY)) ;
        
	for(index=0 ; index<u8Count ;index++)
    {  
         /* Fill output buffer with data */
        SPI6_DR_REG=u8dummy;
        /* Wait for previous transmissions to complete */
   while(IS_BIT_SET(SPI6_SR_REG,RXNE) | IS_BIT_SET(SPI6_SR_REG,TXE)==LOW || IS_BIT_SET(SPI6_SR_REG,BSY)) ;
        /* Read data register */
    u8DataIn[index]=SPI6_DR_REG ;
    }
     break;/**********END OF CASE 6*****/

    default:
        break;
    }/*END OF SWITCH*/

}
