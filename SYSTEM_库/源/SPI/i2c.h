#ifndef _I2C__H_

#define _I2C__H_

void GPIO_Init_u(void);
void IIC_Start (void);
char IIC_ACK (void);
void IIC_Stop (void);
void IIC_Wite_Bit (unsigned char x);
unsigned char IIC_Read_Bit (void);
void IIC_Write (unsigned char x,const unsigned char *y);

#endif