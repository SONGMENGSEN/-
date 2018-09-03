#include "pwm.h"


void TIM3_PWM_Init(u16 arr,u16 psc)
{
	
	u16 CCR1= 36000;          
    u16 CCR2= 36000;
	u16 CCR3= 60000*0.2;          
    u16 CCR4= 60000*0.2;
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO|RCC_APB2Periph_GPIOB,ENABLE);
	
	
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6|GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_0|GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	TIM_TimeBaseStructure.TIM_Period=arr;
	TIM_TimeBaseStructure.TIM_Prescaler=psc;
	TIM_TimeBaseStructure.TIM_ClockDivision=0;
	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStructure);
	
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR2;           
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OC2Init(TIM3,&TIM_OCInitStructure);
	TIM_OC2PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR1;           
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC1Init(TIM3,&TIM_OCInitStructure);
	TIM_OC1PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR3;           
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_Low;
	TIM_OC3Init(TIM3,&TIM_OCInitStructure);
	TIM_OC3PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM2;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = CCR4;           
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OC4Init(TIM3,&TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM3,TIM_OCPreload_Enable);
	
	
	
	
	TIM_ARRPreloadConfig(TIM3, ENABLE);   
	
	
	TIM_Cmd(TIM3,ENABLE);
	
}

