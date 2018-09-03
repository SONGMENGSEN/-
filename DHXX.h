#ifndef __DHXX_H
#define __DHXX_H	 
#include "sys.h"


#define DHT_Out PAout(1)
#define DHT_In  PAin(1)
extern u8 tdata[4];
extern u8 sbuf;
extern u8 check;
void DHT_portIN(void );
 	void DHT_PortOUT(void);	
unsigned char startdht11(void );

void com(void );

u8 readDHT11(void );
#endif
