
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Interface.h"

#include "OsApi.h"

static int Read(pBusTxRxPackage trx)
{
    return 0;
}

static int Write(pBusTxRxPackage trx)
{
    return 0;
}

static void DataCb(uint32_t evtType, void* evtData)
{

}

static void Error(uint32_t evtType, void* evtData)
{
}

static int64_t GetTimeNs(void)
{
    return 0;
}

static void uSleep(uint32_t time)
{
}

static OsAPI apiMem ={.Read = Read, .Write = Write, .DataCb = DataCb, .Error = Error, .malloc = malloc, .GetTimeNs = GetTimeNs, .uSleep = uSleep};
pOsAPI getOsAPI(void)
{
    return &apiMem;
}

