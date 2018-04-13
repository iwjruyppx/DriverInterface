
#ifndef __CWM_INTERFACE_H__
#define __CWM_INTERFACE_H__

typedef enum {
    TYPE_I2C_POLLING 	= 0,
    TYPE_I2C_INTERRUPT,
    TYPE_I2C_DMA,
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
        };
        struct{
            uint16_t csPin;
            uint8_t cpol;
            uint8_t cpha;
        };
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
        };
        struct{
            uint16_t csPin;
        };
    };
} DriverConfig, *pDriverConfig;

#endif /* __CWM_INTERFACE_H__ */
