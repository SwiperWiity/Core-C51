#ifndef _LED__H_
#define _LED__H_

#include "stc15.h"


sbit LED_R = P3 ^ 3;
sbit LED_G = P3 ^ 7;
sbit LED_B = P3 ^ 6;

void LED_RGB (char RGB);

#endif