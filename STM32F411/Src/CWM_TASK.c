
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "CWM_TASK.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#define Task_Name "CWMTask"

extern SPI_HandleTypeDef hspi2;

static void cwm_logout_cb(const char *msg ,...)
{ 
    /* print the log here!! */
    //static char log[32] = {0};
    //memcpy(log, msg, sizeof(char)*32);
}

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

static void CWM_Task(const void *argument)
{  

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

