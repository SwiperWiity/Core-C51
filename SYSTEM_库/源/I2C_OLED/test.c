#include "stc8.h"
#include "i2c.h"
#include "delay.h"
#include "oled.h"

unsigned char n;
void main (void)
{
	Delayx00ms(1);
	OLED_Init();
	while(1)
	{
		OLED_P8x16Str(0,0,"Hello");
		Delayx00ms(10);
		OLED_P8x16Str(0,0,"World");
		Delayx00ms(10);
	}
}