#include "include.h"
#define ORIGIN 0
#define PHOTO_MODE 1
#define IMAGEDEAL_MODE 2
#define CONTROL_MODE 3
#define ROAD_MODE 4
uint8 receive;
uint8 uartMode = ORIGIN;
uint8 sendImageContinue = 0;
uint8 sendImageOne = 0;
uint8 sendRoad_flag = 0;
int8 sendStr[10] = {0};
extern uint16 rightSum;
extern uint16 leftSum;
extern uint8 top_track; //赛道最高点：上面都是1
uint8 sendLine_flag = 0;
/*
P-PHOTO
    PA:发送一帧图像
    PB:连续发送图像
    PC:发送一帧图像的搜线结果
C-CONTROL
    CA:开启车辆
    CB:停车
R-ROAD
    RA:发送当前道路类型及一帧搜线结果
I-IMAGE OR INFORMATION:
    IS:MIDSUM
*/
void sendWhat(void)
{
    if (sendRoad_flag)
    {
        sendRoad_flag = 0;
        sendLine();
        switch (howToDo.road)
        {
        case STRAIGHT:
            LPLD_UART_PutCharArr(UART4, "\nSTRAIGHT\n", 11);
            break;
        case LEFT_TURN:
            LPLD_UART_PutCharArr(UART4, "\nLEFT_TURN\n", 11);
            break;
        case RIGHT_TURN:
            LPLD_UART_PutCharArr(UART4, "\nRIGHT_TURN\n", 11);
            break;
        default:
            break;
        }
        uint8 len=0;
        int8  sendStr[10]={0};
        len = intToStr(sendStr, top_track);
        LPLD_UART_PutCharArr(UART4, sendStr, len);
    }
    if (sendLine_flag)
    {
        sendLine_flag = 0;
        image_fix((uint8 *)Image_Data);
        sendLine();
    }
    if (sendImageContinue || sendImageOne)
    {
        sendImageOne = 0;
        image_fix((uint8 *)Image_Data);
    }
}
void bluetoothIsr()
{
    LPLD_GPIO_Toggle_b(PTA, 15);
    receive = LPLD_UART_GetChar(UART4);
    switch (uartMode)
    {
    case ORIGIN:
        switch (receive)
        {
        case 'P':
            uartMode = PHOTO_MODE;
            break;
        case 'I':
            uartMode = IMAGEDEAL_MODE;
            break;
        case 'C':
            uartMode = CONTROL_MODE;
            break;
        case 'R':
            uartMode = ROAD_MODE;
            break;
        default:
            uartMode = ORIGIN;
            break;
        }
        break;
    case PHOTO_MODE:
        photomode();
        break;
    case IMAGEDEAL_MODE:
        imagemode();
        break;
    case CONTROL_MODE:
        controlmode();
    case ROAD_MODE:
        roadmode();
        break;
    default:
        uartMode = ORIGIN;
        break;
    }
}
void photomode()
{
    switch (receive)
    {
    case 'A':
        sendImageOne = 1;
        break;
    case 'B':
        sendImageContinue = !sendImageContinue;
        break;
    case 'C':
        sendLine_flag = 1;
        break;
    default:
        break;
    }
    uartMode = ORIGIN;
}
void imagemode()
{
    switch (receive)
    {
    case 'S':
        // LPLD_UART_PutCharArr(UART4, "\nleftSum=:", 11);
        // len = intToStr(sendStr, leftSum);
        // LPLD_UART_PutCharArr(UART4, sendStr, len);
        // LPLD_UART_PutCharArr(UART4, "\nrightSum=:", 11);
        // len = intToStr(sendStr, rightSum);
        // LPLD_UART_PutCharArr(UART4, sendStr, len);
        //  LPLD_UART_PutCharArr(UART4, "\nmidSum=:", 11);
        //  len = intToStr(sendStr, rightSum);
        //  LPLD_UART_PutCharArr(UART4, sendStr, len);
        break;

    default:
        break;
    }
    uartMode = ORIGIN;
}
void controlmode()
{
    switch (receive)
    {
    case 'A':
        howToDo.start = 1;
        LPLD_UART_PutCharArr(UART4, "START\n", 7);
        break;
    case 'B':
        howToDo.stop = 1;
        break;
    default:
        break;
    }
    uartMode = ORIGIN;
}
void roadmode()
{
    switch (receive)
    {
    case 'A':
        sendRoad_flag = 1;
        break;
    default:
        break;
    }
    uartMode = ORIGIN;
}
void uartIsr()
{
    LPLD_UART_PutCharArr(uartCom, "Hello World", 12);
}