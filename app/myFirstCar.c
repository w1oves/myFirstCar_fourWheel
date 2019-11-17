#include "include.h"

uint8 Image_Data[ROW][COLUMN];

void main(void)
{
  DisableInterrupts; //关闭中断
  init();            //初始化函数
  EnableInterrupts;  //启动中断
  while (1)
  {
    if (image_getted)
    {
      image_getted = 0;
      image_select((uint8 *)Image_Data, (uint8 *)Pix_Data);
      //程序主要逻辑
#if TEST == ALL_TEST || TEST == UART_TEST
      LPLD_UART_PutChar(uartCom, 'S');
#endif
#if TEST == ALL_TEST
      image_fix((uint8 *)Image_Data);
#endif
    }
#if TEST == ALL_TEST
    //测试电机是否正常工作
    motor_left_turn();
#endif
  }
}