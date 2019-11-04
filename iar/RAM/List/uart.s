///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.40.3.8902/W32 for ARM       04/Nov/2019  20:05:20
// Copyright 1999-2015 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\uart.c
//    Command line =  
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\uart.c -D LPLD_K60
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
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\RAM\List\uart.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        PUBLIC uartIsr

// D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\uart.c
//    1 #include"include.h"
//    2 //待解决：uartCom

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//    3 void uartIsr()
//    4 {
//    5     
//    6 }
uartIsr:
        BX       LR               ;; return

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
// 2 bytes in section .text
// 
// 2 bytes of CODE memory
//
//Errors: none
//Warnings: none
