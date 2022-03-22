#ifndef _INFRARED__H_

#define _INFRARED__H_

void Infrared_W(unsigned char x,unsigned char *y);   	//x is  length,y is address
void Data_Wave(unsigned char x,unsigned char y);		//x  is 0/1;    y is time (us)

#endif