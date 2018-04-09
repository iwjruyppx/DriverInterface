
#ifndef __CWM_SENSORS_LIST_H__
#define __CWM_SENSORS_LIST_H__

#define SENS_TYPE_INVALID         0
#define SENS_TYPE_ACCEL           1
#define SENS_TYPE_ANY_MOTION      2 //provided by ACCEL, nondiscardable edge trigger
#define SENS_TYPE_NO_MOTION       3 //provided by ACCEL, nondiscardable edge trigger
#define SENS_TYPE_SIG_MOTION      4 //provided by ACCEL, nondiscardable edge trigger
#define SENS_TYPE_FLAT            5
#define SENS_TYPE_GYRO            6
#define SENS_TYPE_GYRO_UNCAL      7
#define SENS_TYPE_MAG             8
#define SENS_TYPE_MAG_UNCAL       9
#define SENS_TYPE_BARO            10
#define SENS_TYPE_TEMP            11
#define SENS_TYPE_ALS             12
#define SENS_TYPE_PROX            13
#define SENS_TYPE_ORIENTATION     14
#define SENS_TYPE_HEARTRATE_ECG   15
#define SENS_TYPE_HEARTRATE_PPG   16
#define SENS_TYPE_GRAVITY         17
#define SENS_TYPE_LINEAR_ACCEL    18
#define SENS_TYPE_ROTATION_VECTOR 19
#define SENS_TYPE_GEO_MAG_ROT_VEC 20
#define SENS_TYPE_GAME_ROT_VECTOR 21
#define SENS_TYPE_STEP_COUNT      22
#define SENS_TYPE_STEP_DETECT     23
#define SENS_TYPE_GESTURE         24
#define SENS_TYPE_TILT            25
#define SENS_TYPE_DOUBLE_TWIST    26
#define SENS_TYPE_DOUBLE_TAP      27
#define SENS_TYPE_WIN_ORIENTATION 28
#define SENS_TYPE_HALL            29
#define SENS_TYPE_ACTIVITY        30
#define SENS_TYPE_VSYNC           31
#define SENS_TYPE_ACCEL_RAW       32
// Values 33-37 are reserved
#define SENS_TYPE_WRIST_TILT      39

typedef enum {
    SPI_BMI160 	= 0,
    I2C_BMI160,
} DrvSupportList;

#endif /* __CWM_SENSORS_LIST_H__ */
