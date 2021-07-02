/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_Private.h
* Author                :   Mohamed Reda
* Origin Date           :   1/07/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   STM32F429ZI
* Notes                 :   None
*Description            :   Private header file for SPI driver contains contains Registers
*                            address definitionsand enums and preprocessors  of
*						     STM32F429ZI ARM Micro-Controller.                                    
*                         
*****************************************************************************/
/*This is preprocessor (Header file) guard  */
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* SPIx Base Addresses 
*******************************************************************************/
#define SPI1_BASE_ADDRESS				0x40013000		/*APB2 Bus*/
#define SPI2_BASE_ADDRESS				0x40003800 		/*APB1 Bus*/
#define SPI3_BASE_ADDRESS				0x40003C00		/*APB1 Bus*/
#define SPI4_BASE_ADDRESS				0x40013400		/*APB2 Bus*/
#define SPI5_BASE_ADDRESS				0x40015000		/*APB2 Bus*/
#define SPI6_BASE_ADDRESS				0x40015400		/*APB2 Bus*/



/******************************************************************************
* SPI1 Registers  Addresses 
*******************************************************************************/
#define SPI1_CR1_REG					(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x00)))
#define SPI1_CR2_REG					(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x04)))
#define SPI1_SR_REG						(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x08)))
#define SPI1_DR_REG						(*((volatile uint32*)(SPI1_BASE_ADDRESS + 0x0C)))

/******************************************************************************
* SPI2 Registers  Addresses 
*******************************************************************************/
#define SPI2_CR1_REG					(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x00)))
#define SPI2_CR2_REG					(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x04)))
#define SPI2_SR_REG						(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x08)))
#define SPI2_DR_REG						(*((volatile uint32*)(SPI2_BASE_ADDRESS + 0x0C)))

/******************************************************************************
* SPI3 Registers  Addresses 
*******************************************************************************/
#define SPI3_CR1_REG					(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x00)))
#define SPI3_CR2_REG					(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x04)))
#define SPI3_SR_REG						(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x08)))
#define SPI3_DR_REG						(*((volatile uint32*)(SPI3_BASE_ADDRESS + 0x0C)))
/******************************************************************************
* SPI4 Registers  Addresses 
*******************************************************************************/
#define SPI4_CR1_REG					(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x00)))
#define SPI4_CR2_REG					(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x04)))
#define SPI4_SR_REG						(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x08)))
#define SPI4_DR_REG						(*((volatile uint32*)(SPI4_BASE_ADDRESS + 0x0C)))
/******************************************************************************
* SPI5 Registers  Addresses 
*******************************************************************************/

#define SPI5_CR1_REG					(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x00)))
#define SPI5_CR2_REG					(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x04)))
#define SPI5_SR_REG						(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x08)))
#define SPI5_DR_REG						(*((volatile uint32*)(SPI5_BASE_ADDRESS + 0x0C)))
/******************************************************************************
* SPI6 Registers  Addresses 
*******************************************************************************/
#define SPI6_CR1_REG					(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x00)))
#define SPI6_CR2_REG					(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x04)))
#define SPI6_SR_REG						(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x08)))
#define SPI6_DR_REG						(*((volatile uint32*)(SPI6_BASE_ADDRESS + 0x0C)))

/******************************************************************************
* Configuration Constants
*******************************************************************************/
/******Bits Definition************/

/******CR1 REG************/
#define CPHA       0
#define CPOL       1
#define MSTR       2
#define BR0        3
#define SPE        6
#define LSBFIRST   7
#define SSI        8
#define SSM        9
#define RXONLY     10
#define DFF        11
#define CRCNEXT    12
#define CRCEN      13
#define BIDIOE     14
#define BIDIMODE   15
/******CR2 REG************/
#define RXDMAEN    0
#define TXDMAEN    1
#define SSOE       2
#define ERRIE      5
#define RXNEIE     6
#define TXEIE      7
/******SR REG************/
#define RXNE       0
#define TXE        1
#define CHSIDE     2
#define UDR        3
#define CRCERR     4
#define MODF       5
#define OVR        6
#define BSY        7
/******DR REG************/
// Bits 15:0 DR[15:0]: Data register
/*For an 8-bit data frame, the buffers are 8-bit and only the LSB of the register
(SPI_DR[7:0]) is used for transmission/reception. When in reception mode, the MSB of
the register (SPI_DR[15:8]) is forced to 0.
For a 16-bit data frame, the buffers are 16-bit and the entire register, SPI_DR[15:0] is
used for transmission/reception.
*/

#endif /*SPI_PRIVATE_H_*/