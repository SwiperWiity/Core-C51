#include "Ultrasonic.h"
#include "stc15.h"
#include "Digital.h"


int p;

void Timer0Init(void);
void main (void)
{
	EA = 1;
	Timer0Init();
	while(1)
	{
		p = Ultrasonic();
		Delayx00ms(2);
	}
}

void TIM0_IRQ(void) interrupt 1
{
	Shou_Digital (p);
}

void Timer0Init(void)		//100微秒@24.000MHz
{
	AUXR &= 0x7F;		//定时器时钟12T模式
	TMOD &= 0xF0;		//设置定时器模式
	TL0 = 0x58;		//设置定时初值
	TH0 = 0xFF;		//设置定时初值
	TF0 = 0;		//清除TF0标志
	TR0 = 1;		//定时器0开始计时
	ET0 = 1;
}
