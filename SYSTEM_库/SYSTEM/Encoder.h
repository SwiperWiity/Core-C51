#ifndef _ENCODER__H_
#define _ENCODER__H_

typedef struct
{
	char Rotary_Num;									// +1 / -1
	char Rotary_Flag;									// free yes or no
	char Rotary_key;									// Press
	unsigned char Num;
}Controler; 									 		// About Controler EN-11

extern Controler Analyze;

void ENCODER_INIT (void);
void ENCODER_Flag (void);

#endif
