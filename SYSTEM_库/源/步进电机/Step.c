#include "step.h"
#include "reg52.h"

/* �߾���ʹ�������� ��ʱ�����ã��������ӳٺ���	*/

/*	���繤�� Ƕ��ʽ Ҷ����

	��һ���޶�  4�� ��׼		2020.6.30
	�ڶ����޶�	8�� �߾���		����
*/

void Delay1ms(unsigned char x)		//@24.000MHz
{
	unsigned char i, j ,n;
	for(n = 0;n < x;n++)
	{
		i = 32;
		j = 41;
		do
		{
			while (--j);
		} while (--i);
	}
}

void Motor_Drive (unsigned char x,unsigned char y)
{
	static char n = 0;
	if(y == 'P' || y == 'p')		//Pro
	{
		P0 |= 0x0F;
		P0 &= ~(0x01 << n++);
		
	}
	else if(y == 'c' || y == 'C')	//Con
	{
		P0 |= 0x0F;
		P0 &= ~(0x08 >> n++);
	}
	if(n >= 4)n = 0;
	Delay1ms(x);
}


