#ifndef __FUNCTION
#define __FUNCTION
typedef struct time_struct
{
    uint8 ms;
    uint8 s;
    uint8 min;
}TIME_S;
typedef struct flag_struct
{
    uint8 start;
    uint8 stop;
    uint8 road;
}FLAG_S;
uint8 abs(int16);
uint8 twoAbs(uint8,uint8);//绝对值
uint8 intToStr(int8 *addr,uint16 num);
#endif