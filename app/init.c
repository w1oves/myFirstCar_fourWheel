#include "include.h"

/********************对车内所有部件进行初始化********************/
void init(void)
{
   blue_init();
    switch_init();
    led_init();
    motor_init();
    servo_init();
    camera_init();
    DMA_TransmitInit();
    pit0_init();
   nvic_init();
   qd_init();    //初始化FTM2的正交解码功能
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
void blue_init() //蓝牙初始化函数
{
    uart_init_struct.UART_Uartx = UART4;
    uart_init_struct.UART_BaudRate = 115200;
    uart_init_struct.UART_RxPin = PTE25;
    uart_init_struct.UART_TxPin = PTE24;
    uart_init_struct.UART_RxIntEnable = TRUE;   //使能接收中断
    uart_init_struct.UART_RxIsr = bluetoothIsr; //设置接收中断函数
    LPLD_UART_Init(uart_init_struct);
    LPLD_UART_EnableIrq(uart_init_struct);
    /*
    uart_init_struct.UART_Uartx = UART0;
    uart_init_struct.UART_BaudRate = 9600;
    uart_init_struct.UART_RxPin = PTA15;
    uart_init_struct.UART_TxPin = PTA14;
    uart_init_struct.UART_RxIntEnable = TRUE; //使能接收中断
    uart_init_struct.UART_RxIsr = uartIsr;    //设置接收中断函数
*/
    uartCom = UART4;
    //初始化UART
    // LPLD_UART_Init(uart_init_struct);
    // LPLD_UART_EnableIrq(uart_init_struct);
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
GPIO_InitTypeDef gpio_led_struct;
void led_init(void)
{
    gpio_led_struct.GPIO_PTx = PTA;         //规定端口为PORTA
    gpio_led_struct.GPIO_Pins = GPIO_Pin15; //规定
    gpio_led_struct.GPIO_Dir = DIR_OUTPUT;  //输出
    gpio_led_struct.GPIO_Output = OUTPUT_H;
    gpio_led_struct.GPIO_PinControl = IRQC_DIS; //禁止中断和DMA请求
    LPLD_GPIO_Init(gpio_led_struct);
}

/********************对电机模块进行初始化********************/
FTM_InitTypeDef ftm_motor_init_struct;
void motor_init(void)
{
    //左轮-
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                              //电机 左  PTC1    ftm_motor_ch0
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;                           //设置为PWM输出模式
    ftm_motor_init_struct.FTM_PwmFreq = 15000;                               //设置输出频率为10000HZ
    LPLD_FTM_Init(ftm_motor_init_struct);                                    //初始化
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch0, 0, PTC1, ALIGN_LEFT); //启用FTM0_ch0通道，初始占空比为0，对应引脚为PTC1，脉冲对齐方式为左对齐
                                                                             //
    //左轮+
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                               //电机  左  PTC2    ftm_motor_ch1
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;                            //
    ftm_motor_init_struct.FTM_PwmFreq = 15000;                                //
    LPLD_FTM_Init(ftm_motor_init_struct);                                     //
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch1, 0, PTC2, ALIGN_LEFT); //
                                                                              //
    //右轮-
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                               //电机  右  PTC3    ftm_motor_ch2
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;                            //
    ftm_motor_init_struct.FTM_PwmFreq = 15000;                                //
    LPLD_FTM_Init(ftm_motor_init_struct);                                     //
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch2, 0, PTC3, ALIGN_LEFT); //
                                                                              //
    //右轮+
    ftm_motor_init_struct.FTM_Ftmx = FTM0;                                //电机  右  PTC4    ftm_motor_ch3
    ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;                             //
    ftm_motor_init_struct.FTM_PwmFreq = 15000;                                 //
    LPLD_FTM_Init(ftm_motor_init_struct);                                      //
    LPLD_FTM_PWM_Enable(FTM0, FTM_Ch3, 0, PTC4, ALIGN_LEFT); //
}

/********************对舵机模块进行初始化********************/
FTM_InitTypeDef ftm_servo_init_struct;
void servo_init(void)
{
    ftm_servo_init_struct.FTM_Ftmx = FTM1;         //使能FTM1通道
    ftm_servo_init_struct.FTM_Mode = FTM_MODE_PWM; //使能PWM模式
    ftm_servo_init_struct.FTM_PwmFreq = 50;        //PWM频率50Hz

    LPLD_FTM_Init(ftm_servo_init_struct);

    LPLD_FTM_PWM_Enable(FTM1,             //使用FTM1
                        FTM_Ch1,          //使能Ch0通道
                        SERVO_ZERO_POINT, //初始化角度0度
                        PTB1,             //使用Ch1通道的PTC1引脚
                        ALIGN_LEFT        //脉宽左对齐
    );
}

/********************对摄像头模块进行初始化********************/
GPIO_InitTypeDef Camera1DataPin;
GPIO_InitTypeDef Camera1Pclk;
GPIO_InitTypeDef Camera1Vsyn;
void camera_init(void)
{
    SCCB_GPIO_Init();                    // 配置 PTA26/PTA27为GPIO功能,输出,高电平，禁用中断
    while (OV7725_eagle_reg_init() == 0) //初始化成功
        ;
    //GPIO_InitTypeDef Camera1DataPin;            //定义第一个摄像头引脚，作为输出功能
    Camera1DataPin.GPIO_PTx = PTC;                              //PORT:C
    Camera1DataPin.GPIO_Pins = GPIO_Pin8_15;                    //PIN:8-15
    Camera1DataPin.GPIO_Dir = DIR_INPUT;                        //端口方向为输入
    Camera1DataPin.GPIO_Output = OUTPUT_L;                      //初始化时输出低电平
    Camera1DataPin.GPIO_PinControl = IRQC_DIS | INPUT_PULL_DIS; //禁用中断请求，禁用PULL
    LPLD_GPIO_Init(Camera1DataPin);

    //GPIO_InitTypeDef Camera1Pclk;            //定义第一个摄像头像素中断引脚
    Camera1Pclk.GPIO_PTx = PTE;                                                  //PORT:E
    Camera1Pclk.GPIO_Pins = GPIO_Pin0;                                           //PIN:0
    Camera1Pclk.GPIO_Dir = DIR_INPUT;                                            //端口方向为输入
    Camera1Pclk.GPIO_Output = OUTPUT_L;                                          //初始化时输出低电平
    Camera1Pclk.GPIO_PinControl = IRQC_DMARI | INPUT_PULL_DOWN | INPUT_PULL_DIS; //输入上拉上升沿产生DMA请求
    //question:输入上拉与禁止PULL同时使用，疑为错误
    LPLD_GPIO_Init(Camera1Pclk);

    //GPIO_InitTypeDef Camera1Vsyn;            //定义第一个摄像头场中断引脚
    Camera1Vsyn.GPIO_PTx = PTC;                                            //PORT:C
    Camera1Vsyn.GPIO_Pins = GPIO_Pin16;                                    //PIN:16
    Camera1Vsyn.GPIO_Dir = DIR_INPUT;                                      //端口方向为输入
    Camera1Vsyn.GPIO_Output = OUTPUT_L;                                    //初始化时输出低电平
    Camera1Vsyn.GPIO_PinControl = IRQC_RI | INPUT_PULL_DOWN | INPUT_PF_EN; //上升沿触发外部中断，开启上拉或下拉电阻,使能低通滤波器
    Camera1Vsyn.GPIO_Isr = vsy_isr;                                        //外部中断回调函数-unFinished
    LPLD_GPIO_Init(Camera1Vsyn);
    LPLD_GPIO_EnableIrq(Camera1Vsyn);
}
//DMA初始化
DMA_InitTypeDef Camera1DMAPin;
void DMA_TransmitInit()
{
    Camera1DMAPin.DMA_CHx = DMA_CH0;                       //选择DMA通道0
    Camera1DMAPin.DMA_Req = PORTE_DMAREQ;                  //选择DMA通道请求源为PROT:E
    Camera1DMAPin.DMA_MajorLoopCnt = V * H / 8;            //配置主循环计数为总像素数除以8，即总字节数
    Camera1DMAPin.DMA_MinorByteCnt = 1;                    //配置次循环传输字节数为1，即一次传输一个字节
    Camera1DMAPin.DMA_SourceAddr = (uint32)&PTC->PDIR + 1; //配置源数据地址为PROT:C的输入寄存器的地址的高位
    Camera1DMAPin.DMA_SourceAddrOffset = 0;                //配置每次读取后的偏移量，这里不需要偏移，每次固定读取该寄存器
    Camera1DMAPin.DMA_DestAddr = (uint32)Pix_Data;         //配置目的数据地址为：Pix_Data数组
    Camera1DMAPin.DMA_DestAddrOffset = 1;                  //配置目的数据地址每次传输后偏移一个字节
    Camera1DMAPin.DMA_AutoDisableReq = TRUE;               //使能自动禁用请求，使能后通道请求将在主循环结束后禁用
    LPLD_DMA_Init(Camera1DMAPin);
}
/********************对定时器模块进行初始化********************/
PIT_InitTypeDef pit0_init_struct;
TIME_S cartime;
void pit0_init()
{
    pit0_init_struct.PIT_Pitx = PIT0;
    pit0_init_struct.PIT_PeriodUs = 1000;
    pit0_init_struct.PIT_Isr = pit0_isr;
    LPLD_PIT_Init(pit0_init_struct);
    LPLD_PIT_EnableIrq(pit0_init_struct);

    cartime.ms = 0;
    cartime.min = 0;
    cartime.s = 0;
}

/********************对NVIC模块进行初始化********************/
NVIC_InitTypeDef nvic_struct;
void nvic_init()
{
    nvic_struct.NVIC_IRQChannel = PORTC_IRQn; //场中断
    nvic_struct.NVIC_IRQChannelGroupPriority = NVIC_PriorityGroup_3;
    nvic_struct.NVIC_IRQChannelPreemptionPriority = 0;
    nvic_struct.NVIC_IRQChannelSubPriority = 0;
    nvic_struct.NVIC_IRQChannelEnable = TRUE;
    LPLD_NVIC_Init(nvic_struct);

    /*
  nvic_struct.NVIC_IRQChannel = PORTA_IRQn; //超声波
  nvic_struct.NVIC_IRQChannelGroupPriority = NVIC_PriorityGroup_3;
  nvic_struct.NVIC_IRQChannelPreemptionPriority = 1;
  nvic_struct.NVIC_IRQChannelSubPriority = 0;
  nvic_struct.NVIC_IRQChannelEnable = TRUE;
  LPLD_NVIC_Init(nvic_struct);
  */
}
/********************初始化FTM2的正交解码功能********************/
void qd_init(void)
{

  PORTB->PCR[18] = PORT_PCR_MUX(6);         // 设置引脚 B18引脚为FTM2_PHA功能
  PORTB->PCR[19] = PORT_PCR_MUX(6);         // 设置引脚 B19引脚为FTM2_PHB功能  //单项接地
  SIM->SCGC3 |= SIM_SCGC3_FTM2_MASK;        //使能FTM2时钟
  FTM2->MODE |= FTM_MODE_WPDIS_MASK;        //写保护禁止
  FTM2->QDCTRL |= FTM_QDCTRL_QUADMODE_MASK; //AB相同时确定方向和计数值
  FTM2->CNTIN = 0;                          //FTM2计数器初始值为0
  FTM2->MOD = 65535;                        //结束值
  FTM2->QDCTRL |= FTM_QDCTRL_QUADEN_MASK;   //启用FTM2正交解码模式
  FTM2->MODE |= FTM_MODE_FTMEN_MASK;        //FTM2EN=1
  FTM2->CNT = 0;
}