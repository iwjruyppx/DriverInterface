
#ifndef __DriverHal_H__
#define __DriverHal_H__

/* Standard includes. */
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include "DriverHal_1_0_Config.h"
#include "SPI_BMI160_DEF.h"
#include "SPI_BMI160.h"

#define BMI160_ACC_NORMAL_EN					0
#define BMI160_ACC_SPECIAL_EN					1

typedef struct {
    uint8_t infoAccEn;
    uint8_t accRate;
    uint8_t accMode;

    uint8_t infoGyroEn;
    uint8_t gyroRate;
    uint8_t gyroMode;
    int TimeScale;
} Bmi160Handle_t, *pBmi160Handle_t;

static Bmi160Handle_t BMI160;

static int Read(pDriverHandle_t pHandle, uint8_t reg, uint8_t *data, int len)
{
    BusTxRxPackage info = {.type = TYPE_SPI, .address = pHandle->config.slaveAddr, .reg = reg, .data = data, .len = len};
    return pHandle->api->Read( &info);
}

static int Write(pDriverHandle_t pHandle, uint8_t reg, uint8_t *data, int len)
{
    BusTxRxPackage info = {.type = TYPE_SPI, .address = pHandle->config.slaveAddr, .reg = reg, .data = data, .len = len};
    return pHandle->api->Write( &info);
}

static void sleep(pDriverHandle_t pHandle, uint32_t time)
{
    pHandle->api->uSleep(time * 1000);
}

static int64_t getTimeUs(pDriverHandle_t pHandle)
{
    return pHandle->api->GetTimeNs()/1000ll;
}

static void error(pDriverHandle_t pHandle, int error, void *data)
{
    pHandle->api->Error(error, 0);
}

static void senDataCb(pDriverHandle_t pHandle, float *senData, void *reserved)
{
    pHandle->api->DataCb(&pHandle->config, senData, reserved);
}

static int AccSetRate(pDriverHandle_t pHandle, int rate){
	uint8_t data1 = 0;
	uint8_t data2 = 0;
	int rty = 0;
retry:
	data1 = 0x20;
	if(rate == FASTEST){
		data2 = data1 | BMI160_ACC_CONF_RATE_400;
	}else if(rate == GAME){
		data2 = data1 | BMI160_ACC_CONF_RATE_400;
	}else if(rate == RATE_33){
		data2 = data1 | BMI160_ACC_CONF_RATE_400;
	}else if(rate == RATE_25){
		data2 = data1 | BMI160_ACC_CONF_RATE_100;
	}else if(rate == UI){
		data2 = data1 | BMI160_ACC_CONF_RATE_100;
	}else if(rate == RATE_10){
		data2 = data1 | BMI160_ACC_CONF_RATE_100;
	}else if(rate == NORMAL){
		data2 = data1 | BMI160_ACC_CONF_RATE_100;
	}else{
		data2 = data1 | BMI160_ACC_CONF_RATE_100;
	}
	if(Write(pHandle,BMI160_ACC_CONF_REG,&data2 ,1)){
		return CWM_ERROR_SPI;
	}
	if(!Read(pHandle,BMI160_ACC_CONF_REG,&data1,1)){
		if(data1 !=data2){
			if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
		}
	}
	return 0 ;
}

int AccSetSenMode(pDriverHandle_t pHandle, int mode){
	uint8_t data1 = 0;
	uint8_t data2 = 0;
	if(mode & (1<<MODE_ACC_MOTION_INT)){
		if(BMI160.accMode == MODE_ACC_MOTION_INT){
			if(pHandle->config.privateSetting[2] !=INTERRUPT_OFF){
				data1 =pHandle->config.privateSetting[3];
				data2 =0x00;
				if(Write(pHandle,BMI160_INT_MOTION_0_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
#ifdef BMI160_USE_MOTION
				data1 =BMI160_INT_EN_ANYMO_CONFIG;
				if(Write(pHandle,BMI160_INT_EN_0_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
				data1 = pHandle->config.privateSetting[0];	 //any motion threshold setting by user
				if(Write(pHandle,BMI160_INT_MOTION_1_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
#endif
#ifdef BMI160_USE_NO_MOTION
				data1 =BMI160_INT_EN_NOMO_CONFIG;
				if(Write(pHandle,BMI160_INT_EN_2_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
				data1 = pHandle->config.privateSetting[1];	 //non motion threshold setting by user
				if(Write(pHandle,BMI160_INT_MOTION_2_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
				data1 = BMI160_INT_EN_NOMO_SEL;	 
				if(Write(pHandle,BMI160_INT_MOTION_3_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
				
#endif
				if(pHandle->config.privateSetting[2] == INTERRUPT_USE_INT1){	//int 1
					data1 = BMI160_INT_1_OUTPUT_EN_CONFIG ;
					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
						return CWM_ERROR_SPI;
					}
					data2 =0x00;
#ifdef BMI160_USE_MOTION
					data2 |=BMI160_INT_MAP_EN_ANYMO_CONFIG;
#endif
#ifdef BMI160_USE_NO_MOTION
					data2 |=BMI160_INT_MAP_EN_NOMO_CONFIG;
#endif
					if(Write(pHandle,BMI160_INT_MAP_0_REG,&data2 ,1) ){
						return CWM_ERROR_SPI;
					}
				}else{	//int 2
					data1 = BMI160_INT_2_OUTPUT_EN_CONFIG ;
					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
						return CWM_ERROR_SPI;
					}
					data2 =0x00;
#ifdef BMI160_USE_MOTION
					data2 |=BMI160_INT_MAP_EN_ANYMO_CONFIG;
#endif
#ifdef BMI160_USE_NO_MOTION
					data2 |=BMI160_INT_MAP_EN_NOMO_CONFIG;
#endif
					if(Write(pHandle,BMI160_INT_MAP_2_REG,&data2 ,1) ){
						return CWM_ERROR_SPI;
					}
				}
			}
		}
	}else{
		if(BMI160.accMode == MODE_ACC_MOTION_INT){
			if(pHandle->config.privateSetting[2] !=INTERRUPT_OFF){
				data2 =0x00;
#ifdef BMI160_USE_MOTION
				data1 =0x00;
				if(Write(pHandle,BMI160_INT_EN_0_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}
#endif
#ifdef BMI160_USE_NO_MOTION
				data1 =0x00;
				if(Write(pHandle, BMI160_INT_EN_2_REG,&data1 ,1) ){
					return CWM_ERROR_SPI;
				}				
#endif
				if(pHandle->config.privateSetting[2] == INTERRUPT_USE_INT1){	//int 1
					data1 = 0x00 ;
					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
						return CWM_ERROR_SPI;
					}
					data2 =0x00;
					if(Write(pHandle,BMI160_INT_MAP_0_REG,&data2 ,1) ){
						return CWM_ERROR_SPI;
					}
				}else{	//int 2
					data1 = 0x00 ;
					if(Write(pHandle,BMI160_INT_OUT_CTRL_REG,&data1 ,1) ){
						return CWM_ERROR_SPI;
					}
					data2 =0x00;
					if(Write(pHandle,BMI160_INT_MAP_2_REG,&data2 ,1) ){
						return CWM_ERROR_SPI;
					}
				}
			}
		}
	}
	return 0;
}

static int AccPowerOnCheck(pDriverHandle_t pHandle){
    uint8_t data1 = 0;
    uint8_t data2 = 0;
    int rty = 0;

    if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
        return CWM_ERROR_SPI;
    }
    if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)==BMI160_PMU_ACC_NORMAL){
        return 0;//power mode correct
    }    
retry:
	data1 =BMI160_CMD_ACC_NORMAL;
	if(Write(pHandle,BMI160_CMD_REG,&data1 ,1) ){
		return CWM_ERROR_SPI;
	}
	sleep(pHandle, BMI160_CMD_ACC_SWITCH_TIME);
	if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
		return CWM_ERROR_SPI;
	}
	if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_NORMAL){
		if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
	}

//switch to 4G	
	data1 =BMI160_ACC_RANGE_4G;
	if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) ){
		return CWM_ERROR_SPI;
	}

	data1 =0x00;
	if(Write(pHandle,0x6C,&data1 ,1) ){
		return CWM_ERROR_SPI;
	}
    if(AccSetRate(pHandle, BMI160.accRate)){
        return CWM_ERROR_SPI;
    }
    if(AccSetSenMode(pHandle, BMI160.accMode)){
        return CWM_ERROR_SPI;
    }
    return 0;
}

static int AccSetMode(pDriverHandle_t pHandle, int mode){

	uint8_t data1 = 0;
	uint8_t data2 = 0;
	int	  err = 0;
	int rty = 0;

	if(mode == 0){
		BMI160.infoAccEn &= ~(1<<BMI160_ACC_SPECIAL_EN);
		if(BMI160.infoAccEn){
                if(AccPowerOnCheck(pHandle)){
                    return I2C_FAIL;
                }
			err = AccSetSenMode(pHandle, mode);
			if(err<0){return I2C_FAIL;}
		}else{
			err = AccSetSenMode(pHandle, mode);
			if(err<0){return I2C_FAIL;}
/*****************************************************************************************///Sensors disable
retry:
			data1 =BMI160_CMD_ACC_SUSPEND;
			if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) == I2C_FAIL){
				return I2C_FAIL;
			}
			sleep( pHandle,BMI160_CMD_ACC_SWITCH_TIME);
			if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) == I2C_FAIL){
				return I2C_FAIL;
			}
			if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_SUSPEND){
				if(rty<3){rty++; goto retry;}else{ return I2C_FAIL;}
			}
/*****************************************************************************************/
		}
	}else{
		if(BMI160.infoAccEn){
                if(AccPowerOnCheck(pHandle)){
                    return I2C_FAIL;
                }
		}else{
/*****************************************************************************************/
retry1:
			data1 =BMI160_CMD_ACC_NORMAL;
			if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) == I2C_FAIL){
				return I2C_FAIL;
			}
			sleep( pHandle,BMI160_CMD_ACC_SWITCH_TIME);
			if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) == I2C_FAIL){
				return I2C_FAIL;
			}
			if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_NORMAL){
				if(rty<3){rty++; goto retry1;}else{ return I2C_FAIL;}
			}

		//switch to 4G	
			data1 =BMI160_ACC_RANGE_4G;
			if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) == I2C_FAIL){
				return I2C_FAIL;
			}

			data1 =0x00;
			if(Write(pHandle, 0x6C,&data1 ,1) == I2C_FAIL){
				return I2C_FAIL;
			}
/*****************************************************************************************/
		}
		err = AccSetSenMode(pHandle, mode);
		if(err<0){return I2C_FAIL;}
		BMI160.infoAccEn |= ((uint8_t)(1)<<BMI160_ACC_SPECIAL_EN);
	}
	BMI160.accMode = mode;
	return 0;
}

static int AccInit(pDriverHandle_t pHandle, void *data)
{
    BMI160.infoAccEn = 0;
    return 0;
}

static int AccEnable(pDriverHandle_t pHandle, void *data)
{
	uint8_t data1 = 0;
	uint8_t data2 = 0;
	int rty = 0;
	
	if(BMI160.infoAccEn != 0){
            if(AccPowerOnCheck(pHandle)){
                return CWM_ERROR_SPI;
            }
		BMI160.infoAccEn |= ((uint8_t)(1)<<BMI160_ACC_NORMAL_EN);
		return 0;
	}

retry:
	data1 =BMI160_CMD_ACC_NORMAL;
	if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
		return CWM_ERROR_SPI;
	}
	sleep(pHandle, BMI160_CMD_ACC_SWITCH_TIME);
	if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
		return CWM_ERROR_SPI;
	}
	if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_NORMAL){
		if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
	}

//switch to 4G	
	data1 =BMI160_ACC_RANGE_4G;
	if(Write(pHandle,BMI160_ACC_RANGE_REG,&data1 ,1) ){
		return CWM_ERROR_SPI;
	}

	data1 =0x00;
	if(Write(pHandle,0x6C,&data1 ,1) ){
		return CWM_ERROR_SPI;
	}
	BMI160.infoAccEn |= ((uint8_t)(1)<<BMI160_ACC_NORMAL_EN);
	return 0 ;
}

static int AccDisable(pDriverHandle_t pHandle, void *data)
{	
    uint8_t data1 = 0;
    uint8_t data2 = 0;
    int rty = 0;
    BMI160.infoAccEn &= ~(1<<BMI160_ACC_NORMAL_EN);
    if(BMI160.infoAccEn != 0){
        if(AccPowerOnCheck(pHandle)){
            return CWM_ERROR_SPI;
        }
        return 0;
    }
    
retry:
    data1 =BMI160_CMD_ACC_SUSPEND;
    if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
        return CWM_ERROR_SPI;
    }
    sleep(pHandle, BMI160_CMD_ACC_SWITCH_TIME);
    if(Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
        return CWM_ERROR_SPI;
    }
    if(((data2&BMI160_PMU_STATUS_ACC_MASK)>>BMI160_PMU_STATUS_ACC_SHIFT)!=BMI160_PMU_ACC_SUSPEND){
        if(rty<3){rty++; goto retry;}else{ return CWM_ERROR_SPI;}
    }
    return 0 ;
}

static void accDataVerify(pDriverHandle_t pHandle, int16_t *datas16_raw)
{
    static int16_t Bmi160Accraw[3] = {0};
    static uint64_t Bmi160Acctime = 0;
    static uint8_t Bmi160AccCount = 0;

    if(((Bmi160Accraw[0] == datas16_raw[0]) && (Bmi160Accraw[1] == datas16_raw[1]) && (Bmi160Accraw[2] == datas16_raw[2])))
    {
        Bmi160AccCount ++;
        if(Bmi160Acctime ==0){
        //initial error start time.
        Bmi160Acctime =getTimeUs(pHandle);
        }else if(((getTimeUs(pHandle) -Bmi160Acctime) > 2000000) && (Bmi160AccCount >=10)){
            Bmi160Acctime = 0;
            Bmi160AccCount = 0;
            error(pHandle, DATA_BLOCK, 0);
        }
    }else{
        //reset value, because data not the same or error.
        Bmi160Accraw[0] = datas16_raw[0];
        Bmi160Accraw[1] = datas16_raw[1];
        Bmi160Accraw[2] = datas16_raw[2];
        Bmi160Acctime = 0;
        Bmi160AccCount = 0;
    }
}

static int AccGetData(pDriverHandle_t pHandle, void *data){
    uint8_t tmpreg[6] ={0};
    int16_t datas16_raw[3];
    float	senData[3];
    int i=0;
    if(!Read(pHandle, BMI160_ACC_DATA_14_ACC_XL_REG,tmpreg,6)){
        for(i=0; i<3; i++){
            datas16_raw[i] = (int16_t)((((int16_t)((signed char)tmpreg[2*i+1]))<< 8) | (tmpreg[2*i]));
        } 
        senData[0] = (float)datas16_raw[0] * BMI160_ACC_CONVERT_4G;
        senData[1] = (float)datas16_raw[1] * BMI160_ACC_CONVERT_4G;
        senData[2] = (float)datas16_raw[2] * BMI160_ACC_CONVERT_4G;
        senDataCb(pHandle, senData, NULL);
        accDataVerify(pHandle, datas16_raw);
        if(data != NULL)
            memcpy(data, senData, sizeof(float)*3);
        return CWM_NON;
    }
    return CWM_ERROR_SPI;
}

static int AccGetStatus(pDriverHandle_t pHandle, void *data){
    uint8_t tmpreg[6] ={0};
    if(!Read(pHandle, 0x1C,tmpreg,2)){
        if (tmpreg[0]& (1<<2)){
            return SENSOR_INTERRUPT_MOTION;
        }else if (tmpreg[1]& (1<<7)){
            return SENSOR_INTERRUPT_NON_MOTION;
        }
    }
    return 0;
}

static int AccGetInfo(pDriverHandle_t pHandle, void *data){
    uint8_t tmpreg[6] ={0};
    int16_t datas16_raw[3];
    float	temperature = 0;
    uint8_t *pData = (uint8_t *)data;
    if(!Read(pHandle, BMI160_TEMPERATURE_0_REG,tmpreg,2)){
        datas16_raw[0] = (int16_t)((((int16_t)((signed char)tmpreg[1]))<< 8) | (tmpreg[0]));
        temperature = ((float)datas16_raw[0] /512.0f)+23.0f;
        datas16_raw[0] = (int16_t)(temperature*100);
        pData[0] = datas16_raw[0];
        pData[1] = datas16_raw[0]>>8;
    }
    return 0 ;
}

static int AccReset(pDriverHandle_t pHandle, void *data){
    return 0 ;
}

static int AccSelftTest(pDriverHandle_t pHandle, void *data){
    uint8_t data1 = 0;
    uint8_t tmpreg[6] ={0};
    int16_t acc_selft_data_positive[3] ={0};
    int16_t acc_selft_data_negative[3] ={0};
    int rty = 0;
    int status = NO_ERROR;
    if(AccEnable(pHandle, data))
        return I2C_FAIL;

    //switch to 8G
    data1 =BMI160_ACC_RANGE_8G;
    if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) )
        return I2C_FAIL;
    
    data1 =0x2c;
    if(Write(pHandle, 0x40,&data1 ,1) )
        return I2C_FAIL;
    
    sleep(pHandle, 100);
retry:
    
    status = NO_ERROR;
    //test for x-axis positive
    data1 =BMI160_ACC_SELF_TEST_AMPT | BMI160_ACC_SELF_TEST_SIGN | BMI160_ACC_SELF_TEST_AXIS_X_EN;
    if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) )
        return I2C_FAIL;
    
    sleep(pHandle, 100);
    if(!Read(pHandle, BMI160_ACC_DATA_14_ACC_XL_REG,tmpreg,6) ){
        acc_selft_data_positive[0] = (int16_t)((((int16_t)((signed char)tmpreg[1]))<< 8) | (tmpreg[0]));
        acc_selft_data_positive[1] = (int16_t)((((int16_t)((signed char)tmpreg[3]))<< 8) | (tmpreg[2]));
        acc_selft_data_positive[2] = (int16_t)((((int16_t)((signed char)tmpreg[5]))<< 8) | (tmpreg[4]));
    }
    //test for x-axis negative
    data1 =BMI160_ACC_SELF_TEST_AMPT | BMI160_ACC_SELF_TEST_AXIS_X_EN;
    if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) )
        return I2C_FAIL;
    
    sleep(pHandle, 100);
    if(!Read(pHandle, BMI160_ACC_DATA_14_ACC_XL_REG,tmpreg,6) ){
        acc_selft_data_negative[0] = (int16_t)((((int16_t)((signed char)tmpreg[1]))<< 8) | (tmpreg[0]));
        acc_selft_data_negative[1] = (int16_t)((((int16_t)((signed char)tmpreg[3]))<< 8) | (tmpreg[2]));
        acc_selft_data_negative[2] = (int16_t)((((int16_t)((signed char)tmpreg[5]))<< 8) | (tmpreg[4]));
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //Check Criterion
    if(abs(acc_selft_data_positive[0] - acc_selft_data_negative[0]) <BMI160_ACC_SELF_TEST_AXIS_X_RANGE){
        status = FAIL;
    }
    if(abs(acc_selft_data_positive[0] - acc_selft_data_negative[0]) <BMI160_ACC_SELF_TEST_AXIS_Y_RANGE){
        status = FAIL;
    }
    if(abs(acc_selft_data_positive[0] - acc_selft_data_negative[0]) <BMI160_ACC_SELF_TEST_AXIS_Z_RANGE){
        status = FAIL;
    }
    if(status == FAIL){
        if(rty<2){rty++; goto retry;}
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //Disable Selft Test
    data1 =BMI160_SELF_TEST_DISABLE;
    if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) )
    return I2C_FAIL;
    
    //switch to 4G	
    data1 =BMI160_ACC_RANGE_4G;
    if(Write(pHandle, BMI160_ACC_RANGE_REG,&data1 ,1) )
        return I2C_FAIL;
    
    if(AccDisable(pHandle, data)){
    }
    
    return status;
}

static int SPI_BMI160_CMD_ACC(pDriverHandle_t pHandle, int cmd, void *data)
{
    switch(cmd)
    {
        case senInit:
            return AccInit(pHandle, data);
        case senEnable:
            return AccEnable(pHandle, data);
        case senDisable:
            return AccDisable(pHandle, data);
        case senSetRate:
            BMI160.accRate = ((uint8_t *)data)[0];
            return AccSetRate(pHandle, BMI160.accRate);
        case senSetMode:
            return AccSetMode(pHandle, ((int *)data)[0]);
        case senGetData:
            return AccGetData(pHandle, data);
        case senGetStatus:
            return AccGetStatus(pHandle, data);
        case senGetInfo:
            return AccGetInfo(pHandle, data);
        case senReset:
            return AccReset(pHandle, data);
        case senSelftest:
            return AccSelftTest(pHandle, data);
    }
    return 0;
}

static int GyroCleanFifo(pDriverHandle_t pHandle ){
    uint8_t data1 = 0;
    data1 =BMI160_CMD_CLEAN_FIFO_DATA;
    if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) == I2C_FAIL)
        return I2C_FAIL;
    
    return 0 ;
}

static int GyroSetMode(pDriverHandle_t pHandle, int mode){
    return 0 ;
}

static int GyroSetRate(pDriverHandle_t pHandle, int rate){
    	uint8_t data1 = 0;
	uint8_t data2 = 0;
	int rty = 0;
retry:
	data1 = 0x20;
	if(rate == FASTEST){
		data2 = data1 | BMI160_GYR_CONF_RATE_100;
		BMI160.TimeScale = 10000;
	}else if(rate == GAME){
		data2 = data1 | BMI160_GYR_CONF_RATE_100;
		BMI160.TimeScale = 10000;
	}else if(rate == RATE_33){
		data2 = data1 | BMI160_GYR_CONF_RATE_100;
		BMI160.TimeScale = 10000;
	}else if(rate == RATE_25){
		data2 = data1 | BMI160_GYR_CONF_RATE_25;
		BMI160.TimeScale = 40000;
	}else if(rate == UI){
		data2 = data1 | BMI160_GYR_CONF_RATE_25;
		BMI160.TimeScale = 40000;
	}else if(rate == RATE_10){
		data2 = data1 | BMI160_GYR_CONF_RATE_25;
		BMI160.TimeScale = 83333;
	}else if(rate == NORMAL){
		data2 = data1 | BMI160_GYR_CONF_RATE_25;
		BMI160.TimeScale = 166666;
	}else{
		data2 = data1 | BMI160_GYR_CONF_RATE_100;
		BMI160.TimeScale = 10000;
	}
	if(Write(pHandle, BMI160_GYR_CONF_REG,&data2 ,1) ){
		return I2C_FAIL;
	}
	if(!Read(pHandle, BMI160_GYR_CONF_REG,&data1,1) ){
		if(data1 !=data2){
			if(rty<3){rty++; goto retry;}else{ return I2C_FAIL;}
		}
	}
	if(BMI160.gyroMode ==MODE_GYRO_FIFO_STREAM){
		pHandle->config.privateSetting[0] = BMI160.TimeScale;
	}else{
		pHandle->config.privateSetting[0] = 255;
	}
	return 0 ;
}

static int GyroInit(pDriverHandle_t pHandle, void *data)
{
    return 0;
}

static int GyroEnable(pDriverHandle_t pHandle, void *data)
{
	uint8_t data1 = 0;
	uint8_t data2 = 0;
	int rty = 0;
	
	if(!Read(pHandle, 0x02,&data1,1) ){
		return I2C_FAIL;
	}
    
retry:
	data1 =BMI160_CMD_GYRO_NORMAL;
	if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
		return I2C_FAIL;
	}
	sleep(pHandle, BMI160_CMD_GYRO_SWITCH_TIME);
	if(!Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
		return I2C_FAIL;
	}
	if(((data2&BMI160_PMU_STATUS_GYRO_MASK)>>BMI160_PMU_STATUS_GYRO_SHIFT)!=BMI160_PMU_GYRO_NORMAL){
		if(rty<3){rty++; goto retry;}else{ return I2C_FAIL;}
	}

	if(BMI160.gyroMode == MODE_BYPASS){	//MODE: BYPSS or STREAM
	}else if(BMI160.gyroMode == MODE_GYRO_FIFO_STREAM){
		data1 =BMI160_GYR_FIFO_EN;
		if(Write(pHandle, BMI160_GYR_FIFO_CONFIG_1_REG,&data1 ,1) ){
			return I2C_FAIL;
		}
	}
	BMI160.infoGyroEn = 1;
	return 0 ;
}

static int GyroDisable(pDriverHandle_t pHandle, void *data)
{
	uint8_t data1 = 0;
	uint8_t data2 = 0;
	int rty = 0;
retry:
	data1 =BMI160_CMD_GYRO_SUSPEND;
	if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
		return I2C_FAIL;
	}
	sleep(pHandle, BMI160_CMD_GYRO_SWITCH_TIME);
	if(!Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
		return I2C_FAIL;
	}
	if(((data2&BMI160_PMU_STATUS_GYRO_MASK)>>BMI160_PMU_STATUS_GYRO_SHIFT)!=BMI160_PMU_GYRO_SUSPEND){
		if(rty<3){rty++; goto retry;}else{ return I2C_FAIL;}
	}
	BMI160.infoGyroEn = 0;
    return 0 ;
}

static int GyroGetStatus(pDriverHandle_t pHandle, void *data){
	uint8_t tmpreg[2] ={0};
	int16_t count = 0;
	if(BMI160.gyroMode == MODE_GYRO_FIFO_STREAM){
		if(!Read(pHandle, BMI160_GYR_FIFO_LENGTH_0_REG,tmpreg,2) ){
			count =((int16_t)(((uint16_t)(tmpreg[1]&0x07) << 8) + tmpreg[0]))/6;	//6byte = 1 count(X,Y,Z)
			if(count < BMI160_GYR_FIFO_MAX_ALLOWABLE_VALUES){
				return  count;
			}else{
				GyroCleanFifo(pHandle);
			}
		}
	}else{return 1;}
    return 0;
}

static int GyroGetData(pDriverHandle_t pHandle, void *data)
{
    uint8_t tmpreg[6] ={0};
    int16_t datas16_raw[3];
    float	senData[3];
    int i=0;	
    int err = -1;
    int count = 0;
    
    if(BMI160.gyroMode == MODE_GYRO_FIFO_STREAM){
        count = GyroGetStatus(pHandle, NULL);
        if(count <= 0){
            return CWM_ERROR_NO_DATA;
        }
    }
    do {
        if(!Read(pHandle, BMI160_GYR_DATA_8_GYR_XL_REG,tmpreg,6)){
            for(i=0; i<3; i++){
                datas16_raw[i]=(int16_t)(((uint16_t)tmpreg[2*i+1] << 8) + tmpreg[2*i]);
            } 
            senData[0] = (float)datas16_raw[0] * BMI160_GYRO_CONVERT;
            senData[1] = (float)datas16_raw[1] * BMI160_GYRO_CONVERT;
            senData[2] = (float)datas16_raw[2] * BMI160_GYRO_CONVERT;
            senDataCb(pHandle, senData, NULL);
            if(data != NULL)
                memcpy(data, senData, sizeof(float)*3);
            err = NO_ERROR;
        }
    }while(--count <= 0);
    return err;
}

static int GyroGetInfo(pDriverHandle_t pHandle, void *data){

    return 0 ;
}

static int GyroReset(pDriverHandle_t pHandle, void *data){
    return 0 ;
}

static int GyroSelftTest(pDriverHandle_t pHandle, void *data){
    	uint8_t data1 = 0;
	uint8_t tmpreg = 0;
	uint8_t data2 = 0;
	int rty = 0;
	int count = 3;
	int status = FAIL;
	
retry:
	data1 =BMI160_CMD_GYRO_NORMAL;
	if(Write(pHandle, BMI160_CMD_REG,&data1 ,1) ){
		return I2C_FAIL;
	}
	sleep(pHandle, BMI160_CMD_GYRO_SWITCH_TIME);
	if(!Read(pHandle, BMI160_PMU_STATUS_REG,&data2,1) ){
		return I2C_FAIL;
	}
	if(((data2&BMI160_PMU_STATUS_GYRO_MASK)>>BMI160_PMU_STATUS_GYRO_SHIFT)!=BMI160_PMU_GYRO_NORMAL){
		if(rty<3){rty++; goto retry;}else{ return I2C_FAIL;}
	}

	sleep(pHandle, 50);
	
	data1 =BMI160_GYR_SELF_TEST_START;
	if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) ){
		return I2C_FAIL;
	}
	while(count>0){
		sleep(pHandle, 10);
		if(!Read(pHandle, BMI160_STATUS_REG,&tmpreg,1) ){
			if((tmpreg&BMI160_STATUS_GYR_SELF_TEST_MASK) == BMI160_STATUS_GYR_SELF_TEST_PASS){
				status = NO_ERROR;
				count = 0;
			}
		}
		count --;
	}
	data1 =BMI160_SELF_TEST_DISABLE;
	if(Write(pHandle, BMI160_SELF_TEST_REG,&data1 ,1) ){
		return I2C_FAIL;
	}
	GyroDisable(pHandle, NULL);
	return status;
}

static int SPI_BMI160_CMD_GYRO(pDriverHandle_t pHandle, int cmd, void *data)
{
    switch(cmd)
    {
        case senInit:
            return GyroInit(pHandle, data);
        case senEnable:
            return GyroEnable(pHandle, data);
        case senDisable:
            return GyroDisable(pHandle, data);
        case senSetRate:
            BMI160.gyroRate= ((uint8_t *)data)[0];
            return GyroSetRate(pHandle, BMI160.gyroRate);
        case senSetMode:
            BMI160.gyroMode= ((int *)data)[0];
            return GyroSetMode(pHandle, BMI160.gyroMode);
        case senGetData:
            return GyroGetData(pHandle, data);
        case senGetStatus:
            return GyroGetStatus(pHandle, data);
        case senGetInfo:
            return GyroGetInfo(pHandle, data);
        case senReset:
            return GyroReset(pHandle, data);
        case senSelftest:
            return GyroSelftTest(pHandle, data);
    }
    return 0;
}

int SPI_BMI160_INIT(pDriverHandle_t pHandle, pDriverAPI pAPI, pDriverConfig pConfig)
{
    if(pConfig->id != SPI_BMI160)
        return -1;
    
    memcpy(&pHandle->config, pConfig, sizeof(DriverConfig));
    pHandle->api= pAPI;
    
    if(pConfig->type == TYPE_ACCELEROMETER)
        pHandle->Cmd = SPI_BMI160_CMD_ACC;
        
    if(pConfig->type == TYPE_GYROSCOPE)
        pHandle->Cmd = SPI_BMI160_CMD_GYRO;
    
    return 0;
}


#endif /* __DriverHal_H__ */
