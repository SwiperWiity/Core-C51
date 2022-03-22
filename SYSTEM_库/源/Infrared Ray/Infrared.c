#include "infrared.h"
#include "delay.h"
#include "reg52.h"

sbit Infr = P3 ^ 6;


void Infrared_W(unsigned char x,unsigned char *y)   	//x is  length,y is address
{
	
	
	
}

void Data_Wave(unsigned char x,unsigned char y)			//x  is 0/1;    y is time (us)
{
	unsigned char n;
	if(x == 0 || x == '0')
	{
		Infr = 1;
		Delayx0us(1);
		Infr = 0;
		Delayx0us(1);
	}
	else if(x == 1 || x == '1')
	{
		Infr = 1;
		Delayx0us(1);
	}
}