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
#include "function.h"
#include "control.h"
#include "getSpeed.h"

/********************测试变量********************/
#define ALL_TEST 1
#define TEST ALL_TEST
/********************串口变量********************/
extern UART_Type *uartCom;
extern uint8 sendImageContinue;
/********************控制变量********************/
extern FLAG_S howToDo;

/********************开关变量********************/
extern uint8 dip[8];

/********************摄像头变量********************/
#define ROW 60     //采集行数
#define COLUMN 160 // 采集点数

#define H CAMERA_H //采集行数
#define V CAMERA_W // 采集点数s

extern uint8 Pix_Data[H][V / 8]; //
extern uint8 image_getted;       // 图像采集完成标志，处理后置0
extern uint8 Image_Data[ROW][COLUMN];

/********************时间变量********************/
extern TIME_S cartime;
extern uint8 TIME0flag_10ms;
extern uint8 TIME0flag_20ms;
extern uint8 TIME1flag_100ms;
extern uint8 TIME1flag_1s;

/********************速度变量********************/
extern int16 rightMotorSpeed;
extern int16 leftMotorSpeed;
extern int16 midMotorSpeed;
extern int16 speed_hope;



/********************PID变量********************/
// extern PID motor;
// extern PD servo;
// extern PD servo_mode[5];
extern float servoKp5[5];
extern float servoKd5[5];
extern float motorKp;
extern float motorKd;
extern float motorKi;

/********************道路类型********************/
#define STRAIGHT 1
#define LEFT_TURN 2
#define RIGHT_TURN 3
#define BIG_RIGHT_TURN 4
#define BIG_LEFT_TURN 5
