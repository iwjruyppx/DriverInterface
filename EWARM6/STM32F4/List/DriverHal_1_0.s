///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.80.4.12462/W32 for ARM      26/Nov/2017  21:58:10
// Copyright 1999-2017 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        C:\Users\Paul\Desktop\simulation\DriverInterface\DriverHal_1_0.c
//    Command line =  
//        C:\Users\Paul\Desktop\simulation\DriverInterface\DriverHal_1_0.c -D
//        USE_STDPERIPH_DRIVER -D VECT_TAB_FLASH -D USE_STM32F4_EVB -D
//        STM32F4XX -D STM32F401X -D AKM_MAGNETOMETER_AK09911 -D
//        AKSC_VERSION_DEVICE=9911 -D AKL_SKIP_HW_CHECK -D DEBUG -D
//        AKM_DISABLE_DOEPLUS -D AKM_CUSTOM_CONTINUOUS_MEASURE -D
//        __DOEAG_MODE_EN -D ACC_SENSOR_DISABLE -D AKM_ACCELEROMETER_DUMMY -D
//        AKM_ENABLE_PDC -lC
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\STM32F4\List
//        -lA
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\STM32F4\List
//        --diag_suppress Pa082,pe191 -o
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\STM32F4\Obj
//        --no_cse --no_unroll --no_inline --no_code_motion --no_tbaa
//        --no_clustering --no_scheduling --debug --endian=little
//        --cpu=Cortex-M4 -e --fpu=VFPv4_sp --dlib_config "C:\Program Files
//        (x86)\IAR Systems\Embedded Workbench
//        7.5\arm\INC\c\DLib_Config_Full.h" -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Libraries\STM32_Common\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Libraries\STM32F4xx_StdPeriph_Driver\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Libraries\STM32F4xx_HAL_Driver\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Libraries\CMSIS\Device\STM32F4xx\Include\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\FreeRTOS\FreeRTOS821\Source\include\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\FreeRTOS\FreeRTOS821\Source\portable\IAR\ARM_CM4F\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Libraries\STM32_CPAL_Driver\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Libraries\STM32_CPAL_Driver\devices\stm32f4xx\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\Algorithm\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\Driver\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM8963\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911AG\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911AG\AKM_HAL\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911AG\AKM_Library\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911AG\AKM_Library\libag\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911AG\AKM_Library\libSmartCompass\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\AKM09911AG\AKM_Sensors\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\MMC3524xPJ\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\ST480M\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\Yamaha\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\DriverLibrary\YamahaMini\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\Manager\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\System\Utils\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Release\Driver\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Release\Manager\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Release\Platform\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Release\RtosTask\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Release\System\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\Release\SystemConfig\inc\
//        -I
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\..\..\Source\inc\
//        -I C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\..\..\..\
//        -I C:\work\Develop\Source\Manager\ -I C:\work\Develop\Source\Common\
//        -I C:\work\Develop\Source\Platform_Dependent\ -I
//        C:\work\Develop\Source\Android\ -I C:\work\Develop\Source\TimeSync\
//        -I C:\work\Develop\Source\Protocol\ -On --vla --use_c++_inline -I
//        "C:\Program Files (x86)\IAR Systems\Embedded Workbench
//        7.5\arm\CMSIS\Include\" -D ARM_MATH_CM4
//    Locale       =  Chinese (Traditional)_Taiwan.950
//    List file    =  
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\STM32F4\List\DriverHal_1_0.s
//
///////////////////////////////////////////////////////////////////////////////

        RTMODEL "__SystemLibrary", "DLib"
        RTMODEL "__dlib_file_descriptor", "1"
        RTMODEL "__dlib_full_locale_support", "1"
        AAPCS BASE,INTERWORK,VFP
        PRESERVE8
        REQUIRE8

        #define SHT_PROGBITS 0x1

        EXTERN SPI_BMI160_INIT

        PUBLIC DriverInit
        
          CFI Names cfiNames0
          CFI StackFrame CFA R13 DATA
          CFI Resource R0:32, R1:32, R2:32, R3:32, R4:32, R5:32, R6:32, R7:32
          CFI Resource R8:32, R9:32, R10:32, R11:32, R12:32, R13:32, R14:32
          CFI Resource D0:64, D1:64, D2:64, D3:64, D4:64, D5:64, D6:64, D7:64
          CFI Resource D8:64, D9:64, D10:64, D11:64, D12:64, D13:64, D14:64
          CFI Resource D15:64
          CFI EndNames cfiNames0
        
          CFI Common cfiCommon0 Using cfiNames0
          CFI CodeAlign 2
          CFI DataAlign 4
          CFI ReturnAddress R14 CODE
          CFI CFA R13+0
          CFI R0 Undefined
          CFI R1 Undefined
          CFI R2 Undefined
          CFI R3 Undefined
          CFI R4 SameValue
          CFI R5 SameValue
          CFI R6 SameValue
          CFI R7 SameValue
          CFI R8 SameValue
          CFI R9 SameValue
          CFI R10 SameValue
          CFI R11 SameValue
          CFI R12 Undefined
          CFI R14 SameValue
          CFI D0 Undefined
          CFI D1 Undefined
          CFI D2 Undefined
          CFI D3 Undefined
          CFI D4 Undefined
          CFI D5 Undefined
          CFI D6 Undefined
          CFI D7 Undefined
          CFI D8 SameValue
          CFI D9 SameValue
          CFI D10 SameValue
          CFI D11 SameValue
          CFI D12 SameValue
          CFI D13 SameValue
          CFI D14 SameValue
          CFI D15 SameValue
          CFI EndCommon cfiCommon0
        
// C:\Users\Paul\Desktop\simulation\DriverInterface\DriverHal_1_0.c
//    1 
//    2 #ifndef __DriverHal_H__
//    3 #define __DriverHal_H__
//    4 
//    5 /* Standard includes. */
//    6 #include <stdio.h>
//    7 #include <stdint.h>
//    8 #include <errno.h>
//    9 #include <string.h>
//   10 #include <math.h>
//   11 #include <stdlib.h>
//   12 #include <stdarg.h>
//   13 #include "DriverHal_1_0_Config.h"
//   14 #include "DriverHal_1_0.h"
//   15 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock0 Using cfiCommon0
          CFI Function DriverInit
        THUMB
//   16 int DriverInit(pDriverHandle_t pHandle, pDriverAPI pAPI, pDriverConfig pConfig)
//   17 {
DriverInit:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
//   18     SPI_BMI160_INIT(pHandle, pAPI, pConfig);
        MOVS     R2,R6
        MOVS     R1,R5
        MOVS     R0,R4
          CFI FunCall SPI_BMI160_INIT
        BL       SPI_BMI160_INIT
//   19     
//   20     return 0;
        MOVS     R0,#+0
        POP      {R4-R6,PC}       ;; return
//   21 }
          CFI EndBlock cfiBlock0

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        SECTION __DLIB_PERTHREAD:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        SECTION __DLIB_PERTHREAD_init:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        END
//   22 
//   23 
//   24 #endif /* __DriverHal_H__ */
// 
// 22 bytes in section .text
// 
// 22 bytes of CODE memory
//
//Errors: none
//Warnings: none
