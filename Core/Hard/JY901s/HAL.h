#ifndef __HAL_H_
#define __HAL_H_

#include "../Lib/3rdParty/wit_c_sdk/wit_c_sdk.h"
#include "main.h"

#ifdef __cplusplus
extern "C" {

#endif

    extern float acc_gyro[6];
    extern float mag_euler[6];
    extern float quter[4];

    void User_HalInit(void);

    // JY901S
    void JY901S_Init(void);
    void GetImuRawdata(float* data);
    void GetImuQuater(float * data);
    void GetImuMag(float * data);
    void GetImuEuler(float * data);
    void Imu_Test(void);
    void Imu_Data(void);

#ifdef __cplusplus
};
#endif




#endif // __HAL_H_
