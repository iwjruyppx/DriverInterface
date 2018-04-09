
#ifndef __SEN_HAL_H__
#define __SEN_HAL_H__

typedef struct {
    const char *sensorName; /* sensors.c code does not use this */
    const uint32_t *supportedRates;
    uint8_t sensorType;
    uint8_t numAxis; /* enum NumAxis */
    uint16_t minSamples; /* minimum host fifo size (in # of samples) */
}SensorInfo;


typedef struct {
    int (*sensorPower)(int on, void *);
    int (*sensorSetRate)(uint32_t rate, uint64_t latency, void *);
    int (*sensorCfgData)(void *cfgData, void *);
    int (*sensorCalibrate)(void *);
    int (*sensorSelfTest)(void *);
}SensorOps;

typedef struct {
    void *handle;
    const SensorInfo *si;
    const SensorOps *callInfo;
    uint16_t index;     //defaule:0, if have another sensor this order add.
    uint64_t currentLatency; /* here 0 means no batching */
    uint32_t currentRate;    /* here 0 means off */
} Sensor_t, *pSensor_t;

int SensorHalInit(pOsAPI api);

int sensorRegister(const SensorInfo *si, const SensorOps *ops, uint16_t index);

#endif /* __SEN_HAL_H__ */
