#include<lpc214x.h>
unsigned int x=0;
__irq void Timer0_ISR()
{
	x^=1;
	if(x)
		IOSET1=1<<20;
	else
		IOCLR1=1<<20;
	T0IR=0x01;
	VICVectAddr=0x0000000h;
}
int main()
{
	IODIR1=0x0fffffff;
	T0MCR=0x03;
	T0MR0=0x3456ff;
	VICVectAddr4=(unsigned)Timer0_ISR;
	VICVectCntl4=0x24;
	VICIntEnable=0x10;
	T0TCR=1;
	for(;;);
}
