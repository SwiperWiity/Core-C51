#include "uart.h"
#include "stc8.h"

unsigned char r_1, r_2, r_3, r_4, s, TCount;

unsigned char array_r[16], array_s[16] = "Hello world !";

void TIME0_IRQ(void) interrupt 1
{
	if (r_1 || r_2 || r_3 || r_4)
	{
		TCount++;
		if (TCount > 200)
			TCount = 250;
	}
}

void UART_IRQ(void) interrupt 4
{
	if (RI)
	{
		RI = 0;
		array_r[r_1++] = SBUF;
		TCount = 0;
	}
}

void Baud_Rate(void)
{
	AUXR |= 0x04; 						//��ʱ��2ʱ��ΪFosc,��1T
	T2L = 0x8F;	  						//�趨��ʱ��ֵ
	T2H = 0xFD;	  						//�趨��ʱ��ֵ
	AUXR |= 0x10; 						//������ʱ��2
}						

void UartInit_4(void)
{
	S4CON = 0x10;
	S4CON &= 0xBF;
	Baud_Rate();
	IE2 |= 0x10;
}

void UartInit_3(void)
{
	S3CON = 0x10;
	S3CON &= 0xBF;
	Baud_Rate();
	IE2 |= 0x08;
}

void UartInit_2(void)
{
	S2CON = 0x50;
	Baud_Rate();
	IE2 |= 0x01;
}

void UartInit_1(void)
{
	SCON = 0x50;  		//8λ����,�ɱ䲨����
	AUXR |= 0x01; 		//����1ѡ��ʱ��2Ϊ�����ʷ�����
	Baud_Rate();
	ES = 1;
}

void Uart_Init(unsigned char x)
{
	switch (x)
	{
	case 1:
		UartInit_1();
		Clean(sizeof(array_r), &array_r);
		Clean(sizeof(array_s), &array_s);
		//Timer0Init();
		break;
	case 2:
		UartInit_2();
		break;
	case 3:
		UartInit_3();
		break;
	case 4:
		UartInit_4();
		break;
	default:
		break;
	}
}

void Clean(unsigned char Length, unsigned char *Opinter)
{
	unsigned char n;
	for (n = 0; n < Length; n++)
	{
		*(Opinter + n) = 0;
	}
}

void UARTX_Send(unsigned char Channels,const char *Opinter, unsigned char Length)
{
	unsigned char n;
	for (n = 0; n < Length; n++)
	{
		switch (Channels)
		{
		case 1:
			SBUF = *(Opinter + n);
			while (!TI)
				;
			TI = 0;
			break;
		case 2:
			S2BUF = *(Opinter + n);
			while (!(S2CON & S2TI))
				;
			S2CON &= ~S2TI;
			break;
		case 3:
			S3BUF = *(Opinter + n);
			while (!(S3CON & S3TI))
				;
			S3CON &= ~S3TI;
			break;
		case 4:
			S4BUF = *(Opinter + n);
			while (!(S4CON & S4TI))
				;
			S4CON &= ~S4TI;
			break;
		default:
			break;
		}
	}
}

void Timer0Init(void) 	//1ms,��������Ӱ�쳬������
{
	AUXR |= 0x80;
	TMOD &= 0xF0;
	TL0 = 0x40;
	TH0 = 0xA2;
	TF0 = 0;
	TR0 = 1;
	ET0 = 1;
}
