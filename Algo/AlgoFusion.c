
/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>

#include "CWM_Event.h"
#include "CWM_ErrorCode.h"
#include "CWM_Interface.h"
#include "CWM_SensorList.h"
#include "CWM_Utility.h"

#include "OsApi.h"
#include "AlgoHal.h"
#include "SenHal.h"
#include "AlgoFusion.h"
#include "cwm_fusion_ExMem.h"
#include "Cwm_rotvec_transform.h"
#include "sensorManager.h"

MGR_DEF(rotCtrl);
MGR_DEF(gameCtrl);
MGR_DEF(geoCtrl);

#define DEC_INFO(name, rates, type, axis, samples) \
    .sensorName = name, \
    .supportedRates = rates, \
    .sensorType = type, \
    .numAxis = axis, \
    .minSamples = samples
    
#define DEC_OPS(power, rate, cfg, cal, test) \
    .sensorPower = power, \
    .sensorSetRate = rate, \
    .sensorCfgData = cfg, \
    .sensorCalibrate = cal, \
    .sensorSelfTest = test

typedef enum  {
    ORIENTATION = 0,
    GRAVITY,
    LINEAR_ACCEL,
    ROTATION_VECTOR,
    GEO_MAG_ROT_VEC,
    GAME_ROT_VECTOR,
    NUM_OF_FUSION,
}SensorIndex;
    
typedef struct {
    uint64_t latency;
    uint32_t rate;
    uint8_t active;
} FusionSensor_t, *pFusionSensor_t;

typedef struct {
    SensorEVT_t accEVT;
    SensorEVT_t magEVT;
    SensorEVT_t gyroEVT;
    float rot_vec[5];
    float rot_mat[9];
    int64_t preTimestamp;
} RotSensor_t, *pRotSensor_t;

typedef struct {
    SensorEVT_t accEVT;
    SensorEVT_t gyroEVT;
    int64_t preTimestamp;
} GameSensor_t, *pGameSensor_t;

typedef struct {
    SensorEVT_t accEVT;
    SensorEVT_t magEVT;
    int64_t preTimestamp;
} GeoSensor_t, *pGeoSensor_t;

typedef struct {
    AlgoConfig config;
    pOsAPI api;
    FusionSensor_t sensor[NUM_OF_FUSION];
    RotSensor_t rotMem;
    GameSensor_t gameMem;
    GeoSensor_t geoMem;
    void *hRotMem;
    void *hGameMem;
    void *hGeoMem;
} AlgoFusion_t, *pAlgoFusion_t;

static uint32_t FusionRates[] = {
    SENSOR_HZ(12.5f),
    SENSOR_HZ(25.0f),
    SENSOR_HZ(50.0f),
    SENSOR_HZ(100.0f),
    SENSOR_HZ(200.0f),
    0,
};

static int checkRotGupPower(pAlgoFusion_t p)
{
    for(int i = 0; i < GEO_MAG_ROT_VEC; i++)
        if(p->sensor[i].active)
            return 1;
    return 0;
}

static uint32_t getRotMinRate(pAlgoFusion_t p)
{
    uint32_t minRate = 0xFFFFFFFF;
    for(int i = 0; i < GEO_MAG_ROT_VEC; i++)
        if(minRate > p->sensor[i].rate)
            minRate = p->sensor[i].rate;
    return minRate;
}

static uint64_t getRotMinLatency(pAlgoFusion_t p)
{
    uint64_t minLatency = 0xFFFFFFFFFFFFFFFF;
    for(int i = 0; i < GEO_MAG_ROT_VEC; i++)
        if(minLatency > p->sensor[i].latency)
            minLatency = p->sensor[i].latency;
    return minLatency;
}


static int RotGupStepPower(SensorIndex index, void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    if(on)
    {
        if(!checkRotGupPower(p))
        {
            enable_cwm_fusion(p->hRotMem);
        }
        p->sensor[index].active = on;
    }else{
        p->sensor[index].active = on;
        if(!checkRotGupPower(p))
        {
            disable_cwm_fusion(p->hRotMem);
            p->sensor[index].rate = 0xFFFFFFFF;
            p->sensor[index].latency = 0xFFFFFFFFFFFFFFFF;
            
            MGR_Disable(rotCtrl, SENS_TYPE_ACCEL, 0);
            MGR_Disable(rotCtrl, SENS_TYPE_GYRO, 0);
            MGR_Disable(rotCtrl, SENS_TYPE_MAG, 0);
        }
    }
    
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on, index);
    return CWM_NON;
}

static int RotGupSetRate(SensorIndex index, void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    uint32_t minRate = 0xFFFFFFFF;
    uint64_t minLatency = 0xFFFFFFFFFFFFFFFF;
    
    p->sensor[index].rate = rate;
    p->sensor[index].latency = latency;
    minRate = getRotMinRate(p);
    minLatency = getRotMinLatency(p);

    MGR_Enable(rotCtrl, SENS_TYPE_ACCEL, 0, minRate, minLatency, NULL);
    MGR_Enable(rotCtrl, SENS_TYPE_GYRO, 0, minRate, minLatency, NULL);
    MGR_Enable(rotCtrl, SENS_TYPE_MAG, 0, minRate, minLatency, NULL);
    printf("[%d,%s]%d,%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency, index);
    return CWM_NON;
}

static int RotGupCfgData(SensorIndex index, void *handle, void *data, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    char rotConfig[5] = {1, 15, 3, 3, 0};
    set_config_cwm_fusion(p->hRotMem, rotConfig, sizeof(rotConfig));
    
    return CWM_NON;
}

static int orientStepPower(void *handle, int on, void *cookie)
{
    return RotGupStepPower( ORIENTATION, handle, on, cookie);
}

static int orientSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    return RotGupSetRate( ORIENTATION, handle, rate, latency, cookie);
}

static int orientCfgData(void *handle, void *data, void *cookie)
{
    return RotGupCfgData( ORIENTATION, handle, data, cookie);
}

static int gravityStepPower(void *handle, int on, void *cookie)
{
    return RotGupStepPower( GRAVITY, handle, on, cookie);
}

static int gravitySetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    return RotGupSetRate( GRAVITY, handle, rate, latency, cookie);
}

static int gravityCfgData(void *handle, void *data, void *cookie)
{
    return RotGupCfgData( GRAVITY, handle, data, cookie);
}

static int linearStepPower(void *handle, int on, void *cookie)
{
    return RotGupStepPower( LINEAR_ACCEL, handle, on, cookie);
}

static int linearSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    return RotGupSetRate( LINEAR_ACCEL, handle, rate, latency, cookie);
}

static int linearCfgData(void *handle, void *data, void *cookie)
{
    return RotGupCfgData( LINEAR_ACCEL, handle, data, cookie);
}

static int rotatStepPower(void *handle, int on, void *cookie)
{
    return RotGupStepPower( ROTATION_VECTOR, handle, on, cookie);
}

static int rotatSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    return RotGupSetRate( ROTATION_VECTOR, handle, rate, latency, cookie);
}

static int rotatCfgData(void *handle, void *data, void *cookie)
{
    return RotGupCfgData( ROTATION_VECTOR, handle, data, cookie);
}

static int geomagStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    if(on)
    {
        enable_cwm_geo_rot_vec(p->hRotMem);
        p->sensor[GEO_MAG_ROT_VEC].active = on;
    }else{
        p->sensor[GEO_MAG_ROT_VEC].active = on;
        
        disable_cwm_geo_rot_vec(p->hRotMem);
        p->sensor[GEO_MAG_ROT_VEC].rate = 0xFFFFFFFF;
        p->sensor[GEO_MAG_ROT_VEC].latency = 0xFFFFFFFFFFFFFFFF;
            
        MGR_Disable(gameCtrl, SENS_TYPE_ACCEL, 0);
        MGR_Disable(gameCtrl, SENS_TYPE_MAG, 0);
    }
        
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);
    return CWM_NON;
}

static int geomagSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    
    p->sensor[GEO_MAG_ROT_VEC].rate = rate;
    p->sensor[GEO_MAG_ROT_VEC].latency = latency;

    MGR_Enable(geoCtrl, SENS_TYPE_ACCEL, 0, rate, latency, NULL);
    MGR_Enable(geoCtrl, SENS_TYPE_MAG, 0, rate, latency, NULL);
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    return CWM_NON;
}

static int geomagCfgData(void *handle, void *data, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    char rotConfig[5] = {1, 15, 3, 3, 0};
    set_config_cwm_geo_rot_vec(p->hRotMem, rotConfig, sizeof(rotConfig));
    return CWM_NON;
}

static int gameStepPower(void *handle, int on, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    if(on)
    {
        enable_cwm_game_rot_vec(p->hRotMem);
        p->sensor[GAME_ROT_VECTOR].active = on;
    }else{
        p->sensor[GAME_ROT_VECTOR].active = on;
        
        disable_cwm_game_rot_vec(p->hRotMem);
        p->sensor[GAME_ROT_VECTOR].rate = 0xFFFFFFFF;
        p->sensor[GAME_ROT_VECTOR].latency = 0xFFFFFFFFFFFFFFFF;
            
        MGR_Disable(gameCtrl, SENS_TYPE_ACCEL, 0);
        MGR_Disable(gameCtrl, SENS_TYPE_GYRO, 0);
    }
    printf("[%d,%s]%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, on);
    return CWM_NON;
}

static int gameSetRate(void *handle, uint32_t rate, uint64_t latency, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    
    p->sensor[GAME_ROT_VECTOR].rate = rate;
    p->sensor[GAME_ROT_VECTOR].latency = latency;

    MGR_Enable(geoCtrl, SENS_TYPE_ACCEL, 0, rate, latency, NULL);
    MGR_Enable(geoCtrl, SENS_TYPE_GYRO, 0, rate, latency, NULL);
    printf("[%d,%s]%d,%d,%d,%d\n", __LINE__, __FUNCTION__, p->config.sensor, p->config.index, rate, (int)latency);
    return CWM_NON;
}

static int gameCfgData(void *handle, void *data, void *cookie)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    char rotConfig[5] = {1, 15, 3, 3, 0};
    set_config_cwm_game_rot_vec(p->hRotMem, rotConfig, sizeof(rotConfig));
    return CWM_NON;
}

static const SensorInfo mFusionInfo[NUM_OF_FUSION] =
{
    { DEC_INFO("Orientation", FusionRates, SENS_TYPE_ORIENTATION, 3, 1) },
    { DEC_INFO("Gravity", FusionRates, SENS_TYPE_GRAVITY, 3, 1) },
    { DEC_INFO("Linear Acceleration", FusionRates, SENS_TYPE_LINEAR_ACCEL, 3, 1) },
    { DEC_INFO("Rotation Vector", FusionRates, SENS_TYPE_ROTATION_VECTOR, 3, 1) },
    { DEC_INFO("Geomagnetic Rotation Vector", FusionRates, SENS_TYPE_GEO_MAG_ROT_VEC, 3, 1) },
    { DEC_INFO("Game Rotation Vector", FusionRates, SENS_TYPE_GAME_ROT_VECTOR, 3, 1) },
};

static const SensorOps mFusionOps[NUM_OF_FUSION] =
{
    { DEC_OPS(orientStepPower, orientSetRate, orientCfgData, NULL, NULL) },
    { DEC_OPS(gravityStepPower, gravitySetRate, gravityCfgData, NULL, NULL) },
    { DEC_OPS(linearStepPower, linearSetRate, linearCfgData, NULL, NULL) },
    { DEC_OPS(rotatStepPower, rotatSetRate, rotatCfgData, NULL, NULL) },
    { DEC_OPS(geomagStepPower, geomagSetRate, geomagCfgData, NULL, NULL) },
    { DEC_OPS(gameStepPower, gameSetRate, gameCfgData, NULL, NULL) },
};

static void sensorListenRot(void *handle, pSensorEVT_t sensorEVT)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    int64_t diff;
    SensorEVT_t sensor;
    
    if(!checkRotGupPower(p))
        return;
    
    switch (sensorEVT->sensorType)
    {
        case SENS_TYPE_ACCEL:
            memcpy(&p->rotMem.accEVT, sensorEVT, sizeof(sensorEVT));
            break;
        case SENS_TYPE_MAG:
            memcpy(&p->rotMem.magEVT, sensorEVT, sizeof(sensorEVT));
            break;
        case SENS_TYPE_GYRO:
            memcpy(&p->rotMem.gyroEVT, sensorEVT, sizeof(sensorEVT));
            
            if(p->rotMem.preTimestamp == 0)
                p->rotMem.preTimestamp = sensorEVT->timestamp;
            diff = (sensorEVT->timestamp - p->rotMem.preTimestamp)/1000ll;
            p->rotMem.preTimestamp = sensorEVT->timestamp;

            if(cwm_fusion(p->hRotMem, p->rotMem.accEVT.cData, p->rotMem.gyroEVT.cData, p->rotMem.magEVT.cData, p->rotMem.rot_vec, (float) diff)>0)
            {
                sensor.index = p->config.index;
                sensor.timestamp = sensorEVT->timestamp;
                cwm_get_rot_mat(p->rotMem.rot_vec, p->rotMem.rot_mat);
            
                if(p->sensor[ORIENTATION].active)
                {
                    sensor.sensorType = SENS_TYPE_ORIENTATION;
                    cwm_get_orien(p->rotMem.rot_mat, sensor.fData);
                    MGR_SensorUpdate(&sensor);
                }
                if(p->sensor[GRAVITY].active)
                {
                    sensor.sensorType = SENS_TYPE_GRAVITY;
                    cwm_get_gravity(p->rotMem.rot_mat, sensor.fData);
                    MGR_SensorUpdate(&sensor);
                }
                if(p->sensor[LINEAR_ACCEL].active)
                {
                    sensor.sensorType = SENS_TYPE_LINEAR_ACCEL;
                    cwm_get_linear_acc(p->hRotMem, p->rotMem.rot_mat, sensor.fData);
                    MGR_SensorUpdate(&sensor);
                }
                if(p->sensor[ROTATION_VECTOR].active)
                {
                    sensor.sensorType = SENS_TYPE_ROTATION_VECTOR;
                    memcpy(sensor.fData, p->rotMem.rot_vec, sizeof(float)*5);
                    MGR_SensorUpdate(&sensor);
                }
            }
            break;
        default:
            return;
    }
}

static void sensorListenGame(void *handle, pSensorEVT_t sensorEVT)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    int64_t diff;
    SensorEVT_t sensor;
    
    if(!p->sensor[GAME_ROT_VECTOR].active)
        return;
    
    switch (sensorEVT->sensorType)
    {
        case SENS_TYPE_ACCEL:
            memcpy(&p->gameMem.accEVT, sensorEVT, sizeof(sensorEVT));
            break;
        case SENS_TYPE_GYRO:
            memcpy(&p->gameMem.gyroEVT, sensorEVT, sizeof(sensorEVT));
            
            if(p->gameMem.preTimestamp == 0)
                p->gameMem.preTimestamp = sensorEVT->timestamp;
            diff = (sensorEVT->timestamp - p->gameMem.preTimestamp)/1000ll;
            p->gameMem.preTimestamp = sensorEVT->timestamp;
            
            if(cwm_game_rot_vec(p->hGameMem, p->gameMem.accEVT.cData, p->gameMem.gyroEVT.cData, sensor.fData, (float) diff)>0)
            {
                sensor.sensorType = SENS_TYPE_GAME_ROT_VECTOR;
                sensor.index = p->config.index;
                sensor.timestamp = sensorEVT->timestamp;
                MGR_SensorUpdate(&sensor);
            }
            break;
        default:
            return;
    }
}
static void sensorListenGeo(void *handle, pSensorEVT_t sensorEVT)
{
    pCWMHandle_t pH = handle;
    pAlgoFusion_t p = (pAlgoFusion_t)(pH->mem);
    int64_t diff;
    SensorEVT_t sensor;
    
    if(!p->sensor[GEO_MAG_ROT_VEC].active)
        return;
    
    switch (sensorEVT->sensorType)
    {
        case SENS_TYPE_ACCEL:
            memcpy(&p->geoMem.accEVT, sensorEVT, sizeof(sensorEVT));
            
            if(p->geoMem.preTimestamp == 0)
                p->geoMem.preTimestamp = sensorEVT->timestamp;
            diff = (sensorEVT->timestamp - p->geoMem.preTimestamp)/1000ll;
            p->geoMem.preTimestamp = sensorEVT->timestamp;
            
            if(cwm_geo_rot_vec(p->hGeoMem, p->geoMem.accEVT.cData, p->geoMem.magEVT.cData, sensor.fData, (float) diff)>0)
            {
                sensor.sensorType = SENS_TYPE_GEO_MAG_ROT_VEC;
                sensor.index = p->config.index;
                sensor.timestamp = sensorEVT->timestamp;
                MGR_SensorUpdate(&sensor);
            }
            break;
        case SENS_TYPE_MAG:
            memcpy(&p->geoMem.magEVT, sensorEVT, sizeof(sensorEVT));
            break;
        default:
            return;
    }
}

static int FusionEVT(void *pHandle, uint32_t evtType, void* evtData)
{

    return 0;
}

int AlgoFusion(pCWMHandle_t pHandle, pAlgoConfig config, pOsAPI api)
{
    if(config->sensor!= ALGO_FUSION)
        return CWM_ERROR;

    pAlgoFusion_t p;

    pHandle->handleEvent = FusionEVT;
    pHandle->mem = api->malloc(sizeof(AlgoFusion_t));
    p = (pAlgoFusion_t)pHandle->mem;
    p->api = api;
    memcpy(&p->config, config, sizeof(AlgoConfig));

    /*Fusion Memory alloc*/
    p->hRotMem = api->malloc(memsize_cwm_rot_vec());
    p->hGameMem = api->malloc(memsize_cwm_game_rot_vec());
    p->hGeoMem = api->malloc(memsize_cwm_geo_rot_vec());

    init_cwm_fusion(p->hRotMem);
    init_cwm_game_rot_vec(p->hGameMem);
    init_cwm_geo_rot_vec(p->hGeoMem);
    
    MGR_Create(&rotCtrl, pHandle, sensorListenRot);
    MGR_Create(&gameCtrl, pHandle, sensorListenGame);
    MGR_Create(&geoCtrl, pHandle, sensorListenGeo);
    
    for (int i = 0; i < NUM_OF_FUSION; i++) {
        if(sensorRegister(pHandle, p->config.index, &mFusionInfo[i], &mFusionOps[i]))
            return CWM_ERROR_NO_INITIAL;
    }
    
    return CWM_NON;

}
