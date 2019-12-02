#include "include.h"

extern LPTMR_InitTypeDef lptmr_init_struct;

uint16 get_speed_right() //b轮子用的是正交解码 而a论用的是直接读取
{
    uint16 B_rightMotor;
    B_rightMotor = LPLD_FTM_GetCounter(FTM2);

    LPLD_FTM_ClearCounter(FTM2);
    if (B_rightMotor > 31678)
        B_rightMotor = 65536 - B_rightMotor;
    return B_rightMotor;
}

uint16 get_speed_left() //b轮子用的是正交解码 而a论用的是直接读取
{
    uint16 A_leftMotor;
    A_leftMotor = get_counter_value();
    lptmr_init();
    return A_leftMotor;
}

int16 rightMotorSpeed = 0;
int16 leftMotorSpeed = 0;
int16 midMotorSpeed=0;

void getSpeed()
{
    rightMotorSpeed = get_speed_right(); //命名反了
    leftMotorSpeed = get_speed_left();   //命名反了
    midMotorSpeed = (rightMotorSpeed + leftMotorSpeed) / 2;
    /*	if (!rightMotorSpeed)
		rightMotorSpeed = leftMotorSpeed;
	if (!leftMotorSpeed)
		leftMotorSpeed = rightMotorSpeed;*/
}

/*******************测速子函数******************/

uint16 get_counter_value() //此段函数为获得脉冲CNR
{
    uint16 dataGet = 0;
    dataGet = LPLD_LPTMR_GetPulseAcc();
    LPLD_LPTMR_ResetCounter();
    lptmr_init();
    return dataGet;
}
