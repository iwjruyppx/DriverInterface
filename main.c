#include "main.h"
#include "DriverHal_1_0.h"

DriverHandle_t accHandle;
DriverHandle_t gyroHandle;
DriverAPI driverAPI;

static void driver_init(void)
{
    DriverConfig Config;

    Config.id = SPI_BMI160;
    Config.type = TYPE_ACCELEROMETER;
    Config.slaveAddr = 0x00;
    Config.privateSetting[0] = 0x00;
    Config.privateSetting[1] = 0x00;
    Config.privateSetting[2] = 0x00;
    Config.privateSetting[3] = 0x00;
    DriverInit(&accHandle, &driverAPI, &Config);
    
    Config.id = SPI_BMI160;
    Config.type= TYPE_GYROSCOPE;
    Config.slaveAddr = 0x00;
    Config.privateSetting[0] = 0x00;
    Config.privateSetting[1] = 0x00;
    Config.privateSetting[2] = 0x00;
    Config.privateSetting[3] = 0x00;
    DriverInit(&gyroHandle, &driverAPI, &Config);
}

 int main( void )
{
    driver_init();
    while(1)
    {
        printf("test\n");
    }
}

