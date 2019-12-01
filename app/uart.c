#include"include.h"
void uartIsr()
{
    LPLD_UART_PutCharArr(uartCom,"Hello World",12);
}
void bluetoothIsr()
{
    LPLD_GPIO_Output_b(PTA, 15, 1);
    image_fix((uint8 *)Image_Data);
}