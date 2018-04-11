
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "CWM_ErrorCode.h"

#include "search.h"
#include "interpolationSearch.h"
#include "insertionSort.h"

#include "CWM_SensorList.h"
#include "sensorManager.h"

typedef struct {
    uint8_t sensorId;
    uint8_t index;
    uint8_t reserved;
    uint8_t reserved1;
    uint32_t rate;
    uint64_t latency;
    void *next;
} MSG_Node_t, *pMSG_Node_t;

typedef struct {
    void (*callBack)(pSensorEVT_t sensorEVT);
    pMSG_Node_t next;
} MGR_Node_t, *pMGR_Node_t;

typedef struct {
    pMGR_Node_t node[MAX_MGRID];
    int nodeCount;
    MSG_Node_t msgNode[MAX_CTRL_MSG_SIZE];
    int msgCount;
} SensorManager_t, *pSensorManager_t;

static SensorManager_t mgrMEM;

static pMSG_Node_t getMsgNode(void)
{
    for(int i=0;i<mgrMEM.msgCount;i++)
    {
        if(mgrMEM.msgNode[i].sensorId == 0)
            return &mgrMEM.msgNode[i];
    }
    return NULL;
}
static void addMSG(pMGR_Node_t p, pMSG_Node_t pN)
{
    pMSG_Node_t ptr;
    if(p->next == NULL)
    {
        p->next = pN;
        return;
    }
    ptr = p->next;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = pN;
}

void MGR_Sync(uint32_t sensorId, uint32_t index)
{
    
}

int MGR_Enable(mgr_id_t const * p_mgr_id, 
                        uint32_t sensorId, 
                        uint32_t index, 
                        uint32_t rate, 
                        uint64_t latency, 
                        void *evtData)
{
    pMGR_Node_t p = (pMGR_Node_t)p_mgr_id;
    pMSG_Node_t pN = getMsgNode();
    if(pN == NULL)
        return CWM_ERROR_MEMORY_ALLOC_FAIL;
    
    pN->sensorId = sensorId;
    pN->index = index;
    pN->rate = rate;
    pN->latency = latency;
    pN->next = NULL;
    addMSG(p, pN);
    MGR_Sync(sensorId, index);
    
    return CWM_NON;
}

int MGR_Disable(mgr_id_t const * p_mgr_id, uint32_t sensorId, uint32_t index)
{

    return CWM_NON;
}

int MGR_Create(mgr_id_t const * p_mgr_id, sensor_listen_handler_t listen)
{
    mgrMEM.node[mgrMEM.nodeCount] =  (pMGR_Node_t)p_mgr_id;
    mgrMEM.node[mgrMEM.nodeCount]->callBack = listen;
    
    mgrMEM.nodeCount++;
    return CWM_NON;
}

void MGR_init(void)
{

}


