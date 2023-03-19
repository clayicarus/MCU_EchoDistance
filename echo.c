#include"echo.h"
#include"delay.h"
#include"timer0.h"

static void Count(void);
unsigned long _DT_; //1000us per _DT_
unsigned int _ECHO_DAT_[2];


void Count(void)
{
    _DT_++;
}

void EchoInit(void)
{
    Timer0_Init(Count);
}

unsigned int *GetDistance(unsigned char num)
{
    
    unsigned long temp;

    temp=0;
    _ECHO_DAT_[0]=0;
    _ECHO_DAT_[1]=0;

    switch (num)
    {
        case 0:
            Trig0 = 1;
            delay_us(10);
            Trig0 = 0; //10us pulse at least

            Timer0_Set(TC,0);
            while(!Echo0)
                continue;
            Timer0_Start();
            while(Echo0)
                continue;
            Timer0_Pause();
            break;
    }
    
    temp=SDV*50*_DT_;
    temp+=Timer0_GetDt()*(SDV/2/10);
    temp/=100;

    _ECHO_DAT_[0]=(unsigned int)temp;
    _ECHO_DAT_[1]=_DT_;

    Timer0_Reset();
    _DT_=0;

    return _ECHO_DAT_;  //mm
}

// unsigned int * GetDistance0(void)
// {
//     unsigned int _ECHO_DAT_[2];
//     unsigned long temp;

//     temp=0;
//     _ECHO_DAT_[0]=0;
//     _ECHO_DAT_[1]=0;

//     Trig0 = 1;
//     // TH0 = TL0 = 0;
//     delay_us(10);
//     Trig0 = 0; //10us high voltage

//     Timer0_Set(TC,0);
//     while(!Echo0)
//         continue;
//     Timer0_Start();
//     while(Echo0)
//         continue;
//     Timer0_Pause();

//     temp=SDV*50*_DT_;
//     temp+=Timer0_GetDt()*(SDV/2/10);
//     temp/=100;

//     _ECHO_DAT_[0]=(unsigned int)temp;
//     _ECHO_DAT_[1]=_DT_;

//     Timer0_Reset();
//     _DT_=0;

//     return _ECHO_DAT_;  //mm
// }
