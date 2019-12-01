#include "include.h"
/********************电机控制参数********************/
PID motor;

/********************舵机控制参数********************/
#define SERVO_POINT SERVO_ZERO_POINT
PD servo;
PD servo_mode[5];
int16 duty;

/********************综合控制参数********************/
int16 speed_hope = 0; //速度期望值

/********************PID参数初始化********************/
void pid_int(void)
{
    motor.p = 72;
    motor.i = 4.5;
    motor.d = 4;
    if (speed_hope > 240)
    { /**********310-250**********/
        servo_mode[DEFAULT__SERVO].p = 1.1;
        servo_mode[STRAIGHT__SERVO].p = 0.9;
        servo_mode[LEFT_TURN__SERVO].p = 1.38;
        servo_mode[RIGHT_TURN__SERVO].p = 1.3;
        servo_mode[BIG_TURN__SERVO].p = 8.3;
        servo_mode[DEFAULT__SERVO].d = 0;
        servo_mode[STRAIGHT__SERVO].d = 1.43;
        servo_mode[LEFT_TURN__SERVO].d = 0.8;
        servo_mode[RIGHT_TURN__SERVO].d = 1.03;
        servo_mode[BIG_TURN__SERVO].d = 0;
    }
    if (speed_hope > 200 && speed_hope <= 240)
    {
        servo_mode[DEFAULT__SERVO].p = 1.1;
        servo_mode[STRAIGHT__SERVO].p = 0.9;
        servo_mode[LEFT_TURN__SERVO].p = 1.38;
        servo_mode[RIGHT_TURN__SERVO].p = 1.3;
        servo_mode[BIG_TURN__SERVO].p = 8.3;
        servo_mode[DEFAULT__SERVO].d = 0;
        servo_mode[STRAIGHT__SERVO].d = 1.43;
        servo_mode[LEFT_TURN__SERVO].d = 0.8;
        servo_mode[RIGHT_TURN__SERVO].d = 1.03;
        servo_mode[BIG_TURN__SERVO].d = 0;
    }
    servo.p = servo_mode[DEFAULT__SERVO].p;
    servo.d = servo_mode[DEFAULT__SERVO].d;
}
/********************舵机PD参数设置********************/
void ServoPDSet(uint8 flag)
{

    if (flag == STRAIGHT) //直道
    {
        servo = servo_mode[STRAIGHT__SERVO];
    }
    else if (flag == LEFT_TURN)
    {
        servo = servo_mode[LEFT_TURN__SERVO];
    }
    else if (flag == RIGHT_TURN)
    {
        servo = servo_mode[RIGHT_TURN__SERVO];
    }
    else if (flag == BIG_LEFT_TURN || flag == BIG_RIGHT_TURN)
    {
        servo = servo_mode[BIG_TURN__SERVO];
    }
}
/********************舵机PD控制算法********************/
void ServoPd(int16 nowError)
{
    static int16 lastError;
    int16 D_Error_Servo = nowError - lastError;
    int16 servoControl = (int16)(servo.p * nowError + servo.d * D_Error_Servo);
    lastError = nowError;
    duty = (int16)(SERVO_POINT - servoControl);
    if (duty <= SERVO_RIGHT)
        duty = SERVO_RIGHT;
    else if (duty > SERVO_LEFT)
        duty = SERVO_LEFT;
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, duty); //B1口
}

