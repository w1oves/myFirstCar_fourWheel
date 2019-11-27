#include "include.h"

/********************加速、减速********************/
//粗略的进行加减速操作，用于当前速度与期望速度差异过大时
void motor_speed_up(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, MOTOR_DUTY_SPEED_UP);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, MOTOR_DUTY_SPEED_UP);
}
void motor_slow_down(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, MOTOR_DUTY_SLOW_DOWN);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, MOTOR_DUTY_SLOW_DOWN);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
}

/********************左转、右转********************/
void motor_left_turn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, MOTOR_DUTY_SLOW_DOWN);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, MOTOR_DUTY_SPEED_UP);
}
void motor_right_turn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, MOTOR_DUTY_SPEED_UP);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, MOTOR_DUTY_SLOW_DOWN);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
}

/********************停车********************/
void motor_stop(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
}