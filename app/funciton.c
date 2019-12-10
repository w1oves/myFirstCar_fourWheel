#include"include.h"
uint8 abs(int16 a)
{
	return (uint8)(a>0?a:(0-a));
}

uint8 twoAbs(uint8 n,uint8 m)
{
	return (n>m?(n-m):(m-n));
}
uint8 intToStr(int8 *addr,uint16 num)
{
	int8 out[10]={'\0'};
	int i=9;
	while (num!=0)
	{
		out[i--]=num%10;
		num/=10;
	}
	for ( i = 0; i < 10; i++)
	{
		addr[i]=out[i]+'0';
	}
	
	return 10;
}