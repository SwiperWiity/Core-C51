#ifndef _UART__H_

#define _UART__H_

#define UART1 1
#define UART2 2

/*
		stc 15w 版本 1.0	24.0 MHz
*/

extern unsigned char r_1,s,TCount;
extern unsigned char array_r[16],array_s[16];


void Uart_Init(unsigned char x);
void Clean(unsigned char Length, unsigned char *Opinter);				//x参 长度 , y参 首地址
void UARTX_Send(unsigned char Channels,char *Opinter,unsigned char Length);


#endif
