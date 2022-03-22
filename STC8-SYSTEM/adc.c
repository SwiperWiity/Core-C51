#include "STC8.h"
#include "delay.h"
#include "adc.h"

/*
		stc8 �汾 1.0
*/

unsigned char ADC_array[10] = {0,0,'.',0,0,0,' ','V',0,'S'};

sfr ADCCFG      =   0xde;

#define ADC_POWER   0x80            //ADC��Դ����λ
#define ADC_START   0x40            //ADC��ʼ����λ
#define ADC_FLAG    0x20            //ADC��ɱ�־

#define ADC_SPEEDLL 0x0F            //512��ʱ��
#define ADC_SPEEDL  0x07            //256��ʱ��
#define ADC_SPEEDH  0x02            //96��ʱ��
#define ADC_SPEEDHH 0x00            //32��ʱ��

unsigned int GPIOX_ADCY(unsigned char Px, unsigned char ADCX)		//x Ϊ GPIOX,	YΪ ADCX
{
	float i;
	unsigned int num;
	ADC_RES = 0;
	ADC_RESL = 0;
	
	if(Px == 0)
	{
		P0M0 &= ~(0X01 << ADCX);
		P0M1 |= (0X01 << ADCX);
	}
	else if(Px == 1)
	{
		P1M0 &= ~(0X01 << ADCX);
		P1M1 |= (0X01 << ADCX);
	}
										//����̬ѡ��
	
	ADC_CONTR = ADC_POWER | ADCX;			// ʹ��ADC ģ�� / ѡ��ADCX
	
	ADCCFG = ADC_SPEEDLL | 0x20;		// Speed  /  Right
	Delayxms (10);
	
	IE |= 0x20;							//ʹ�� ADC�ж�
	
 ADC_CONTR |= ADC_START;				//stc 15w ��ʼADC �ı�־
	
	while(!(ADC_CONTR & ADC_FLAG));		//�ȴ�ת������
	ADC_CONTR &= ~ADC_FLAG;         					//���ADC�жϱ�־
	num = ADC_RES;
	num = (num << 8) + ADC_RESL;
	i = num;
	i = (i/4095) * 5;
	num = i * 1000;
	return num;
}

void ADC_Num(unsigned int num)
{
	int Mul = 10000;
	char n;
	for(n = 0;n < 6;n++)
	{
		if(n == 2) n++;
		ADC_array[n] = (num / Mul) %10 + '0';
		Mul /= 10;
	}
}

/*
			�ж�
*/

void ADC_IRQ() interrupt 5
{
	if(ADC_CONTR & ADC_FLAG)
	{
		ADC_CONTR |= ADC_START;
	}
}