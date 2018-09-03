#include "exti.h"
#include "led.h"
#include "key.h"
#include "delay.h"
#include "usart.h"

void EXTIX_Init(void)
{
	EXTI_InitTypeDef EXTI_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 RCC_ClocksTypeDef RCC_CLOCKS;
	KEY_Init();
	
	RCC_APB2PeriphClockCmd (RCC_APB2Periph_AFIO,ENABLE);

	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource0);
	EXTI_InitStructure.EXTI_Line=EXTI_Line0;
	EXTI_InitStructure.EXTI_Mode=EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger=EXTI_Trigger_Falling;
	EXTI_Init(&EXTI_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource1);
	EXTI_InitStructure.EXTI_Line=EXTI_Line1;
	EXTI_Init(&EXTI_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource10);
	EXTI_InitStructure.EXTI_Line=EXTI_Line10;
	EXTI_Init(&EXTI_InitStructure);
	
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOB,GPIO_PinSource11);
	EXTI_InitStructure.EXTI_Line=EXTI_Line11;
	
	EXTI_Init(&EXTI_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI0_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0X02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0X03;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	
	NVIC_InitStructure.NVIC_IRQChannel=EXTI1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0X02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0X02;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	NVIC_InitStructure.NVIC_IRQChannel=EXTI15_10_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0X02;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority=0X01;
	NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStructure);


     if(RCC_GetSYSCLKSource()==0x08)
	 {printf("系统时钟源为PLL!\r\n");}
	 RCC_GetClocksFreq(&RCC_CLOCKS);
	 printf("SYSCLK: %d HZ\r\n",RCC_CLOCKS.SYSCLK_Frequency);
	 printf("HCLK  : %d HZ\r\n",RCC_CLOCKS.HCLK_Frequency);
	 printf("PCLK1 : %d HZ\r\n",RCC_CLOCKS.PCLK1_Frequency);
	 printf("PCLK2 : %d HZ\r\n",RCC_CLOCKS.PCLK2_Frequency);
	 
}


	void EXTI0_IRQHandler()
	{
		delay_ms(10);
		if(KEY0==0)
		{
		  LED0=!LED0;
		}
		EXTI_ClearITPendingBit(EXTI_Line0);
	}
	
	
	
	void EXTI1_IRQHandler()
	{
		delay_ms(10);
		if(KEY1==0)
		{
		  LED1=!LED1;
		}
		EXTI_ClearITPendingBit(EXTI_Line1);
	}
	
	
	void EXTI15_10_IRQHandler()
	{
		delay_ms(10);
		if(KEY2==0)
		{
		  LED2=!LED2;
		}
		EXTI_ClearITPendingBit(EXTI_Line10);
		
		delay_ms(10);
		if(KEY3==0)
			
		{
		  LED3=!LED3;
		}
		EXTI_ClearITPendingBit(EXTI_Line11);
	}
	
	
	
	


