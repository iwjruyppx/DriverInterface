#include "main.h"

#include "CWM_Event.h"

#include "CWM_Init.h"
#include "CWM_StateMachine.h"

#include "CWM_SensorList.h"
#include "sensorManager.h"

MGR_DEF(sensor);

static void sensorListen(void * handle, pSensorEVT_t sensorEVT)
{
    printf("[%d,%s]%d,%d,%f,%f,%f,%lld\n", __LINE__, __FUNCTION__
        , sensorEVT->sensorType, sensorEVT->index
        ,sensorEVT->fData[0], sensorEVT->fData[1], sensorEVT->fData[2]
        ,sensorEVT->timestamp);
}

static void init(void)
{
    MGR_init();

    MGR_Create(&sensor, NULL, sensorListen);
    
    MGR_Enable(sensor, SENS_TYPE_ACCEL, 0, 10000000, 1000000000, NULL);
    MGR_Enable(sensor, SENS_TYPE_GYRO, 0, 20000000, 2000000000, NULL);
    
    MGR_Enable(sensor, SENS_TYPE_ORIENTATION, 0, 10000000, 1000000000, NULL);
    MGR_Enable(sensor, SENS_TYPE_GRAVITY, 0, 20000000, 2000000000, NULL);
    MGR_Enable(sensor, SENS_TYPE_LINEAR_ACCEL, 0, 10000000, 1000000000, NULL);
    MGR_Enable(sensor, SENS_TYPE_ROTATION_VECTOR, 0, 20000000, 2000000000, NULL);
    MGR_Enable(sensor, SENS_TYPE_GEO_MAG_ROT_VEC, 0, 10000000, 1000000000, NULL);
    MGR_Enable(sensor, SENS_TYPE_GAME_ROT_VECTOR, 0, 20000000, 2000000000, NULL);    
}

static void time(void)
{
    static uint32_t timestamp = 0;
    if((timestamp%5) == 0)
        osEnqueueCommon(EVT_TIMER_5MS_TRIGGER, &timestamp);
    if((timestamp%10) == 0)
        osEnqueueCommon(EVT_TIMER_10MS_TRIGGER, &timestamp);
    if((timestamp%20) == 0)
        osEnqueueCommon(EVT_TIMER_20MS_TRIGGER, &timestamp);
    if((timestamp%100) == 0)
        osEnqueueCommon(EVT_TIMER_100MS_TRIGGER, &timestamp);
    if((timestamp%1000) == 0)
        osEnqueueCommon(EVT_TIMER_1000MS_TRIGGER, &timestamp);
    
    timestamp++;

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
        time();
        
    }
}
