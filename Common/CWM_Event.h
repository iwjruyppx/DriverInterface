
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
    0x00010000 ~ 0x0001FFFF
*/
#define EVT_SENSOR_DATA_RDY_BASE           0x00010000
#define EVT_SENSOR_RDY(id)                  ((uint32_t)id | EVT_SENSOR_DATA_RDY_BASE)

/*
    System event
        0x00020000 ~ 0x0002FFFF
*/
#define EVT_SYSTEM_EVT_BASE           0x00020000
#define EVT_SYSTEM_INIT                    EVT_SYSTEM_EVT_BASE
#define EVT_TIMER_5MS_TRIGGER        0x00020001
#define EVT_TIMER_10MS_TRIGGER        0x00020002
#define EVT_TIMER_20MS_TRIGGER        0x00020003
#define EVT_TIMER_100MS_TRIGGER        0x00020004
#define EVT_TIMER_1000MS_TRIGGER        0x00020005

/*
    HW event
        0x00030000 ~ 0x0003FFFF
*/
#define EVT_HW_EVT_BASE           0x00030000

#define EVT_HW_ACC_INT1_TRIGGER        0x00030001
#define EVT_HW_ACC_INT2_TRIGGER        0x00030002
#define EVT_HW_GYRO_INT1_TRIGGER        0x00030003
#define EVT_HW_GYRO_INT2_TRIGGER        0x00030004
#define EVT_HW_MAG_INT1_TRIGGER        0x00030005
#define EVT_HW_MAG_INT2_TRIGGER        0x00030006

#endif /* __CWM_EVENT_H__ */
