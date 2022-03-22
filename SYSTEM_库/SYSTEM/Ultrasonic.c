#include "reg52.h"
#include "delay.h"
#include "ultrasonic.h"

sbit Echo = P2 ^ 7;
sbit Trig = P2 ^ 6;

unsigned int Ultrasonic(void)
{
	int i = 0;
	char n = 0;
    Trig = 1;
	Delayx0us(2);
	Trig = 0;
	while(!Echo)		//等到High开始
	{
		Delayx0us(5);
		n++;
		if(n > 100) return 0;
	}
	do{
		Delayx0us(1);
		i++;
	  }while(Echo); 	//等到 Low结束
	i = ((i * 17) / 10); //处理超声波数据
	return i;		//返回测到的时间 ，送去hanlde计算
}
