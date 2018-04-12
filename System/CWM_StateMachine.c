
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Event.h"
#include "subscribeEvent.h"
#include "search.h"

#include "CWM_StateMachine.h"
#include "CWM_Utility.h"
#include "Queue.h"

#define MAX_QUEUE_SIZE									32

#define INFO_PRINT(fmt, ...)
#define DEBUG_PRINT(fmt, ...)

static struct Queue* evtQueue;


void osSubscribeEvent(uint32_t evtType, uint32_t taskID){
    subscribeEvent(evtType, taskID);
}

void osUnSubscribeEvent(uint32_t evtType, uint32_t taskID){
    unSubscribeEvent(evtType, taskID);
}

int osEnqueuePrivateEvt(uint32_t evtType, void* evtData, uint32_t taskID){
    int result;
	result = Enqueue(evtQueue, evtType, evtData, taskID);
    if (!result){
        INFO_PRINT("Enqueue Private failed, type:%d id:%d\n",evtType, taskID);
    }
    return result;
}

int osEnqueuePrivateEvtFromIsr(uint32_t evtType, void* evtData, uint32_t taskID){
    int result;
	result = EnqueueFromIsr(evtQueue, evtType, evtData, taskID);
    if (!result){
        INFO_PRINT("Enqueue Private failed, type:%d id:%d\n",evtType, taskID);
    }
    return result;
}

int osEnqueueCommon(uint32_t evtType, void* evtData){
    int result;
	result =  Enqueue(evtQueue, evtType, evtData, 0);
    if (!result){
        INFO_PRINT("Enqueue Common failed, type:%d\n",evtType);
    }
    return result;
}

int osEnqueueCommonFromIsr(uint32_t evtType, void* evtData){
    int result;
	result =  EnqueueFromIsr(evtQueue, evtType, evtData, 0);
    if (!result){
        INFO_PRINT("Enqueue Common failed, type:%d\n",evtType);
    }
    return result;
}

void osCreateEventQ(int max_count){
	evtQueue = createQueue(max_count);
	return;
}

int osevtQueueDequeue(uint32_t* evtType, void** evtData, uint32_t* taskID){
	struct evtRecord* rec;
	rec = Dequeue(evtQueue);
	if(rec == NULL)
		return 0;
	else{
		*evtType = rec->evtType;
		*taskID = rec->Tid;
		*evtData = rec->evtData;
	}
	return 1;
}

static int callBack(uint32_t evtType, uint32_t taskId, void* evtData)
{
    pCWMHandle_t pHandle;
    uint32_t tid = 0;
    tid = TASK_EVT_CHECK(taskId);
    if(tid){
        pHandle = getTidMemory(tid);
        pHandle->handleEvent(pHandle, evtType, evtData);
    }
    return 0;
}

int MainDequeueLoop(void){
    uint32_t type;
    uint32_t tid = 0;
    void* data;
    int job_find = 0;
    pCWMHandle_t pHandle;
    if(!osevtQueueDequeue(&type, &data, &tid))
        return job_find;

    tid = TASK_EVT_CHECK(tid);
    if(tid){
        pHandle = getTidMemory(tid);
        pHandle->handleEvent(pHandle, type, data);
        job_find = 1;
    }
    else{
        job_find = subscribeEventCheck(type, data, callBack);
    }
    return job_find;
}

void CWM_StateMachineInit(void)
{
    subscribeEventInit();
    osCreateEventQ(MAX_QUEUE_SIZE);
}

