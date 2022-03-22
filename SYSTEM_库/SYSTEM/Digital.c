#include "Digital.h"
#include "REG52.h"

/////////数码管需要足够的时间显示（500us+），不然会有 余辉。
////////  P1位选  P2段选

unsigned char NUM_CODE[16] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
    0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};			//字的CODE

unsigned char com;
unsigned char array_bit[8] = {1,2,3,4,5};						//X位显示的字内容

void Shou_Digital (unsigned int x)
{
	unsigned char n;
	int p = 1;								//倍率
	for(n = 0;n < 4;n++)
	{
		array_bit[n] = (x/p)%10;
		p*= 10;
	}
	Show_Bit(com++);
	if(com > 3)com = 0;						//防止跑偏
	if(array_bit[3] == 0 && com >= 2 )		//消零
	{
		if(com > 2)com = 0;
		if(array_bit[2] == 0 && com > 1)com = 0;
	}
}

void Show_Bit(unsigned char x)
{
	unsigned char i = 0x01;
	P1 |= 0x0F;								//位
	P2 = NUM_CODE[array_bit[x]];			//段
	if(x == 1) P2 &= 0x7F;					//小数点
	if(x>3)x = 0;
	P1 &= ~(i<<x);
}