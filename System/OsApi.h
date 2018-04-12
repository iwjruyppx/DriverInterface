
#ifndef __OS_API_H__
#define __OS_API_H__

typedef struct{
    int (*Read)(pBusTxRxPackage);
    int (*Write)(pBusTxRxPackage);
    void (*DataCb)(uint32_t evtType, void* evtData);
    void (*Error)(uint32_t evtType, void* evtData);
    void *(*malloc)(size_t size);
    int64_t (*GetTimeNs)(void);
    void (*uSleep)(uint32_t);
} OsAPI, *pOsAPI;

pOsAPI getOsAPI(void);

#define CRITICAL_REGION_ENTER()                     
#define CRITICAL_REGION_EXIT()

#endif /* __OS_API_H__ */
