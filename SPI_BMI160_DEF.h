#ifndef __SPI_BMI160_DEF_H__
#define __SPI_BMI160_DEF_H__

///////////////////////////////////////////////////////////////////////////////////////////////////////
#define BMI160_CHIP_ID_REG						0x00
#define BMI160_CHIP_ID							0xD1
#define BMI160_SLAVE_ADDRESS					0xD0
#define BMI160_SLAVE_ADDRESS1					0xD2
///////////////////////////////////////////////////////////////////////////////////////////////////////

#define BMI160_PMU_ACC_SUSPEND				0x00
#define BMI160_PMU_ACC_NORMAL				0x01
#define BMI160_PMU_ACC_LOWPOWER_L1			0x02
#define BMI160_PMU_ACC_LOWPOWER_L2			0x03
#define BMI160_PMU_STATUS_ACC_MASK			0x30
#define BMI160_PMU_STATUS_ACC_SHIFT			4

#define BMI160_PMU_GYRO_SUSPEND				0x00
#define BMI160_PMU_GYRO_NORMAL				0x01
#define BMI160_PMU_GYRO_FAST_START_UP		0x03
#define BMI160_PMU_STATUS_GYRO_MASK			0x0C
#define BMI160_PMU_STATUS_GYRO_SHIFT			2

#define BMI160_ERR_STATUS_REG					0x02
#define BMI160_PMU_STATUS_REG					0x03			//power mode status register

#define BMI160_CMD_ACC_EN						0x10
#define BMI160_CMD_ACC_SUSPEND				(BMI160_CMD_ACC_EN|BMI160_PMU_ACC_SUSPEND)
#define BMI160_CMD_ACC_NORMAL				(BMI160_CMD_ACC_EN|BMI160_PMU_ACC_NORMAL)
#define BMI160_CMD_ACC_LOWPOWER_L1			(BMI160_CMD_ACC_EN|BMI160_PMU_ACC_LOWPOWER_L1)
#define BMI160_CMD_ACC_LOWPOWER_L2			(BMI160_CMD_ACC_EN|BMI160_PMU_ACC_LOWPOWER_L2)
#define BMI160_CMD_ACC_SWITCH_TIME			40				//PMU mode switch time is 0.35 ms

#define BMI160_CMD_GYRO_EN					0x14
#define BMI160_CMD_GYRO_SUSPEND				(BMI160_CMD_GYRO_EN|BMI160_PMU_GYRO_SUSPEND)
#define BMI160_CMD_GYRO_NORMAL				(BMI160_CMD_GYRO_EN|BMI160_PMU_GYRO_NORMAL)
#define BMI160_CMD_GYRO_FAST_START_UP		(BMI160_CMD_GYRO_EN|BMI160_PMU_GYRO_FAST_START_UP)
#define BMI160_CMD_GYRO_SWITCH_TIME			80		//PMU mode switch time is 55 ms

#define BMI160_CMD_CLEAN_FIFO_DATA			0xB0
#define BMI160_CMD_SOFTRESET					0xB6

#define BMI160_CMD_REG							0x7E			//command register

#define BMI160_STEPCOUNTER_REG				0x78			//pedometer Enable register
#define BMI160_INT_STEP_DET_CONF_REG			0x7A			//pedometer Config register
#define BMI160_INT_STEP_DET_ENABLE_REG		0x7B			//pedometer Enable register

#define BMI160_SELF_TEST_REG					0x6D
#define BMI160_STATUS_REG						0x1B
#define BMI160_STATUS_GYR_SELF_TEST_MASK	0x02
#define BMI160_STATUS_GYR_SELF_TEST_PASS		0x02
#define BMI160_STATUS_GYR_SELF_TEST_FAIL_OR_RUNNING	0x00

#define BMI160_SELF_TEST_DISABLE				0x00
#define BMI160_GYR_SELF_TEST_START			0x10
#define BMI160_ACC_SELF_TEST_AMPT				0x08
#define BMI160_ACC_SELF_TEST_SIGN				0x04
#define BMI160_ACC_SELF_TEST_AXIS_DISABLE	0x00
#define BMI160_ACC_SELF_TEST_AXIS_X_EN		0x01
#define BMI160_ACC_SELF_TEST_AXIS_Y_EN		0x02
#define BMI160_ACC_SELF_TEST_AXIS_Z_EN		0x03

#define BMI160_ACC_SELF_TEST_AXIS_X_RANGE	3000
#define BMI160_ACC_SELF_TEST_AXIS_Y_RANGE	3000
#define BMI160_ACC_SELF_TEST_AXIS_Z_RANGE	1500

///////////////////////////////////////////////////////////////////////////////////////////////////////

#define BMI160_ACC_CONF_RATE_6				0x04
#define BMI160_ACC_CONF_RATE_12				0x05
#define BMI160_ACC_CONF_RATE_25				0x06
#define BMI160_ACC_CONF_RATE_50				0x07
#define BMI160_ACC_CONF_RATE_100				0x08
#define BMI160_ACC_CONF_RATE_200				0x09
#define BMI160_ACC_CONF_RATE_400				0x0A
#define BMI160_ACC_CONF_RATE_800				0x0B
#define BMI160_ACC_CONF_MASK					0xF0
#define BMI160_ACC_CONF_REG					0x40			//ACC rate(odr) setting register

#define BMI160_ACC_DATA_14_ACC_XL_REG		0x12			//ACC data register
#define BMI160_ACC_DATA_15_ACC_XH_REG		0x13			//ACC data register
#define BMI160_ACC_DATA_16_ACC_YL_REG		0x14			//ACC data register
#define BMI160_ACC_DATA_17_ACC_YH_REG		0x15			//ACC data register
#define BMI160_ACC_DATA_18_ACC_ZL_REG		0x16			//ACC data register
#define BMI160_ACC_DATA_19_ACC_ZH_REG		0x17			//ACC data register

#define BMI160_ACC_INT_STATUS_1_REG			0x1D			//ACC Int status 1
#define BMI160_ACC_INT_STATUS_2_REG			0x1E			//ACC Int status 2
#define BMI160_TEMPERATURE_0_REG				0x20			//TEMPERATURE_0
#define BMI160_TEMPERATURE_1_REG				0x21			//TEMPERATURE_1

#define BMI160_ACC_RANGE_REG					0x41			//ACC RANGE
#define BMI160_ACC_RANGE_2G					0x03			//ACC RANGE 2G
#define BMI160_ACC_RANGE_4G					0x05			//ACC RANGE 4G
#define BMI160_ACC_RANGE_8G					0x08			//ACC RANGE 8G
#define BMI160_ACC_RANGE_16G					0x0C			//ACC RANGE 16G

#ifndef GRAVITY_EARTH
#define GRAVITY_EARTH	9.8066f
#endif

#define BMI160_ACC_CONVERT_2G		(float)GRAVITY_EARTH/16384.0f
#define BMI160_ACC_CONVERT_4G		(float)GRAVITY_EARTH/8192.0f

///////////////////////////////////////////////////////////////////////////////////////////////////////
#define BMI160_GYR_CONF_RATE_6				0x04
#define BMI160_GYR_CONF_RATE_12				0x05
#define BMI160_GYR_CONF_RATE_25				0x06
#define BMI160_GYR_CONF_RATE_50				0x07
#define BMI160_GYR_CONF_RATE_100				0x08
#define BMI160_GYR_CONF_RATE_200				0x09
#define BMI160_GYR_CONF_RATE_400				0x0A
#define BMI160_GYR_CONF_RATE_800				0x0B
#define BMI160_GYR_CONF_MASK					0xF0
#define BMI160_GYR_CONF_REG					0x42			//GYRO rate(odr) setting register

#define BMI160_GYR_DATA_8_GYR_XL_REG			0x0C			//GYR data register
#define BMI160_GYR_DATA_9_GYR_XH_REG			0x0D			//GYR data register
#define BMI160_GYR_DATA_10_GYR_YL_REG		0x0E			//GYR data register
#define BMI160_GYR_DATA_11_GYR_YH_REG		0x0F			//GYR data register
#define BMI160_GYR_DATA_12_GYR_ZL_REG		0x10			//GYR data register
#define BMI160_GYR_DATA_13_GYR_ZH_REG		0x11			//GYR data register

#ifndef M_PI
#define M_PI       3.1415926f
#endif
#define BMI160_GYRO_CONVERT		(float)(M_PI/((float)16.4 * (float)180))

#define BMI160_GYR_FIFO_EN					0x80			
#define BMI160_GYR_FIFO_CONFIG_1_REG		0x47			//GYRO FIFO config register

#define BMI160_GYR_FIFO_LENGTH_0_REG		0x22			//GYRO FIFO count register L
#define BMI160_GYR_FIFO_LENGTH_1_REG		0x23			//GYRO FIFO count register H
#define BMI160_GYR_FIFO_DATA_REG			0x24			//GYRO FIFO data register

#define BMI160_GYR_FIFO_MAX_ALLOWABLE_VALUES			(32)			//GYRO FIFO data max Allowable values count 32 * 6byte


///////////////////////////////////////////////////////////////////////////////////////////////////////

#define BMI160_INT_MAP_EN_NOMO_CONFIG				0x08			//int pin map en config
#define BMI160_INT_MAP_EN_ANYMO_CONFIG				0x04			//int pin map en config
#define BMI160_INT_MAP_0_REG				0x55			//motion int slect int 1
#define BMI160_INT_MAP_2_REG				0x57			//motion int slect int 2

#define BMI160_INT_MOTION_0_REG			0x5F			//motion duty cycle
#define BMI160_INT_MOTION_1_REG			0x60			//motion threshold
#define BMI160_INT_MOTION_2_REG			0x61			//non-motion threshold

#define BMI160_INT_EN_NOMO_SEL			0x01			//Enable no motion select
#define BMI160_INT_MOTION_3_REG			0x62			//non-motion en

#define BMI160_INT_EN_NOMO_CONFIG		0x07			//Enable no motion config
#define BMI160_INT_DISABLE_ANYMO_CONFIG	0x00			//Disable anymotion config
#define BMI160_INT_EN_ANYMO_CONFIG		0x07			//Enable anymotion config
#define BMI160_INT_EN_0_REG				0x50			//interrupt config register
#define BMI160_INT_EN_1_REG				0x51			//interrupt config register
#define BMI160_INT_EN_2_REG				0x52			//interrupt config register




#ifdef BMI160_INT_ACTIVE_HIGH
#define BMI160_INT_1_OUTPUT_EN_CONFIG	0x0A			//int1 en
#define BMI160_INT_2_OUTPUT_EN_CONFIG	0xA0			//int2 en
#else
#define BMI160_INT_1_OUTPUT_EN_CONFIG	0x08			//int1 en
#define BMI160_INT_2_OUTPUT_EN_CONFIG	0x80			//int2 en
#endif
#define BMI160_INT_1_ACTIVE_HIGH_CONFIG	0x02			//int1 ACTIVE HIGH
#define BMI160_INT_OUT_CTRL_REG			0x53			//interrupt config register

///////////////////////////////////////////////////////////////////////////////////////////////////////
#define BMI160_USE_MOTION
#define BMI160_USE_NO_MOTION
#define BMI160_INT_ACTIVE_HIGH
//#define BMI160_USE_SOFT_RESET
///////////////////////////////////////////////////////////////////////////////////////////////////////

#endif /* __SPI_BMI160_DEF_H__ */
