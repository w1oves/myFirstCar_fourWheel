#include "include.h"

/********************加速、减速********************/
/*
    CH1:L-
    CH2:L+
    CH3:R+
    CH4:R-
 */
//粗略的进行加减速操作，用于当前速度与期望速度差异过大时
void motor_speed_up(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 8000);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 8000);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
    
}
void motor_slow_down(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 9000);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 9000);
}

/********************左转、右转********************/
void motor_left_turn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 9000);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 8000);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
}
void motor_right_turn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 8000);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 9000);
}

/********************停车********************/
void motor_stop(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
}
/********************匀速前进********************/
void motor_speed_go(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, 3150);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 3600);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, 0);
}