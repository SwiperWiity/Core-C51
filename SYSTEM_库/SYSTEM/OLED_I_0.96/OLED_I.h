#ifndef _OLED_I__H_
#define _OLED_I__H_

/*   ��һ���޸ģ���������STM32�ļ�����      2020.6.26 */
/*   I2C �汾OLED ������� GPIO ����  ����I2CЭ�鼴�� */

void OLED_Fill(unsigned char y);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Write(unsigned char x, unsigned char y);

void OLED_Init(void);

void OLED_P8x16Str(unsigned char x, unsigned char y,const char ch[]);

#endif

