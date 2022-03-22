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
	while(!Echo);		//等到High开始
	do{
		Delayx0us(1);
		i++;
	  }while(Echo); 	//等到 Low结束
	i = ((i * 17) / 10); //处理超声波数据
	return i;		//返回测到的时间 ，送去hanlde计算
}

void Delayx0us(unsigned char x) //@24.000MHz		超声波延迟
{
    unsigned char i;
    for (x; x > 0; x--)
    {
        i = 71;
        while (--i)
            ;
    }
}

void Delayxms(unsigned char x)		//@24.000MHz		按键消抖延迟
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

void Delayx00ms(unsigned char x) //@24.000MHz	通用延迟
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