#include<LPC214x.h>
void onwait()
{
	T0MR0=0x7A11;
	T0PR=0;//pre scalar factor=0 (not required)
	T0TCR=1;//Enable the timer
	while(!(T0TC==T0MR0));
	T0TCR=3;//Stop and reset timer
}
void offwait()
{
	T0MR0=0xB71A;
	//T0MR0=0x16E35 if T0PR=0
	T0PR=1;//pre scalar factor=1
	T0TCR=1;//Enable the timer
	while(!(T0TC==T0MR0));
	T0TCR=3;//Stop and reset timer
}


int main()
{
	T0MCR=0X4;//stop on match
	
	IODIR0=1<<16;//port 0 pin 16(left shifted)
	while(1)
	{
		IOSET0=1<<16;
		onwait();
		IOCLR0=1<<16;
		offwait();
	}
}
