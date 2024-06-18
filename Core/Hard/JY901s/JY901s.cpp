#include "HAL.h"
#include <cstdint>

#define I2C_SDA GPIO_PIN_7
#define I2C_CLK GPIO_PIN_6
#define I2C_PORT GPIOB
#define JY901X_ADDRESS 0x50

#define ACC_UPDATE		0x01
#define GYRO_UPDATE		0x02
#define ANGLE_UPDATE	0x04
#define MAG_UPDATE		0x08
#define READ_UPDATE		0x80
static volatile char s_cDataUpdate = 0;
static bool USER_DEBUG = 0; //调试标志位

#define i2c_header hi2c1

float acc_gyro[6] = {0};
float mag_euler[6] = {0};
float quter[4] = {0};
static void IIC_Start(void);
static void IIC_Stop(void);
static void Delayms(uint16_t ucMs);
static void SensorDataUpdata(uint32_t uiReg, uint32_t uiRegNum);
static void AutoScanSensor(void);
static int32_t I2C_ReadBytes(uint8_t dev, uint8_t reg, uint8_t *data, uint32_t length);
static int32_t I2C_WriteBytes(uint8_t dev, uint8_t reg, uint8_t *data, uint32_t length);


extern "C"
{

    void JY901S_Init(void)
    {
        // Do nothing
        WitInit(WIT_PROTOCOL_I2C, JY901X_ADDRESS);
        WitRegisterCallBack(SensorDataUpdata);
        WitI2cFuncRegister(I2C_WriteBytes, I2C_ReadBytes);
        WitDelayMsRegister(Delayms);
        printf("\r\n********************** wit-motion IIC ************************\r\n");
        AutoScanSensor();
    }

    /**
    * @brief Get the Imu Rawdata object
    *
    * @note  读取原始加速度、角速度数据	data[0~2] [accelx : accely : accelz]
    * 									  data[3~5] [gyrox : gyroy : gyroz]
    * @param data
    */
    void GetImuRawdata(float* data)
    {
        int i;
        WitReadReg(AX, 6);
        Delayms(10);
        if(s_cDataUpdate)
        {
            for(i = 0; i < 3; i++)
            {
                *(data+i) = sReg[AX+i] / 32768.0f * 16.0f;
                *(data+3+i) = sReg[GX+i] / 32768.0f * 2000.0f;
            }
            if(USER_DEBUG)
                printf("acc:%.3f %.3f %.3f\r\n", data[0], data[1],data[2]);
                printf("gyro:%.2f %.2f %.2f\r\n", data[3], data[4], data[5]);

        }
    }

    /**
    * @brief Get the Imu Quater object
    *
    * @note  读取四元数据	data[0~3] [q0 : q1 : q2 : q3]
    * @param data
    */
    void GetImuQuater(float * data)
    {
        int i;
        WitReadReg(q0, 4);
        Delayms(10);
        for(i = 0; i < 4; i++)
        {
            *(data+i) = sReg[q0+i] / 32768.0f;
        }
        if(USER_DEBUG)
            printf("quator:%.2f %.2f %.2f %.2f\r\n",data[0], data[1], data[2], data[3]);
    }

    /**
    * @brief Get the Imu Mag object
    *
    * @note  读取磁场数据	data[0~2] [magx : magy : magz]
    * @param data
    */
    void GetImuMag(float * data)
    {
        int i;
        WitReadReg(HX, 3);
        Delayms(10);
        for(i = 0; i < 3; i++)
        {
            *(data+i) = sReg[HX+i];
        }
        if(USER_DEBUG)
            printf("Mag:%.2f %.2f %.2f \r\n",data[0], data[1], data[2]);
    }

    /**
     * @brief Get the Imu Euler object
     *
     * @note  读取欧拉角数据	data[0~2] [roll : pitch : yaw]
     * @param data
     */
    void GetImuEuler(float * data)
    {
        int i;
        WitReadReg(Roll, 3);
        Delayms(10);
        for(i = 0; i < 3; i++)
        {
            *(data+i) = sReg[Roll+i] / 32768.0f*180;
        }
    if(USER_DEBUG)
        printf("Euler:%.2f %.2f %.2f \r\n",data[0], data[1], data[2]);
    }

    void Imu_Test(void)
    {
        USER_DEBUG = 1;

        GetImuRawdata(acc_gyro);
        GetImuMag(mag_euler);
        GetImuEuler(mag_euler+3);
        GetImuQuater(quter);

    }
}

/**
 * @brief 读取指定设备的指定寄存器的数据
 *
 * @param dev 设备地址
 * @param reg 寄存器地址
 * @param data 保存读取数据的缓冲区
 * @param len 要读取的数据长度
 * @return 成功返回1，失败返回-1
 */
static int32_t I2C_ReadBytes(uint8_t dev, uint8_t reg, uint8_t *data, uint32_t len)
{
    static HAL_StatusTypeDef status;
    IIC_Start();
    // 开始I2C传输并发送要读取的寄存器地址
    status = HAL_I2C_Mem_Read(&i2c_header, dev, reg, I2C_MEMADD_SIZE_8BIT, data, len, 1000);
    if(status != HAL_OK)
        return -1;
    HAL_Delay ( 5 );
    IIC_Stop();
    return 1;
}


/**
 * @brief 向指定设备的指定寄存器写入数据
 *
 * @param dev 设备地址
 * @param reg 寄存器地址
 * @param data 要写入的数据缓冲区
 * @param len 要写入的数据长度
 * @return 成功返回1，失败返回-1
 */
static int32_t I2C_WriteBytes(uint8_t dev, uint8_t reg, uint8_t *data, uint32_t len)
{
    static HAL_StatusTypeDef status;

    if(len == 0)
        return 0;
    IIC_Start();
    status = HAL_I2C_Mem_Write(&i2c_header, dev, reg, I2C_MEMADD_SIZE_8BIT, data, len, 1000);
    // 返回执行结果
    IIC_Stop();
    if (status == HAL_OK)
        return 1;
    else
        return -1;
}


/**
 * @brief 发送I2C起始信号
 */
static void IIC_Start(void)
{
    HAL_GPIO_WritePin(I2C_PORT ,I2C_SDA ,GPIO_PIN_SET);
    HAL_GPIO_WritePin(I2C_PORT ,I2C_CLK ,GPIO_PIN_SET);

    HAL_Delay(5);
    HAL_GPIO_WritePin(I2C_PORT ,I2C_SDA ,GPIO_PIN_RESET);

    HAL_Delay(5);
    HAL_GPIO_WritePin(I2C_PORT ,I2C_CLK ,GPIO_PIN_RESET);
}


/**
 * @brief 发送I2C停止信号
 */
static void IIC_Stop(void)
{
    HAL_GPIO_WritePin(I2C_PORT ,I2C_SDA ,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(I2C_PORT ,I2C_CLK ,GPIO_PIN_RESET);

    HAL_Delay(5);
    HAL_GPIO_WritePin(I2C_PORT ,I2C_SDA ,GPIO_PIN_SET);
    HAL_GPIO_WritePin(I2C_PORT ,I2C_CLK ,GPIO_PIN_SET);
    HAL_Delay(5);

}


static void Delayms(uint16_t ucMs)
{
    HAL_Delay(ucMs);
}


/**
 * @brief 传感器数据更新回调函数
 *
 * @param uiReg 寄存器地址
 * @param uiRegNum 寄存器数量
 */
static void SensorDataUpdata(uint32_t uiReg, uint32_t uiRegNum)
{
    int i;
    for(i = 0; i < uiRegNum; i++)
    {
        switch(uiReg)
        {
//            case AX:
//            case AY:
            case AZ:
                s_cDataUpdate |= ACC_UPDATE;
                break;
//            case GX:
//            case GY:
            case GZ:
                s_cDataUpdate |= GYRO_UPDATE;
                break;
//            case HX:
//            case HY:
            case HZ:
                s_cDataUpdate |= MAG_UPDATE;
                break;
//            case Roll:
//            case Pitch:
            case Yaw:
                s_cDataUpdate |= ANGLE_UPDATE;
                break;
            default:
                s_cDataUpdate |= READ_UPDATE;
                break;
        }
        uiReg++;
    }
}


static void AutoScanSensor(void)
{
    int i, iRetry;

    for(i = 0; i < 0x7F; i++)
    {
        WitInit(WIT_PROTOCOL_I2C, i);
        iRetry = 2;
        do
        {
            s_cDataUpdate = 0;
            WitReadReg(AX, 3);
            HAL_Delay(10);
            if(s_cDataUpdate != 0)
            {
                printf("find 0x%02X addr sensor\r\n", i);
                return ;
            }
            iRetry--;
        }while(iRetry);
    }
    printf("can not find sensor\r\n");
    printf("please check your connection\r\n");
}