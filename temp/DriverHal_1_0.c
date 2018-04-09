
#ifndef __DriverHal_H__
#define __DriverHal_H__

/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include "DriverHal_1_0_Config.h"
#include "DriverHal_1_0.h"

int DriverInit(pDriverHandle_t pHandle, pDriverAPI pAPI, pDriverConfig pConfig)
{
    SPI_BMI160_INIT(pHandle, pAPI, pConfig);
    
    return 0;
}


#endif /* __DriverHal_H__ */