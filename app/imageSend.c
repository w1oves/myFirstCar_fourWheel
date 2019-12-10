#include "include.h"
extern uint8 leftLine[ROW], middleLine[ROW], rightLine[ROW];
void three(uint16 num)
{
    uint8 d = num / 1000;
    uint8 c = num / 100 - d * 10;
    uint8 b = num / 10 - 10 * c - d * 100;
    uint8 a = num % 10;
    LPLD_UART_PutChar(UART4, 0x09);
    LPLD_UART_PutChar(UART4, d + 0x30);
    LPLD_UART_PutChar(UART4, c + 0x30);
    LPLD_UART_PutChar(UART4, b + 0x30);
    LPLD_UART_PutChar(UART4, a + 0x30);
}
void image_fix(uint8 *Image)
{
    uint16 i = 0, j = 0;
    for (i = 0; i < 10; i++) //分隔符  发送前九个数字
    {
        LPLD_UART_PutChar(UART4, i + 0x30);
        for (j = 0; j < 9; j++)
            LPLD_UART_PutChar(UART4, 0x20);
    }
    for (i = 0; i < 10; i++) //发送后面8个数字
    {
        LPLD_UART_PutChar(UART4, i + 0x30); //发送数字
        for (j = 0; j < 9; j++)
            LPLD_UART_PutChar(UART4, 0x20);
    }
    LPLD_UART_PutChar(UART4, 0x0d); //回车键
   LPLD_UART_PutChar(UART4, 0x0a); //换行键
    for (i = 0; i < 10; i++)        //列数符
    {
        for (j = 0; j < 10; j++)
            LPLD_UART_PutChar(UART4, j + 0x30);
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            LPLD_UART_PutChar(UART4, j + 0x30);
    }
   LPLD_UART_PutChar(UART4, 0x0d);
    LPLD_UART_PutChar(UART4, 0x0a);

    for (i = 0; i < ROW; i++) //发图像
    {

        for (j = 0; j < COLUMN; j++)
        {
            if (!*(Image + i * COLUMN + j))
                LPLD_UART_PutChar(UART4, 0x31); //黑点
            else
                LPLD_UART_PutChar(UART4, 0x20);
        }
        three(i);
      LPLD_UART_PutChar(UART4, 0x0d);
        LPLD_UART_PutChar(UART4, 0x0a);
    }
   LPLD_UART_PutChar(UART4, 0x0d);
    LPLD_UART_PutChar(UART4, 0x0a);
}


void sendLine()
{
  uint8 i, j;
  for (i = 0; i < ROW; i++) //边线，中线发送
  {

    for (j = 0; j < COLUMN; j++)
    {
      if (j == leftLine[i])
        LPLD_UART_PutChar(UART4, 0x3c); //'<'
      else if (j == middleLine[i])
        LPLD_UART_PutChar(UART4, 0x3d); //'='
      else if (j == rightLine[i])
        LPLD_UART_PutChar(UART4, 0x3e); //'>'
      else
        LPLD_UART_PutChar(UART4, 0x20);//' '
    }
    three(i);
    LPLD_UART_PutChar(UART4, 0X0d);//'\n'
    LPLD_UART_PutChar(UART4, 0X0a);//'\n'
  }
}

