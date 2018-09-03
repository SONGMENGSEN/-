#include "timer.h"
#include "led.h"

#include "usart.h"

void   TIM3_Int_Init(u16 arr, u16 psc)
{
	int Tout;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	
	
	TIM_TimeBaseStructure.TIM_Period=arr;
	TIM_TimeBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure);
    TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE );
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(TIM3,ENABLE);
	Tout= ((arr+1)*(psc+1))/(72*1000);
	printf("TIMER3  IS %d ms  \r\t",Tout);
	
}

void   TIM2_Int_Init(u16 arr, u16 psc)
{
	int Tout;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	
	
	TIM_TimeBaseStructure.TIM_Period=arr;
	TIM_TimeBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);
    TIM_ITConfig(TIM2,TIM_IT_Update,ENABLE );
	
	NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	TIM_Cmd(TIM2,ENABLE);
	Tout= ((arr+1)*(psc+1))/(72*1000);
	printf("TIMER2  IS  %d ms  \r\t",Tout);
	
}


void TIM3_IRQHandler(void)
{
		if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET)
		{
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update );
			LED1=!LED1;
		
		}

}

void TIM2_IRQHandler(void)
{
		if(TIM_GetITStatus(TIM2,TIM_IT_Update)!=RESET)
		{
		TIM_ClearITPendingBit(TIM2, TIM_IT_Update );
			LED0=!LED0;
		
		}

}
