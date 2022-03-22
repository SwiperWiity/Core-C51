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

void Timer0Init(void)		//100΢��@24.000MHz
{
	AUXR &= 0x7F;		//��ʱ��ʱ��12Tģʽ
	TMOD &= 0xF0;		//���ö�ʱ��ģʽ
	TL0 = 0x58;		//���ö�ʱ��ֵ
	TH0 = 0xFF;		//���ö�ʱ��ֵ
	TF0 = 0;		//���TF0��־
	TR0 = 1;		//��ʱ��0��ʼ��ʱ
	ET0 = 1;
}
