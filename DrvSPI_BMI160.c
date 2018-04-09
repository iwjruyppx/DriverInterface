
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_ErrorCode.h"
#include "CWM_Interface.h"
#include "CWM_SensorList.h"
#include "CWM_Utility.h"

#include "OsApi.h"
#include "DrvHal.h"

#include "SenHal.h"
#include "DrvSPI_BMI160.h"

typedef struct {
    DriverConfig config;
    pOsAPI api;
    int TimeScale;
} SPI_BMI160_t, *pSPI_BMI160_t;

enum SensorIndex {
    ACC = 0,
    GYR,
    NUM_OF_SENSOR,
};

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
    
static int accStepPower(int on, void *cookie)
{

    return CWM_NON;
}
static int accSetRate(uint32_t rate, uint64_t latency, void *cookie)
{

    return CWM_NON;
}

static int accCfgData(void *data, void *cookie)
{

    return CWM_NON;
}

static int accCalibration(void *cookie)
{

    return CWM_NON;
}

static int accSelfTest(void *cookie)
{

    return CWM_NON;
}

static int gyrStepPower(int on, void *cookie)
{

    return CWM_NON;
}
static int gyrSetRate(uint32_t rate, uint64_t latency, void *cookie)
{

    return CWM_NON;
}

static int gyrCfgData(void *data, void *cookie)
{

    return CWM_NON;
}

static int gyrCalibration(void *cookie)
{

    return CWM_NON;
}

static int gyrSelfTest(void *cookie)
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
    

    return CWM_NON;
}
