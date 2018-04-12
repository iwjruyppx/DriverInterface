
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
    sensor_listen_handler_t callBack;
    void *handle;
    pMSG_Node_t next;
} MGR_Node_t, *pMGR_Node_t;

typedef struct {
    pMGR_Node_t node[MAX_MGRID];
    int nodeCount;
    MSG_Node_t msgNode[MAX_CTRL_MSG_SIZE];
} SensorManager_t, *pSensorManager_t;

static SensorManager_t mgrMEM;

static void addMSG(pMGR_Node_t p,
                        uint32_t sensorId, 
                        uint32_t index, 
                        uint32_t rate, 
                        uint64_t latency)
{
    pMSG_Node_t ptr = p->next;
    pMSG_Node_t ptrInsert;
    while(ptr != NULL)
    {
        if((ptr->sensorId == sensorId) && (ptr->index == index))
        {
            ptr->rate = rate;
            ptr->latency = latency;
            return;
        }
        ptr = ptr->next;
    }

    for(int i=0;i<MAX_CTRL_MSG_SIZE;i++)
    {
        if(mgrMEM.msgNode[i].sensorId == 0)
        {
            ptrInsert = &mgrMEM.msgNode[i];
            break;
        }
    }

    ptrInsert->sensorId = sensorId;
    ptrInsert->index = index;
    ptrInsert->rate = rate;
    ptrInsert->latency = latency;
    
    if(p->next == NULL)
    {
        p->next = ptrInsert;
        return;
    }
    ptr = p->next;
    while(ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = ptrInsert;
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

int MGR_SensorUpdate(pSensorEVT_t sensorEVT)
{  
    for(int i=0;i<mgrMEM.nodeCount;i++)
    {
        mgrMEM.node[i]->callBack(mgrMEM.node[i]->handle, sensorEVT);
    }
    return CWM_NON;
}

int MGR_Enable(mgr_id_t p_mgr_id, 
                        uint32_t sensorId, 
                        uint32_t index, 
                        uint32_t rate, 
                        uint64_t latency, 
                        void *evtData)
{
    pMGR_Node_t p = (pMGR_Node_t)p_mgr_id;
    addMSG(p, sensorId, index, rate, latency);
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

int MGR_Create(mgr_id_t const * p_mgr_id, void *handle, sensor_listen_handler_t listen)
{
    mgrMEM.node[mgrMEM.nodeCount] =  (pMGR_Node_t)*p_mgr_id;
    mgrMEM.node[mgrMEM.nodeCount]->callBack = listen;
    mgrMEM.node[mgrMEM.nodeCount]->handle = handle;
    
    mgrMEM.nodeCount++;
    return CWM_NON;
}

void MGR_init(void)
{

}


