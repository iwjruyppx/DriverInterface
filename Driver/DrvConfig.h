
#ifndef __DRV_CONFIG_H__
#define __DRV_CONFIG_H__

#include "CWM_Interface.h"
#include "CWM_Utility.h"
#include "OsApi.h"

/*Driver List*/
#include "DrvSPI_BMI160.h"

#define NUMBER_OF_DRIVER_SUPPORT \
    (sizeof(m_pDriverSupList)/sizeof(m_pDriverSupList[0]))

typedef int(*DRIVER_INIT_FUN_PTR)(pCWMHandle_t pHandle, pDriverConfig config, pOsAPI api);

const DRIVER_INIT_FUN_PTR m_pDriverSupList[] =
{
    drvSPI_BMI160,
};

#endif /* __DRV_CONFIG_H__ */
