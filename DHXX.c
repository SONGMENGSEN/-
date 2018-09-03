#include "dhxx.h"
#include "delay.h"
u8 tdata[4]={0x00,0x00,0x00,0x00};
u8 sbuf,check;
	u8 a1,a2;
void DHT_portIN(void )
{
	GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;     
    GPIO_Init(GPIOA,&GPIO_InitStructure);

}

void DHT_PortOUT(void)
{
    GPIO_InitTypeDef  GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_1 ;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;     
    GPIO_Init(GPIOA,&GPIO_InitStructure);
}

unsigned char startdht11(void )
{
  DHT_PortOUT();
	DHT_Out=0;
	delay_ms(20);
	
	DHT_Out=1;
	DHT_portIN();
	delay_us(20);
	if(!DHT_In)
	{
		while(!DHT_In);
		while(DHT_In);
		return 1;
	}
 return 0;
}

void com(void )
{
	u8 i,tt;
	tt=0;
	
	for(i=0;i<8;i++)
	{
	sbuf<<=1;
		delay_us(20);
		while(!DHT_In);
		delay_us(25);
		tt=100;
		while(tt++);
		if(DHT_In)
		{
			sbuf |=0x01;
			delay_us(30);
			
		}
		else 
		{
		  sbuf&=0xfe;
		}
	
	}
	
}

u8 readDHT11(void )
{
	u8 sum;
	if(startdht11())
	{
	com();
		tdata[0]=sbuf;
		com();
		tdata[1]=sbuf;
		com();
		tdata[2]=sbuf;
		com();
		tdata[3]=sbuf;
		com();
		check=sbuf;
		sum=(tdata[0]+tdata[1]+tdata[2]+tdata[3]);
	}
	if(check==sum)
	
	 return 1;
		else 
		return 0;
	
	
}


 
//	while(1)
//	{
//		
//		aa=readDHT11();
//		delay_ms (2000);
//		
//      if(aa==1)
//	   {
//			printf("当前环境湿度为%d.%d﹪，当前环境温度为%d.%d℃\r\n",tdata[0],tdata[1],tdata[2],tdata[3]);
//		    
//	   }
//	   else 
//	   {  
//		   printf("采样失败!!!\r\n");
//	}
//	 delay_ms(2000);  
//	
// }

//}
