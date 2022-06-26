#include<lpc214x.h>
void init()
{
	PINSEL0=0X05;
	U0FCR=0X07;
	U0LCR=0x83;
	U0DLL=0X5D;
	U0DLM=0x00;
	U0LCR=0x03;
}
void delay()
{
	int i;
	for(i=0;i<2000000;i++);
}
int main()
{
	unsigned char p[]="This thing killin` me";
		int z;
	init();
	for(z=0;z<=20;z++)
	{
		U0THR=p[z];
		while(!(U0LSR&0x20));
	delay();
	}
	while(1);
}
