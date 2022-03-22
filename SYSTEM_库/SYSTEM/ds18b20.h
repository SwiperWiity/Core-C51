#ifndef _DS18B20__H_
#define _DS18B20__H_

void Write_DS(char Byte);
unsigned char Read_Ds(void);

void DS_Register(char x);

char Init_DS(void);
int DS18B20_Drive (void);

#endif 