
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Interface.h"
#include "CWM_SensorList.h"
#include "CWM_Utility.h"
#include "CWM_StateMachine.h"

#include "OsApi.h"
#include "DrvHal.h"
#include "SenHal.h"
#include "AlgoHal.h"

static void Driver_Init(void)
{
    pCWMHandle_t pHandle;
    pOsAPI api = getOsAPI();
    
    pHandle = tidAlloc();
    if(pHandle != NULL)
    {
        DriverConfig config;
        config.sensor = I2C_AKM09911;
        config.index = 0;
        config.slaveAddr = 0x84;
        DriverInit(pHandle, &config, api);
    }
    pHandle = tidAlloc();
    if(pHandle != NULL)
    {
        DriverConfig config;
        config.sensor = I2C_BMI160;
        config.index = 0;
        config.csPin = 199;
        DriverInit(pHandle, &config, api);
    }
    pHandle = tidAlloc();
    if(pHandle != NULL)
    {
        DriverConfig config;
        config.sensor = SPI_BMI160;
        config.index = 1;
        config.csPin = 199;
        DriverInit(pHandle, &config, api);
    }
}

static void algoInit(void)
{
    pCWMHandle_t pHandle;
    pOsAPI api = getOsAPI();
    
    pHandle = tidAlloc();
    if(pHandle != NULL)
    {
        AlgoConfig config;
        config.sensor = ALGO_FUSION;
        config.index = 0;
        AlgoInit(pHandle, &config, api);
    }
}

void CWM_INIT(void)
{
    CWM_StateMachineInit();
    Driver_Init();
    algoInit();    
}
