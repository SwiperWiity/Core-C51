#ifndef _SPI__H_

#define _SPI__H_


extern char SPI_array_r[20];
extern char SPI_array_s[20];

char SPI2_Write_And_Read_Byte(char dat);			//Master
char SPI_Read_And_Write (char dat);					//Slave

char *SPI_Write_And_Read (const char * x,char y);


#endif