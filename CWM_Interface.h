
#ifndef __CWM_INTERFACE_H__
#define __CWM_INTERFACE_H__

typedef enum {
    TYPE_I2C 	= 0,
    TYPE_SPI,
} devType;

typedef struct{
    uint32_t tid;
    uint32_t type;
    union{
        struct{
            uint16_t slaveAddr;
            uint16_t address;
            uint16_t reg;
        }i2cDev;
        struct{
            uint16_t csPin;
            uint8_t cpol;
            uint8_t cpha;
        }spiDev;
    };
    uint8_t *data;
    int len;
} BusTxRxPackage, *pBusTxRxPackage;

typedef struct{
    uint16_t sensor;
    uint16_t index;
    uint8_t privateSetting[4];
    union{
        struct{
            uint16_t slaveAddr;
        }i2cDev;
        struct{
            uint16_t csPin;
        }spiDev;
    };
} DriverConfig, *pDriverConfig;

#endif /* __CWM_INTERFACE_H__ */
