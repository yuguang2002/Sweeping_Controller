/**
 * @file 自动清扫模块
 */

#include "autosweep.h"

Robot robot;
const float wheel_base = 20.0f;     //机器人的直径（厘米）
int obs = 0;                        //障碍物的数量及触碰次数
int return_flag = 0;                //越过障碍物时返回清扫对面的部分
float y_last = 0;

/**
 * @brief 判断障碍物
 */
ObstacleType detect_obstacle(Robot* robot)
{
    if (LS_OFF || RS_OFF)
    {
        float y_update = distance_get(encoder_count_l,encoder_count_r);
        robot->y = y_update - y_last;
        //判断行驶距离是否走完一个墙壁的位置
        if (-10.0f < robot->y - robot->dis_flag[0] < 10.0f)
        {
            return WALL;
        }
        else
        {
            obs ++;
            return OBSTACLE;
        }
    }
    return NO_OBSTACLE;
}

/**
 * @brief 改进BCD算法
 */
void avoid_obstacle(Robot* robot, ObstacleType obstacle)
{
    //如果障碍物为墙壁
    if (obstacle == WALL)
    {
        if(robot->theta == 0)
        {
            if(obs == 0)
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Right(20,90);
                HAL_Delay(100);
                robot->theta = 90;

                Move_Forward_d(20,20);
                HAL_Delay(100);

                turn_Right(20,90);
                HAL_Delay(100);
                robot->theta = 180;

                robot->x ++;
                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
            else
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Left(20,90);
                HAL_Delay(100);
                robot->theta = 270;

                Move_Forward_d(20,20);
                HAL_Delay(100);

                turn_Left(20,90);
                HAL_Delay(100);
                robot->theta = 180;

                return_flag = 1;
                robot->x ++;
                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
        }
        else if(robot->theta == 180)
        {
            if(obs == 0)
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Left(20,90);
                HAL_Delay(100);
                robot->theta = 90;

                Move_Forward_d(20,20);
                HAL_Delay(100);

                turn_Left(20,90);
                HAL_Delay(100);
                robot->theta = 0;

                robot->x ++;
                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
            else
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Right(20,90);
                HAL_Delay(100);
                robot->theta = 270;

                Move_Forward_d(20,20);
                HAL_Delay(100);

                turn_Right(20,90);
                HAL_Delay(100);
                robot->theta = 0;

                return_flag = 1;

                robot->x ++;
                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
        }
    }

    //如果障碍物为障碍,且为第一遍清扫
    else if (obstacle == OBSTACLE && return_flag == 0)
    {
        if (robot->theta == 0)
        {
            if (obs % 2 == 1)
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Right(20, 180);
                HAL_Delay(100);
                robot->theta = 180;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
            else if (obs % 2 == 0)
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Right(20, 90);
                HAL_Delay(100);
                robot->theta = 90;

                Move_Forward_d(20,20);
                HAL_Delay(100);

                turn_Right(20, 90);
                HAL_Delay(100);
                robot->theta = 180;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
        }
        else if (robot->theta == 180)
        {
            if (obs % 2 == 1)
            {
                Move_Back_d(20,10);
                HAL_Delay(100);

                turn_Right(20, 180);
                HAL_Delay(100);
                robot->theta = 0;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
            else if (obs % 2 == 0)
            {
                Move_Back(20);
                HAL_Delay(100);

                turn_Left(20, 90);
                HAL_Delay(100);
                robot->theta = 90;

                Move_Forward_d(20,20);
                HAL_Delay(100);

                turn_Left(20, 90);
                HAL_Delay(100);
                robot->theta = 0;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
        }
    }

    //如果障碍物为障碍,且为第二遍清扫
    else if (obstacle == OBSTACLE && return_flag == 1)
    {
        if(robot->theta == 0)
        {
            if(obs % 2 == 1)
            {
                Move_Back(20);
                HAL_Delay(100);

                turn_Right(20,180);
                HAL_Delay(100);
                robot->theta = 180;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
            else if(obs % 2 == 0)
            {
                Move_Back(20);
                HAL_Delay(100);

                turn_Left(20,90);
                HAL_Delay(100);
                robot->theta = 270;

                Move_Forward(100);
                HAL_Delay(100);

                turn_Left(20,90);
                HAL_Delay(100);
                robot->theta = 180;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
        }
        else if(robot->theta == 180)
        {
            if(obs % 2 == 1)
            {
                Move_Back(20);
                HAL_Delay(100);

                turn_Right(20,180);
                HAL_Delay(100);
                robot->theta = 0;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
            else if(obs % 2 == 0)
            {
                Move_Back(20);
                HAL_Delay(100);

                turn_Right(20,90);
                HAL_Delay(100);
                robot->theta = 270;

                Move_Forward(100);
                HAL_Delay(100);

                turn_Right(20,90);
                HAL_Delay(100);
                robot->theta = 0;

                y_last= distance_get(encoder_count_l,encoder_count_r);
            }
        }
    }
}