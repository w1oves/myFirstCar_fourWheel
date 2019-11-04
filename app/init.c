#include "include.h"

/********************对车内所有部件进行初始化********************/
void init(void)
{
    uart_init();
}

/********************对串口通信进行初始化********************/
UART_InitTypeDef uart_init_struct;
//有线串口通信初始化函数
void uart_init(void)
{
    uart_init_struct.UART_Uartx = UART4;      //端口
    uart_init_struct.UART_BaudRate = 115200;  //波特率
    uart_init_struct.UART_RxPin = PTE25;      //Rx引脚
    uart_init_struct.UART_TxPin = PTE24;      //Tx引脚
    uart_init_struct.UART_RxIntEnable = TRUE; //使能接收中断
    uart_init_struct.UART_RxIsr = uartIsr;    //设置接收中断函数
    LPLD_UART_Init(uart_init_struct);         //初始化
    LPLD_UART_EnableIrq(uart_init_struct);    //中断使能
}