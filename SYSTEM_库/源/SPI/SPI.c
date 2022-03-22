#include "spi.h"
#include "delay.h"
#include "REG52.h"


sbit MOSI = P1 ^ 7;
sbit MISO = P1 ^ 6;
sbit SCLK = P1 ^ 5;
sbit CS   = P1 ^ 4;

char SPI_array_r[20];
char SPI_array_s[20];

char SPI2_Write_And_Read_Byte(char dat)				//master
{
	char ret_data;
	char n,m;
	MOSI = 1;
	SCLK = 1;
	m = 0x80;
	CS   = 0;
	Delayx0us(5);
	for(n = 0;n < 8;n++)
	{
		SCLK = 0;
		MOSI = 0x80 & (dat << n);
		Delayx0us(1);
		_nop_();
		SCLK = 1;
		if(MISO == 1) ret_data |= (0x80 >> n);
		else          ret_data |= (0x00 >> n);
		Delayx0us(1);
		_nop_();
		
	}
	MOSI = 1;
	SCLK = 1;
	CS   = 1;
	return ret_data;
}

char SPI_Read_And_Write (char dat)						//Slave
{
	char ret_data = 0;
	unsigned char n,m;
	if(CS == 0)
	{
		m = 0x80;
		MISO = 1;
		for(n = 0;n < 8;n++)
		{
			while(SCLK);
			MISO = 0x80 & (dat << n);					//Slave OUT
			while(!SCLK);
			if(MOSI == 1)	ret_data |= (m >> n);
		}
		MISO = 1;
	}
	return ret_data;
}

char *SPI_Write_And_Read (const char * x,char y)
{
	char n;
	CS = 0;
	for(n = 0;n < y;n++)
	{
		SPI_array_r[n] = SPI2_Write_And_Read_Byte(*(x + n));
	}
	CS = 1;
	return SPI_array_r;
}

