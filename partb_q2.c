#include<LPC214x.h>
void onwait()
{
	T0MR0=0x7974;
	T0PR=0;
	T0TCR=1;
	while(!(T0TC==T0MR0));
	T0TCR=3;
}
void offwait()
{
	T0MR0=0xB630;
	T0PR=1;
	T0TCR=1;
	while(!(T0TC==T0MR0));
	T0TCR=3;
}


int main()
{
	//T0MR1=0x000034ff;
	T0MCR=0X4;
	
	IODIR0=1<<16;
	while(1)
	{
		IOSET0=1<<16;
		onwait();
		IOCLR0=1<<16;
		offwait();
	}
}
