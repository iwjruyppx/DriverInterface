
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
#include "DrvBMI160_REG.h"

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
    uint8_t accEnStatus;
    uint8_t motEnStatus;
} BMI160_t, *pBMI160_t;

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

#define ACC_SLAVE_ADDR_0    0xD0
#define ACC_SLAVE_ADDR_1    0xD2

#define GYR_SLAVE_ADDR_0    0xD0
#define GYR_SLAVE_ADDR_1    0xD2

static int BMI160Read(pCWMHandle_t pH, uint16_t reg, uint8_t *data, int len)
{
    pBMI160_t p = (pBMI160_t)pH->mem;
    BusTxRxPackage msg;
    
    msg.tid = pH->tid;
    msg.type = TYPE_I2C_POLLING;
    msg.slaveAddr = p->config.slaveAddr;
    msg.reg = reg;
    msg.data = data;
    msg.len = len;
    return p->api->Read(&msg);
}

static int BMI160Write(pCWMHandle_t pH, uint16_t reg, uint8_t *data, int len)
{
    pBMI160_t p = (pBMI160_t)pH->mem;
    BusTxRxPackage msg;
    
    msg.tid = pH->tid;
    msg.type = TYPE_I2C_POLLING;
    msg.slaveAddr = p->config.slaveAddr;
    msg.reg = reg;
    msg.data = data;
    msg.len = len;
    return p->api->Write(&msg);
}
 
static int BMI160AccEnable( pCWMHandle_t pH )
{   
    pBMI160_t p = (pBMI160_t)pH->mem;
    uint8_t tmp_wdata = 0x00;
    uint8_t tmp_rdata = 0x00;
    
    uint8_t check_cnt  = 0x00;
    uint8_t check_flag = 0x00;

    // Power Mode Selection
    if( (p->accEnStatus == 0) && (p->motEnStatus == 0) )
    {
        // step 1: change mode to NORMAL
        tmp_wdata = ACC_MODE_WR_MASK | ACC_MODE_NORMAL;
        if( BMI160Write(pH, REG_CMD, &tmp_wdata, 1) < 0)
            return CWM_ERROR_BUS_RW;
    
        // step 2: verify mode for triple times
        for( check_cnt=0 ; (check_cnt<3) && (check_flag==0) ; check_cnt++ )
        {
            p->api->uSleep(20000);

            tmp_rdata = 0x00;
            if( BMI160Read(pH, REG_PMU_STATUS, &tmp_rdata, 1) < 0)
                return CWM_ERROR_BUS_RW;

            tmp_rdata = tmp_rdata & ACC_MODE_RD_MASK;
            tmp_rdata = tmp_rdata >> 4;

            if( tmp_rdata == ACC_MODE_NORMAL )
                check_flag = 1;
        }
        
        // Check Power Mode Pass or Fail
        if( check_flag == 0 )
            return CWM_ERROR;
    }
        
    // Full scale selection
#ifdef FULL_SCALE_USE_2G
    tmp_wdata = ACC_RANGE_2G;
#elif defined(FULL_SCALE_USE_4G)
    tmp_wdata = ACC_RANGE_4G;
#elif defined(FULL_SCALE_USE_8G)
    tmp_wdata = ACC_RANGE_8G;
#elif defined(FULL_SCALE_USE_16G)
    tmp_wdata = ACC_RANGE_16G;
#endif

    if( BMI160Write(pH, REG_ACC_RANGE, &tmp_wdata, 1) < 0 )
        return CWM_ERROR_BUS_RW;
    p->accEnStatus = 1;
    
    return CWM_NON;
}

static int BMI160AccDisable( pCWMHandle_t pH )
{
    pBMI160_t p = (pBMI160_t)pH->mem;
    uint8_t tmp_wdata = 0x00;
    uint8_t tmp_rdata = 0x00;
    
    uint8_t check_cnt  = 0x00;
    uint8_t check_flag = 0x00;
    
    // Power Mode Selection
    if( (p->accEnStatus == 1) && (p->motEnStatus == 0) )
    {
        // step 1: change mode to SUSPEND
        tmp_wdata = ACC_MODE_WR_MASK | ACC_MODE_SUSPEND;
        if( BMI160Write(pH, REG_CMD, &tmp_wdata, 1) < 0 )
            return CWM_ERROR_BUS_RW;
    
        // step 2: verify mode for triple times
        for( check_cnt=0 ; (check_cnt<3) && (check_flag==0) ; check_cnt++ )
        {       
            p->api->uSleep(20000);
        
            tmp_rdata = 0x00;
            if( BMI160Read(pH, REG_PMU_STATUS, &tmp_rdata, 1) < 0 )
                return CWM_ERROR_BUS_RW;
            
            tmp_rdata = tmp_rdata & ACC_MODE_RD_MASK;
            tmp_rdata = tmp_rdata >> 4;
        
            if( tmp_rdata == ACC_MODE_SUSPEND )
                check_flag = 1;
        }
        
        if( check_flag == 0 )
            return CWM_ERROR;
    }

    p->accEnStatus = 0;
    
    return CWM_NON;
}

static int BMI160AccSetRate( pCWMHandle_t pH, uint32_t rate)
{
    uint8_t tmp_wdata = ODR_MASK | ACC_RATE_100Hz;
    
    if( BMI160Write(pH, REG_ACC_CONF, &tmp_wdata, 1) < 0 )
        return CWM_ERROR_BUS_RW;
    
    return CWM_NON;
}

static int BMI160GetAccData(pCWMHandle_t pH, int64_t timestamp)
{
    pBMI160_t p = (pBMI160_t)pH->mem;
    SensorEVT_t sensor;
    uint8_t tmp_raw8[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    int16_t tmp_raw16[3] = {0, 0, 0};
    
    if(!p->sensor[ACC].active)
        return CWM_NON;
    
    if( BMI160Read(pH, REG_DATA_ACC_XL, tmp_raw8, 6) < 0 )
        return CWM_ERROR_BUS_RW;
            
    tmp_raw16[0] = (tmp_raw8[1]<<8) | tmp_raw8[0];
    tmp_raw16[1] = (tmp_raw8[3]<<8) | tmp_raw8[2];
    tmp_raw16[2] = (tmp_raw8[5]<<8) | tmp_raw8[4];
        
    sensor.rData[0] = (float)tmp_raw16[0]*ACC_RANGE_CONVERT;
    sensor.rData[1] = (float)tmp_raw16[1]*ACC_RANGE_CONVERT;
    sensor.rData[2] = (float)tmp_raw16[2]*ACC_RANGE_CONVERT;

    sensor.sensorType = SENS_TYPE_ACCEL;
    sensor.index = p->config.index;
    sensor.timestamp = timestamp;
    return MGR_SensorUpdate(&sensor);
}
 
static int accStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pBMI160_t p = (pBMI160_t)pH->mem;
    p->sensor[ACC].active = on;
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);
    if(p->sensor[ACC].active)
        BMI160AccEnable(pH);
    else
        BMI160AccDisable(pH);
        
    return CWM_NON;
}
static int accSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pBMI160_t p = (pBMI160_t)pH->mem;
    p->sensor[ACC].rate= rate;
    p->sensor[ACC].latency= latency;
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    
    return BMI160AccSetRate(pH, rate);
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

static int BMI160GyroEnable( pCWMHandle_t pH )
{   
    pBMI160_t p = (pBMI160_t)pH->mem;
    
    uint8_t tmp_wdata = 0x00;
    uint8_t tmp_rdata = 0x00;
    uint8_t check_cnt  = 0x00;
    uint8_t check_flag = 0x00;

    // Power Mode Selection
    // step 1: change mode to NORMAL
    tmp_wdata = GYR_MODE_WR_MASK | GYR_MODE_NORMAL;
    if( BMI160Write(pH, REG_CMD, &tmp_wdata, 1) < 0 )
        return CWM_ERROR_BUS_RW;
        
    // step 2: verify mode triple times
    for( check_cnt=0 ; (check_cnt<3) && (check_flag==0) ; check_cnt++ )
    {
        tmp_rdata = 0x00;
        
        p->api->uSleep(60000);
         
        if( BMI160Read(pH, REG_PMU_STATUS, &tmp_rdata, 1) < 0)
            return CWM_ERROR_BUS_RW;
            
        tmp_rdata = tmp_rdata & GYR_MODE_RD_MASK;
        tmp_rdata = tmp_rdata >> 2;

        if( tmp_rdata == GYR_MODE_NORMAL )
            check_flag = 1;
    }
        
    // Check Power Mode Pass or Fail
    if( check_flag == 0 )
        return CWM_ERROR_BUS_RW;

    tmp_wdata = 0x80; // (tmp_rdata | 0x80) & 0xEF;
    if( BMI160Write(pH, REG_FIFO_CONFIG_1, &tmp_wdata, 1) < 0)
        return CWM_ERROR_BUS_RW;

    return CWM_NON;
}

static int BMI160GyroDisable( pCWMHandle_t pH )
{
    pBMI160_t p = (pBMI160_t)pH->mem;
    uint8_t tmp_wdata = 0x00;
    uint8_t tmp_rdata = 0x00;
    
    uint8_t check_cnt  = 0x00;
    uint8_t check_flag = 0x00;
    
    // Power Mode Selection
    // step 1: change mode to SUSPEND
    tmp_wdata = GYR_MODE_WR_MASK | GYR_MODE_SUSPEND;
    if( BMI160Write(pH, REG_CMD, &tmp_wdata, 1) < 0)
        return CWM_ERROR_BUS_RW;
        
    // step 2: verify mode triple times
    for( check_cnt=0 ; (check_cnt<3) && (check_flag==0) ; check_cnt++ )
    {
        tmp_rdata = 0x00;
        
        p->api->uSleep(60000);
         
        if( BMI160Read(pH, REG_PMU_STATUS, &tmp_rdata, 1) < 0)
            return CWM_ERROR_BUS_RW;
            
        tmp_rdata = tmp_rdata & GYR_MODE_RD_MASK;
        tmp_rdata = tmp_rdata >> 2;

        if( tmp_rdata == GYR_MODE_SUSPEND )
            check_flag = 1;
    }
    
    if( check_flag == 1 )
        return CWM_NON;
    return CWM_ERROR;
}

static int BMI160GyroSetRate( pCWMHandle_t pH, uint32_t rate)
{
    uint8_t tmp_wdata = ODR_MASK | GYR_RATE_100Hz;
    
    if( BMI160Write(pH, REG_GYR_CONF, &tmp_wdata, 1) < 0 )
        return CWM_ERROR_BUS_RW;
    
    return CWM_NON;
}

static int BMI160GetGyroFifoCount(pCWMHandle_t pH)
{
    uint16_t fifo_count;
    uint8_t tmp_rdata[2] = {0x00, 0x00};
    uint8_t tmp_wdata = 0xB0;
    
    // Operation Mode Selection, Always be MODE_FIFO_STREAM
    if( BMI160Read(pH, REG_FIFO_LENGTH_0, tmp_rdata, 2) < 0)
        return CWM_ERROR_BUS_RW;
	
    fifo_count = (tmp_rdata[1]<<8) | tmp_rdata[0];
    fifo_count = fifo_count & 0x07FF;

    if ((fifo_count%6) != 0){ //flush fifo
        tmp_wdata = 0xB0;
        if( BMI160Write(pH, REG_CMD, &tmp_wdata, 1) < 0){
            return CWM_ERROR_BUS_RW;
        }
        fifo_count = 0;
    }else{
        fifo_count = fifo_count / 6;
    }
    return fifo_count;
}

static int BMI160GetGyroData(pCWMHandle_t pH, int64_t timestamp)
{
    pBMI160_t p = (pBMI160_t)pH->mem;
    SensorEVT_t sensor;
    int count;
    uint8_t tmp_raw8[6] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    int16_t tmp_raw16[3] = {0, 0, 0};
    
    if(!p->sensor[GYR].active)
        return CWM_NON;
    
    count = BMI160GetGyroFifoCount(pH);
    for(int i=0;i<count;i++)
    {
        if( BMI160Read(pH, REG_FIFO_DATA, tmp_raw8, 6) < 0)
            return CWM_ERROR_BUS_RW;
                
        tmp_raw16[0] = (tmp_raw8[1]<<8) | tmp_raw8[0];
        tmp_raw16[1] = (tmp_raw8[3]<<8) | tmp_raw8[2];
        tmp_raw16[2] = (tmp_raw8[5]<<8) | tmp_raw8[4];
     
        sensor.rData[0] = (float)tmp_raw16[0]*GYR_DPS_CONVERT;
        sensor.rData[1] = (float)tmp_raw16[1]*GYR_DPS_CONVERT;
        sensor.rData[2] = (float)tmp_raw16[2]*GYR_DPS_CONVERT;

        sensor.sensorType = SENS_TYPE_GYRO;
        sensor.index = p->config.index;
        sensor.timestamp = timestamp;
        MGR_SensorUpdate(&sensor);
    }
    return CWM_NON;
}

static int gyrStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pBMI160_t p = (pBMI160_t)pH->mem;
    p->sensor[GYR].active = on;
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);
    if(p->sensor[GYR].active)
        BMI160GyroEnable(pH);
    else
        BMI160GyroDisable(pH);
    
    return CWM_NON;
}
static int gyrSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = (pCWMHandle_t)handle;
    pBMI160_t p = (pBMI160_t)pH->mem;
    p->sensor[GYR].rate= rate;
    p->sensor[GYR].latency= latency;
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    
    return BMI160GyroSetRate(pH, rate);
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


static int BMI160_CMD(void *pHandle, uint32_t evtType, void* evtData)
{
    pCWMHandle_t pH = (pCWMHandle_t)pHandle;
    int64_t *time = evtData;

    switch(evtType)
    {
        case EVT_TIMER_10MS_TRIGGER:
            BMI160GetAccData(pH, time[0]);
            BMI160GetGyroData(pH, time[0]);
            printf("[%d,%s]%s,%lld\n", __LINE__, __FUNCTION__, "EVT_TIMER_10MS_TRIGGER", time[0]);
            break;
    }
    
    return 0;
}

int drvSPI_BMI160(pCWMHandle_t pHandle, pDriverConfig config, pOsAPI api)
{
    if(config->sensor!= SPI_BMI160)
        return CWM_ERROR;

    pBMI160_t p;

    pHandle->handleEvent = BMI160_CMD;
    pHandle->mem = api->malloc(sizeof(BMI160_t));
    
    p = (pBMI160_t)pHandle->mem;
    p->api = api;
    memcpy(&p->config, config, sizeof(DriverConfig));
    
    for (int i = 0; i < NUM_OF_SENSOR; i++) {
        if(sensorRegister(pHandle, p->config.index, &mSensorInfo[i], &mSensorOps[i]))
            return CWM_ERROR_NO_INITIAL;
    }
    osSubscribeEvent(EVT_TIMER_10MS_TRIGGER, pHandle->tid);
    return CWM_NON;
}
