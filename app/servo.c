#include "include.h"
void servo_leftTurn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, SERVO_DGREE_LEFT_45); //B1口
}
void servo_rightTurn(void)
{
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, SERVO_DGREE_RIGHT_45); //B1口
}