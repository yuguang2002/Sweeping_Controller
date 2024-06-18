/**
 * @file 自动清扫模块
 */

#ifndef VET6_AUTOSWEEP_H
#define VET6_AUTOSWEEP_H

#include "main.h"


// 机器人的位置和方向
typedef struct {
    float x;            // 机器人的X坐标
    float y;            // 机器人的Y坐标
    int theta;          // 机器人全局坐标系下的方向（向前为0,向右位90,向后为180,向左为270）
    int count_x;        //机器人的x方向移动的身位
    float dis_flag[];   //记录x位置时y的位移
} Robot;

// 障碍物检测
typedef enum {
    NO_OBSTACLE,        //无障碍物
    OBSTACLE,           //障碍物
    WALL                //墙壁
} ObstacleType;


extern Robot robot;
void avoid_obstacle(Robot* robot, ObstacleType obstacle);
ObstacleType detect_obstacle(Robot* robot);

#endif //VET6_AUTOSWEEP_H
