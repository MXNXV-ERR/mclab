#include<lpc214x.h>
void pwm_init()
{
	PINSEL0=0x2;
	PWMPR=2;
	PWMPCR=0x200;
	PWMMR0=0xC37F;
	PWMMCR=0x2;
	PWMTCR=0x9;
}
int main()
{
	int i;
	pwm_init();
	while(1)
	{
		for(i=0;i<10;i++)
		{
		PWMMR1=0xfff+(0xff5*i);
		PWMLER=0x02;
		}
	}
}
