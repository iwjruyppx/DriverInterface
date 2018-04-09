
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

static OsAPI apiMem;

void osApiInit(void)
{   

}

pOsAPI getOsAPI(void)
{
    return &apiMem;
}

