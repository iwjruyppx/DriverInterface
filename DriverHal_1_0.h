
#ifndef __DriverHal_1_0_H__
#define __DriverHal_1_0_H__

typedef enum {
    TYPE_I2C 	= 0,
    TYPE_SPI,
} BusType;

typedef enum {
    SPI_BMI160 	= 0,
    I2C_BMI160,
} DriverID;

typedef enum {
    TYPE_ACCELEROMETER= 0,
    TYPE_GYROSCOPE,
    TYPE_MAGNETIC_FIELD,
} DriverType;

typedef enum {
    senInit 	= 0,
    senEnable,
    senDisable,
    senSetRate,
    senSetMode,
    senGetData,
    senGetStatus,
    senGetInfo,
    senReset,
    senSelftest,
} DriverCmd;

typedef struct{
    int type;
    uint16_t address;
    uint16_t reg;
    int len;
    uint8_t *data;
} BusTxRxPackage, *pBusTxRxPackage;

typedef struct{
    int id;
    int type;
    uint16_t slaveAddr;
    uint8_t privateSetting[4];		//private_setting[2] = INTERRUPT_SETTING
    uint8_t axis;
    float hwbias[3];
} DriverConfig, *pDriverConfig;

typedef struct{
    int (*Read)(pBusTxRxPackage);
    int (*Write)(pBusTxRxPackage);
    void (*uSleep)(uint32_t);
    int64_t (*GetTimeNs)(void);
    void (*Error)(int, void *);
    void (*DataCb)(float *, void *);
} DriverAPI, *pDriverAPI;

typedef struct DriverH_t{
    DriverConfig config;
    pDriverAPI api;
    int (*Cmd)(struct DriverH_t *, int, void *);
} DriverHandle_t, *pDriverHandle_t;
/************************************************************/

int DriverInit(pDriverHandle_t pHandle, pDriverAPI pAPI, pDriverConfig pConfig);
/************************************************************/



#endif /* __DriverHal_1_0_H__ */
