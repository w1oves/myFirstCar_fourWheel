#include"include.h"

void main(void)
{
  DisableInterrupts; //关闭中断
  init();            //初始化函数
  EnableInterrupts;  //启动中断
  while (1)
  {
  }
}
