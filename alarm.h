#ifndef _ALARM_H_
#define _ALARM_H_

#include<reg51.h>
//alarm set

sbit LED0 = P3^0;
                             
void Alarm(unsigned char num,bit status);
void AlarmInit(void);

#endif