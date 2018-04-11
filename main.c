#include "main.h"
#include "CWM_Init.h"
#include "CWM_StateMachine.h"

#include "CWM_SensorList.h"
#include "sensorManager.h"

MGR_DEF(sensor);

void sensorListen(pSensorEVT_t sensorEVT)
{
    printf("[%d,%s]%X,%X,%X,%f,%f,%f\n", __LINE__, __FUNCTION__, 
        sensorEVT->sensorType, sensorEVT->index, sensorEVT->status,
        sensorEVT->fData[0],sensorEVT->fData[1],sensorEVT->fData[2]);
}

static void init(void)
{
    MGR_Create(&sensor, sensorListen);
    
}
 int main( void )
{
    CWM_INIT();
    init();
    while(1)
    {
        if(!MainDequeueLoop()){
            /*Into Low power state*/
        }
        osEnqueueCommon(0x00010001, NULL);
        osEnqueueCommon(0x00010002, NULL);
        
    }
}

