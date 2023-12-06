#include "lpc_2148.h"
#include "adc.h"
                 
void init_adc0(void)
{
  
  PINSEL0 |= 0x3 << 8;								//select channel6 of AD0
}


int adc_read(void)
{
   	  int i;
      AD0CR = 0x00200400 | (1<<6) ;    // select channel
	  AD0CR |= 0x01000000; // Start A/D Conversion
      while ((AD0STAT & 0x00010002) == 0); // Wait for end of A/D Conversion
      i = AD0DR6; // Read A/D Data Register
	  return i;
 }

main() {
	 	 int dig = 0;
	 init_adc0();
	 IODIR0 = 0x00FF0000;                     /* P0.16..23 defined as Outputs */	
	  while(1)
  {
  dig = adc_read();
  dig &= 0x0000ffff	;
  if(dig >= 0x00000000 && dig<=0x00004d80)
  {
  	IOCLR0 |= 0x00ff0000;
	IOSET0 |= 0x00030000;
	}
  else if(dig >= 0x00004d81 && dig<=0x00009b00)
  {
  	IOCLR0 |= 0x00ff0000;
  	IOSET0 |= 0x000f0000;
	}
  else if(dig >= 0x00009b01 && dig<=0x0000c1c0)
  {
  	IOCLR0 |= 0x00ff0000;
  	IOSET0 |= 0x003f0000;
	}
  else if(dig >= 0x0000c1c1 && dig<=0x0000e880)
  {
  	IOCLR0 |= 0x00ff0000;
  	IOSET0 |= 0x00ff0000;
	}
else
	IOCLR0 |= 0x00ff0000;	
  }
  }