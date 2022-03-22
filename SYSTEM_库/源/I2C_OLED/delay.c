#include "intrins.h"
#include "delay.h"

void Delayx0us(unsigned char x) //@24.000MHz		³¬Éù²¨ÑÓ³Ù
{
    unsigned char i;
    for (x; x > 0; x--)
    {
        i = 71;
        while (--i)
            ;
    }
}

void Delayxms(unsigned char x)		//@24.000MHz		°´¼üÏû¶¶ÑÓ³Ù
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

void Delayx00ms(unsigned char x) //@24.000MHz	Í¨ÓÃÑÓ³Ù
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