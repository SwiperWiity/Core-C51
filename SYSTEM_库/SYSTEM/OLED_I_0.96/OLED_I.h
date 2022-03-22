#ifndef _OLED_I__H_
#define _OLED_I__H_

/*   第一次修改：增加了与STM32的兼容性      2020.6.26 */
/*   I2C 版本OLED 无需额外 GPIO 控制  调用I2C协议即可 */

void OLED_Fill(unsigned char y);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Write(unsigned char x, unsigned char y);

void OLED_Init(void);

void OLED_P8x16Str(unsigned char x, unsigned char y,const char ch[]);

#endif

