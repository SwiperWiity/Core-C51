#include "intrins.h"
#include "delay.h"

void Delayx0us(unsigned char x)     //@24.000MHz		�������ӳ�
{
    unsigned char i;
    for (x; x > 0; x--)
    {
        i = 71;
        while (--i)
            ;
    }
}

void Delay2us(unsigned char x)		//@24.000MHz         DS18B20
{
	unsigned char i,n;
	for(n = 0;n < x;n++)
	{
		_nop_();
		i = 8;
		while (--i);
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