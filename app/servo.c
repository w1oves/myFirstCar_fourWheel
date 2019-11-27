#include "include.h"
void servo_leftTurn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, SERVO_LEFT); //B1口
}
void servo_rightTurn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, SERVO_RIGHT); //B1口
}
void servo_midTurn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, SERVO_ZERO_POINT); //B1口
}