#ifndef __HAL_H_
#define __HAL_H_

#include "../3rdParty/wit_c_sdk/wit_c_sdk.h"

#ifdef __cplusplus
extern "C" {
#endif

    #include "main.h"

    void User_HalInit(void);

    // JY901S
    void JY901S_Init(void);
    void GetImuRawdata(float* data);
    void GetImuQuater(float * data);
    void GetImuMag(float * data);
    void GetImuEuler(float * data);
    void Imu_Test(void);

#ifdef __cplusplus
};
#endif




#endif // __HAL_H_
