#include "STC15.h"
#include "delay.h"
#include "adc.h"

/*
	��һ�θ��� �� float
*/

#define ADC_POWER 0x80 //ADC��Դ����λ
#define ADC_FLAG 0x10  //ADC��ɱ�־
#define ADC_START 0x08 //ADC��ʼ����λ

#define ADC_SPEEDLL 0x00 //540��ʱ��
#define ADC_SPEEDL 0x20	 //360��ʱ��
#define ADC_SPEEDH 0x40	 //180��ʱ��
#define ADC_SPEEDHH 0x60 //90��ʱ��

unsigned char ADC_array[10] = {0, 0, '.', 0, 0, 0, ' ', 'V', 0, 'S'};

/*
		stc 15w �汾 2.0
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
	} 														//����̬ѡ��
	else
		return 0;

	ADC_RES = 0;
	EADC = 1;											   //ʹ�� ADC�ж�
	ADC_CONTR = ADC_POWER | ADC_SPEEDL | ADC_START | ADCX; //ʹ��ADCģ�� /ADC �ٶ� /��ʼADCת�� /ADC ͨ��
	Delayxms(10);

	while (!(ADC_CONTR & ADC_FLAG))
		;													//�ȴ�ת������
	ADC_CONTR &= ~ADC_FLAG; 								//���ADC�жϱ�־

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
			�ж�
*/

void ADC_IRQ() interrupt 5
{
	if (ADC_CONTR & ADC_FLAG)
	{
		ADC_CONTR &= ~(ADC_START); 								//ֹͣADC ת��
	}
}