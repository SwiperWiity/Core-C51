#include "step.h"
#include "reg52.h"

/* 高精度使用请启动 定时器调用，并屏蔽延迟函数	*/

/*	机电工程 嵌入式 叶天宇

	第一次修订  4节 标准		2020.6.30
	第二次修订	8节 高精度		？？
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


