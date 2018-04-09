
#ifndef __OS_API_H__
#define __OS_API_H__

typedef struct{
    void *(*malloc)(size_t size);
    int (*Read)(pBusTxRxPackage);
    int (*Write)(pBusTxRxPackage);
    void (*DataCb)(uint32_t evtType, void* evtData);
    void (*Error)(uint32_t evtType, void* evtData);
    int64_t (*GetTimeNs)(void);
    void (*uSleep)(uint32_t);
} OsAPI, *pOsAPI;

void osApiInit(void);
pOsAPI getOsAPI(void);

#endif /* __OS_API_H__ */
