
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
#include "DrvSPI_BMI160.h"

#include "CWM_StateMachine.h"
#include "sensorManager.h"

enum SensorIndex {
    ACC = 0,
    GYR,
    NUM_OF_SENSOR,
};

typedef struct {
    uint64_t latency;
    uint32_t rate;
    uint8_t active;
} Bmi160Sensor_t, *pBmi160Sensor_t;

typedef struct {
    DriverConfig config;
    pOsAPI api;
    Bmi160Sensor_t sensor[NUM_OF_SENSOR];
} SPI_BMI160_t, *pSPI_BMI160_t;

static uint32_t AccRates[] = {
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

static uint32_t GyrRates[] = {
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
    
static int accStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pSPI_BMI160_t p = (pSPI_BMI160_t)pH->mem;
    p->sensor[ACC].active = on;
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);
    return CWM_NON;
}
static int accSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pSPI_BMI160_t p = (pSPI_BMI160_t)pH->mem;
    p->sensor[ACC].rate= rate;
    p->sensor[ACC].latency= latency;
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    return CWM_NON;
}

static int accCfgData(void *handle, void *data, void *cookie)
{

    return CWM_NON;
}

static int accCalibration(void *handle, void *cookie)
{

    return CWM_NON;
}

static int accSelfTest(void *handle, void *cookie)
{

    return CWM_NON;
}

static int gyrStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pSPI_BMI160_t p = (pSPI_BMI160_t)pH->mem;
    p->sensor[GYR].active = on;
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);
    
    return CWM_NON;
}
static int gyrSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pSPI_BMI160_t p = (pSPI_BMI160_t)pH->mem;
    p->sensor[GYR].rate= rate;
    p->sensor[GYR].latency= latency;
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    return CWM_NON;
}

static int gyrCfgData(void *handle, void *data, void *cookie)
{

    return CWM_NON;
}

static int gyrCalibration(void *handle, void *cookie)
{

    return CWM_NON;
}

static int gyrSelfTest(void *handle, void *cookie)
{

    return CWM_NON;
}

static const SensorInfo mSensorInfo[NUM_OF_SENSOR] =
{
    {DEC_INFO("Accelerometer", AccRates, SENS_TYPE_ACCEL, 3, 1)},
    {DEC_INFO("Gyroscope", GyrRates, SENS_TYPE_GYRO, 3, 1)},
};

static const SensorOps mSensorOps[NUM_OF_SENSOR] =
{
    { DEC_OPS(accStepPower, accSetRate, accCfgData, accCalibration, accSelfTest) },
    { DEC_OPS(gyrStepPower, gyrSetRate, gyrCfgData, gyrCalibration, gyrSelfTest) },
};


static int SPI_BMI160_CMD(void *pHandle, uint32_t evtType, void* evtData)
{
    pCWMHandle_t pH = (pCWMHandle_t)pHandle;
    pSPI_BMI160_t p = (pSPI_BMI160_t)pH->mem;
    uint32_t *time = evtData;
    
    SensorEVT_t sensor;

    switch(evtType)
    {
        case EVT_TIMER_5MS_TRIGGER:
            
            if(p->sensor[ACC].active)
            {
                sensor.sensorType = SENS_TYPE_ACCEL;
                sensor.index = p->config.index;
                sensor.fData[0] = 0.0f;
                sensor.fData[1] = 0.0f;
                sensor.fData[2] = 9.81f;
                sensor.timestamp = ((int64_t)time[0])*1000000;
                MGR_SensorUpdate(&sensor);
            }
            if(p->sensor[GYR].active)
            {
                sensor.sensorType = SENS_TYPE_GYRO;
                sensor.index = p->config.index;
                sensor.fData[0] = 0.0f;
                sensor.fData[1] = 0.0f;
                sensor.fData[2] = 0.1f;
                sensor.timestamp = ((int64_t)time[0])*1000000;
                MGR_SensorUpdate(&sensor);
            }
            break;
        case EVT_TIMER_10MS_TRIGGER:
            printf("[%d,%s]%s,%d\n", __LINE__, __FUNCTION__, "EVT_TIMER_10MS_TRIGGER", time[0]);
            break;
        case EVT_TIMER_20MS_TRIGGER:
            printf("[%d,%s]%s,%d\n", __LINE__, __FUNCTION__, "EVT_TIMER_20MS_TRIGGER", time[0]);
            break;
        case EVT_TIMER_100MS_TRIGGER:
            printf("[%d,%s]%s,%d\n", __LINE__, __FUNCTION__, "EVT_TIMER_100MS_TRIGGER", time[0]);
            break;
        case EVT_TIMER_1000MS_TRIGGER:
            printf("[%d,%s]%s,%d\n", __LINE__, __FUNCTION__, "EVT_TIMER_1000MS_TRIGGER", time[0]);
            break;
    }
    
    return 0;
}


int drvSPI_BMI160(pCWMHandle_t pHandle, pDriverConfig config, pOsAPI api)
{
    if(config->sensor!= SPI_BMI160)
        return CWM_ERROR;

    pSPI_BMI160_t p;

    pHandle->handleEvent = SPI_BMI160_CMD;
    pHandle->mem = api->malloc(sizeof(SPI_BMI160_t));
    
    p = (pSPI_BMI160_t)pHandle->mem;
    p->api = api;
    memcpy(&p->config, config, sizeof(DriverConfig));
    
    for (int i = 0; i < NUM_OF_SENSOR; i++) {
        if(sensorRegister(pHandle, p->config.index, &mSensorInfo[i], &mSensorOps[i]))
            return CWM_ERROR_NO_INITIAL;
    }
    osSubscribeEvent(EVT_TIMER_5MS_TRIGGER, pHandle->tid);
    #if 0
    osSubscribeEvent(EVT_TIMER_10MS_TRIGGER, pHandle->tid);
    osSubscribeEvent(EVT_TIMER_20MS_TRIGGER, pHandle->tid);
    osSubscribeEvent(EVT_TIMER_100MS_TRIGGER, pHandle->tid);
    osSubscribeEvent(EVT_TIMER_1000MS_TRIGGER, pHandle->tid);
    #endif
    return CWM_NON;
}
