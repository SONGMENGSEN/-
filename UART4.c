
#include <stdio.h>


#include "UART4.h"

               
       
//int fputc(int ch, FILE *f)
//{
//USART_SendData(USART1, (uint8_t) ch);

//while (USART_GetFlagStatus(UART4, USART_FLAG_TC) == RESET);
//return ch;
//}
int fputc(int ch, FILE *f)
{ 	
	while((UART4 ->SR&0X40)==0);//循环发送,直到发送完毕   
	UART4 ->DR = (u8) ch;      
	return ch;
}
void UART4_Init()
{

	GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4,ENABLE );
//	RCC_MCO1Config(RCC_MCO1Source_PLLCLK,RCC_MCO1Div_2);
	
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource10,GPIO_AF_UART4); //GPIOA9复用为USART1
	GPIO_PinAFConfig(GPIOC,GPIO_PinSource11,GPIO_AF_UART4); 
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11; //GPIOA9与GPIOA10
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;//复用功能
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//速度50MHz
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //推挽复用输出
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //上拉
	GPIO_Init(GPIOC,&GPIO_InitStructure); //初始化PA9，PA10

	
	

	
	USART_InitStructure.USART_BaudRate=115200;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Tx;
	
    USART_Init(UART4,&USART_InitStructure);
	
	USART_Cmd(UART4 ,ENABLE);
	//USART_DMACmd(USART1,ENABLE,USART_DMAReq_Rx);
	
	
	USART_ClearFlag(UART4 ,USART_FLAG_TC);
	

	
	
}
