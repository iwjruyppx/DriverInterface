
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Utility.h"

static CWMHandle_t tidMem[MAX_TID_INDEX];

static uint32_t tidSearch(void)
{
    for(int i=1; i<MAX_TID_INDEX; i++)
        if(tidMem[i].tid == 0)
            return i;
    return 0;
}

pCWMHandle_t getTidMemory(uint32_t tid)
{
    uint32_t currentTid = ((uint32_t)tid>>8)&0x000000FF;
    return &tidMem[currentTid];
}

pCWMHandle_t tidAlloc(void)
{
    uint32_t currentTid = tidSearch();
    if(currentTid == 0 )
        return NULL;
    
    tidMem[currentTid].tid = (currentTid<<8);

    return &tidMem[currentTid];
}

void tidFree(pCWMHandle_t pHandle)
{
    pHandle->tid = 0;
}

