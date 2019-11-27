#include "include.h"

uint8 Image_Data[ROW][COLUMN];


void main(void)
{

  DisableInterrupts; //关闭中断

  init();            //初始化函数
  EnableInterrupts;  //启动中断

/*
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);//ok,right fan
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 10000);
  */
     LPLD_GPIO_Output_b(PTA,15,0); 
  while (1)
  {
    
    /*
    if (image_getted)
    {
      image_getted = 0;
      image_select((uint8 *)Image_Data, (uint8 *)Pix_Data);
      //程序主要逻辑
      image_fix((uint8 *)Image_Data);
    }
    //测试电机是否正常工作

   */
  }
}