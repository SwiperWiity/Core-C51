#include "Digital.h"
#include "REG52.h"

/////////�������Ҫ�㹻��ʱ����ʾ��500us+������Ȼ���� ��ԡ�
////////  P1λѡ  P2��ѡ

unsigned char NUM_CODE[16] = {
    0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8,
    0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};			//�ֵ�CODE

unsigned char com;
unsigned char array_bit[8] = {1,2,3,4,5};						//Xλ��ʾ��������

void Shou_Digital (unsigned int x)
{
	unsigned char n;
	int p = 1;								//����
	for(n = 0;n < 4;n++)
	{
		array_bit[n] = (x/p)%10;
		p*= 10;
	}
	Show_Bit(com++);
	if(com > 3)com = 0;						//��ֹ��ƫ
	if(array_bit[3] == 0 && com >= 2 )		//����
	{
		if(com > 2)com = 0;
		if(array_bit[2] == 0 && com > 1)com = 0;
	}
}

void Show_Bit(unsigned char x)
{
	unsigned char i = 0x01;
	P1 |= 0x0F;								//λ
	P2 = NUM_CODE[array_bit[x]];			//��
	if(x == 1) P2 &= 0x7F;					//С����
	if(x>3)x = 0;
	P1 &= ~(i<<x);
}