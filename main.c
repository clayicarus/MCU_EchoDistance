#include<reg51.h>
#include"key.h"
#include"echo.h"
#include"alarm.h"
#include"data_process.h"
#include"lcd_1602.h"

#define ECHO_NUM 1
#define MEASURE_DT 10
#define SAMPLE 10

#define ALM_DIS 500

//b00000000
static unsigned char flag;       //out of range is 0,1 to alarm. cant use bit flag[n].
static unsigned char i;

// void main_alarm(void);
void setAlarmFlagFromD(unsigned * d);

void main(void)
{
    unsigned int * p_dat;       //[2]={distance, dt}
    unsigned int d[ECHO_NUM];   //20<=d<=4500
    unsigned int dt[ECHO_NUM];
    unsigned char mea_c;

    mea_c = 0;
    flag = 0;
    
    LCD_Init();
    AlarmInit();
    EchoInit();

    LCD_ShowString(1, 1, "MEASURING");

    LCD_ShowString(2, 1, "D0:");
    LCD_ShowString(2, 11, "mm");

    while(1)
    {
        mea_c++;
        if(mea_c >= MEASURE_DT)               //simulate delay
        {
            LCD_ShowNum(2, 5, d[0], 5);
            LCD_ShowNum(2, 15, dt[0], 2);

            for(i = 0; i < ECHO_NUM; i++)
            {
                p_dat = GetProcessD(i, SAMPLE);                      
                d[i] = p_dat[0];
                dt[i] = p_dat[1];

                if(((flag >> i) & 1) == 1)
                    Alarm(i, 1);
                else
                    Alarm(i, 0);  
            }
            mea_c = 0;
        }
        setAlarmFlagFromD(d);
    }
}

void setAlarmFlagFromD(unsigned * d)
{
    for(i = 0; i < ECHO_NUM; i++)
    {
        if(d[i] < ALM_DIS)
            flag |= (1 << i);   //set 1.
        else
            flag &= ~(1 << i);  //set 0.
    }
}
