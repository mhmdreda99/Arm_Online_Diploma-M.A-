// Memory to Memory Mode Application 

/********************************************************************************/ 
/* We have 3 options to copy data from one array to another
/* - Using Indirect method: for loop  u32DST_Array[index] = u32SRC_Array[index] 
/* - Using Direct method(Pointers): while loop *u32DST_Array++ = *u32SRC_Array++
/* - Using DMA
/* Conclusion: DMA is the fastest method then pointer method then indirect method
/******************************************************************************/
/******************************************************************************
* Includes
*******************************************************************************/
#include "STD_TYPES.h"
#include "NVIC.h"
#include "DMA.h"

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define SIZE                  500
#define NVIC_Interrupt_Num    56


void main()
{
    uint32 u32SRC_Array[SIZE];
    uint32 u32DST_Array[SIZE];
    uint32 u32index;
    // Intialiaze array with these values : {0,1,2,3,..,499}
    for(u32index=0; u32index<SIZE; u32index++)
    {
	    u32SRC_Array[u32index]=u32index;
    }
    
vNVIC_SetEnable(NVIC_Interrupt_Num);
u8DMA_StreamInit();
vDMA_SetAddresses(u32SRC_Array,u32DST_Array,SIZE);
vDMA_Enable();

}

// This ISR function is called if any flag is raised from the 5 flags of DMA
void DMA2_Stream0_IRQHandler(void)
{
	// Action indicates that transfer complete operation is done successfully 
	
	DMA2_Instant->StreamID[0].LIFCR |=(1U<<5);  // clear transfer complete flag 
}

