#include "i2c.h"
#include "stc15.h"
#include "delay.h"

sbit IIC_SCL = P4 ^ 1;
sbit IIC_SDA = P4 ^ 0;


void IIC_Start (void)
{
	IIC_SDA = 1;
	IIC_SCL = 1;
	Delayx0us(1);
	IIC_SDA = 0;		//下降的起始信号
	Delayx0us(1);
	IIC_SCL = 0;
}


char IIC_ACK (void)
{
	char count = 0;
	IIC_SCL = 0;
	IIC_SDA = 0;
	Delayx0us(1);
	IIC_SDA = 1;
	while(IIC_SDA)
	{
		count++;
		Delayx0us(1);
		if(count >= 10)
		{
			//IIC_Stop ();
			IIC_SCL = 1;
			Delayx0us(1);
			return 0;
		}
	}
	IIC_SCL = 1;
	Delayx0us(1);
	return 1;
}

void IIC_Stop (void)
{
	IIC_SDA = 0;
	IIC_SCL = 0;
	Delayx0us(1);
	IIC_SCL = 1;
	Delayx0us(1);
	IIC_SDA = 1;		//下降的起始信号
	Delayx0us(1);
}

void IIC_Wite_Bit (unsigned char x)
{
	char n;
	IIC_SCL = 0;
	Delayx0us(1);
	for(n = 0;n < 8;n++)
	{
		IIC_SCL = 0;
		if((x << n) & 0x80) IIC_SDA = 1;
		else IIC_SDA = 0;
		Delayx0us(1);
		IIC_SCL = 1;
		Delayx0us(1);
	}
	IIC_ACK ();
}

unsigned char IIC_Read_Bit (void)
{
	unsigned char n,m;
	for(n = 0;n < 8;n++)
	{
		while(!IIC_SCL);
		Delayx0us(1);
		m <<= n;
		if(IIC_SDA == 1)
		{
			m |= 1;
		}
		else
		{
			m |= 0; 
		}
		while(IIC_SCL);
		Delayx0us(1);
	}
	return m;
}

void IIC_Write (unsigned char x,const unsigned char *y)
{
	unsigned char n = 0;
	IIC_Start ();
	IIC_Wite_Bit (*(y + n) & 0xfe);		//写地址
	for(n = 1;n < x;n++)
	{
		IIC_Wite_Bit (*(y + n));
	}
	IIC_Stop ();
}
