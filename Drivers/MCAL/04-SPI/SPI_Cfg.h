/****************************************************************************
* Title                 :   SPI   
* Filename              :   SPI_Cfg.h
* Author                :   Mohamed Reda
* Origin Date           :   1/7/2021
* Version               :   1.0.0
* Compiler              :   TODO: COMPILER GOES HERE
* Target                :   TODO: MCU GOES HERE
* Notes                 :   None
*
*****************************************************************************/

#ifndef SPI_CFG_H_
#define SPI_CFG_H_

/******************************************************************************
* Includes
*******************************************************************************/

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Configuration Constants
*******************************************************************************/
#define SPI_MASTER_MODE 		0
#define SPI_SLAVE_MODE 		    1

#define DATASIZE_8 		        0
#define DATASIZE_16 	        1

#define FRAMEFORMAT_MSB 	    0
#define FRAMEFORMAT_LSB 	    1

#define NSS_MODE_SW		        0
#define NSS_MODE_HW		        1

/*REG CR1 Configuration*/
/**
 * Choose your configuration
 * BIDIMODE: Bidirectional data mode enable
 * 0: 2-line unidirectional data mode selected
 * 1: 1-line bidirectional data mode selected
 * BIDIOE: Output enable in bidirectional mode
 * This bit combined with the BIDImode bit selects the direction of transfer in bidirectional mode
 * 0: Output disabled (receive-only mode)
 * 1: Output enabled (transmit-only mode)
 * CRCEN: Hardware CRC calculation enable
 * 0: CRC calculation disabled
 * 1: CRC calculation enabled
 * CRCNEXT: CRC transfer next
 * 0: Data phase (no CRC phase)
 * 1: Next transfer is CRC (CRC phase)
 * DFF: Data frame format
 * 0: 8-bit data frame format is selected for transmission/reception
 * 1: 16-bit data frame format is selected for transmission/reception
 * RXONLY: Receive only
 * 0: Full duplex (Transmit and receive)
 * 1: Output disabled (Receive-only mode)
 * SSM: Software slave management
 * When the SSM bit is set, the NSS pin input is replaced with the value from the SSI bit.
 * 0: Software slave management disabled
 * 1: Software slave management enabled
 * SSI: Internal slave select
 * This bit has an effect only when the SSM bit is set. The value of this bit is forced onto the
 * NSS pin and the IO value of the NSS pin is ignored.
 * LSBFIRST: Frame format
 * 0: MSB transmitted first
 * 1: LSB transmitted first
 * SPE: SPI enable
 * 0: Peripheral disabled
 * 1: Peripheral enabled
 * BR: Baud rate control
 * 000: fPCLK/2
 * 001: fPCLK/4
 * 010: fPCLK/8
 * 011: fPCLK/16
 * 100: fPCLK/32
 * 101: fPCLK/64
 * 110: fPCLK/128
 * 111: fPCLK/256
 * MSTR: Master selection
 * 0: Slave configuration
 * 1: Master configuration
 * CPOL: Clock polarity
 * 0: CK to 0 when idle
 * 1: CK to 1 when idle
 * CPHA: Clock phase
 * 0: The first clock transition is the first data capture edge
 * 1: The second clock transition is the first data capture edge
 * */


/*REG CR2 Configuration*/
/**
 * Choose your configuration
 * TXEIE: Tx buffer empty interrupt enable
 * 0: TXE interrupt masked
 * 1: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
 * RXNEIE: RX buffer not empty interrupt enable
 * 0: RXNE interrupt masked
 * 1: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 * ERRIE: Error interrupt enable
 * This bit controls the generation of an interrupt when an error condition occurs (CRCERR,
 * OVR, MODF in SPI mode and UDR, OVR in I2S mode).
 * 0: Error interrupt is masked
 * 1: Error interrupt is enabled
 * SSOE: SS output enable
 * 0: SS output is disabled in master mode and the cell can work in multimaster configuration
 * 1: SS output is enabled in master mode and when the cell is enabled. The cell cannot work in a multimaster environment.
 * TXDMAEN: Tx buffer DMA enable
 * When this bit is set, the DMA request is made whenever the TXE flag is set.
 * 0: Tx buffer DMA disabled
 * 1: Tx buffer DMA enabled
 * RXDMAEN: Rx buffer DMA enable
 * When this bit is set, the DMA request is made whenever the RXNE flag is set.
 * 0: Rx buffer DMA disabled
 * 1: Rx buffer DMA enabled
 * */










#endif 