#ifndef _KEY_H_
#define _KEY_H_

#define KEYPORT P1

sbit K1=KEYPORT^0;
sbit K2=KEYPORT^1;
sbit K3=KEYPORT^2;
sbit K4=KEYPORT^3;
sbit K5=KEYPORT^4;
sbit K6=KEYPORT^5;
sbit K7=KEYPORT^6;
sbit K8=KEYPORT^7;

// #define DOWN_TICKS 2900
// #define UP_TICKS 1FlucT0
#define FlucT 20 

//define true=1,false=0.
//key is the num of the key.
// bit GetKeyDown(unsigned char key);

//define true=1,false=0.
bit GetKeyUp(unsigned char key);
//define true=1,false=0.
bit GetKey(unsigned char key);
//turn output to high voltage.
unsigned char Get(void);

#endif