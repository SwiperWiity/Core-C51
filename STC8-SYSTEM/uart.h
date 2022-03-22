#ifndef _UART__H_

#define _UART__H_

#define UART1 1
#define UART2 2
#define UART3 3
#define UART4 4

extern unsigned char r_1,r_2,r_3,r_4,s,TCount;
extern unsigned char array_r[16],array_s[16];

void Uart_Init(unsigned char x);
void Clean(unsigned char Length, unsigned char *Opinter);				//x参 长度 , y参 首地址
void UARTX_Send(unsigned char Channels,char *Opinter,unsigned char Length);

#endif
