#ifndef _I2C__H_

#define _I2C__H_

/*   第一次修改：增加了与STM32的兼容性  函数格式与STM32保持一致  2020.6.26 */

/*   第二次修改：增加了与STM32的兼容性  对于传入地址新增  const 2020.6.26 */

void GPIO_Init_u(void);
void IIC_Start (void);
char IIC_ACK (void);
void IIC_Stop (void);
void IIC_Wite_Bit (char x);
unsigned char IIC_Read_Bit (void);
void IIC_Write (unsigned char x,const char *y);

#endif