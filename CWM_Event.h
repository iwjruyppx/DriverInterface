
#ifndef __CWM_EVENT_H__
#define __CWM_EVENT_H__

/*
    Task ID & task internal event used.
        0x00000000 ~ 0x0000FFFF 
        0x0000XX00 [xx:task ID] 
        0x000001xx [xx:task Internal Event] 
    Sensor event
        0x00010000 ~ 0x0001FFFF
    System event
        0x00020000 ~ 0x0002FFFF
*/

#define EVT_TASK_ID_BASE           0x00000100
#define TASK_EVT_CHECK(tid)      (((uint32_t)tid&0xFFFF0000) == 0) ? tid : 0

/*Sensor Data Ready
    0x00010000 ~ 0x000100FF
*/
#define EVT_SENSOR_DATA_RDY_BASE           0x00010000
#define EVT_SENSOR_RDY(id)                  ((uint32_t)id | EVT_SENSOR_DATA_RDY_BASE)

#endif /* __CWM_EVENT_H__ */
