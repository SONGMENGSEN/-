#ifndef __ADC_H
#define __ADC_H	 


#include "sys.h"
#include "delay.h"


void  adc_Init(void);
u16 GET_adc(u8 ch);
u16 GET_Average(u8 ch,u8 times);


#endif
