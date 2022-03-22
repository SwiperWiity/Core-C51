#include "reg52.h"
#include "delay.h"
#include "ultrasonic.h"

sbit Echo = P2 ^ 7;
sbit Trig = P2 ^ 6;

unsigned int Ultrasonic(void)
{
	int i = 0;
	char n = 0;
    Trig = 1;
	Delayx0us(2);
	Trig = 0;
	while(!Echo)		//�ȵ�High��ʼ
	{
		Delayx0us(5);
		n++;
		if(n > 100) return 0;
	}
	do{
		Delayx0us(1);
		i++;
	  }while(Echo); 	//�ȵ� Low����
	i = ((i * 17) / 10); //������������
	return i;		//���ز⵽��ʱ�� ����ȥhanlde����
}
