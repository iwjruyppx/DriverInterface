
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Utility.h"

//TID [31:16]TaskId, [15:0] Task Internal Event.
static CWMHandle_t tidMem[MAX_TID_INDEX];

static uint32_t tidSearch(void)
{
    for(int i=0; i<MAX_TID_INDEX; i++)
        if(tidMem[i].tid == 0)
            return i;
    return -1;
}

pCWMHandle_t tidAlloc(void)
{
    uint32_t currentTid = tidSearch();
    if(currentTid <0 )
        return NULL;
    
    tidMem[currentTid].tid = (currentTid<<16);

    return &tidMem[currentTid];
}

void tidFree(pCWMHandle_t pHandle)
{
    pHandle->tid = 0;
}
