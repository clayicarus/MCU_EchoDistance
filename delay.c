#include<intrins.h>

void delay(unsigned ms)       //@12.000MHz.
{
    while(ms--)
    {        
        unsigned char i, j;

        i = 2;
        j = 239;
        do
        {
            while (--j);
        } while (--i);
    }
}

void delay_us(unsigned us)
{
    while(us--)
    {
        _nop_();
    }
}