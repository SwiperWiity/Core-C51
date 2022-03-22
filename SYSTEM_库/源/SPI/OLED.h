#ifndef _OLED__H_
#define _OLED__H_


void OLED_P8x16Str(unsigned char x, unsigned char y,const char ch[]);
void OLED_Init(void);
void OLED_Fill(unsigned char y);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Write(unsigned char x, unsigned char y);

#endif

