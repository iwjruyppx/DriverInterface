
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
#include "SenHal.h"

#define MAX_SENSOR_TYPE_SUPPORT     10

typedef struct {
    int regCounter;
    Sensor_t    sensor[MAX_SENSOR_TYPE_SUPPORT];
} SEN_HAL_t, *pSEN_HAL_t;

static SEN_HAL_t senMem;

static int sensorSearch(uint32_t sensorId, uint32_t index)
{
    for(int i = 0; i < senMem.regCounter; i++)
    {
        if(senMem.sensor[i].index == index && senMem.sensor[i].si->sensorType == sensorId)
            return i;
    }
    return CWM_ERROR_NOT_FOUND;
}


int sensorEnable(uint32_t sensorId, uint32_t index, uint32_t rate, uint64_t latency, void *evtData)
{
    int id = sensorSearch(sensorId, index);
    if(id <0)
        return id;
    pSensor_t p = &senMem.sensor[id];

    if(p->en == 0)
    {
        p->callInfo->sensorPower(p->handle, 1, evtData);
        p->en = 1;
    }
    if((p->currentRate != rate) || (p->currentLatency !=latency))
    {
        p->callInfo->sensorSetRate(p->handle, rate, latency, evtData);
        p->currentRate = rate;
        p->currentLatency = latency;
    }
    return CWM_NON;
}

int sensorDisable(uint32_t sensorId, uint32_t index)
{
    int id = sensorSearch(sensorId, index);
    if(id <0)
        return id;
    pSensor_t p = &senMem.sensor[id];
    
    if(p->en == 1)
    {
        p->callInfo->sensorPower(p->handle, 0, NULL);
        p->en = 0;
        p->currentRate = 0;
        p->currentLatency = 0;
    }
    return CWM_NON;
}

int sensorRegister(void *handle, uint16_t index, const SensorInfo *si, const SensorOps *ops)
{
    pSensor_t p= &senMem.sensor[senMem.regCounter];
    senMem.regCounter++;
    
    p->handle = handle;
    p->index = index;
    p->si = si;
    p->callInfo = ops;

    return CWM_NON;
}

int SensorHalInit(pOsAPI api)
{
    return CWM_NON;
}

