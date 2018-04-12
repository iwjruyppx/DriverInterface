
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_ErrorCode.h"
#include "CWM_Interface.h"
#include "CWM_SensorList.h"
#include "CWM_Utility.h"

#include "OsApi.h"
#include "AlgoHal.h"
#include "AlgoConfig.h"

int AlgoInit(pCWMHandle_t pHandle, pAlgoConfig config, pOsAPI api)
{
    int ret = 0;
    for(int i =0; i< NUMBER_OF_ALGO_SUPPORT; i++)
    {
        ret = m_pAlgoSupList[i](pHandle, config, api);
        if(ret >= 0)
            return ret;
    }
    
    return CWM_ERROR_NOT_FOUND;
}

