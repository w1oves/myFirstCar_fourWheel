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