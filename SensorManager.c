
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "CWM_ErrorCode.h"
#include "CWM_Interface.h"
#include "CWM_SensorList.h"
#include "CWM_Utility.h"
#include "OsApi.h"
#include "SenHal.h"

#include "search.h"
#include "interpolationSearch.h"
#include "insertionSort.h"

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
} SensorManager_t, *pSensorManager_t;

static SensorManager_t mgrMEM;

static pMSG_Node_t getMsgNode(void)
{
    for(int i=0;i<MAX_CTRL_MSG_SIZE;i++)
    {
        if(mgrMEM.msgNode[i].sensorId == 0)
        {
            return &mgrMEM.msgNode[i];
        }
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

static void delMSG(pMGR_Node_t p, uint32_t sensorId, uint32_t index)
{
    pMSG_Node_t ptr,prePtr;
    if(p->next == NULL)
    {
        return;
    }else {
        ptr = p->next;
        if(ptr->sensorId == sensorId && ptr->index == index)
        {
            p->next = ptr->next;
            memset(ptr, 0x00, sizeof(MSG_Node_t));
            return;
        }
    }
    
    prePtr = ptr;
    ptr = p->next;
    while(ptr != NULL)
    {
        if(ptr->sensorId == sensorId && ptr->index == index)
        {
            prePtr->next = ptr->next;
            memset(ptr, 0x00, sizeof(MSG_Node_t));
            return;
        }
        prePtr = ptr;
        ptr = p->next;
    }
}

void MGR_Sync(uint32_t sensorId, uint32_t index)
{
    pMSG_Node_t p;
    uint32_t rate = 0xFFFFFFFF;
    uint64_t latency = 0xFFFFFFFFFFFFFFFF;
    
    for(int i=0;i<mgrMEM.nodeCount;i++)
    {
        p = mgrMEM.node[i]->next;
        while(p!=NULL)
        {
            if(p->sensorId == sensorId && p->index == index)
            {
                if(rate > p->rate)
                    rate = p->rate;
                if(latency > p->latency)
                    latency = p->latency;
            }
            p = p->next;
        }
    }
    if((rate == 0xFFFFFFFF) && (latency == 0xFFFFFFFFFFFFFFFF) )
        sensorDisable(sensorId, index);
    else
        sensorEnable(sensorId, index, rate, latency, NULL);
        
}

int MGR_Enable(mgr_id_t p_mgr_id, 
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

int MGR_Disable(mgr_id_t p_mgr_id, uint32_t sensorId, uint32_t index)
{
    pMGR_Node_t p = (pMGR_Node_t)p_mgr_id;
    delMSG(p, sensorId, index);
    MGR_Sync(sensorId, index);

    return CWM_NON;
}

int MGR_Create(mgr_id_t const * p_mgr_id, sensor_listen_handler_t listen)
{
    mgrMEM.node[mgrMEM.nodeCount] =  (pMGR_Node_t)*p_mgr_id;
    mgrMEM.node[mgrMEM.nodeCount]->callBack = listen;
    
    mgrMEM.nodeCount++;
    return CWM_NON;
}

void MGR_init(void)
{

}

