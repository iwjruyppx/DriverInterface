
#include <stdio.h>
#include <string.h>
#include "main.h"
#include "CWM_TASK1.h"
#include "stm32f4xx_hal.h"
#include "cmsis_os.h"

#include "DriverHal_1_0_Config.h"
#include "DriverHal_1_0.h"

#define Task_Name "CWMTask1"

static void CWM_Task1(const void *argument)
{  
    for (;;)
    {
        osDelay(10);
    }
}

void CWM_TASK1_INIT(void)
{
    osThreadDef(Task_Name, CWM_Task1, osPriorityNormal, 0, configMINIMAL_STACK_SIZE);
    osThreadCreate(osThread(Task_Name), NULL);
}

