#ifndef _ECHO_H_
#define _ECHO_H_

#include<reg51.h>
//sound speed(m/s)
#define SDV 350
//program ticks per 1000us
#define TC 936
// sbit Trig=P3^0;
// sbit Echo=P3^1;
sbit Trig0=P2^0;
sbit Echo0=P2^1;

// float GetDistance(void);
void EchoInit(void);
unsigned int * GetDistance(unsigned char num);

#endif