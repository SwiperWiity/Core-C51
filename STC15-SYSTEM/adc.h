#ifndef _ADC__H_
#define _ADC__H_

#define GPIO0 0
#define GPIO1 1

/*
		stc 15w �汾 2.0
*/

extern unsigned char ADC_array[10];

unsigned int GPIOX_ADCY(unsigned char Px, unsigned char ADCX);			//ADC��ȡ����
void ADC_Num(unsigned int num);										//��ѹ����

#endif