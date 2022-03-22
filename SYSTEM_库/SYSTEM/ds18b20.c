#include "ds18b20.h"
#include "reg52.h"
#include "delay.h"

sbit DQ = P1 ^ 0;

char Init_DS(void)
{
	unsigned char n = 1,m = 0;
	while(n)
	{
		DQ = 0;
		Delay2us(250);
		DQ = 1;
		Delay2us(45);
		
		if (DQ == 0)
		{
			n = 0;
			while(!DQ);
		}
		else n = 1;
		m++;
		if(m > 10) return 0;
	}
	return 1;
}

void Write_DS(char Byte)
{
	char n;
	for(n = 0;n < 8;n++)
	{
		DQ = 0;
		Delay2us(3);
		DQ = (Byte>>n) & 0x01;
		Delay2us(33);
		DQ = 1;
		Delay2us(3);
	}
}

unsigned char Read_Ds(void)
{
	unsigned char n,m,p = 0;
	for(n = 0;n < 8;n++)
	{
		DQ = 0;
		Delay2us(3);
		DQ = 1;
		Delay2us(3);
		m = DQ;
		if(DQ == 0) m = 0;
		else m = 0x01;

		p |= (m<<n);

		Delay2us(33);
	}
	return p;
}

void DS_Register(char x)
{
	DQ = 1;
	if(x == 'C' || x == 'c')
	{
		Write_DS(0xcc);
		Write_DS(0x44);
	}
	else if(x == 'R' || x == 'r')
	{
		Write_DS(0xcc);
		Write_DS(0xbe);
	}
}

int DS18B20_Drive (void)
{
	int Temp,minus;
	float num;
	unsigned char Temp_L,Temp_H,flag;
	EA = 0;
	flag = Init_DS();
	if(flag == 0) return 0;
	Delayxms(1);
	DS_Register('c');
	Delayxms(10);
	Init_DS();
	flag = Init_DS();
	if(flag == 0) return 0;
	Delayxms(1);
	DS_Register('R');
	Temp_L = Read_Ds();
	Temp_H = Read_Ds();
	DQ = 1;
	Temp = Temp_H;
	Temp = (Temp << 8) + Temp_L;
	
	minus = Temp & 0x8000;				//Judgment minus or Positive
	
	if(minus != 0) Temp = ~(Temp - 1);
	
	num = Temp;
	num /= 16;
	Temp = num * 100;
	EA = 1;
	return Temp;
}
