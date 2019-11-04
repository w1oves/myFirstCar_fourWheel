///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.40.3.8902/W32 for ARM       04/Nov/2019  20:05:20
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

        EXTERN LPLD_UART_EnableIrq
        EXTERN LPLD_UART_Init
        EXTERN __aeabi_memcpy4
        EXTERN uartIsr

        PUBLIC init
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
//    7 }
        POP      {R0,PC}          ;; return
//    8 
//    9 /********************对串口通信进行初始化********************/

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
//   10 UART_InitTypeDef uart_init_struct;
uart_init_struct:
        DS8 28
//   11 //有线串口通信初始化函数

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//   12 void uart_init(void)
//   13 {
uart_init:
        PUSH     {R5-R7,LR}
//   14     uart_init_struct.UART_Uartx = UART4;      //端口
        LDR.N    R0,??DataTable0  ;; 0x400ea000
        LDR.N    R1,??DataTable0_1
        STR      R0,[R1, #+0]
//   15     uart_init_struct.UART_BaudRate = 115200;  //波特率
        MOVS     R0,#+115200
        LDR.N    R1,??DataTable0_1
        STR      R0,[R1, #+4]
//   16     uart_init_struct.UART_RxPin = PTE25;      //Rx引脚
        MOVS     R0,#+149
        LDR.N    R1,??DataTable0_1
        STRB     R0,[R1, #+9]
//   17     uart_init_struct.UART_TxPin = PTE24;      //Tx引脚
        MOVS     R0,#+148
        LDR.N    R1,??DataTable0_1
        STRB     R0,[R1, #+8]
//   18     uart_init_struct.UART_RxIntEnable = TRUE; //使能接收中断
        MOVS     R0,#+1
        LDR.N    R1,??DataTable0_1
        STRB     R0,[R1, #+10]
//   19     uart_init_struct.UART_RxIsr = uartIsr;    //设置接收中断函数
        LDR.N    R0,??DataTable0_2
        LDR.N    R1,??DataTable0_1
        STR      R0,[R1, #+20]
//   20     LPLD_UART_Init(uart_init_struct);         //初始化
        LDR.N    R1,??DataTable0_1
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_UART_Init
//   21     LPLD_UART_EnableIrq(uart_init_struct);    //中断使能
        LDR.N    R1,??DataTable0_1
        SUB      SP,SP,#+16
        MOV      R0,SP
        MOVS     R2,#+28
        BL       __aeabi_memcpy4
        POP      {R0-R3}
        BL       LPLD_UART_EnableIrq
//   22 }
        POP      {R0-R2,PC}       ;; return

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable0:
        DC32     0x400ea000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable0_1:
        DC32     uart_init_struct

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable0_2:
        DC32     uartIsr

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
// 28 bytes in section .bss
// 98 bytes in section .text
// 
// 98 bytes of CODE memory
// 28 bytes of DATA memory
//
//Errors: none
//Warnings: none
