#include "common.h"

#include "init.h"
#include "uart.h"
#include "switch.h"
#include "motor.h"
#include "servo.h"
#include "eagle.h"
#include "SCCB.h"
#include "isr.h"
#include "imagePreDeal.h"
#include "imageSend.h"

/********************测试变量********************/
#define NO_TEST 1
#define ALL_TEST 2
#define UART_TEST 3
#define TEST ALL_TEST
/********************串口变量********************/
extern UART_Type *uartCom;

/********************开关变量********************/
extern uint8 dip[8];

/********************摄像头变量********************/
#define ROW 60     //采集行数
#define COLUMN 160 // 采集点数

#define H CAMERA_H //采集行数
#define V CAMERA_W // 采集点数

extern uint8 Pix_Data[H][V / 8]; //
extern uint8 image_getted;       // 图像采集完成标志，处理后置0
extern uint8 Image_Data[ROW][COLUMN];