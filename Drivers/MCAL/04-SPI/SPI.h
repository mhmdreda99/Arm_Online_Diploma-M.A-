/****************************************************************************
* Title                 :   SPI  
* Filename              :   SPI.h
* Author                :   Mohamed Reda
* Origin Date           :   1/07/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            : header file for SPI driver contains Function Prototypes 
*                        of STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/
/*This is preprocessor (Header file) guard  */
#ifndef SPI_H
#define SPI_H

/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/
/*** Choose the number of SPI****** */
#define SPI1      1
#define SPI2      2
#define SPI3      3
#define SPI4      4
#define SPI5      5
#define SPI6      6





/******************************************************************************
* Function Prototypes
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
);
void SPI_Enable(uint8 U8SPI_Num);
void SPI_Disable(uint8 U8SPI_Num);
uint8 u8SPI_Write8BitData(uint8 u8SPI_Num, uint8 u8DataOut);
void vSPI_WriteMulti8BitData(uint8 u8SPI_Num, uint8* u8DataOut, uint8* u8DataIn, uint8 u8Count);
void vSPI_ReadMulti8BitData(uint8 u8SPI_Num, uint8* u8DataIn, uint8 u8dummy, uint8 u8Count);





#endif 