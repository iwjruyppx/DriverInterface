
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "CWM_TASK1.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#include "SensorsManagerApi.h"

#define Task_Name "CWMTask1"

extern SPI_HandleTypeDef hspi2;
volatile uint64_t timestamp;

SensorsDataEvent_T gSenData[5];

int CW_I2C_Write_MutiByte(uint8_t DeviceAddr, uint8_t RegAddr, uint8_t* pBuffer, uint16_t NumByteToWrite)
{
    return 0;
}

int CW_I2C_Read(uint8_t DeviceAddr, uint8_t RegAddr,uint8_t* pBuffer, uint16_t NumByteToRead)
{
    return 0;
}

int spiWrite(uint8_t *pBuffer, uint8_t WriteAddr, uint16_t NumByteToWrite )
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
int spiRead(uint8_t *pBuffer, uint8_t ReadAddr, uint16_t NumByteToRead )
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

static void uSleep(uint32_t us){
    uint32_t ms = (us+1000)/1000;
    osDelay(ms);
}

static int64_t GetTimeNs(void)
{
    int64_t time = osKernelSysTick();
    return time*1000000ll;
}

static void error(int error, void *data){
}

int LOGE(const char * format,...){
	return 0;
}

int	SensorsManagerAPISetting(void){
	SensorsInit_T AccInit;
	SensorsInit_T GyroInit;

	/*ACC*/
	AccInit.hw_id = SPI_BMI160;
	AccInit.deviceaddr= 0xD2;		//D0 | D2
	AccInit.rate= FASTEST;
	AccInit.mode= MODE_ACC_MOTION_INT;
	AccInit.position= 5;
	AccInit.private_setting[0] = 0x02;
	AccInit.private_setting[1] = 0x04;
	AccInit.private_setting[2] = INTERRUPT_USE_INT2;
	SensorsManagerAPIInitSensor(ACCELERATION, &AccInit);
   
	/*GYRO*/
	GyroInit.hw_id = SPI_BMI160;
	GyroInit.deviceaddr= 0xD2;
	GyroInit.rate= FASTEST;
	GyroInit.mode= MODE_GYRO_FIFO_STREAM;
	GyroInit.position= 5;
	SensorsManagerAPIInitSensor(GYRO, &GyroInit);
	return 0;
}

int SensorsManagerAPICallBack(SensorsDataEvent_T *data){
    if(data->id == ACCELERATION)
        memcpy(&gSenData[0], data, sizeof(SensorsDataEvent_T));
    if(data->id == AIRMOUSE)
    {
        memcpy(&gSenData[1], data, sizeof(SensorsDataEvent_T));
     //   printf("%2d,%2d,%2d\n",(int)data->data[0],(int)data->data[1],(int)data->data[2]);
    }
    if(data->id == GAME_ROTATION_VECTOR)
        memcpy(&gSenData[2], data, sizeof(SensorsDataEvent_T));
    return 0;
}

int SensorsManagerAPIDataQueueOutput(SensorsDataEvent_T *data){
    SensorsManagerAPIDataQueueInput(data);
    return 0;
}

int SensorsManagerAPICalibratorCallBack(CALIBRATOR_STATUS status){
	return 0;
}

void SensorsManagerFloatToUint8(float *data,  uint8_t *dataI2c,int ratio){
	int16_t	temp_data[3] = {0};
	temp_data[0] = (int16_t)(data[0]*ratio);
	temp_data[1] = (int16_t)(data[1]*ratio);
	temp_data[2] = (int16_t)(data[2]*ratio);
	memcpy(dataI2c,temp_data,sizeof(uint8_t)*6);
}

int SensorsManagerAPIDelay(int ms){
	uSleep(ms*1000);
	return 0;
}

int SensorsManagerAPISetMagStaticCalibratorData(int HwId,void *data, int size){
	return 0;
}

int SensorsManagerAPIErrorCallBack(int error, int data){

    return 0;
}


void CWM_LIBRARY_INIT(void)
{

}

static void CWM_Task1(const void *argument)
{  
#if 1
    SensorsManagerAPIEnable(CustomerHandle,ACCELERATION);
    SensorsManagerAPISetRate(CustomerHandle,ACCELERATION,NORMAL);
    #endif
    osDelay(10);
    SensorsManagerAPIEnable(CustomerHandle,AIRMOUSE);
    SensorsManagerAPISetRate(CustomerHandle,AIRMOUSE,GAME);
    SensorsManagerAPIEnable(CustomerHandle,GAME_ROTATION_VECTOR);
    SensorsManagerAPISetRate(CustomerHandle,GAME_ROTATION_VECTOR,GAME);
    for (;;)
    {
        SensorsManagerAPIProcess();
        osDelay(10);
        timestamp +=10000;
    }
}

void CWM_TASK1_INIT(void)
{
    
    SensorsManagerAPIInit();

    osThreadDef(Task_Name, CWM_Task1, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
    osThreadCreate(osThread(Task_Name), NULL);
}

