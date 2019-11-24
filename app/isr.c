#include "include.h"
uint8 Pix_Data[H][V / 8];
uint8 image_getted = 0;
/********************摄像头场中断函数********************/
void vsy_isr() //场中断触发
{
    if (LPLD_GPIO_IsPinxExt(PORTC, GPIO_Pin16)) //如果场中断引脚触q发中断
    {
        //  LPLD_GPIO_DisableIrq(Camera1Vsyn);
        LPLD_DMA_LoadDstAddr(DMA_CH0, Pix_Data); //检测到场开始信号，加载目的地址
        LPLD_GPIO_ClearIntFlag(PORTE);
        //检测到行开始信号，使能DMA请求
        LPLD_DMA_EnableReq(DMA_CH0);
        LPLD_GPIO_ClearIntFlag(PORTE);
        image_getted = 1;
    }
}
/********************定时器中断函数********************/
extern PIT_InitTypeDef pit0_init_struct;
void pit0_isr(void)
{
    LPLD_PIT_DisableIrq(pit0_init_struct); //关pit0中断
    cartime.ms++;
    if (cartime.ms % 1000 == 0)
    {
        cartime.ms = 0;
        cartime.s++;
        if (cartime.s % 60 == 0)
        {
            cartime.s = 0;
            cartime.min++;
        }
    }
    LPLD_PIT_EnableIrq(pit0_init_struct); //开pit0中断
}