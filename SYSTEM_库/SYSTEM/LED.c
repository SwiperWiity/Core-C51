#include "LED.h"

void LED_RGB (char RGB)
{
	switch (LED_X)
	{
		case 'R': LED_G = 1;LED_B = 1;LED_R = 0;	break;
		case 'G': LED_R = 1;LED_B = 1;LED_G = 0; 	break;
		case 'B': LED_R = 1;LED_G = 1;LED_B = 0;  	break;
		
		default : LED_R = 1;LED_G = 1;LED_B = 1;  	break;
	}
}