///////////////////////////////////////////////////////////////////////////////
//
// IAR ANSI C/C++ Compiler V7.80.4.12462/W32 for ARM      27/Nov/2017  14:39:06
// Copyright 1999-2017 IAR Systems AB.
//
//    Cpu mode     =  thumb
//    Endian       =  little
//    Source file  =  
//        C:\Users\Paul\Desktop\simulation\DriverInterface\SPI_BMI160.c
//    Command line =  
//        C:\Users\Paul\Desktop\simulation\DriverInterface\SPI_BMI160.c -D
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
//        C:\Users\Paul\Desktop\simulation\DriverInterface\EWARM6\STM32F4\List\SPI_BMI160.s
//
///////////////////////////////////////////////////////////////////////////////

        RTMODEL "__SystemLibrary", "DLib"
        RTMODEL "__dlib_file_descriptor", "1"
        RTMODEL "__dlib_full_locale_support", "1"
        AAPCS BASE,INTERWORK,VFP
        PRESERVE8
        REQUIRE8

        #define SHT_PROGBITS 0x1

        EXTERN __aeabi_ldivmod
        EXTERN __aeabi_memcpy
        EXTERN abs

        PUBLIC AccGetInfo
        PUBLIC AccGetStatus
        PUBLIC AccPowerOnCheck
        PUBLIC AccReset
        PUBLIC AccSelftTest
        PUBLIC AccSetMode
        PUBLIC DriverBmi160AccGetData
        PUBLIC SPI_BMI160_INIT
        
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
        
// C:\Users\Paul\Desktop\simulation\DriverInterface\SPI_BMI160.c
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
//   14 #include "SPI_BMI160_DEF.h"
//   15 #include "SPI_BMI160.h"
//   16 
//   17 #define BMI160_ACC_NORMAL_EN					0
//   18 #define BMI160_ACC_SPECIAL_EN					1
//   19 
//   20 typedef struct {
//   21     uint8_t infoAccEn;
//   22     uint8_t accRate;
//   23     uint8_t accMode;
//   24 
//   25     uint8_t infoGyroEn;
//   26 } Bmi160Handle_t, *pBmi160Handle_t;
//   27 

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
        DATA
//   28 static Bmi160Handle_t BMI160;
BMI160:
        DS8 4
//   29 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock0 Using cfiCommon0
          CFI Function Read
        THUMB
//   30 static int Read(pDriverHandle_t pHandle, uint8_t reg, uint8_t *data, int len)
//   31 {
Read:
        PUSH     {R4-R7,LR}
          CFI R14 Frame(CFA, -4)
          CFI R7 Frame(CFA, -8)
          CFI R6 Frame(CFA, -12)
          CFI R5 Frame(CFA, -16)
          CFI R4 Frame(CFA, -20)
          CFI CFA R13+20
        SUB      SP,SP,#+20
          CFI CFA R13+40
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
        MOVS     R7,R3
//   32     BusTxRxPackage info = {.type = TYPE_SPI, .address = pHandle->config.slaveAddr, .reg = reg, .data = data, .len = len};
        LDR.W    R0,??DataTable11
        LDM      R0,{R0-R3}
        MOV      R12,SP
        STM      R12,{R0-R3}
        LDRH     R0,[R4, #+8]
        STRH     R0,[SP, #+4]
        UXTB     R5,R5            ;; ZeroExt  R5,R5,#+24,#+24
        STRH     R5,[SP, #+6]
        STR      R7,[SP, #+8]
        STR      R6,[SP, #+12]
//   33     return pHandle->api->Read( &info);
        MOV      R0,SP
        LDR      R1,[R4, #+28]
        LDR      R1,[R1, #+0]
          CFI FunCall
        BLX      R1
        ADD      SP,SP,#+20
          CFI CFA R13+20
        POP      {R4-R7,PC}       ;; return
//   34 }
          CFI EndBlock cfiBlock0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC8 0, 0, 0, 0, 0, 0, 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC16 0, 0, 0
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
        DC16 0, 0, 0
        DC8 0, 0

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_6:
        DC32 1
        DC16 0, 0
        DC32 0, 0H
//   35 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock1 Using cfiCommon0
          CFI Function Write
        THUMB
//   36 static int Write(pDriverHandle_t pHandle, uint8_t reg, uint8_t *data, int len)
//   37 {
Write:
        PUSH     {R4-R7,LR}
          CFI R14 Frame(CFA, -4)
          CFI R7 Frame(CFA, -8)
          CFI R6 Frame(CFA, -12)
          CFI R5 Frame(CFA, -16)
          CFI R4 Frame(CFA, -20)
          CFI CFA R13+20
        SUB      SP,SP,#+20
          CFI CFA R13+40
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
        MOVS     R7,R3
//   38     BusTxRxPackage info = {.type = TYPE_SPI, .address = pHandle->config.slaveAddr, .reg = reg, .data = data, .len = len};
        LDR.W    R0,??DataTable11_1
        LDM      R0,{R0-R3}
        MOV      R12,SP
        STM      R12,{R0-R3}
        LDRH     R0,[R4, #+8]
        STRH     R0,[SP, #+4]
        UXTB     R5,R5            ;; ZeroExt  R5,R5,#+24,#+24
        STRH     R5,[SP, #+6]
        STR      R7,[SP, #+8]
        STR      R6,[SP, #+12]
//   39     return pHandle->api->Write( &info);
        MOV      R0,SP
        LDR      R1,[R4, #+28]
        LDR      R1,[R1, #+4]
          CFI FunCall
        BLX      R1
        ADD      SP,SP,#+20
          CFI CFA R13+20
        POP      {R4-R7,PC}       ;; return
//   40 }
          CFI EndBlock cfiBlock1

        SECTION `.rodata`:CONST:REORDER:NOROOT(2)
        DATA
?_7:
        DC32 1
        DC16 0, 0
        DC32 0, 0H
//   41 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock2 Using cfiCommon0
          CFI Function sleep
        THUMB
//   42 static void sleep(pDriverHandle_t pHandle, uint32_t time)
//   43 {
sleep:
        PUSH     {R3-R5,LR}
          CFI R14 Frame(CFA, -4)
          CFI R5 Frame(CFA, -8)
          CFI R4 Frame(CFA, -12)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
//   44     pHandle->api->uSleep(time * 1000);
        MOV      R0,#+1000
        MUL      R0,R0,R5
        LDR      R1,[R4, #+28]
        LDR      R1,[R1, #+8]
          CFI FunCall
        BLX      R1
//   45 }
        POP      {R0,R4,R5,PC}    ;; return
          CFI EndBlock cfiBlock2
//   46 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock3 Using cfiCommon0
          CFI Function getTimeUs
        THUMB
//   47 static int64_t getTimeUs(pDriverHandle_t pHandle)
//   48 {
getTimeUs:
        PUSH     {R4,LR}
          CFI R14 Frame(CFA, -4)
          CFI R4 Frame(CFA, -8)
          CFI CFA R13+8
        MOVS     R4,R0
//   49     return pHandle->api->GetTimeNs()/1000ll;
        LDR      R0,[R4, #+28]
        LDR      R0,[R0, #+12]
          CFI FunCall
        BLX      R0
        MOV      R2,#+1000
        MOVS     R3,#+0
          CFI FunCall __aeabi_ldivmod
        BL       __aeabi_ldivmod
        POP      {R4,PC}          ;; return
//   50 }
          CFI EndBlock cfiBlock3
//   51 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock4 Using cfiCommon0
          CFI Function error
        THUMB
//   52 static void error(pDriverHandle_t pHandle, int error, void *data)
//   53 {
error:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
//   54     pHandle->api->Error(error, 0);
        MOVS     R1,#+0
        MOVS     R0,R5
        LDR      R2,[R4, #+28]
        LDR      R2,[R2, #+16]
          CFI FunCall
        BLX      R2
//   55 }
        POP      {R4-R6,PC}       ;; return
          CFI EndBlock cfiBlock4
//   56 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock5 Using cfiCommon0
          CFI Function senDataCb
        THUMB
//   57 static void senDataCb(pDriverHandle_t pHandle, float *senData, void *reserved)
//   58 {
senDataCb:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
//   59     pHandle->api->DataCb(senData, reserved);
        MOVS     R1,R6
        MOVS     R0,R5
        LDR      R2,[R4, #+28]
        LDR      R2,[R2, #+20]
          CFI FunCall
        BLX      R2
//   60 }
        POP      {R4-R6,PC}       ;; return
          CFI EndBlock cfiBlock5
//   61 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock6 Using cfiCommon0
          CFI Function AccSetMode
        THUMB
//   62 int AccSetMode(pDriverHandle_t pHandle, int mode){
AccSetMode:
        PUSH     {R3-R5,LR}
          CFI R14 Frame(CFA, -4)
          CFI R5 Frame(CFA, -8)
          CFI R4 Frame(CFA, -12)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
//   63 	uint8_t data1 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//   64 	uint8_t data2 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//   65 	if(mode & (1<<MODE_ACC_MOTION_INT)){
        LSLS     R0,R5,#+24
        BPL.W    ??AccSetMode_0
//   66 		if(BMI160.accMode == MODE_ACC_MOTION_INT){
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+2]
        CMP      R0,#+7
        BNE.W    ??AccSetMode_1
//   67 			if(pHandle->config.privateSetting[2] !=INTERRUPT_OFF){
        LDRB     R0,[R4, #+12]
        CMP      R0,#+0
        BEQ.W    ??AccSetMode_1
//   68 				data1 =pHandle->config.privateSetting[3];
        LDRB     R0,[R4, #+13]
        STRB     R0,[SP, #+0]
//   69 				data2 =0x00;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//   70 				if(Write(pHandle,BMI160_INT_MOTION_0_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+95
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_2
//   71 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//   72 				}
//   73 #ifdef BMI160_USE_MOTION
//   74 				data1 =BMI160_INT_EN_ANYMO_CONFIG;
??AccSetMode_2:
        MOVS     R0,#+7
        STRB     R0,[SP, #+0]
//   75 				if(Write(pHandle,BMI160_INT_EN_0_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+80
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_4
//   76 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//   77 				}
//   78 				data1 = pHandle->config.privateSetting[0];	 //any motion threshold setting by user
??AccSetMode_4:
        LDRB     R0,[R4, #+10]
        STRB     R0,[SP, #+0]
//   79 				if(Write(pHandle,BMI160_INT_MOTION_1_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+96
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_5
//   80 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//   81 				}
//   82 #endif
//   83 #ifdef BMI160_USE_NO_MOTION
//   84 				data1 =BMI160_INT_EN_NOMO_CONFIG;
??AccSetMode_5:
        MOVS     R0,#+7
        STRB     R0,[SP, #+0]
//   85 				if(Write(pHandle,BMI160_INT_EN_2_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+82
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_6
//   86 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//   87 				}
//   88 				data1 = pHandle->config.privateSetting[1];	 //non motion threshold setting by user
??AccSetMode_6:
        LDRB     R0,[R4, #+11]
        STRB     R0,[SP, #+0]
//   89 				if(Write(pHandle,BMI160_INT_MOTION_2_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+97
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_7
//   90 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//   91 				}
//   92 				data1 = BMI160_INT_EN_NOMO_SEL;	 
??AccSetMode_7:
        MOVS     R0,#+1
        STRB     R0,[SP, #+0]
//   93 				if(Write(pHandle,BMI160_INT_MOTION_3_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+98
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_8
//   94 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//   95 				}
//   96 				
//   97 #endif
//   98 				if(pHandle->config.privateSetting[2] == INTERRUPT_USE_INT1){	//int 1
??AccSetMode_8:
        LDRB     R0,[R4, #+12]
        CMP      R0,#+1
        BNE.N    ??AccSetMode_9
//   99 					data1 = BMI160_INT_1_OUTPUT_EN_CONFIG ;
        MOVS     R0,#+8
        STRB     R0,[SP, #+0]
//  100 					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+83
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_10
//  101 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  102 					}
//  103 					data2 =0x00;
??AccSetMode_10:
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  104 #ifdef BMI160_USE_MOTION
//  105 					data2 |=BMI160_INT_MAP_EN_ANYMO_CONFIG;
        LDRB     R0,[SP, #+1]
        ORRS     R0,R0,#0x4
        STRB     R0,[SP, #+1]
//  106 #endif
//  107 #ifdef BMI160_USE_NO_MOTION
//  108 					data2 |=BMI160_INT_MAP_EN_NOMO_CONFIG;
        LDRB     R0,[SP, #+1]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
//  109 #endif
//  110 					if(Write(pHandle,BMI160_INT_MAP_0_REG,&data2 ,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+85
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.W    ??AccSetMode_1
//  111 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  112 					}
//  113 				}else{	//int 2
//  114 					data1 = BMI160_INT_2_OUTPUT_EN_CONFIG ;
??AccSetMode_9:
        MOVS     R0,#+128
        STRB     R0,[SP, #+0]
//  115 					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+83
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_11
//  116 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  117 					}
//  118 					data2 =0x00;
??AccSetMode_11:
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  119 #ifdef BMI160_USE_MOTION
//  120 					data2 |=BMI160_INT_MAP_EN_ANYMO_CONFIG;
        LDRB     R0,[SP, #+1]
        ORRS     R0,R0,#0x4
        STRB     R0,[SP, #+1]
//  121 #endif
//  122 #ifdef BMI160_USE_NO_MOTION
//  123 					data2 |=BMI160_INT_MAP_EN_NOMO_CONFIG;
        LDRB     R0,[SP, #+1]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
//  124 #endif
//  125 					if(Write(pHandle,BMI160_INT_MAP_2_REG,&data2 ,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+87
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_1
//  126 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  127 					}
//  128 				}
//  129 			}
//  130 		}
//  131 	}else{
//  132 		if(BMI160.accMode == MODE_ACC_MOTION_INT){
??AccSetMode_0:
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+2]
        CMP      R0,#+7
        BNE.N    ??AccSetMode_1
//  133 			if(pHandle->config.privateSetting[2] !=INTERRUPT_OFF){
        LDRB     R0,[R4, #+12]
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_1
//  134 				data2 =0x00;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  135 #ifdef BMI160_USE_MOTION
//  136 				data1 =0x00;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  137 				if(Write(pHandle,BMI160_INT_EN_0_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+80
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_12
//  138 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  139 				}
//  140 #endif
//  141 #ifdef BMI160_USE_NO_MOTION
//  142 				data1 =0x00;
??AccSetMode_12:
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  143 				if(Write(pHandle,BMI160_INT_EN_2_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+82
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_13
//  144 					return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  145 				}				
//  146 #endif
//  147 				if(pHandle->config.privateSetting[2] == INTERRUPT_USE_INT1){	//int 1
??AccSetMode_13:
        LDRB     R0,[R4, #+12]
        CMP      R0,#+1
        BNE.N    ??AccSetMode_14
//  148 					data1 = 0x00 ;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  149 					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+83
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_15
//  150 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  151 					}
//  152 					data2 =0x00;
??AccSetMode_15:
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  153 					if(Write(pHandle,BMI160_INT_MAP_0_REG,&data2 ,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+85
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_1
//  154 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  155 					}
//  156 				}else{	//int 2
//  157 					data1 = 0x00 ;
??AccSetMode_14:
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  158 					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+83
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_16
//  159 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  160 					}
//  161 					data2 =0x00;
??AccSetMode_16:
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  162 					if(Write(pHandle,BMI160_INT_MAP_2_REG,&data2 ,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+87
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetMode_1
//  163 						return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetMode_3
//  164 					}
//  165 				}
//  166 			}
//  167 		}
//  168 	}
//  169 	return 0;
??AccSetMode_1:
        MOVS     R0,#+0
??AccSetMode_3:
        POP      {R1,R4,R5,PC}    ;; return
//  170 }
          CFI EndBlock cfiBlock6
//  171 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock7 Using cfiCommon0
          CFI Function AccSetRate
        THUMB
//  172 static int AccSetRate(pDriverHandle_t pHandle, int rate){
AccSetRate:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        SUB      SP,SP,#+8
          CFI CFA R13+24
        MOVS     R4,R0
        MOVS     R5,R1
//  173 	uint8_t data1 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  174 	uint8_t data2 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  175 	int rty = 0;
        MOVS     R6,#+0
//  176 retry:
//  177 	data1 = 0x20;
??AccSetRate_0:
        MOVS     R0,#+32
        STRB     R0,[SP, #+0]
//  178 	if(rate == FASTEST){
        CMP      R5,#+10
        BNE.N    ??AccSetRate_1
//  179 		data2 = data1 | BMI160_ACC_CONF_RATE_400;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0xA
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  180 	}else if(rate == GAME){
??AccSetRate_1:
        CMP      R5,#+20
        BNE.N    ??AccSetRate_3
//  181 		data2 = data1 | BMI160_ACC_CONF_RATE_400;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0xA
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  182 	}else if(rate == RATE_33){
??AccSetRate_3:
        CMP      R5,#+30
        BNE.N    ??AccSetRate_4
//  183 		data2 = data1 | BMI160_ACC_CONF_RATE_400;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0xA
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  184 	}else if(rate == RATE_25){
??AccSetRate_4:
        CMP      R5,#+40
        BNE.N    ??AccSetRate_5
//  185 		data2 = data1 | BMI160_ACC_CONF_RATE_100;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  186 	}else if(rate == UI){
??AccSetRate_5:
        CMP      R5,#+60
        BNE.N    ??AccSetRate_6
//  187 		data2 = data1 | BMI160_ACC_CONF_RATE_100;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  188 	}else if(rate == RATE_10){
??AccSetRate_6:
        CMP      R5,#+100
        BNE.N    ??AccSetRate_7
//  189 		data2 = data1 | BMI160_ACC_CONF_RATE_100;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  190 	}else if(rate == NORMAL){
??AccSetRate_7:
        CMP      R5,#+200
        BNE.N    ??AccSetRate_8
//  191 		data2 = data1 | BMI160_ACC_CONF_RATE_100;
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
        B.N      ??AccSetRate_2
//  192 	}else{
//  193 		data2 = data1 | BMI160_ACC_CONF_RATE_100;
??AccSetRate_8:
        LDRB     R0,[SP, #+0]
        ORRS     R0,R0,#0x8
        STRB     R0,[SP, #+1]
//  194 	}
//  195 	if(Write(pHandle,BMI160_ACC_CONF_REG,&data2 ,1)){
??AccSetRate_2:
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+64
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSetRate_9
//  196 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccSetRate_10
//  197 	}
//  198 	if(!Read(pHandle,BMI160_ACC_CONF_REG,&data1,1)){
??AccSetRate_9:
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+64
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BNE.N    ??AccSetRate_11
//  199 		if(data1 !=data2){
        LDRB     R0,[SP, #+0]
        LDRB     R1,[SP, #+1]
        CMP      R0,R1
        BEQ.N    ??AccSetRate_11
//  200 			if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
        CMP      R6,#+3
        BGE.N    ??AccSetRate_12
        ADDS     R6,R6,#+1
        B.N      ??AccSetRate_0
??AccSetRate_12:
        MVNS     R0,#+6
        B.N      ??AccSetRate_10
//  201 		}
//  202 	}
//  203 	return 0 ;
??AccSetRate_11:
        MOVS     R0,#+0
??AccSetRate_10:
        POP      {R1,R2,R4-R6,PC}  ;; return
//  204 }
          CFI EndBlock cfiBlock7
//  205 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock8 Using cfiCommon0
          CFI Function AccInit
          CFI NoCalls
        THUMB
//  206 static int AccInit(pDriverHandle_t pHandle, void *data)
//  207 {
AccInit:
        MOVS     R2,R0
//  208     BMI160.infoAccEn = 0;
        MOVS     R0,#+0
        LDR.W    R3,??DataTable11_2
        STRB     R0,[R3, #+0]
//  209 
//  210     return 0;
        MOVS     R0,#+0
        BX       LR               ;; return
//  211 }
          CFI EndBlock cfiBlock8
//  212 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock9 Using cfiCommon0
          CFI Function AccPowerOnCheck
        THUMB
//  213 int AccPowerOnCheck(pDriverHandle_t pHandle){
AccPowerOnCheck:
        PUSH     {R3-R5,LR}
          CFI R14 Frame(CFA, -4)
          CFI R5 Frame(CFA, -8)
          CFI R4 Frame(CFA, -12)
          CFI CFA R13+16
        MOVS     R4,R0
//  214     uint8_t data1 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  215     uint8_t data2 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  216     int rty = 0;
        MOVS     R5,#+0
//  217 
//  218     if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+3
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_0
//  219         return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  220     }
//  221     if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)==BMI160_PMU_ACC_NORMAL){
??AccPowerOnCheck_0:
        LDRB     R0,[SP, #+1]
        UBFX     R0,R0,#+4,#+2
        UXTB     R0,R0            ;; ZeroExt  R0,R0,#+24,#+24
        CMP      R0,#+1
        BNE.N    ??AccPowerOnCheck_2
//  222         return 0;//power mode correct
        MOVS     R0,#+0
        B.N      ??AccPowerOnCheck_1
//  223     }    
//  224 retry:
//  225 	data1 =BMI160_CMD_ACC_NORMAL;
??AccPowerOnCheck_2:
        MOVS     R0,#+17
        STRB     R0,[SP, #+0]
//  226 	if(Write(pHandle,BMI160_CMD_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+126
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_3
//  227 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  228 	}
//  229 	sleep(pHandle, BMI160_CMD_ACC_SWITCH_TIME);
??AccPowerOnCheck_3:
        MOVS     R1,#+40
        MOVS     R0,R4
          CFI FunCall sleep
        BL       sleep
//  230 	if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+3
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_4
//  231 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  232 	}
//  233 	if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_NORMAL){
??AccPowerOnCheck_4:
        LDRB     R0,[SP, #+1]
        UBFX     R0,R0,#+4,#+2
        UXTB     R0,R0            ;; ZeroExt  R0,R0,#+24,#+24
        CMP      R0,#+1
        BEQ.N    ??AccPowerOnCheck_5
//  234 		if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
        CMP      R5,#+3
        BGE.N    ??AccPowerOnCheck_6
        ADDS     R5,R5,#+1
        B.N      ??AccPowerOnCheck_2
??AccPowerOnCheck_6:
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  235 	}
//  236 
//  237 //switch to 4G	
//  238 	data1 =BMI160_ACC_RANGE_4G;
??AccPowerOnCheck_5:
        MOVS     R0,#+5
        STRB     R0,[SP, #+0]
//  239 	if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+65
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_7
//  240 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  241 	}
//  242 
//  243 	data1 =0x00;
??AccPowerOnCheck_7:
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  244 	if(Write(pHandle,0x6C,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+108
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_8
//  245 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  246 	}
//  247     if(AccSetRate(pHandle, BMI160.accRate)){
??AccPowerOnCheck_8:
        LDR.W    R0,??DataTable11_2
        LDRB     R1,[R0, #+1]
        MOVS     R0,R4
          CFI FunCall AccSetRate
        BL       AccSetRate
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_9
//  248         return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  249     }
//  250     if(AccSetMode(pHandle, BMI160.accMode)){
??AccPowerOnCheck_9:
        LDR.W    R0,??DataTable11_2
        LDRB     R1,[R0, #+2]
        MOVS     R0,R4
          CFI FunCall AccSetMode
        BL       AccSetMode
        CMP      R0,#+0
        BEQ.N    ??AccPowerOnCheck_10
//  251         return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccPowerOnCheck_1
//  252     }
//  253     return 0;
??AccPowerOnCheck_10:
        MOVS     R0,#+0
??AccPowerOnCheck_1:
        POP      {R1,R4,R5,PC}    ;; return
//  254 }
          CFI EndBlock cfiBlock9
//  255 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock10 Using cfiCommon0
          CFI Function AccEnable
        THUMB
//  256 static int AccEnable(pDriverHandle_t pHandle, void *data)
//  257 {
AccEnable:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        SUB      SP,SP,#+8
          CFI CFA R13+24
        MOVS     R4,R0
        MOVS     R5,R1
//  258 	uint8_t data1 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  259 	uint8_t data2 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  260 	int rty = 0;
        MOVS     R6,#+0
//  261 	
//  262 	if(BMI160.infoAccEn != 0){
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+0]
        CMP      R0,#+0
        BEQ.N    ??AccEnable_0
//  263             if(AccPowerOnCheck(pHandle)){
        MOVS     R0,R4
          CFI FunCall AccPowerOnCheck
        BL       AccPowerOnCheck
        CMP      R0,#+0
        BEQ.N    ??AccEnable_1
//  264                 return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccEnable_2
//  265             }
//  266 		BMI160.infoAccEn |= ((uint8_t)(1)<<BMI160_ACC_NORMAL_EN);
??AccEnable_1:
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+0]
        ORRS     R0,R0,#0x1
        LDR.W    R1,??DataTable11_2
        STRB     R0,[R1, #+0]
//  267 		return 0;
        MOVS     R0,#+0
        B.N      ??AccEnable_2
//  268 	}
//  269 
//  270 retry:
//  271 	data1 =BMI160_CMD_ACC_NORMAL;
??AccEnable_0:
        MOVS     R0,#+17
        STRB     R0,[SP, #+0]
//  272 	if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+126
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccEnable_3
//  273 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccEnable_2
//  274 	}
//  275 	sleep(pHandle, BMI160_CMD_ACC_SWITCH_TIME);
??AccEnable_3:
        MOVS     R1,#+40
        MOVS     R0,R4
          CFI FunCall sleep
        BL       sleep
//  276 	if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+3
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BEQ.N    ??AccEnable_4
//  277 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccEnable_2
//  278 	}
//  279 	if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_NORMAL){
??AccEnable_4:
        LDRB     R0,[SP, #+1]
        UBFX     R0,R0,#+4,#+2
        UXTB     R0,R0            ;; ZeroExt  R0,R0,#+24,#+24
        CMP      R0,#+1
        BEQ.N    ??AccEnable_5
//  280 		if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
        CMP      R6,#+3
        BGE.N    ??AccEnable_6
        ADDS     R6,R6,#+1
        B.N      ??AccEnable_0
??AccEnable_6:
        MVNS     R0,#+6
        B.N      ??AccEnable_2
//  281 	}
//  282 
//  283 //switch to 4G	
//  284 	data1 =BMI160_ACC_RANGE_4G;
??AccEnable_5:
        MOVS     R0,#+5
        STRB     R0,[SP, #+0]
//  285 	if(Write(pHandle,BMI160_ACC_RANGE_REG,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+65
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccEnable_7
//  286 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccEnable_2
//  287 	}
//  288 
//  289 	data1 =0x00;
??AccEnable_7:
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  290 	if(Write(pHandle,0x6C,&data1 ,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+108
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccEnable_8
//  291 		return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccEnable_2
//  292 	}
//  293 	BMI160.infoAccEn |= ((uint8_t)(1)<<BMI160_ACC_NORMAL_EN);
??AccEnable_8:
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+0]
        ORRS     R0,R0,#0x1
        LDR.W    R1,??DataTable11_2
        STRB     R0,[R1, #+0]
//  294 	return 0 ;
        MOVS     R0,#+0
??AccEnable_2:
        POP      {R1,R2,R4-R6,PC}  ;; return
//  295 }
          CFI EndBlock cfiBlock10
//  296 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock11 Using cfiCommon0
          CFI Function AccDisable
        THUMB
//  297 static int AccDisable(pDriverHandle_t pHandle, void *data)
//  298 {	
AccDisable:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        SUB      SP,SP,#+8
          CFI CFA R13+24
        MOVS     R4,R0
        MOVS     R5,R1
//  299     uint8_t data1 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+1]
//  300     uint8_t data2 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  301     int rty = 0;
        MOVS     R6,#+0
//  302     BMI160.infoAccEn &= ~(1<<BMI160_ACC_NORMAL_EN);
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+0]
        ANDS     R0,R0,#0xFE
        LDR.W    R1,??DataTable11_2
        STRB     R0,[R1, #+0]
//  303     if(BMI160.infoAccEn != 0){
        LDR.W    R0,??DataTable11_2
        LDRB     R0,[R0, #+0]
        CMP      R0,#+0
        BEQ.N    ??AccDisable_0
//  304         if(AccPowerOnCheck(pHandle)){
        MOVS     R0,R4
          CFI FunCall AccPowerOnCheck
        BL       AccPowerOnCheck
        CMP      R0,#+0
        BEQ.N    ??AccDisable_1
//  305             return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccDisable_2
//  306         }
//  307         return 0;
??AccDisable_1:
        MOVS     R0,#+0
        B.N      ??AccDisable_2
//  308     }
//  309     
//  310 retry:
//  311     data1 =BMI160_CMD_ACC_SUSPEND;
??AccDisable_0:
        MOVS     R0,#+16
        STRB     R0,[SP, #+1]
//  312     if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
        MOVS     R3,#+1
        ADD      R2,SP,#+1
        MOVS     R1,#+126
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccDisable_3
//  313         return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccDisable_2
//  314     }
//  315     sleep(pHandle, BMI160_CMD_ACC_SWITCH_TIME);
??AccDisable_3:
        MOVS     R1,#+40
        MOVS     R0,R4
          CFI FunCall sleep
        BL       sleep
//  316     if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+3
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BEQ.N    ??AccDisable_4
//  317         return CWM_ERROR_SPI;
        MVNS     R0,#+6
        B.N      ??AccDisable_2
//  318     }
//  319     if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_SUSPEND){
??AccDisable_4:
        LDRB     R0,[SP, #+0]
        UBFX     R0,R0,#+4,#+2
        UXTB     R0,R0            ;; ZeroExt  R0,R0,#+24,#+24
        CMP      R0,#+0
        BEQ.N    ??AccDisable_5
//  320         if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
        CMP      R6,#+3
        BGE.N    ??AccDisable_6
        ADDS     R6,R6,#+1
        B.N      ??AccDisable_0
??AccDisable_6:
        MVNS     R0,#+6
        B.N      ??AccDisable_2
//  321     }
//  322     return 0 ;
??AccDisable_5:
        MOVS     R0,#+0
??AccDisable_2:
        POP      {R1,R2,R4-R6,PC}  ;; return
//  323 }
          CFI EndBlock cfiBlock11
//  324 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock12 Using cfiCommon0
          CFI Function accDataVerify
        THUMB
//  325 static void accDataVerify(pDriverHandle_t pHandle, int16_t *datas16_raw)
//  326 {
accDataVerify:
        PUSH     {R3-R5,LR}
          CFI R14 Frame(CFA, -4)
          CFI R5 Frame(CFA, -8)
          CFI R4 Frame(CFA, -12)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
//  327     static int16_t Bmi160Accraw[3] = {0};
//  328     static uint64_t Bmi160Acctime = 0;
//  329     static uint8_t Bmi160AccCount = 0;
//  330 
//  331     if(((Bmi160Accraw[0] == datas16_raw[0]) && (Bmi160Accraw[1] == datas16_raw[1]) && (Bmi160Accraw[2] == datas16_raw[2])))
        LDR.W    R0,??DataTable11_3
        LDRSH    R0,[R0, #+0]
        LDRSH    R1,[R5, #+0]
        CMP      R0,R1
        BNE.N    ??accDataVerify_0
        LDR.W    R0,??DataTable11_3
        LDRSH    R0,[R0, #+2]
        LDRSH    R1,[R5, #+2]
        CMP      R0,R1
        BNE.N    ??accDataVerify_0
        LDR.W    R0,??DataTable11_3
        LDRSH    R0,[R0, #+4]
        LDRSH    R1,[R5, #+4]
        CMP      R0,R1
        BNE.N    ??accDataVerify_0
//  332     {
//  333         Bmi160AccCount ++;
        LDR.W    R0,??DataTable11_4
        LDRB     R0,[R0, #+0]
        ADDS     R0,R0,#+1
        LDR.W    R1,??DataTable11_4
        STRB     R0,[R1, #+0]
//  334         if(Bmi160Acctime ==0){
        LDR.W    R0,??DataTable11_5
        LDRD     R0,R1,[R0, #+0]
        MOVS     R2,#+0
        MOVS     R3,#+0
        CMP      R1,R3
        BNE.N    ??accDataVerify_1
        CMP      R0,R2
        BNE.N    ??accDataVerify_1
//  335         //initial error start time.
//  336         Bmi160Acctime =getTimeUs(pHandle);
        MOVS     R0,R4
          CFI FunCall getTimeUs
        BL       getTimeUs
        LDR.W    R2,??DataTable11_5
        STRD     R0,R1,[R2, #+0]
        B.N      ??accDataVerify_2
//  337         }else if(((getTimeUs(pHandle) -Bmi160Acctime) > 2000000) && (Bmi160AccCount >=10)){
??accDataVerify_1:
        MOVS     R0,R4
          CFI FunCall getTimeUs
        BL       getTimeUs
        LDR.W    R2,??DataTable11_5
        LDRD     R2,R3,[R2, #+0]
        SUBS     R0,R0,R2
        SBCS     R1,R1,R3
        LDR.W    R2,??DataTable11_6  ;; 0x1e8481
        MOVS     R3,#+0
        CMP      R1,R3
        BCC.N    ??accDataVerify_2
        BHI.N    ??accDataVerify_3
        CMP      R0,R2
        BCC.N    ??accDataVerify_2
??accDataVerify_3:
        LDR.W    R0,??DataTable11_4
        LDRB     R0,[R0, #+0]
        CMP      R0,#+10
        BLT.N    ??accDataVerify_2
//  338             Bmi160Acctime = 0;
        MOVS     R0,#+0
        MOVS     R1,#+0
        LDR.W    R2,??DataTable11_5
        STRD     R0,R1,[R2, #+0]
//  339             Bmi160AccCount = 0;
        MOVS     R0,#+0
        LDR.W    R1,??DataTable11_4
        STRB     R0,[R1, #+0]
//  340             error(pHandle, DATA_BLOCK, 0);
        MOVS     R2,#+0
        MVNS     R1,#+4
        MOVS     R0,R4
          CFI FunCall error
        BL       error
        B.N      ??accDataVerify_2
//  341         }
//  342     }else{
//  343         //reset value, because data not the same or error.
//  344         Bmi160Accraw[0] = datas16_raw[0];
??accDataVerify_0:
        LDRH     R0,[R5, #+0]
        LDR.W    R1,??DataTable11_3
        STRH     R0,[R1, #+0]
//  345         Bmi160Accraw[1] = datas16_raw[1];
        LDRH     R0,[R5, #+2]
        LDR.W    R1,??DataTable11_3
        STRH     R0,[R1, #+2]
//  346         Bmi160Accraw[2] = datas16_raw[2];
        LDRH     R0,[R5, #+4]
        LDR.W    R1,??DataTable11_3
        STRH     R0,[R1, #+4]
//  347         Bmi160Acctime = 0;
        MOVS     R0,#+0
        MOVS     R1,#+0
        LDR.W    R2,??DataTable11_5
        STRD     R0,R1,[R2, #+0]
//  348         Bmi160AccCount = 0;
        MOVS     R0,#+0
        LDR.W    R1,??DataTable11_4
        STRB     R0,[R1, #+0]
//  349     }
//  350 }
??accDataVerify_2:
        POP      {R0,R4,R5,PC}    ;; return
          CFI EndBlock cfiBlock12

        SECTION `.bss`:DATA:REORDER:NOROOT(2)
        DATA
`accDataVerify::Bmi160Accraw`:
        DS8 8

        SECTION `.bss`:DATA:REORDER:NOROOT(3)
        DATA
`accDataVerify::Bmi160Acctime`:
        DS8 8

        SECTION `.bss`:DATA:REORDER:NOROOT(0)
        DATA
`accDataVerify::Bmi160AccCount`:
        DS8 1
//  351 

        SECTION `.text`:CODE:NOROOT(2)
          CFI Block cfiBlock13 Using cfiCommon0
          CFI Function DriverBmi160AccGetData
        THUMB
//  352 int DriverBmi160AccGetData(pDriverHandle_t pHandle, void *data){
DriverBmi160AccGetData:
        PUSH     {R4-R8,LR}
          CFI R14 Frame(CFA, -4)
          CFI R8 Frame(CFA, -8)
          CFI R7 Frame(CFA, -12)
          CFI R6 Frame(CFA, -16)
          CFI R5 Frame(CFA, -20)
          CFI R4 Frame(CFA, -24)
          CFI CFA R13+24
        SUB      SP,SP,#+32
          CFI CFA R13+56
        MOVS     R4,R0
        MOVS     R5,R1
//  353     uint8_t tmpreg[6] ={0};
        ADD      R0,SP,#+8
        MOVS     R1,#+0
        MOVS     R2,#+0
        STRD     R1,R2,[R0, #+0]
//  354     int16_t datas16_raw[3];
//  355     float	senData[3];
//  356     int i=0;
        MOVS     R6,#+0
//  357     if(!Read(pHandle, BMI160_ACC_DATA_14_ACC_XL_REG,tmpreg,6)){
        MOVS     R3,#+6
        ADD      R2,SP,#+8
        MOVS     R1,#+18
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BNE.N    ??DriverBmi160AccGetData_0
//  358         for(i=0; i<3; i++){
        MOVS     R0,#+0
        MOVS     R6,R0
??DriverBmi160AccGetData_1:
        CMP      R6,#+3
        BGE.N    ??DriverBmi160AccGetData_2
//  359             datas16_raw[i] = (int16_t)((((int16_t)((signed char)tmpreg[2*i+1]))<< 8) | (tmpreg[2*i]));
        ADD      R0,SP,#+8
        ADD      R0,R0,R6, LSL #+1
        LDRSB    R0,[R0, #+1]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        ADD      R1,SP,#+8
        LDRB     R1,[R1, R6, LSL #+1]
        ORRS     R0,R1,R0, LSL #+8
        MOV      R1,SP
        STRH     R0,[R1, R6, LSL #+1]
//  360         } 
        ADDS     R6,R6,#+1
        B.N      ??DriverBmi160AccGetData_1
//  361         senData[0] = (float)datas16_raw[0] * BMI160_ACC_CONVERT_4G;
??DriverBmi160AccGetData_2:
        LDRSH    R0,[SP, #+0]
        VMOV     S0,R0
        VCVT.F32.S32 S0,S0
        VLDR.W   S1,??DataTable9  ;; 0x411ce7d5
        VMUL.F32 S0,S0,S1
        VLDR.W   S1,??DataTable9_1  ;; 0x46000000
        VDIV.F32 S0,S0,S1
        VSTR     S0,[SP, #+16]
//  362         senData[1] = (float)datas16_raw[1] * BMI160_ACC_CONVERT_4G;
        LDRSH    R0,[SP, #+2]
        VMOV     S0,R0
        VCVT.F32.S32 S0,S0
        VLDR.W   S1,??DataTable9  ;; 0x411ce7d5
        VMUL.F32 S0,S0,S1
        VLDR.W   S1,??DataTable9_1  ;; 0x46000000
        VDIV.F32 S0,S0,S1
        VSTR     S0,[SP, #+20]
//  363         senData[2] = (float)datas16_raw[2] * BMI160_ACC_CONVERT_4G;
        LDRSH    R0,[SP, #+4]
        VMOV     S0,R0
        VCVT.F32.S32 S0,S0
        VLDR.W   S1,??DataTable9  ;; 0x411ce7d5
        VMUL.F32 S0,S0,S1
        VLDR.W   S1,??DataTable9_1  ;; 0x46000000
        VDIV.F32 S0,S0,S1
        VSTR     S0,[SP, #+24]
//  364         senDataCb(pHandle, senData, NULL);
        MOVS     R2,#+0
        ADD      R1,SP,#+16
        MOVS     R0,R4
          CFI FunCall senDataCb
        BL       senDataCb
//  365         accDataVerify(pHandle, datas16_raw);
        MOV      R1,SP
        MOVS     R0,R4
          CFI FunCall accDataVerify
        BL       accDataVerify
//  366         memcpy(data, senData, sizeof(float)*3);
        MOVS     R7,#+12
        ADD      R8,SP,#+16
        MOVS     R2,R7
        MOV      R1,R8
        MOVS     R0,R5
          CFI FunCall __aeabi_memcpy
        BL       __aeabi_memcpy
//  367         return CWM_NON;
        MOVS     R0,#+0
        B.N      ??DriverBmi160AccGetData_3
//  368     }
//  369     return CWM_ERROR_SPI;
??DriverBmi160AccGetData_0:
        MVNS     R0,#+6
??DriverBmi160AccGetData_3:
        ADD      SP,SP,#+32
          CFI CFA R13+24
        POP      {R4-R8,PC}       ;; return
//  370 }
          CFI EndBlock cfiBlock13
//  371 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock14 Using cfiCommon0
          CFI Function AccGetStatus
        THUMB
//  372 int AccGetStatus(pDriverHandle_t pHandle, void *data){
AccGetStatus:
        PUSH     {R4,R5,LR}
          CFI R14 Frame(CFA, -4)
          CFI R5 Frame(CFA, -8)
          CFI R4 Frame(CFA, -12)
          CFI CFA R13+12
        SUB      SP,SP,#+12
          CFI CFA R13+24
        MOVS     R4,R0
        MOVS     R5,R1
//  373     uint8_t tmpreg[6] ={0};
        MOV      R0,SP
        MOVS     R1,#+0
        MOVS     R2,#+0
        STRD     R1,R2,[R0, #+0]
//  374     if(!Read(pHandle, 0x1C,tmpreg,2)){
        MOVS     R3,#+2
        MOV      R2,SP
        MOVS     R1,#+28
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BNE.N    ??AccGetStatus_0
//  375         if (tmpreg[0]& (1<<2)){
        LDRB     R0,[SP, #+0]
        LSLS     R0,R0,#+29
        BPL.N    ??AccGetStatus_1
//  376             return SENSOR_INTERRUPT_MOTION;
        MOVS     R0,#+1
        B.N      ??AccGetStatus_2
//  377         }else if (tmpreg[1]& (1<<7)){
??AccGetStatus_1:
        LDRB     R0,[SP, #+1]
        LSLS     R0,R0,#+24
        BPL.N    ??AccGetStatus_0
//  378             return SENSOR_INTERRUPT_NON_MOTION;
        MOVS     R0,#+2
        B.N      ??AccGetStatus_2
//  379         }
//  380     }
//  381     return 0;
??AccGetStatus_0:
        MOVS     R0,#+0
??AccGetStatus_2:
        POP      {R1-R5,PC}       ;; return
//  382 }
          CFI EndBlock cfiBlock14
//  383 

        SECTION `.text`:CODE:NOROOT(2)
          CFI Block cfiBlock15 Using cfiCommon0
          CFI Function AccGetInfo
        THUMB
//  384 int AccGetInfo(pDriverHandle_t pHandle, void *data){
AccGetInfo:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        VPUSH    {D8}
          CFI D8 Frame(CFA, -24)
          CFI CFA R13+24
        SUB      SP,SP,#+16
          CFI CFA R13+40
        MOVS     R4,R0
        MOVS     R5,R1
//  385     uint8_t tmpreg[6] ={0};
        ADD      R0,SP,#+8
        MOVS     R1,#+0
        MOVS     R2,#+0
        STRD     R1,R2,[R0, #+0]
//  386     int16_t datas16_raw[3];
//  387     float	temperature = 0;
        VLDR.W   S16,??DataTable10  ;; 0x0
//  388     uint8_t *pData = (uint8_t *)data;
        MOVS     R6,R5
//  389     if(!Read(pHandle, BMI160_TEMPERATURE_0_REG,tmpreg,2)){
        MOVS     R3,#+2
        ADD      R2,SP,#+8
        MOVS     R1,#+32
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BNE.N    ??AccGetInfo_0
//  390         datas16_raw[0] = (int16_t)((((int16_t)((signed char)tmpreg[1]))<< 8) | (tmpreg[0]));
        LDRSB    R0,[SP, #+9]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+8]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+0]
//  391         temperature = ((float)datas16_raw[0] /512.0f)+23.0f;
        LDRSH    R0,[SP, #+0]
        VMOV     S0,R0
        VCVT.F32.S32 S0,S0
        VLDR.W   S1,??DataTable10_1  ;; 0x44000000
        VDIV.F32 S0,S0,S1
        VMOV.F32 S1,#23.0
        VADD.F32 S0,S0,S1
        VMOV.F32 S16,S0
//  392         datas16_raw[0] = (int16_t)(temperature*100);
        VLDR.W   S0,??DataTable10_2  ;; 0x42c80000
        VMUL.F32 S0,S16,S0
        VCVT.S32.F32 S0,S0
        VMOV     R0,S0
        STRH     R0,[SP, #+0]
//  393         pData[0] = datas16_raw[0];
        LDRH     R0,[SP, #+0]
        STRB     R0,[R6, #+0]
//  394         pData[1] = datas16_raw[0]>>8;
        LDRSH    R0,[SP, #+0]
        ASRS     R0,R0,#+8
        STRB     R0,[R6, #+1]
//  395     }
//  396     return 0 ;
??AccGetInfo_0:
        MOVS     R0,#+0
        ADD      SP,SP,#+16
          CFI CFA R13+24
        VPOP     {D8}
          CFI D8 SameValue
          CFI CFA R13+16
        POP      {R4-R6,PC}       ;; return
//  397 }
          CFI EndBlock cfiBlock15

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9:
        DC32     0x411ce7d5

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable9_1:
        DC32     0x46000000
//  398 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock16 Using cfiCommon0
          CFI Function AccReset
          CFI NoCalls
        THUMB
//  399 int AccReset(pDriverHandle_t pHandle, void *data){
AccReset:
        MOVS     R2,R0
//  400     return 0 ;
        MOVS     R0,#+0
        BX       LR               ;; return
//  401 }
          CFI EndBlock cfiBlock16
//  402 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock17 Using cfiCommon0
          CFI Function AccSelftTest
        THUMB
//  403 int AccSelftTest(pDriverHandle_t pHandle, void *data){
AccSelftTest:
        PUSH     {R4-R7,LR}
          CFI R14 Frame(CFA, -4)
          CFI R7 Frame(CFA, -8)
          CFI R6 Frame(CFA, -12)
          CFI R5 Frame(CFA, -16)
          CFI R4 Frame(CFA, -20)
          CFI CFA R13+20
        SUB      SP,SP,#+28
          CFI CFA R13+48
        MOVS     R4,R0
        MOVS     R5,R1
//  404     uint8_t data1 = 0;
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  405     uint8_t tmpreg[6] ={0};
        ADD      R0,SP,#+4
        MOVS     R1,#+0
        MOVS     R2,#+0
        STRD     R1,R2,[R0, #+0]
//  406     int16_t acc_selft_data_positive[3] ={0};
        ADD      R0,SP,#+20
        MOVS     R1,#+0
        MOVS     R2,#+0
        STRD     R1,R2,[R0, #+0]
//  407     int16_t acc_selft_data_negative[3] ={0};
        ADD      R0,SP,#+12
        MOVS     R1,#+0
        MOVS     R2,#+0
        STRD     R1,R2,[R0, #+0]
//  408     int rty = 0;
        MOVS     R6,#+0
//  409     int status = NO_ERROR;
        MOVS     R7,#+0
//  410     if(AccEnable(pHandle, data))
        MOVS     R1,R5
        MOVS     R0,R4
          CFI FunCall AccEnable
        BL       AccEnable
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_0
//  411         return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  412 
//  413     //switch to 8G
//  414     data1 =BMI160_ACC_RANGE_8G;
??AccSelftTest_0:
        MOVS     R0,#+8
        STRB     R0,[SP, #+0]
//  415     if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) )
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+65
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_2
//  416         return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  417     
//  418     data1 =0x2c;
??AccSelftTest_2:
        MOVS     R0,#+44
        STRB     R0,[SP, #+0]
//  419     if(Write(pHandle, 0x40,&data1 ,1) )
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+64
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_3
//  420         return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  421     
//  422     sleep(pHandle, 100);
??AccSelftTest_3:
        MOVS     R1,#+100
        MOVS     R0,R4
          CFI FunCall sleep
        BL       sleep
//  423 retry:
//  424     
//  425     status = NO_ERROR;
??AccSelftTest_4:
        MOVS     R0,#+0
        MOVS     R7,R0
//  426     //test for x-axis positive
//  427     data1 =BMI160_ACC_SELF_TEST_AMPT | BMI160_ACC_SELF_TEST_SIGN | BMI160_ACC_SELF_TEST_AXIS_X_EN;
        MOVS     R0,#+13
        STRB     R0,[SP, #+0]
//  428     if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) )
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+109
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_5
//  429         return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  430     
//  431     sleep(pHandle, 100);
??AccSelftTest_5:
        MOVS     R1,#+100
        MOVS     R0,R4
          CFI FunCall sleep
        BL       sleep
//  432     if(!Read(pHandle, BMI160_ACC_DATA_14_ACC_XL_REG,tmpreg,6) ){
        MOVS     R3,#+6
        ADD      R2,SP,#+4
        MOVS     R1,#+18
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BNE.N    ??AccSelftTest_6
//  433         acc_selft_data_positive[0] = (int16_t)((((int16_t)((signed char)tmpreg[1]))<< 8) | (tmpreg[0]));
        LDRSB    R0,[SP, #+5]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+4]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+20]
//  434         acc_selft_data_positive[1] = (int16_t)((((int16_t)((signed char)tmpreg[3]))<< 8) | (tmpreg[2]));
        LDRSB    R0,[SP, #+7]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+6]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+22]
//  435         acc_selft_data_positive[2] = (int16_t)((((int16_t)((signed char)tmpreg[5]))<< 8) | (tmpreg[4]));
        LDRSB    R0,[SP, #+9]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+8]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+24]
//  436     }
//  437     //test for x-axis negative
//  438     data1 =BMI160_ACC_SELF_TEST_AMPT | BMI160_ACC_SELF_TEST_AXIS_X_EN;
??AccSelftTest_6:
        MOVS     R0,#+9
        STRB     R0,[SP, #+0]
//  439     if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) )
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+109
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_7
//  440         return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  441     
//  442     sleep(pHandle, 100);
??AccSelftTest_7:
        MOVS     R1,#+100
        MOVS     R0,R4
          CFI FunCall sleep
        BL       sleep
//  443     if(!Read(pHandle, BMI160_ACC_DATA_14_ACC_XL_REG,tmpreg,6) ){
        MOVS     R3,#+6
        ADD      R2,SP,#+4
        MOVS     R1,#+18
        MOVS     R0,R4
          CFI FunCall Read
        BL       Read
        CMP      R0,#+0
        BNE.N    ??AccSelftTest_8
//  444         acc_selft_data_negative[0] = (int16_t)((((int16_t)((signed char)tmpreg[1]))<< 8) | (tmpreg[0]));
        LDRSB    R0,[SP, #+5]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+4]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+12]
//  445         acc_selft_data_negative[1] = (int16_t)((((int16_t)((signed char)tmpreg[3]))<< 8) | (tmpreg[2]));
        LDRSB    R0,[SP, #+7]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+6]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+14]
//  446         acc_selft_data_negative[2] = (int16_t)((((int16_t)((signed char)tmpreg[5]))<< 8) | (tmpreg[4]));
        LDRSB    R0,[SP, #+9]
        SXTB     R0,R0            ;; SignExt  R0,R0,#+24,#+24
        LDRB     R1,[SP, #+8]
        ORRS     R0,R1,R0, LSL #+8
        STRH     R0,[SP, #+16]
//  447     }
//  448     //////////////////////////////////////////////////////////////////////////////////////////////////
//  449     //Check Criterion
//  450     if(abs(acc_selft_data_positive[0] - acc_selft_data_negative[0]) <BMI160_ACC_SELF_TEST_AXIS_X_RANGE){
??AccSelftTest_8:
        LDRSH    R0,[SP, #+20]
        LDRSH    R1,[SP, #+12]
        SUBS     R0,R0,R1
          CFI FunCall abs
        BL       abs
        MOVW     R1,#+3000
        CMP      R0,R1
        BGE.N    ??AccSelftTest_9
//  451         status = FAIL;
        MOVS     R0,#-1
        MOVS     R7,R0
//  452     }
//  453     if(abs(acc_selft_data_positive[0] - acc_selft_data_negative[0]) <BMI160_ACC_SELF_TEST_AXIS_Y_RANGE){
??AccSelftTest_9:
        LDRSH    R0,[SP, #+20]
        LDRSH    R1,[SP, #+12]
        SUBS     R0,R0,R1
          CFI FunCall abs
        BL       abs
        MOVW     R1,#+3000
        CMP      R0,R1
        BGE.N    ??AccSelftTest_10
//  454         status = FAIL;
        MOVS     R0,#-1
        MOVS     R7,R0
//  455     }
//  456     if(abs(acc_selft_data_positive[0] - acc_selft_data_negative[0]) <BMI160_ACC_SELF_TEST_AXIS_Z_RANGE){
??AccSelftTest_10:
        LDRSH    R0,[SP, #+20]
        LDRSH    R1,[SP, #+12]
        SUBS     R0,R0,R1
          CFI FunCall abs
        BL       abs
        MOVW     R1,#+1500
        CMP      R0,R1
        BGE.N    ??AccSelftTest_11
//  457         status = FAIL;
        MOVS     R0,#-1
        MOVS     R7,R0
//  458     }
//  459     if(status == FAIL){
??AccSelftTest_11:
        CMN      R7,#+1
        BNE.N    ??AccSelftTest_12
//  460         if(rty<2){rty++; goto retry;}
        CMP      R6,#+2
        BGE.N    ??AccSelftTest_12
        ADDS     R6,R6,#+1
        B.N      ??AccSelftTest_4
//  461     }
//  462     //////////////////////////////////////////////////////////////////////////////////////////////////
//  463     //Disable Selft Test
//  464     data1 =BMI160_SELF_TEST_DISABLE;
??AccSelftTest_12:
        MOVS     R0,#+0
        STRB     R0,[SP, #+0]
//  465     if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) )
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+109
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_13
//  466     return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  467     
//  468     //switch to 4G	
//  469     data1 =BMI160_ACC_RANGE_4G;
??AccSelftTest_13:
        MOVS     R0,#+5
        STRB     R0,[SP, #+0]
//  470     if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) )
        MOVS     R3,#+1
        MOV      R2,SP
        MOVS     R1,#+65
        MOVS     R0,R4
          CFI FunCall Write
        BL       Write
        CMP      R0,#+0
        BEQ.N    ??AccSelftTest_14
//  471         return I2C_FAIL;
        MVNS     R0,#+3
        B.N      ??AccSelftTest_1
//  472     
//  473     if(AccDisable(pHandle, data)){
??AccSelftTest_14:
        MOVS     R1,R5
        MOVS     R0,R4
          CFI FunCall AccDisable
        BL       AccDisable
//  474     }
//  475     
//  476 return status;
        MOVS     R0,R7
??AccSelftTest_1:
        ADD      SP,SP,#+28
          CFI CFA R13+20
        POP      {R4-R7,PC}       ;; return
//  477 }
          CFI EndBlock cfiBlock17
//  478 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock18 Using cfiCommon0
          CFI Function SPI_BMI160_CMD_ACC
        THUMB
//  479 static int SPI_BMI160_CMD_ACC(pDriverHandle_t pHandle, int cmd, void *data)
//  480 {
SPI_BMI160_CMD_ACC:
        PUSH     {R4-R6,LR}
          CFI R14 Frame(CFA, -4)
          CFI R6 Frame(CFA, -8)
          CFI R5 Frame(CFA, -12)
          CFI R4 Frame(CFA, -16)
          CFI CFA R13+16
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
//  481     switch(cmd)
        CMP      R5,#+0
        BEQ.N    ??SPI_BMI160_CMD_ACC_0
        CMP      R5,#+2
        BEQ.N    ??SPI_BMI160_CMD_ACC_1
        BCC.N    ??SPI_BMI160_CMD_ACC_2
        CMP      R5,#+4
        BEQ.N    ??SPI_BMI160_CMD_ACC_3
        BCC.N    ??SPI_BMI160_CMD_ACC_4
        CMP      R5,#+6
        BEQ.N    ??SPI_BMI160_CMD_ACC_5
        BCC.N    ??SPI_BMI160_CMD_ACC_6
        CMP      R5,#+8
        BEQ.N    ??SPI_BMI160_CMD_ACC_7
        BCC.N    ??SPI_BMI160_CMD_ACC_8
        CMP      R5,#+9
        BEQ.N    ??SPI_BMI160_CMD_ACC_9
        B.N      ??SPI_BMI160_CMD_ACC_10
//  482     {
//  483         case senInit:
//  484             return AccInit(pHandle, data);
??SPI_BMI160_CMD_ACC_0:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccInit
        BL       AccInit
        B.N      ??SPI_BMI160_CMD_ACC_11
//  485         case senEnable:
//  486             return AccEnable(pHandle, data);
??SPI_BMI160_CMD_ACC_2:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccEnable
        BL       AccEnable
        B.N      ??SPI_BMI160_CMD_ACC_11
//  487         case senDisable:
//  488             return AccDisable(pHandle, data);
??SPI_BMI160_CMD_ACC_1:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccDisable
        BL       AccDisable
        B.N      ??SPI_BMI160_CMD_ACC_11
//  489         case senSetRate:
//  490             BMI160.accRate = ((uint8_t *)data)[0];
??SPI_BMI160_CMD_ACC_4:
        LDRB     R0,[R6, #+0]
        LDR.N    R1,??DataTable11_2
        STRB     R0,[R1, #+1]
//  491             return AccSetRate(pHandle, BMI160.accRate);
        LDR.N    R0,??DataTable11_2
        LDRB     R1,[R0, #+1]
        MOVS     R0,R4
          CFI FunCall AccSetRate
        BL       AccSetRate
        B.N      ??SPI_BMI160_CMD_ACC_11
//  492         case senSetMode:
//  493             BMI160.accMode = ((int *)data)[0];
??SPI_BMI160_CMD_ACC_3:
        LDR      R0,[R6, #+0]
        LDR.N    R1,??DataTable11_2
        STRB     R0,[R1, #+2]
//  494             return AccSetMode(pHandle, BMI160.accMode);
        LDR.N    R0,??DataTable11_2
        LDRB     R1,[R0, #+2]
        MOVS     R0,R4
          CFI FunCall AccSetMode
        BL       AccSetMode
        B.N      ??SPI_BMI160_CMD_ACC_11
//  495         case senGetData:
//  496             return DriverBmi160AccGetData(pHandle, data);
??SPI_BMI160_CMD_ACC_6:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall DriverBmi160AccGetData
        BL       DriverBmi160AccGetData
        B.N      ??SPI_BMI160_CMD_ACC_11
//  497         case senGetStatus:
//  498             return AccGetStatus(pHandle, data);
??SPI_BMI160_CMD_ACC_5:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccGetStatus
        BL       AccGetStatus
        B.N      ??SPI_BMI160_CMD_ACC_11
//  499         case senGetInfo:
//  500             return AccGetInfo(pHandle, data);
??SPI_BMI160_CMD_ACC_8:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccGetInfo
        BL       AccGetInfo
        B.N      ??SPI_BMI160_CMD_ACC_11
//  501         case senReset:
//  502             return AccReset(pHandle, data);
??SPI_BMI160_CMD_ACC_7:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccReset
        BL       AccReset
        B.N      ??SPI_BMI160_CMD_ACC_11
//  503         case senSelftest:
//  504             return AccSelftTest(pHandle, data);
??SPI_BMI160_CMD_ACC_9:
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall AccSelftTest
        BL       AccSelftTest
        B.N      ??SPI_BMI160_CMD_ACC_11
//  505     }
//  506 
//  507     return 0;
??SPI_BMI160_CMD_ACC_10:
        MOVS     R0,#+0
??SPI_BMI160_CMD_ACC_11:
        POP      {R4-R6,PC}       ;; return
//  508 }
          CFI EndBlock cfiBlock18

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable10:
        DC32     0x0

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable10_1:
        DC32     0x44000000

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable10_2:
        DC32     0x42c80000

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock19 Using cfiCommon0
          CFI Function SPI_BMI160_CMD_GYRO
          CFI NoCalls
        THUMB
//  509 static int SPI_BMI160_CMD_GYRO(pDriverHandle_t pHandle, int cmd, void *data)
//  510 {
SPI_BMI160_CMD_GYRO:
        MOVS     R3,R0
//  511     switch(cmd)
        CMP      R1,#+0
        BEQ.N    ??SPI_BMI160_CMD_GYRO_0
        CMP      R1,#+2
        BEQ.N    ??SPI_BMI160_CMD_GYRO_1
        BCC.N    ??SPI_BMI160_CMD_GYRO_2
        CMP      R1,#+4
        BEQ.N    ??SPI_BMI160_CMD_GYRO_3
        BCC.N    ??SPI_BMI160_CMD_GYRO_4
        CMP      R1,#+6
        BEQ.N    ??SPI_BMI160_CMD_GYRO_5
        BCC.N    ??SPI_BMI160_CMD_GYRO_6
        CMP      R1,#+8
        BEQ.N    ??SPI_BMI160_CMD_GYRO_7
        BCC.N    ??SPI_BMI160_CMD_GYRO_8
        CMP      R1,#+9
        BEQ.N    ??SPI_BMI160_CMD_GYRO_9
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  512     {
//  513         case senInit:
//  514             break;
??SPI_BMI160_CMD_GYRO_0:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  515         case senEnable:
//  516             break;
??SPI_BMI160_CMD_GYRO_2:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  517         case senDisable:
//  518             break;
??SPI_BMI160_CMD_GYRO_1:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  519         case senSetRate:
//  520             break;
??SPI_BMI160_CMD_GYRO_4:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  521         case senSetMode:
//  522             break;
??SPI_BMI160_CMD_GYRO_3:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  523         case senGetData:
//  524             break;
??SPI_BMI160_CMD_GYRO_6:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  525         case senGetStatus:
//  526             break;
??SPI_BMI160_CMD_GYRO_5:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  527         case senGetInfo:
//  528             break;
??SPI_BMI160_CMD_GYRO_8:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  529         case senReset:
//  530             break;
??SPI_BMI160_CMD_GYRO_7:
        B.N      ??SPI_BMI160_CMD_GYRO_10
//  531         case senSelftest:
//  532             break;
//  533     }
//  534 
//  535     return 0;
??SPI_BMI160_CMD_GYRO_9:
??SPI_BMI160_CMD_GYRO_10:
        MOVS     R0,#+0
        BX       LR               ;; return
//  536 }
          CFI EndBlock cfiBlock19
//  537 

        SECTION `.text`:CODE:NOROOT(1)
          CFI Block cfiBlock20 Using cfiCommon0
          CFI Function SPI_BMI160_INIT
        THUMB
//  538 int SPI_BMI160_INIT(pDriverHandle_t pHandle, pDriverAPI pAPI, pDriverConfig pConfig)
//  539 {
SPI_BMI160_INIT:
        PUSH     {R3-R7,LR}
          CFI R14 Frame(CFA, -4)
          CFI R7 Frame(CFA, -8)
          CFI R6 Frame(CFA, -12)
          CFI R5 Frame(CFA, -16)
          CFI R4 Frame(CFA, -20)
          CFI CFA R13+24
        MOVS     R4,R0
        MOVS     R5,R1
        MOVS     R6,R2
//  540     if(pConfig->id != SPI_BMI160)
        LDR      R0,[R6, #+0]
        CMP      R0,#+0
        BEQ.N    ??SPI_BMI160_INIT_0
//  541         return -1;
        MOVS     R0,#-1
        B.N      ??SPI_BMI160_INIT_1
//  542     
//  543     memcpy(&pHandle->config, pConfig, sizeof(DriverConfig));
??SPI_BMI160_INIT_0:
        MOVS     R7,#+28
        MOVS     R2,R7
        MOVS     R1,R6
        MOVS     R0,R4
          CFI FunCall __aeabi_memcpy
        BL       __aeabi_memcpy
//  544     pHandle->api= pAPI;
        STR      R5,[R4, #+28]
//  545     
//  546     if(pConfig->type == TYPE_ACCELEROMETER)
        LDR      R0,[R6, #+4]
        CMP      R0,#+0
        BNE.N    ??SPI_BMI160_INIT_2
//  547         pHandle->Cmd = SPI_BMI160_CMD_ACC;
        LDR.N    R0,??DataTable11_7
        STR      R0,[R4, #+32]
//  548         
//  549     if(pConfig->type == TYPE_GYROSCOPE)
??SPI_BMI160_INIT_2:
        LDR      R0,[R6, #+4]
        CMP      R0,#+1
        BNE.N    ??SPI_BMI160_INIT_3
//  550         pHandle->Cmd = SPI_BMI160_CMD_GYRO;
        LDR.N    R0,??DataTable11_8
        STR      R0,[R4, #+32]
//  551     
//  552     return 0;
??SPI_BMI160_INIT_3:
        MOVS     R0,#+0
??SPI_BMI160_INIT_1:
        POP      {R1,R4-R7,PC}    ;; return
//  553 }
          CFI EndBlock cfiBlock20

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11:
        DC32     ?_6

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_1:
        DC32     ?_7

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_2:
        DC32     BMI160

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_3:
        DC32     `accDataVerify::Bmi160Accraw`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_4:
        DC32     `accDataVerify::Bmi160AccCount`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_5:
        DC32     `accDataVerify::Bmi160Acctime`

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_6:
        DC32     0x1e8481

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_7:
        DC32     SPI_BMI160_CMD_ACC

        SECTION `.text`:CODE:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
??DataTable11_8:
        DC32     SPI_BMI160_CMD_GYRO

        SECTION `.iar_vfe_header`:DATA:NOALLOC:NOROOT(2)
        SECTION_TYPE SHT_PROGBITS, 0
        DATA
        DC32 0

        SECTION __DLIB_PERTHREAD:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        SECTION __DLIB_PERTHREAD_init:DATA:REORDER:NOROOT(0)
        SECTION_TYPE SHT_PROGBITS, 0

        END
//  554 
//  555 
//  556 #endif /* __DriverHal_H__ */
// 
//    21 bytes in section .bss
//    80 bytes in section .rodata
// 3 180 bytes in section .text
// 
// 3 180 bytes of CODE  memory
//    80 bytes of CONST memory
//    21 bytes of DATA  memory
//
//Errors: none
//Warnings: none
