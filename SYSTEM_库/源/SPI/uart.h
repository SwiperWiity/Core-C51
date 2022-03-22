#ifndef _UART__H_

#define _UART__H_

#define UART1 1
#define UART2 2
#define UART3 3
#define UART4 4

extern unsigned char r_1,r_2,r_3,r_4,s,TCount;
extern unsigned char array_r[16],array_s[16];

void Clean (unsigned char x,unsigned char *y);				//x参 长度 , y参 首地址
void UARTX_Send(unsigned char x,char *y,unsigned char z);	//x参 UARTX, y参 首地址, z参 长度

void UartInit_4(void);
void UartInit_3(void);
void UartInit_2(void);
void UartInit_1(void);
void Timer0Init(void);

void Uart_Init(unsigned char x);

///////     stc15w 没有定时器1

#endif
