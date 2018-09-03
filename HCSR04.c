#include "HCSR04.H"
#include "delay.h"
#include "timer.h"
#include "usart.h"
void ultrasonic_config()
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;//trig
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_Init(GPIOB ,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;//echo
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}



u32  Distance_Calculate(u32 count)
{
    u32  Distance = 0;
    Distance = (u32)(((float)count / 1000000) * 3400/2);
    return Distance;
}



void ultrasonic_ON()
{
	 u32 count = 0;
    u32  Distance = 0;
	
	TRIG=0;
	TRIG=1;
	delay_us(10);
	TRIG=0;
	TIM2->CNT = 0;
	while(ECHO==0);
	TIM_Cmd(TIM2,ENABLE );
	while(ECHO==1);
	TIM_Cmd(TIM2,DISABLE );
     count=TIM2->CNT;
	
	 Distance=Distance_Calculate(count);
	printf("Distance = %d\r\n", Distance);
       
        delay_ms(1000);
	
}

