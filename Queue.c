#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdint.h>
#include <stddef.h>

#include "CWM_Interface.h"
#include "OsApi.h"
#include "Queue.h"

struct Queue * createQueue(int maxElements)
{
    /* Create a Queue */
    struct Queue *Q;
    Q = (struct Queue *)malloc(sizeof(struct Queue));
    /* Initialise its properties */
    Q->elements = malloc(sizeof(struct evtRecord)*maxElements);
    Q->capacity = maxElements;
    Q->front = 0;
    Q->rear = 0;
    
    /* Return the pointer */
    return Q;
}

static int getUseSize(struct Queue *Q)
{
    if(Q->front >= Q->rear)
        return Q->front - Q->rear;
    else
        return Q->capacity - (Q->rear - Q->front);
}

struct evtRecord* Dequeue(struct Queue *Q)
{
    struct evtRecord *tmp = NULL;
    
    CRITICAL_REGION_ENTER();
    if(getUseSize(Q) > 0)
    {
        tmp = &(Q->elements[Q->rear]);
        Q->rear = (Q->rear+1) % Q->capacity;
    }
    CRITICAL_REGION_EXIT();
    
    return tmp;
}

struct evtRecord* DequeueFromIsr(struct Queue *Q)
{
    struct evtRecord *tmp = NULL;
    
    if(getUseSize(Q) > 0)
    {
        tmp = &(Q->elements[Q->rear]);
        Q->rear = (Q->rear+1) % Q->capacity;
    }
    
    return tmp;
}

static int getEmptySize(struct Queue *Q)
{
    if(Q->front >= Q->rear)
        return Q->capacity -(Q->front - Q->rear);
    else
        return Q->rear - Q->front;
}

int Enqueue(struct Queue *Q, uint32_t evtType, void* evtData, uint32_t taskID)
{
    int state = 0;
    
    CRITICAL_REGION_ENTER();
    if(getEmptySize(Q) > 0)
    {
        Q->elements[Q->front].evtData = evtData;
        Q->elements[Q->front].evtType = evtType;
        Q->elements[Q->front].Tid = taskID;
        Q->front = (Q->front + 1) % Q->capacity;
        state = 1;
    }
    CRITICAL_REGION_EXIT();
    
    return state;
}

int EnqueueFromIsr(struct Queue *Q, uint32_t evtType, void* evtData, uint32_t taskID)
{
    int state = 0;
    
    if(getEmptySize(Q) > 0)
    {
        Q->elements[Q->front].evtData = evtData;
        Q->elements[Q->front].evtType = evtType;
        Q->elements[Q->front].Tid = taskID;
        Q->front = (Q->front + 1) % Q->capacity;
        state = 1;
    }
    
    return state;
}

