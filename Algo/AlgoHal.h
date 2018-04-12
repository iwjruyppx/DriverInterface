
#ifndef __ALGO_HAL_H__
#define __ALGO_HAL_H__

typedef struct{
    uint16_t sensor;
    uint16_t index;
} AlgoConfig, *pAlgoConfig;

int AlgoInit(pCWMHandle_t pHandle, pAlgoConfig config, pOsAPI api);

#endif /* __ALGO_HAL_H__ */
