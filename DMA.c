#include "DMA.H"
#include "usart.h"

extern vu16 ADC_CONV;

//extern uint8_t   ReceiveBuff[30];
void DMA_config()
{
	DMA_InitTypeDef DMA_InitStructure;
	DMA_DeInit(DMA1_Channel1);
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_DMA1,ENABLE);
	/*设置DMA地址*/
	DMA_InitStructure.DMA_MemoryBaseAddr=(u32)&ADC_CONV;
	DMA_InitStructure.DMA_PeripheralBaseAddr=(uint32_t)&ADC1->DR;
	
	DMA_InitStructure.DMA_DIR=DMA_DIR_PeripheralSRC;//CUN CHU QI
	DMA_InitStructure.DMA_BufferSize=1;
	DMA_InitStructure.DMA_PeripheralInc=DMA_PeripheralInc_Disable;
	DMA_InitStructure.DMA_MemoryInc=DMA_MemoryInc_Disable;
	DMA_InitStructure.DMA_PeripheralDataSize=DMA_PeripheralDataSize_HalfWord;
	DMA_InitStructure.DMA_MemoryDataSize=DMA_MemoryDataSize_HalfWord;
	DMA_InitStructure.DMA_Mode=DMA_Mode_Circular;
	DMA_InitStructure.DMA_Priority=DMA_Priority_High;
	DMA_InitStructure.DMA_M2M=DMA_M2M_Disable;
	DMA_Init(DMA1_Channel1,&DMA_InitStructure);
	DMA_Cmd(DMA1_Channel1,ENABLE);

	
}



//void DMA_NVIC_Configuration(void)
//{                                                                      
//    NVIC_InitTypeDef NVIC_InitStructure;            
//    
//    /* 配置中断源 */
//    NVIC_InitStructure.NVIC_IRQChannel = DMA1_Channel4_IRQn;
//    NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
//    NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
//    NVIC_Init(&NVIC_InitStructure);    

//    /* 配置DMA发送完成后产生中断 */            
//    DMA_ITConfig(DMA1_Channel4,DMA_IT_TC,ENABLE);
//	

//}



//void DMA1_Channel4_IRQHandler(void)
//{
//	DMA_Cmd (DMA1_Channel4,ENABLE);
//	printf("SCHKAC  OK\r\n");

//}

