#include"include.h"
#define ORIGIN 0
#define PHOTO 1
void uartIsr()
{
    LPLD_UART_PutCharArr(uartCom,"Hello World",12);
}
uint8 receive;
uint8 uartMode=ORIGIN;
uint8 sendImageContinue=0;
/*
P-PHOTO
    PA:发送一帧图像
    PB:连续发送图像
*/
void bluetoothIsr()
{
    LPLD_GPIO_Toggle_b(PTA, 15);
    receive=LPLD_UART_GetChar(UART4);
    switch (receive)
    {
    case 'A':
        if(uartMode==ORIGIN)
        {
            //
            break;
        }
        else
        {
            switch (uartMode)
            {
            case PHOTO:
                image_fix((uint8 *)Image_Data);
                break;
            default:
                break;
            }
            uartMode=ORIGIN;
        }
        break;
    case 'B':
        if(uartMode==ORIGIN)
        {
            //
            break;
        }
        else
        {
            switch (uartMode)
            {
            case PHOTO:
                sendImageContinue=!sendImageContinue;
                break;
            default:
                break;
            }
            uartMode=ORIGIN;
        }
        break;
    case 'P':
        if(uartMode==ORIGIN)
        {
            uartMode=PHOTO;
            break;
        }
        else
        {
            switch (uartMode)
            {
            case PHOTO:
                //
                break;
            default:
                break;
            }
            uartMode=ORIGIN;
        }
        break;
    
    default:
        break;
    }
}