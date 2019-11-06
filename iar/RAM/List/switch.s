///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.40.3.8902/W32 for ARM       04/Nov/2019  22:01:29
// Copyright 1999-2015 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\switch.c
//    Command line =  
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\switch.c -D LPLD_K60
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
//        D:\Study\car\myFirstCar\myFirstCar_fourWheel\iar\RAM\List\switch.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        PUBLIC dip

// D:\Study\car\myFirstCar\myFirstCar_fourWheel\app\switch.c
//    1 #include"include.h"
//    2 enum dip_enum{
//    3     launch_dip,
//    4     stop_dip
//    5 };

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
//    6 uint8 dip[8]={0};
dip:
        DS8 8

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
// 8 bytes in section .bss
// 
// 8 bytes of DATA memory
//
//Errors: none
//Warnings: none
