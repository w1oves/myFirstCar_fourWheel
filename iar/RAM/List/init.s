///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.40.3.8902/W32 for ARM       04/Nov/2019  22:01:29
// Copyright 1999-2015 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\init.c
//    Command line =  
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\init.c -D LPLD_K60
//        -D USE_K60DZ10 -lCN
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\RAM\List\ -lB
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\RAM\List\ -o
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\RAM\Obj\ --no_cse
//        --no_unroll --no_inline --no_code_motion --no_tbaa --no_clustering
//        --no_scheduling --debug --endian=little --cpu=Cortex-M4 -e --fpu=None
//        --dlib_config "D:\Study Software\arm\INC\c\DLib_Config_Normal.h" -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\app\ -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\CPU\ -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\common\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\LPLD\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\LPLD\HW\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\LPLD\DEV\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\LPLD\FUNC\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\uCOS-II\Ports\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\uCOS-II\Source\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\FatFs\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\FatFs\option\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\USB\common\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\USB\driver\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\USB\descriptor\
//        -I
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\..\..\..\lib\USB\class\
//        -Ol -I "D:\Study Software\arm\CMSIS\Include\" -D ARM_MATH_CM4
//    List file    =  
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\RAM\List\init.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        EXTERN LPLD_FTM_Init
        EXTERN LPLD_FTM_PWM_Enable
        EXTERN LPLD_GPIO_Init
        EXTERN LPLD_UART_EnableIrq
        EXTERN LPLD_UART_Init
        EXTERN __aeabi_memcpy4
        EXTERN uartIsr

        PUBLIC ftm_motor_init_struct
        PUBLIC gpio_switch_struct
        PUBLIC init
        PUBLIC motor_init
        PUBLIC switch_init
        PUBLIC uartCom
        PUBLIC uart_init
        PUBLIC uart_init_struct

// D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\init.c
//    1 #include "include.h"
//    2 
//    3 /********************对车内所有部件进行初始化********************/

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//    4 void init(void)
//    5 {
init:
        PUSH     {R7,LR}
//    6     uart_init();
        BL       uart_init
//    7     switch_init();
        BL       switch_init
//    8     motor_init();
        BL       motor_init
//    9 }
        POP      {R0,PC}          ;; return
//   10 
//   11 /********************对串口通信进行初始化********************/

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
//   12 UART_InitTypeDef uart_init_struct; //串口初始化结构体
uart_init_struct:
        DS8 28

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
//   13 UART_Type *uartCom;                //串口使用端口
uartCom:
        DS8 4
//   14 //串口通信初始化函数

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//   15 void uart_init(void)
//   16 {
uart_init:
        PUSH     {R5-R7,LR}
//   17     //有线串口通信初始化
//   18     uart_init_struct.UART_Uartx = UART4;      //端口
        LDR.N    R0,??DataTable2  ;; 0x400ea000
        LDR.N    R1,??DataTable2_1
        STR      R0,[R1, #+0]
//   19     uart_init_struct.UART_BaudRate = 115200;  //波特率
        MOVS     R0,#+115200
        LDR.N    R1,??DataTable2_1
        STR      R0,[R1, #+4]
//   20     uart_init_struct.UART_RxPin = PTE25;      //Rx引脚
        MOVS     R0,#+149
        LDR.N    R1,??DataTable2_1
        STRB     R0,[R1, #+9]
//   21     uart_init_struct.UART_TxPin = PTE24;      //Tx引脚
        MOVS     R0,#+148
        LDR.N    R1,??DataTable2_1
        STRB     R0,[R1, #+8]
//   22     uart_init_struct.UART_RxIntEnable = TRUE; //使能接收中断
        MOVS     R0,#+1
        LDR.N    R1,??DataTable2_1
        STRB     R0,[R1, #+10]
//   23     uart_init_struct.UART_RxIsr = uartIsr;    //设置接收中断函数
        LDR.N    R0,??DataTable2_2
        LDR.N    R1,??DataTable2_1
        STR      R0,[R1, #+20]
//   24     LPLD_UART_Init(uart_init_struct);         //初始化
        LDR.N    R1,??DataTable2_1
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_UART_Init
//   25     LPLD_UART_EnableIrq(uart_init_struct);    //中断使能
        LDR.N    R1,??DataTable2_1
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_UART_EnableIrq
//   26                                               //
//   27     uartCom = UART4;                          //端口设置
        LDR.N    R0,??DataTable2  ;; 0x400ea000
        LDR.N    R1,??DataTable2_3
        STR      R0,[R1, #+0]
//   28 }
        POP      {R0-R2,PC}       ;; return
//   29 
//   30 /********************对拨码开关进行初始化********************/

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
//   31 GPIO_InitTypeDef gpio_switch_struct;
gpio_switch_struct:
        DS8 20

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//   32 void switch_init(void)
//   33 {
switch_init:
        PUSH     {R7,LR}
//   34     gpio_switch_struct.GPIO_PTx = PTD;                               //规定端口为PORTD
        LDR.N    R0,??DataTable2_4  ;; 0x400ff0c0
        LDR.N    R1,??DataTable2_5
        STR      R0,[R1, #+0]
//   35     gpio_switch_struct.GPIO_Pins = GPIO_Pin0_7;                      //规定
        MOVS     R0,#+255
        LDR.N    R1,??DataTable2_5
        STR      R0,[R1, #+4]
//   36     gpio_switch_struct.GPIO_Dir = DIR_INPUT;                         //输入
        MOVS     R0,#+0
        LDR.N    R1,??DataTable2_5
        STRB     R0,[R1, #+12]
//   37     gpio_switch_struct.GPIO_PinControl = INPUT_PULL_DOWN | IRQC_DIS; //输入内部下拉，禁止中断和DMA请求
        MOVS     R0,#+2
        LDR.N    R1,??DataTable2_5
        STR      R0,[R1, #+8]
//   38     LPLD_GPIO_Init(gpio_switch_struct);
        LDR.N    R1,??DataTable2_5
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+20
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_GPIO_Init
//   39 }
        POP      {R0,PC}          ;; return
//   40 
//   41 /********************对电机模块进行初始化********************/

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
//   42 FTM_InitTypeDef ftm_motor_init_struct;
ftm_motor_init_struct:
        DS8 28

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//   43 void motor_init(void)
//   44 {
motor_init:
        PUSH     {R5-R7,LR}
//   45     ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机 左  PTC1    ftm_motor_ch0
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+0]
//   46     ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //设置为PWM输出模式
        MOVS     R0,#+1
        LDR.N    R1,??DataTable2_7
        STRB     R0,[R1, #+4]
//   47     ftm_motor_init_struct.FTM_PwmFreq = 10000;               //设置输出频率为10000HZ
        MOVW     R0,#+10000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+8]
//   48     LPLD_FTM_Init(ftm_motor_init_struct);                    //初始化
        LDR.N    R1,??DataTable2_7
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_FTM_Init
//   49     LPLD_FTM_PWM_Enable(FTM0, FTM_Ch0, 0, PTC1, ALIGN_LEFT); //启用FTM0_ch0通道，初始占空比为0，对应引脚为PTC1，脉冲对齐方式为左对齐
        MOVS     R0,#+40
        STR      R0,[SP, #+0]
        MOVS     R3,#+61
        MOVS     R2,#+0
        MOVS     R1,#+0
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        BL       LPLD_FTM_PWM_Enable
//   50                                                              //
//   51     ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机  左  PTC2    ftm_motor_ch1
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+0]
//   52     ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //
        MOVS     R0,#+1
        LDR.N    R1,??DataTable2_7
        STRB     R0,[R1, #+4]
//   53     ftm_motor_init_struct.FTM_PwmFreq = 10000;               //
        MOVW     R0,#+10000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+8]
//   54     LPLD_FTM_Init(ftm_motor_init_struct);                    //
        LDR.N    R1,??DataTable2_7
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_FTM_Init
//   55     LPLD_FTM_PWM_Enable(FTM0, FTM_Ch1, 0, PTC2, ALIGN_LEFT); //
        MOVS     R0,#+40
        STR      R0,[SP, #+0]
        MOVS     R3,#+62
        MOVS     R2,#+0
        MOVS     R1,#+1
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        BL       LPLD_FTM_PWM_Enable
//   56                                                              //
//   57     ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机  右  PTC3    ftm_motor_ch2
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+0]
//   58     ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //
        MOVS     R0,#+1
        LDR.N    R1,??DataTable2_7
        STRB     R0,[R1, #+4]
//   59     ftm_motor_init_struct.FTM_PwmFreq = 10000;               //
        MOVW     R0,#+10000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+8]
//   60     LPLD_FTM_Init(ftm_motor_init_struct);                    //
        LDR.N    R1,??DataTable2_7
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_FTM_Init
//   61     LPLD_FTM_PWM_Enable(FTM0, FTM_Ch2, 0, PTC3, ALIGN_LEFT); //
        MOVS     R0,#+40
        STR      R0,[SP, #+0]
        MOVS     R3,#+63
        MOVS     R2,#+0
        MOVS     R1,#+2
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        BL       LPLD_FTM_PWM_Enable
//   62 
//   63     ftm_motor_init_struct.FTM_Ftmx = FTM0;                   //电机  右  PTC4    ftm_motor_ch3
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+0]
//   64     ftm_motor_init_struct.FTM_Mode = FTM_MODE_PWM;           //
        MOVS     R0,#+1
        LDR.N    R1,??DataTable2_7
        STRB     R0,[R1, #+4]
//   65     ftm_motor_init_struct.FTM_PwmFreq = 10000;               //
        MOVW     R0,#+10000
        LDR.N    R1,??DataTable2_7
        STR      R0,[R1, #+8]
//   66     LPLD_FTM_Init(ftm_motor_init_struct);                    //
        LDR.N    R1,??DataTable2_7
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_FTM_Init
//   67     LPLD_FTM_PWM_Enable(FTM0, FTM_Ch3, 0, PTC4, ALIGN_LEFT); //
        MOVS     R0,#+40
        STR      R0,[SP, #+0]
        MOVS     R3,#+64
        MOVS     R2,#+0
        MOVS     R1,#+3
        LDR.N    R0,??DataTable2_6  ;; 0x40038000
        BL       LPLD_FTM_PWM_Enable
//   68 }
        POP      {R0-R2,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2:
        DC32     0x400ea000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_1:
        DC32     uart_init_struct

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_2:
        DC32     uartIsr

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_3:
        DC32     uartCom

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_4:
        DC32     0x400ff0c0

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_5:
        DC32     gpio_switch_struct

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_6:
        DC32     0x40038000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable2_7:
        DC32     ftm_motor_init_struct

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        SECTION __DLIB_PERTHREAD:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        SECTION __DLIB_PERTHREAD_init:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        END
// 
//  80 bytes in section .bss
// 398 bytes in section .text
// 
// 398 bytes of CODE memory
//  80 bytes of DATA memory
//
//Errors: none
//Warnings: none
