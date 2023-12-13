#include <LPC214X.h>

void delay(){
T0MR0 = 3000000;    //Load Calculated Count for desirted delay
T0MCR = 0x00000004;  //Stop on MR0
T0TCR = 1;				// Enable Timer 0
while(T0TC != T0MR0);   //wait untill TC reaches the desired delay
T0TC=0;					// Reset Timer
}
main(){
IODIR0 = 0xFFFFFFFF;  //Configure POrt 0 as output port
while(1){
IOSET0 = 0xFFFFFFFF;  // Make all poins of port 0 High
delay();
IOCLR0 = 0xFFFFFFFF;   // Make all poins of port 0 Low
delay();
}

}