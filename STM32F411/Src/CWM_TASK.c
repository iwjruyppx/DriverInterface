
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "CWM_TASK.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#include "DriverHal_1_0_Config.h"
#include "DriverHal_1_0.h"

#define Task_Name "CWMTask"

extern SPI_HandleTypeDef hspi2;

DriverHandle_t accHandle;
DriverHandle_t gyroHandle;
DriverAPI driverAPI;

static int spiWrite(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite )
{
    uint8_t pTxData[255];
    uint8_t pRxData[255];
    int status;
    pTxData[0] = WriteAddr;
    memcpy(&pTxData[1], pBuffer, NumByteToWrite);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    status = HAL_SPI_TransmitReceive(&hspi2, pTxData, pRxData, NumByteToWrite + 1, 100);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
    return status;
}
static int spiRead(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead )
{
    uint8_t pTxData[255];
    uint8_t pRxData[255];
    int status;
    pTxData[0] = ReadAddr;
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
    status = HAL_SPI_TransmitReceive(&hspi2, pTxData, pRxData, NumByteToRead + 1, 100);
    memcpy(pBuffer, &pRxData[1], NumByteToRead);
    HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
    return status;
}

static int read(pBusTxRxPackage info)
{
    return spiRead(info->data, (info->reg |0x80), info->len);
}
static int write(pBusTxRxPackage info)
{
    return spiWrite(info->data, info->reg, info->len);
}

void uSleep(uint32_t us){
    uint32_t ms = (us+1000)/1000;
    osDelay(ms);
}

int64_t GetTimeNs(void)
{
    int64_t time = osKernelSysTick();
    return time*1000000ll;
}

void error(int error, void *data){
}

float gAccData[3];
void dataCb(pDriverConfig drvInfo, float *data, void *reserved){
    memcpy(gAccData, data, sizeof(float)*3);
}

static void driver_init(void)
{
    DriverConfig Config;
    
    driverAPI.Read = read;
    driverAPI.Write = write;
    driverAPI.uSleep = uSleep;
    driverAPI.GetTimeNs= GetTimeNs;
    driverAPI.Error= error;
    driverAPI.DataCb= dataCb;

    Config.id = SPI_BMI160;
    Config.type = TYPE_ACCELEROMETER;
    Config.slaveAddr = 0x00;
    Config.privateSetting[0] = 0x02;
    Config.privateSetting[1] = 0x04;
    Config.privateSetting[2] = INTERRUPT_USE_INT2;
    Config.privateSetting[3] = 0x0B;
    DriverInit(&accHandle, &driverAPI, &Config);
    
    Config.id = SPI_BMI160;
    Config.type= TYPE_GYROSCOPE;
    Config.slaveAddr = 0x00;
    Config.privateSetting[0] = 0x00;
    Config.privateSetting[1] = 0x00;
    Config.privateSetting[2] = 0x00;
    Config.privateSetting[3] = 0x00;
    DriverInit(&gyroHandle, &driverAPI, &Config);
}

/*
    senInit 	= 0,
    senEnable,
    senDisable,
    senSetRate,
    senSetMode,
    senGetData,
    senGetStatus,
    senGetInfo,
    senReset,
    senSelftest,
*/

int accEn(void)
{
    return accHandle.Cmd(&accHandle, senEnable, NULL);
}

int accSetRate(int rate)
{
    uint8_t u8rate = (uint8_t) rate;
    return accHandle.Cmd(&accHandle, senSetRate, &u8rate);
}

void dataProcess(void)
{
    accHandle.Cmd(&accHandle, senGetData, NULL);
}

static void CWM_Task(const void *argument)
{  
    driver_init();
    accEn();
    accSetRate(FASTEST);
    osDelay(100);
    for (;;)
    {
        dataProcess();
        osDelay(10);
    }
}

void CWM_TASK_INIT(void)
{

    osThreadDef(Task_Name, CWM_Task, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
    osThreadCreate(osThread(Task_Name), NULL);
}

