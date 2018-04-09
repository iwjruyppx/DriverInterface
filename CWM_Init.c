
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

#include "OsApi.h"
#include "DrvHal.h"

static void Driver_Init(void)
{
    pCWMHandle_t pHandle;
    pOsAPI api = getOsAPI();
    
    pHandle = tidAlloc();
    if(pHandle != NULL)
    {
        DriverConfig config;
        config.sensor = I2C_BMI160;
        config.index = 0;
        config.i2cDev.slaveAddr = 0x84;
        DriverInit(pHandle, &config, api);
    }
    pHandle = tidAlloc();
    if(pHandle != NULL)
    {
        DriverConfig config;
        config.sensor = SPI_BMI160;
        config.index = 1;
        config.spiDev.csPin = 199;
        DriverInit(pHandle, &config, api);
    }
}

static void algoInit(void)
{

}

void CWM_INIT(void)
{
    Driver_Init();
    algoInit();
}
