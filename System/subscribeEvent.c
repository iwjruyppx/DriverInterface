
/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

#include "subscribeEvent.h"
#include "search.h"

/*
linklist A:
	list all of SubscribeEvent list
	
Linklist B~Bn:
	list SubscribeEvent task info.
	
		|ListB0|ListB1|ListB2|ListBN|
		
List A: |event1|event2|event3|event4|	
		|Taskx1|Taskx0|Taskx5|taskx0|
		|Taskx2|Taskx1|Taskx6|taskx2|
		|Taskx3|Taskx3|Taskx7|taskx4|
		|Taskx4|Taskx4|Taskx8|taskx5|
		|Taskx5|Taskx5|Taskx9|taskx8|
		|TaskxN|TaskxN|TaskxN|taskxN|
*/

#define MAX_LISTEN_EVENT_SIZE  120          //60 event listen
#define MAX_REGISTER_TYPE_SIZE 110         //75 register

typedef struct
{
    uint32_t taskId;
    void *next;
}node_t, *pNode_t;

typedef struct
{
    int usedCount;
    node_t  node[MAX_LISTEN_EVENT_SIZE];
}subscribeEvent_t;

static subscribeEvent_t evtMem;
static searchMem_t searchMem;

static pNode_t nodeAlloc(void)
{
    int i;
    for(i =0; i< MAX_LISTEN_EVENT_SIZE; i++)
    {
        if(evtMem.node[i].taskId == 0xFFFFFFFF)
        {
            evtMem.usedCount++;
            return &evtMem.node[i];
        }
    }
    printf("[%d]%s:%s\n",__LINE__,__FUNCTION__,"memory alloc fail");
    return NULL;
}

static void nodeFree(pNode_t node)
{
    node->taskId = 0xFFFFFFFF;
    node->next = NULL;
    evtMem.usedCount--;
}


int subscribeEventCheck(uint32_t evtType, void* evtData, int (*callback)(uint32_t type, uint32_t taskId, void* data))
{
    pNode_t ptr = searchIndex(&searchMem, evtType);
    uint32_t id;
    if(ptr == NULL)
        return 0;
    do{
        id = ptr->taskId;
        ptr = ptr->next;
        callback(evtType, id, evtData);
    }while(ptr != NULL);
    return 1;
}

void unSubscribeEvent(uint32_t evtType, uint32_t taskId)
{
    pNode_t ptr = searchIndex(&searchMem, evtType);
    pNode_t ptrPre;
    
    if(ptr == NULL)
        return;
    if(ptr->taskId == taskId)
    {
        ptrPre = ptr;
        ptr = ptr->next;
        if(ptr == NULL)
            searchNodeDel(&searchMem, evtType);
        else
            searchNodeModify(&searchMem, evtType, ptr);
        nodeFree(ptrPre);
    }else{
        while(ptr->next != NULL){
            ptrPre = ptr;
            ptr = ptr->next;
            if(ptr->taskId == taskId)
            {
                ptrPre->next = ptr->next;
                nodeFree(ptr);
                break;
            }
        }
    }
}

int subscribeEvent(uint32_t evtType, uint32_t taskId)
{
    pNode_t pNode;
    pNode_t ptr;

    ptr = searchIndex(&searchMem, evtType);
    
    /*Add new search Event*/
    if(ptr == NULL)
    {
        pNode = nodeAlloc();
        if(pNode == NULL)
            return -1;
        pNode->taskId = taskId;
        searchNodeAdd(&searchMem, evtType, pNode);
    }else{
        while(1)
        {
            if(ptr->taskId == taskId)
                return -1;
            if(ptr->next == NULL)
                break;
             ptr = ptr->next;
        }
        
        pNode = nodeAlloc();
        if(pNode == NULL)
            return -1;
        pNode->taskId = taskId;
        ptr->next = pNode;
    }
    
    return 0;
}

void subscribeEventInit(void)
{
    int i;
    evtMem.usedCount= 0;
    for(i=0; i<MAX_LISTEN_EVENT_SIZE; i++)
    {
        evtMem.node[i].taskId = 0xFFFFFFFF;
        evtMem.node[i].next = NULL;
    }
    searchMem.memSize = 8 * MAX_REGISTER_TYPE_SIZE;
    searchMem.mem = (void *)malloc(searchMem.memSize);
}


