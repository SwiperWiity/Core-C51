#include "stc8.h"
#include "spi.h"
#include "delay.h"
#include "oled.h"

sbit LED = P5 ^ 0;

char xdata array[16] = "num:   !";
char k,n;
unsigned int COUNT;

void main (void)
{
	Delayx00ms(1);
	OLED_Init();
	Delayx00ms(10);
	
	while(1)
	{
		array[5] = SPI_Read_And_Write ('S');	
		if(array[5] != 0)
		{
			OLED_P8x16Str(0,0,array);
			Delayx00ms(1);
		}
	}
}