#include "encoder.h"

#include "stc8.h"

sbit KEY_EC = P3 ^ 2;
sbit Rotary_A = P5 ^ 5;
sbit Rotary_B = P3 ^ 3;

Controler Analyze = {0,0,0,10}; 									 // About Controler EN-11

void ENCODER_INIT (void)
{
	IT0 = 1;                                    //ʹ��INT0�½����ж�
    EX0 = 1;                                    //ʹ��INT0�ж�
	IT1 = 1;                                    //ʹ��INT1�½����ж�
    EX1 = 1;                                    //ʹ��INT1�ж�
}

void INT0_Isr() interrupt 0
{
	if(KEY_EC == 0)
	{
		Analyze.Rotary_key = 1;
	}
}

void ENCODER_Flag(void)
{
	if (Rotary_A == 1 && Rotary_B == 1)
	{
		Analyze.Rotary_Flag = 1;
	}
}

void INT1_Isr() interrupt 2
{
    if (Analyze.Rotary_Flag == 1)
	{
		ET0 = 0;							//ȡ���ж�
		
		Analyze.Rotary_Flag = 0;
		if(Rotary_B == 0)
		{
			if (Rotary_A != 0)
			{
				Analyze.Rotary_Num = (-1);
			}
			else
			{
				Analyze.Rotary_Num = (1);
			}
		}
		
		ET0 = 1;							//��ʼ�ж�
	}
}
