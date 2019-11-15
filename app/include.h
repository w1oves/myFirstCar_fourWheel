#include "common.h"

#include "init.h"
#include "uart.h"
#include "switch.h"
#include "motor.h"
#include "servo.h"
#include "eagle.h"
#include "SCCB.h"
#include "isr.h"

/********************串口变量********************/
extern UART_Type *uartCom;

/********************开关变量********************/
extern uint8 dip[8];

/********************摄像头变量********************/
#define H CAMERA_H //采集行数
#define V CAMERA_W // 采集点数
extern uint8 Pix_Data[H][V / 8];
extern uint8 image_getted; // 图像采集完成标志，处理后置0