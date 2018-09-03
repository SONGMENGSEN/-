#ifndef __DMA_H
#define __DMA_H	 


#include "sys.h"
#include "delay.h"


void DMA_config(void);

void DMA_NVIC_Configuration(void);

void DMA1_Channel4_IRQHandler(void );


#endif
