#include<LPC214x.h>
void wait(void);
int main()
{
	T0MR1=0x000000ff;
	T0MCR=0X20;
	IODIR0=0xFFFFFFFF;
	while(1)
	{
		
		IOPIN0=~IOPIN0;
		wait();
	}
}
void wait(void)
{
	T0TCR=1;
	while(!(T0TC==T0MR1));
}
