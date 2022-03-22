#include "reg52.h"
#include "intrins.h"
#include "ultrasonic.h"

sbit Echo = P3 ^ 5;
sbit Trig = P3 ^ 4;

unsigned int Ultrasonic(void)
{
	unsigned int i = 0;
    Trig = 1;
	Delayx0us(2);
	Trig = 0;
	while(!Echo);		//�ȵ�High��ʼ
	do{
		Delayx0us(1);
		i++;
	  }while(Echo); 	//�ȵ� Low����
	i = ((i * 17) / 10); //������������
	return i;		//���ز⵽��ʱ�� ����ȥhanlde����
}

void Delayx0us(unsigned char x) //@24.000MHz		�������ӳ�
{
    unsigned char i;
    for (x; x > 0; x--)
    {
        i = 71;
        while (--i)
            ;
    }
}

void Delayxms(unsigned char x)		//@24.000MHz		���������ӳ�
{
	unsigned char i, j;
	for(x;x > 0;x--)
	{
		_nop_();
		i = 30;
		j = 40;
		do
		{
			while (--j);
		} while (--i);
	}
}

void Delayx00ms(unsigned char x) //@24.000MHz	ͨ���ӳ�
{
    unsigned char i, j, k;
    for (x; x > 0; x--)
    {
        _nop_();
        _nop_();
        i = 13;
        j = 45;
        k = 214;
        do
        {
            do
            {
                while (--k)
                    ;
            } while (--j);
        } while (--i);
    }
}