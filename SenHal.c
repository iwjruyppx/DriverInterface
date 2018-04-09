
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

#define MAX_SENSOR_TYPE_SUPPORT     20

typedef struct {
    Sensor_t    sensor[MAX_SENSOR_TYPE_SUPPORT];
    
} SEN_HAL_t, *pSEN_HAL_t;

static SEN_HAL_t senMem;


int sensorRegister(const SensorInfo *si, const SensorOps *ops, uint16_t index)
{

    return CWM_NON;
}

int SensorHalInit(pOsAPI api)
{
    
    return CWM_NON;
}


