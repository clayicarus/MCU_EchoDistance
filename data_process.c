#include "data_process.h"
#include "echo.h"
#include "delay.h"

unsigned int _DAT_[2];
unsigned int * GetProcessD(unsigned char num,unsigned char times)
{
    unsigned char i, valid_count;
    unsigned int * temp;
    unsigned long sum_d;
    unsigned int sum_dt;
    sum_d=0;
    sum_dt=0;
    _DAT_[0]=0;
    _DAT_[1]=0;

    for(i = 0, valid_count = 0; i < times; i++)
    {
        temp=GetDistance(num);
        if(temp[1]<50)
        {
            sum_d+=temp[0];
            sum_dt+=temp[1];
            valid_count++;
        }
        delay(10);
    }
    
    if(valid_count>0)
    {
        _DAT_[0]=(unsigned int)(sum_d / valid_count);
        _DAT_[1]=(unsigned int)(sum_dt / valid_count);
    }
    else
    {
        _DAT_[0]=65535;
        _DAT_[1]=70;   
    }

    return _DAT_;
}