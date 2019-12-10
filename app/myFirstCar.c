#include "include.h"

uint8 Image_Data[ROW][COLUMN];

void main(void)
{

  DisableInterrupts; //关闭中断

  init();           //初始化函数
  EnableInterrupts; //启动中断

  LPLD_GPIO_Output_b(PTA, 15, 1);
  while (!howToDo.start)
  {
    dip[0] = (uint8)(LPLD_GPIO_Input_b(PTD, 0));
    if (dip[0] == 0)
    {
      howToDo.start = 1;
      break;
    }
  }

  servo_midTurn();
  motor_speed_go();
  LPLD_GPIO_Output_b(PTA, 15, 0);
  while (1)
  {
    if (image_getted)
    {
      image_select((uint8 *)Image_Data, (uint8 *)Pix_Data);
      image_getted = 0;
      imageDeal();
      autoRun();
#if TEST
      sendWhat();
#endif
      //程序主要逻辑
    }
    if (howToDo.stop)
    {
      motor_stop();
      servo_midTurn();
      LPLD_GPIO_Output_b(PTA, 15, 1);
    }
  }
}