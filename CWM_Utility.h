
#ifndef __CWM_UTILITY_H__
#define __CWM_UTILITY_H__

#define MAX_TID_INDEX   20

#define SENSOR_HZ(_hz)          ((uint32_t)((_hz) * 1024.0f))

typedef struct {
    uint32_t tid;
    int (*handleEvent)(void *pHandle, uint32_t evtType, void* evtData);
    void *mem;
} CWMHandle_t, *pCWMHandle_t;

pCWMHandle_t tidAlloc(void);
pCWMHandle_t getTidMemory(uint32_t tid);
void tidFree(pCWMHandle_t pHandle);

#endif /* __CWM_UTILITY_H__ */
