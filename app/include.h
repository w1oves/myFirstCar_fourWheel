#include "common.h"

#include "init.h"
#include "uart.h"
#include "switch.h"
#include "motor.h"

/********************串口变量********************/
extern UART_Type *uartCom;

/********************开关变量********************/
extern uint8 dip[8];