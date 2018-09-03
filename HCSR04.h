#ifndef __HCSR04_H
#define __HCSR04_H	 
#include "sys.h"

#define TRIG PBout(8)

#define ECHO PBin(9)
void ultrasonic_config(void );

u32 Distance_Calculate(u32 count);

void ultrasonic_ON(void );
#endif
