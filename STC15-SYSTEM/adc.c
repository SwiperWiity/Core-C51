#include "STC15.h"
#include "delay.h"
#include "adc.h"

/*
	第一次更新 ： float
*/

#define ADC_POWER 0x80 //ADC电源控制位
#define ADC_FLAG 0x10  //ADC完成标志
#define ADC_START 0x08 //ADC起始控制位

#define ADC_SPEEDLL 0x00 //540个时钟
#define ADC_SPEEDL 0x20	 //360个时钟
#define ADC_SPEEDH 0x40	 //180个时钟
#define ADC_SPEEDHH 0x60 //90个时钟

unsigned char ADC_array[10] = {0, 0, '.', 0, 0, 0, ' ', 'V', 0, 'S'};

/*
		stc 15w 版本 2.0
*/

unsigned int GPIOX_ADCY(unsigned char Px, unsigned char ADCX)
{
	float i;
	unsigned int num;
	/*PxM1.n,PxM0.n     =00--->Standard,    01--->push-pull
					=10--->pure input,  11--->open drain	*/
	if (ADCX > 7)
		return 0;
	if (Px == 1 || Px == '1')
	{
		P1ASF = (0X01 << ADCX);
		P1M0 &= ~(0X01 << ADCX);
		P1M1 |= (0X01 << ADCX);
	} 														//高阻态选择
	else
		return 0;

	ADC_RES = 0;
	EADC = 1;											   //使能 ADC中断
	ADC_CONTR = ADC_POWER | ADC_SPEEDL | ADC_START | ADCX; //使能ADC模块 /ADC 速度 /开始ADC转换 /ADC 通道
	Delayxms(10);

	while (!(ADC_CONTR & ADC_FLAG))
		;													//等待转换结束
	ADC_CONTR &= ~ADC_FLAG; 								//清除ADC中断标志

	num = ADC_RES;
	num = (num << 2) + ADC_RESL;
	i = num;
	i = (i / 1024) * 5.0;
	num = i * 1000;
	return num;
}

void ADC_Num(unsigned int num)
{
	int Mul = 10000;
	char n;
	for (n = 0; n < 6; n++)
	{
		if (n == 2)
			n++;
		ADC_array[n] = (num / Mul) % 10 + '0';
		Mul /= 10;
	}
}

/*
			中断
*/

void ADC_IRQ() interrupt 5
{
	if (ADC_CONTR & ADC_FLAG)
	{
		ADC_CONTR &= ~(ADC_START); 								//停止ADC 转换
	}
}