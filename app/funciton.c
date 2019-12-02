#include"include.h"
uint8 abs(int16 a)
{
	return (uint8)(a>0?a:(0-a));
}

uint8 twoAbs(uint8 n,uint8 m)
{
	return (n>m?(n-m):(m-n));
}