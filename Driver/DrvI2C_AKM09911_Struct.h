
#ifndef __DRV_I2C_AKM09911_STRUCT_H__
#define __DRV_I2C_AKM09911_STRUCT_H__

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_SensorList.h"
#include "CWM_Utility.h"
#include "CWM_Event.h"
#include "CWM_ErrorCode.h"
#include "CWM_Interface.h"
#include "OsApi.h"

#define AKM09911_SLAVE_ADDRESS          0x18
#define AKM09911_SLAVE_ADDRESS1         0x1A
#define AKM09911_SLAVE_ADDRESS2         0x1C
#define AKM09911_SLAVE_ADDRESS3         0x1E

#define AKM09911_SLAVE_ADDR          AKM09911_SLAVE_ADDRESS

#define AKM09911_RATE_100HZ                     0x08
#define AKM09911_RATE_50HZ                     0x06
#define AKM09911_RATE_20HZ                     0x04
#define AKM09911_RATE_10HZ                     0x02


enum SensorIndex {
    MAG = 0,
    NUM_OF_SENSOR,
};

typedef struct {
    uint64_t latency;
    uint32_t rate;
    uint8_t active;
} AKM09911Sensor_t, *pAKM09911Sensor_t;

typedef struct {
    DriverConfig config;
    pOsAPI api;
    AKM09911Sensor_t sensor[NUM_OF_SENSOR];
} SPI_AKM09911_t, *pSPI_AKM09911_t;

int AkmI2cWrite(pCWMHandle_t pH, uint16_t reg, uint8_t *data, int len);
int AkmI2cRead(pCWMHandle_t pH, uint16_t reg, uint8_t *data, int len);

#endif /* __DRV_I2C_AKM09911_STRUCT_H__ */
