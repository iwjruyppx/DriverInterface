
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

float gData[3];
int  gDataInt[3];
void dataCb(pDriverConfig drvInfo, float *data, void *reserved){
    int i;
    memcpy(gData, data, sizeof(float)*3);
    for(i=0;i<3;i++)
        gDataInt[i] = gData[i] * 1000;
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

int accEn(int en)
{
    if(en)
        return accHandle.Cmd(&accHandle, senEnable, NULL);
    else
        return accHandle.Cmd(&accHandle, senDisable, NULL);        
}

int accSetRate(int rate)
{
    uint8_t u8rate = (uint8_t) rate;
    return accHandle.Cmd(&accHandle, senSetRate, &u8rate);
}

void accSendataProcess(void)
{
    accHandle.Cmd(&accHandle, senGetData, NULL);
}

int accSenDataTest(void)
{
    int count = 0;
    accEn(1);
    accSetRate(FASTEST);
    osDelay(100);
    for (;;)
    {
        accSendataProcess();
        osDelay(10);
        if (count++ > 1000)
        {
            count = 0;
            break;
        }
    }
    accEn(0);
    osDelay(100);
    for (;;)
    {
        accSendataProcess();
        osDelay(10);
    }
}

int gyroEn(int en)
{
    if(en)
        return gyroHandle.Cmd(&gyroHandle, senEnable, NULL);
    else
        return gyroHandle.Cmd(&gyroHandle, senDisable, NULL);
}

int gyroSetRate(int rate)
{
    uint8_t u8rate = (uint8_t) rate;
    return gyroHandle.Cmd(&gyroHandle, senSetRate, &u8rate);
}

int gyroSenDataTest(void)
{
    int count = 0;
    gyroEn(1);
    gyroSetRate(FASTEST);
    osDelay(100);
    for (;;)
    {
        gyroHandle.Cmd(&gyroHandle, senGetData, NULL);
        osDelay(10);
        if (count++ > 1000)
        {
            count = 0;
            break;
        }
    }
    gyroEn(0);
    for (;;)
    {
        gyroHandle.Cmd(&gyroHandle, senGetData, NULL);
        osDelay(10);
    }
}

static int accSelfTestStatus = 0;
static int gyroSelfTestStatus = 0;
static void CWM_Task(const void *argument)
{  
    driver_init();
    int testCase = 11;

    switch (testCase)
    {
        case 0:
            accSenDataTest();
            break;
        case 1:
            accSelfTestStatus =  accHandle.Cmd(&accHandle, senSelftest, NULL);
            break;
        case 11:
            gyroSenDataTest();
            break;
        case 12:
            gyroSelfTestStatus =  gyroHandle.Cmd(&gyroHandle, senSelftest, NULL);
            break;
        default:
            break;
    }
    
    for (;;)
    {
        osDelay(10);
    }
}

void CWM_TASK_INIT(void)
{

    osThreadDef(Task_Name, CWM_Task, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
    osThreadCreate(osThread(Task_Name), NULL);
}

