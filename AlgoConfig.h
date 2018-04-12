
#ifndef __ALGO_CONFIG_H__
#define __ALGO_CONFIG_H__

#include "CWM_Interface.h"
#include "CWM_Utility.h"
#include "OsApi.h"

/*ALGO List*/
#include "AlgoFusion.h"

#define NUMBER_OF_ALGO_SUPPORT \
    (sizeof(m_pAlgoSupList)/sizeof(m_pAlgoSupList[0]))

typedef int(*ALGO_INIT_FUN_PTR)(pCWMHandle_t pHandle, pAlgoConfig config, pOsAPI api);

const ALGO_INIT_FUN_PTR m_pAlgoSupList[] =
{
    AlgoFusion,
};

#endif /* __ALGO_CONFIG_H__ */
