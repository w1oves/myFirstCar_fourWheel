#include"include.h"
void uartIsr()
{
    LPLD_UART_PutCharArr(uartCom,"Hello World",12);
}