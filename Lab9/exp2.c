#include <LPC21xx.H>                       /* LPC21xx definitions */

#define T0CTCR          (*((volatile unsigned long *) 0xE0004070))
#define T1CTCR          (*((volatile unsigned long *) 0xE0008070))
										
int count;
int main(void)
{
	
	PINSEL0 = 0x00200020;	//Setting for Capture in port P0.2 and P0.10
	T0TCR = 0x00000001;		//Enable Timercounter register for counting
	T1TCR = 0x00000001;		//Enable Timercounter register for counting
	T0CTCR = 0x00000001;	// enabling counter for counting on rising edge od signal in CAP0 Timer0 pin
	T1CTCR = 0x00000001;	// enabling counter for counting on rising edge od signal in CAP0 Timer1 pin
	while(1)
		count = T0TC;
}