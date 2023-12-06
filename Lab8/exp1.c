#include "lpc_2148.h"
#include "adc.h"
                 
void init_adc0(void)
{
  
//  PINSEL1 = (PINSEL1 & ~(1 << 24)) | (1 << 24);   //select channel1 of AD0
  PINSEL1 = 0x01000000;
}


int adc_read(void)
{
   	  int i;
      AD0CR = 0x00200400 | (1<<1) ;    // select channel
	  AD0CR |= 0x01000000; // Start A/D Conversion
      while ((AD0STAT & 0x00010002) == 0); // Wait for end of A/D Conversion
      i = AD0DR1; // Read A/D Data Register
	  return i;
 }

 main() {
	 int dig = 0;
	 init_adc0();
	 IODIR0 = 0x00FF0000;                     /* P1.16..23 defined as Outputs */	
	  while(1)
  {
  dig = adc_read();
  dig &= 0x0000ffff	;
  
  }
  }