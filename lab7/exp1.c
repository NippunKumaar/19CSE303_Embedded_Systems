#include <LPC21xx.H> 


int main()
{
	IODIR0 |= (1<<10);		  //Settin P0.10 as output port
	IODIR0 |= (0<<1);		// Setting P0.1 as input port
	while(1) {

		if (IOPIN0 & (1<<1))
			IOSET0 |= (1<<10) ;		//Sending HIGH to P0.10
		else
			IOCLR0 |= (1<<10) ;		//Sending LOW to P0.10
			
		}
	return(0);
}