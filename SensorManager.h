
#ifndef __SENSOR_MANAGER_H
#define __SENSOR_MANAGER_H

#define MAX_MGRID    5
#define MAX_CTRL_MSG_SIZE (MAX_MGRID * 10)

#define MANAGER_NODE_SIZE          32

#define CEIL_DIV(A, B)      \
    (((A) + (B) - 1) / (B))
    
typedef struct mgr_t { uint32_t data[CEIL_DIV(MANAGER_NODE_SIZE, sizeof(uint32_t))]; } mgr_t;

/**@brief sensor manager ID type.
 * Never declare a variable of this type, but use the macro @ref mgr_DEF instead.*/
typedef mgr_t * mgr_id_t;

/**@brief Application sensor listen handler type. */
typedef void (*sensor_listen_handler_t)(pSensorEVT_t sensorEVT);


/**
 * @brief Create a sensor manager identifier and statically allocate memory for the sensor.
 *
 * @param mgr_id Name of the timer identifier variable that will be used to control the sensor.
 */
#define MGR_DEF(mgr_id)                                  \
    static mgr_t mgr_id##_data = { {0} };                  \
    static const mgr_id_t mgr_id = &mgr_id##_data
    
int MGR_Enable(mgr_id_t p_mgr_id, 
                        uint32_t sensorId, 
                        uint32_t index, 
                        uint32_t rate, 
                        uint64_t latency, 
                        void *evtData);

int MGR_Disable(mgr_id_t p_mgr_id, uint32_t sensorId, uint32_t index);

int MGR_Create(mgr_id_t const * p_mgr_id, sensor_listen_handler_t listen);

void MGR_init(void);

#endif /* __SENSOR_MANAGER_H */
