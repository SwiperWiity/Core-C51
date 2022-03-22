#include "stc8.h"
#include "intrins.h"
#include "Digital.h"

char w,n= 0;
int p = 1234;
void Timer0Init(void);
void main (void)
{
	unsigned char i, j, k;
	Timer0Init();
	EA = 1;
	while(1)
	{
		p = 314;
		_nop_();
		_nop_();
		i = 210;
		j = 34;
		k = 153;
		do
		{
			do
			{
				while (--k);
			} while (--j);
		} while (--i);
		
		
		p = 1592;
		_nop_();
		_nop_();
		i = 210;
		j = 34;
		k = 153;
		do
		{
			do
			{
				while (--k);
			} while (--j);
		} while (--i);
		
		p = 6;
		_nop_();
		_nop_();
		i = 210;
		j = 34;
		k = 153;
		do
		{
			do
			{
				while (--k);
			} while (--j);
		} while (--i);
		
	}
}

void TIM0_IRQ(void)	interrupt 1
{
	Shou_Digital (p);
}

void Timer0Init(void)		//5����@24.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0xF0;		//���ö�ʱ��ֵ
	TH0 = 0xD8;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
}
