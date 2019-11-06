#include "include.h"

/********************对车内所有部件进行初始化********************/
void init(void)
{
    uart_init();
    switch_init();
    motor_init();
}

/********************对串口通信进行初始化********************/
UART_InitTypeDef uart_init_struct; //串口初始化结构体
UART_Type *uartCom;                //串口使用端口
//串口通信初始化函数
void uart_init(void)
{
    //有线串口通信初始化
    uart_init_struct.UART_Uartx = UART4;      //端口
    uart_init_struct.UART_BaudRate = 115200;  //波特率
    uart_init_struct.UART_RxPin = PTE25;      //Rx引脚
    uart_init_struct.UART_TxPin = PTE24;      //Tx引脚
    uart_init_struct.UART_RxIntEnable = TRUE; //使能接收中断
    uart_init_struct.UART_RxIsr = uartIsr;    //设置接收中断函数
    LPLD_UART_Init(uart_init_struct);         //初始化
    LPLD_UART_EnableIrq(uart_init_struct);    //中断使能
                                              //
    uartCom = UART4;                          //端口设置
}

/********************对拨码开关进行初始化********************/
GPIO_InitTypeDef gpio_switch_struct;
void switch_init(void)
{
    gpio_switch_struct.GPIO_PTx = PTD;                               //规定端口为PORTD
    gpio_switch_struct.GPIO_Pins = GPIO_Pin0_7;                      //规定
    gpio_switch_struct.GPIO_Dir = DIR_INPUT;                         //输入
    gpio_switch_struct.GPIO_PinControl = INPUT_PULL_DOWN | IRQC_DIS; //输入内部下拉，禁止中断和DMA请求
    LPLD_GPIO_Init(gpio_switch_struct);
}

/********************对电机模块进行初始化********************/
FTM_InitTypeDef ftm_motor_init_struct;
void motor_init(void)
{
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机 左  PTC1    ftm_motor_ch0
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //设置为PWM输出模式
    ftm_motor_init_struct.FTM_PwmFreq = 10000;               //设置输出频率为10000HZ
    LPLD_FTM_Init(ftm_motor_init_struct);                    //初始化
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch0, 0, PTC1, ALIGN_LEFT); //启用FTM0_ch0通道，初始占空比为0，对应引脚为PTC1，脉冲对齐方式为左对齐
                                                             //
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机  左  PTC2    ftm_motor_ch1
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //
    ftm_motor_init_struct.FTM_PwmFreq = 10000;               //
    LPLD_FTM_Init(ftm_motor_init_struct);                    //
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch1, 0, PTC2, ALIGN_LEFT); //
                                                             //
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机  右  PTC3    ftm_motor_ch2
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //
    ftm_motor_init_struct.FTM_PwmFreq = 10000;               //
    LPLD_FTM_Init(ftm_motor_init_struct);                    //
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch2, 0, PTC3, ALIGN_LEFT); //

    ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机  右  PTC4    ftm_motor_ch3
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //
    ftm_motor_init_struct.FTM_PwmFreq = 10000;               //
    LPLD_FTM_Init(ftm_motor_init_struct);                    //
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch3, 0, PTC4, ALIGN_LEFT); //
}