#include <LPC21xx.H> 


int main()
{
	IODIR0 |= (1<<10);		  //Settin P0.10 as output port
	while(1) {

		IOSET0 |= (1<<10) ;		//Sending HIGH to P0.10

		}
	return(0);
}