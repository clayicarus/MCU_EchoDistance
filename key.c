#include<reg51.h>
#include"key.h"

static void _delay(unsigned ms);


bit GetKey(unsigned char key)
{
    switch(key)
    {
        case 1:
            if(K1==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;
        case 2:
            if(K2==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;
        case 3:
            if(K3==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;
        case 4:
            if(K4==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 5:
            if(K5==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;
        case 6:
            if(K6==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;

        case 7:
            if(K7==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;
        case 8:
            if(K8==0)
            {
                // delay(FlucT);
                return 1;
            }
            return 0;
        default:
            return 0;
    }
}

// bit GetKeyDown(unsigned char key)
// {
//     switch(key)
//     {
//         case 1:
//             if(K1==1)
//             {
//                 delay(FlucT);
//                 while(K1==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 2:
//             if(K2==1)
//             {
//                 delay(FlucT);
//                 while(K2==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 3:
//             if(K3==1)
//             {
//                 delay(FlucT);
//                 while(K3==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 4:
//             if(K4==1)
//             {
//                 delay(FlucT);
//                 while(K4==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 5:
//             if(K5==1)
//             {
//                 delay(FlucT);
//                 while(K5==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 6:
//             if(K6==1)
//             {
//                 delay(FlucT);
//                 while(K6==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 7:
//             if(K7==1)
//             {
//                 delay(FlucT);
//                 while(K7==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         case 8:
//             if(K8==1)
//             {
//                 delay(FlucT);
//                 while(K8==1)
//                     continue;
//                 delay(FlucT);
//                 return 1;
//             }
//             return 0;

//             break;
//         default:
//             return 0;
//     }
// }

bit GetKeyUp(unsigned char key)
{
    switch(key)
    {
        case 1:
            if(K1==0)
            {
                _delay(FlucT);
                while(K1==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 2:
            if(K2==0)
            {
                _delay(FlucT);
                while(K2==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 3:
            if(K3==0)
            {
                _delay(FlucT);
                while(K3==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 4:
            if(K4==0)
            {
                _delay(FlucT);
                while(K4==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 5:
            if(K5==0)
            {
                _delay(FlucT);
                while(K5==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 6:
            if(K6==0)
            {
                _delay(FlucT);
                while(K6==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 7:
            if(K7==0)
            {
                _delay(FlucT);
                while(K7==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        case 8:
            if(K8==0)
            {
                _delay(FlucT);
                while(K8==0)
                    continue;
                _delay(FlucT);
                return 1;
            }
            return 0;

            break;
        default:
            return 0;
    }
}

unsigned char Get(void)
{
    return ~KEYPORT;
}

void _delay(unsigned ms)       //@12.000MHz.
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