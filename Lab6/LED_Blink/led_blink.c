#include <LPC21xx.H> 

delay()		  //Delay function
{
	int count;
	for(count = 0;count<=10000;count++);
}

int main()
{
	IODIR1 |= (1<<17);				 //setting P1.17 as output port
	while(1){

		IOSET1 |= (1<<17) ;			   //Sending HIGH to P1.17
		delay();
		IOCLR1 |= (1<<17) ;			   // Sending LOW to p1.17
		delay();
		}
	return(0);
}