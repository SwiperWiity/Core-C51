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

void Timer0Init(void)		//5毫秒@24.000MHz
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0xF0;		//设置定时初值
	TH0 = 0xD8;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
}
