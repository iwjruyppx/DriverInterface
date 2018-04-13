
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Event.h"
#include "CWM_ErrorCode.h"
#include "CWM_Interface.h"
#include "CWM_SensorList.h"
#include "CWM_Utility.h"

#include "OsApi.h"
#include "DrvHal.h"

#include "SenHal.h"
#include "DrvI2C_AKM09911_Struct.h"
#include "DrvI2C_AKM09911.h"
#include "LIB_API_AKM09911.h"

#include "CWM_StateMachine.h"
#include "sensorManager.h"

#define AK09911_CNTL3_SOFT_RESET			0x01

static uint32_t MagRates[] = {
    SENSOR_HZ(25.0f/8.0f),
    SENSOR_HZ(25.0f/4.0f),
    SENSOR_HZ(25.0f/2.0f),
    SENSOR_HZ(25.0f),
    SENSOR_HZ(50.0f),
    SENSOR_HZ(100.0f),
    SENSOR_HZ(200.0f),
    SENSOR_HZ(400.0f),
    0,
};

#define DEC_INFO(name, rates, type, axis, samples) \
    .sensorName = name, \
    .supportedRates = rates, \
    .sensorType = type, \
    .numAxis = axis, \
    .minSamples = samples
    
#define DEC_OPS(power, rate, cfg, cal, test) \
    .sensorPower = power, \
    .sensorSetRate = rate, \
    .sensorCfgData = cfg, \
    .sensorCalibrate = cal, \
    .sensorSelfTest = test

static int magStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pSPI_AKM09911_t p = (pSPI_AKM09911_t)pH->mem;
    
    p->sensor[MAG].active = on;
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);

    if(on){

    }else{
        return AKM_DISABLE(pH);
    }
    return CWM_NON;
}

static int magSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pSPI_AKM09911_t p = (pSPI_AKM09911_t)pH->mem;
    
    p->sensor[MAG].rate= rate;
    p->sensor[MAG].latency= latency;
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    return AKM_ENABLE(pH, rate);
}

static int magGetData(pCWMHandle_t pH, int64_t timestamp)
{
    SensorEVT_t sensor;
    pSPI_AKM09911_t p = (pSPI_AKM09911_t)pH->mem;
    
    if(!p->sensor[MAG].active)
        return CWM_NON;

    if(AKM_GET_DATA(pH, &sensor)<0)
        return CWM_ERROR_I2C;
    
    sensor.sensorType = SENS_TYPE_MAG;
    sensor.index = p->config.index;
    sensor.timestamp = timestamp;
    return MGR_SensorUpdate(&sensor);
}


static int magCfgData(void *handle, void *data, void *cookie)
{

    return CWM_NON;
}

static int magCalibration(void *handle, void *cookie)
{

    return CWM_NON;
}

static int magSelfTest(void *handle, void *cookie)
{

    return CWM_NON;
}

static const SensorInfo mSensorInfo[NUM_OF_SENSOR] =
{
    {DEC_INFO("Magnetometer", MagRates, SENS_TYPE_MAG, 3, 1)},
};

static const SensorOps mSensorOps[NUM_OF_SENSOR] =
{
    { DEC_OPS(magStepPower, magSetRate, magCfgData, magCalibration, magSelfTest) },
};

static int SPI_AKM09911_CMD(void *pHandle, uint32_t evtType, void* evtData)
{
    pCWMHandle_t pH = (pCWMHandle_t)pHandle;
    int64_t *time = evtData;

    switch(evtType)
    {
        case EVT_TIMER_10MS_TRIGGER:
            magGetData(pH, time[0]);
            break;
        case EVT_SYSTEM_INIT:
            AKM_INIT(pH);
            osUnSubscribeEvent(EVT_SYSTEM_INIT, pH->tid);
            break;
    }
    
    return 0;
}


int drvI2C_AKM09911(pCWMHandle_t pHandle, pDriverConfig config, pOsAPI api)
{
    if(config->sensor!= I2C_AKM09911)
        return CWM_ERROR;

    pSPI_AKM09911_t p;

    pHandle->handleEvent = SPI_AKM09911_CMD;
    pHandle->mem = api->malloc(sizeof(SPI_AKM09911_t));
    
    p = (pSPI_AKM09911_t)pHandle->mem;
    p->api = api;
    memcpy(&p->config, config, sizeof(DriverConfig));
    
    for (int i = 0; i < NUM_OF_SENSOR; i++) {
        if(sensorRegister(pHandle, p->config.index, &mSensorInfo[i], &mSensorOps[i]))
            return CWM_ERROR_NO_INITIAL;
    }
    
    osSubscribeEvent(EVT_SYSTEM_INIT, pHandle->tid);
    return CWM_NON;
}
