///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.40.3.8902/W32 for ARM       03/Nov/2019  21:57:38
// Copyright 1999-2015 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  D:\Study\car\myFirstCar\app\myFirstCar.c
//    Command line =  
//        D:\Study\car\myFirstCar\app\myFirstCar.c -D LPLD_K60 -D USE_K60DZ10
//        -lCN D:\Study\car\myFirstCar\iar\RAM\List\ -lB
//        D:\Study\car\myFirstCar\iar\RAM\List\ -o
//        D:\Study\car\myFirstCar\iar\RAM\Obj\ --no_cse --no_unroll --no_inline
//        --no_code_motion --no_tbaa --no_clustering --no_scheduling --debug
//        --endian=little --cpu=Cortex-M4 -e --fpu=None --dlib_config "D:\Study
//        Software\arm\INC\c\DLib_Config_Normal.h" -I
//        D:\Study\car\myFirstCar\iar\..\app\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\CPU\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\common\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\LPLD\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\LPLD\HW\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\LPLD\DEV\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\LPLD\FUNC\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\uCOS-II\Ports\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\uCOS-II\Source\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\FatFs\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\FatFs\option\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\USB\common\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\USB\driver\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\USB\descriptor\ -I
//        D:\Study\car\myFirstCar\iar\..\..\..\lib\USB\class\ -Ol -I "D:\Study
//        Software\arm\CMSIS\Include\" -D ARM_MATH_CM4
//    List file    =  D:\Study\car\myFirstCar\iar\RAM\List\myFirstCar.s
//
///////////////////////////////////////////////////////////////////////////////

        #define SHT_PROGBITS 0x1

        PUBLIC main

// D:\Study\car\myFirstCar\app\myFirstCar.c
//    1 /**
//    2  * --------------基于"拉普兰德K60底层库V3"的工程（myFirstCar）-----------------
//    3  * @file myFirstCar.c
//    4  * @version 0.0
//    5  * @date 2013-9-29
//    6  * @brief 关于该工程的描述
//    7  *
//    8  * 版权所有:北京拉普兰德电子技术有限公司
//    9  * http://www.lpld.cn
//   10  * mail:support@lpld.cn
//   11  * 硬件平台:  LPLD K60 Card / LPLD K60 Nano
//   12  *
//   13  * 本工程基于"拉普兰德K60底层库V3"开发，
//   14  * 所有开源代码均在"lib"文件夹下，用户不必更改该目录下代码，
//   15  * 所有用户工程需保存在"project"文件夹下，以工程名定义文件夹名，
//   16  * 底层库使用方法见相关文档。 
//   17  *
//   18  */
//   19 #include "common.h"
//   20 

        SECTION `.text`:CODE:NOROOT(1)
        THUMB
//   21 void main (void)
//   22 {
//   23 
//   24   while(1)
main:
??main_0:
        B.N      ??main_0
//   25   {
//   26 
//   27   } 
//   28 }

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        SECTION __DLIB_PERTHREAD:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        SECTION __DLIB_PERTHREAD_init:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        END
//   29 
// 
// 2 bytes in section .text
// 
// 2 bytes of CODE memory
//
//Errors: none
//Warnings: none
