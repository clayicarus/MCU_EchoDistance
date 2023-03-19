#include"alarm.h"

void Alarm(unsigned char num,bit status)
{
    switch (num)
    {
        case 0:
            LED0=status;
            break;
    }
}

void AlarmInit(void)
{
    LED0=0;
}
