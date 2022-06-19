#include<LPC214X.h>
void delay(int n)
{for(int i=0;i<n;i++);}
int main()
{
	IODIR0=0x00000001;
	while(1)
	{
	IOSET0=0x00000001;
	delay(500);
	IOCLR0=0x00000001;
	delay(500);
	}
}
	
