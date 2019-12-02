#include "include.h"
/********************电机控制参数********************/
// PID motor;
float32 motorKp;
float32 motorKd;
float32 motorKi;
/********************舵机控制参数********************/
#define SERVO_POINT SERVO_ZERO_POINT
// PD servo;
// PD servo_mode[5];
int16 duty;
float32 servoKp = 0.7; //舵机的p值
float32 servoKd = 0;   //d值
float32 servoKp5[5] = {1.10, 1.0, 1.2, 1.3, 8.3};
float32 servoKd5[5] = {0, 0.1, 0.7, 1, 0};
/********************综合PID控制参数********************/
#define DIFF_SPEED_LIMIT 70
int16 speed_hope = 0; //速度期望值
int16 adjustLeft = 0;
int16 adjustRight = 0;
int16 last_left_err;
int16 prelast_left_err;
int16 last_right_err;
int16 prelast_right_err;

/********************PID参数初始化********************/
void pid_init()
{
    motorKp = 72;  //22
    motorKi = 4.5; //17.57
    motorKd = 4;   //
    // DistanceSet = 1200;
    // Distance_Ki = 0.3;

    if (speed_hope > 240)
    {
        //250-310
        servoKp5[0] = 1.1;
        servoKp5[1] = 0.9;
        servoKp5[2] = 1.38;
        servoKp5[3] = 1.3;
        servoKp5[4] = 8.3;
        servoKd5[0] = 0;
        servoKd5[1] = 1.43;
        servoKd5[2] = 0.8;
        servoKd5[3] = 1.03;
        servoKd5[4] = 0;
    }
    if (speed_hope > 200 && speed_hope <= 240)
    {
        //200-240
        servoKp5[0] = 1.1;
        servoKp5[1] = 0.9;
        servoKp5[2] = 1.38;
        servoKp5[3] = 1.3;
        servoKp5[4] = 8.3;
        servoKd5[0] = 0;
        servoKd5[1] = 1.43;
        servoKd5[2] = 0.8;
        servoKd5[3] = 1.03;
        servoKd5[4] = 0;
    }

    servoKp = servoKp5[0];
    servoKd = servoKd5[0];
}
// void pid_int(void)
// {
//     motor.p = 72;
//     motor.i = 4.5;
//     motor.d = 4;
//     if (speed_hope > 240)
//     { /**********310-250**********/
//         servo_mode[DEFAULT__SERVO].p = 1.1;
//         servo_mode[STRAIGHT__SERVO].p = 0.9;
//         servo_mode[LEFT_TURN__SERVO].p = 1.38;
//         servo_mode[RIGHT_TURN__SERVO].p = 1.3;
//         servo_mode[BIG_TURN__SERVO].p = 8.3;
//         servo_mode[DEFAULT__SERVO].d = 0;
//         servo_mode[STRAIGHT__SERVO].d = 1.43;
//         servo_mode[LEFT_TURN__SERVO].d = 0.8;
//         servo_mode[RIGHT_TURN__SERVO].d = 1.03;
//         servo_mode[BIG_TURN__SERVO].d = 0;
//     }
//     if (speed_hope > 200 && speed_hope <= 240)
//     {
//         servo_mode[DEFAULT__SERVO].p = 1.1;
//         servo_mode[STRAIGHT__SERVO].p = 0.9;
//         servo_mode[LEFT_TURN__SERVO].p = 1.38;
//         servo_mode[RIGHT_TURN__SERVO].p = 1.3;
//         servo_mode[BIG_TURN__SERVO].p = 8.3;
//         servo_mode[DEFAULT__SERVO].d = 0;
//         servo_mode[STRAIGHT__SERVO].d = 1.43;
//         servo_mode[LEFT_TURN__SERVO].d = 0.8;
//         servo_mode[RIGHT_TURN__SERVO].d = 1.03;
//         servo_mode[BIG_TURN__SERVO].d = 0;
//     }
//     servo.p = servo_mode[DEFAULT__SERVO].p;
//     servo.d = servo_mode[DEFAULT__SERVO].d;
// }
/********************舵机PD参数设置********************/
void ServoPDSet(uint8 flag)
{

    if (flag == STRAIGHT) //直道
    {
        servoKp = servoKp5[1];
        servoKd = servoKd5[1]; //0.1
    }
    else if (flag == LEFT_TURN)
    {
        //左转
        servoKp = servoKp5[2];
        servoKd = servoKd5[2];
    }
    else if (flag == RIGHT_TURN)
    {
        //右转
        servoKp = servoKp5[3];
        servoKd = servoKd5[3];
    }
    else if (flag == BIG_LEFT_TURN || flag == BIG_RIGHT_TURN)
    {
        //大转弯
        servoKp = servoKp5[4];
        servoKd = servoKd5[4];
    }
}
// void ServoPDSet(uint8 flag)
// {
//     if (flag == STRAIGHT) //直道
//     {
//         servo = servo_mode[STRAIGHT__SERVO];
//     }
//     else if (flag == LEFT_TURN)
//     {
//         servo = servo_mode[LEFT_TURN__SERVO];
//     }
//     else if (flag == RIGHT_TURN)
//     {
//         servo = servo_mode[RIGHT_TURN__SERVO];
//     }
//     else if (flag == BIG_LEFT_TURN || flag == BIG_RIGHT_TURN)
//     {
//         servo = servo_mode[BIG_TURN__SERVO];
//     }
// }
/********************舵机PD控制算法********************/
void ServoPd(int16 nowError)
{
    static int16 lastError;
    int16 D_Error_Servo = nowError - lastError;
    int16 servoControl = (int16)(servoKp * nowError + servoKd * D_Error_Servo);
    lastError = nowError;
    duty = (int16)(SERVO_POINT - servoControl);
    if (duty <= SERVO_RIGHT)
        duty = SERVO_RIGHT;
    else if (duty > SERVO_LEFT)
        duty = SERVO_LEFT;
    LPLD_FTM_PWM_ChangeDuty(FTM1, FTM_Ch1, duty); //B1口
}
/********************电机期望速度逼近控制算法********************/
void speedControl(int16 differ)
{
    int16 speedDiff = speed_hope - (uint16)((rightMotorSpeed + leftMotorSpeed) / 2);
    if ((howToDo.stop == 1 || speed_hope == 0) && (rightMotorSpeed < 30 || leftMotorSpeed < 30))
    {
        motor_stop();
    }
    else if (speedDiff < -60)
        motor_speed_up();
    else if (speedDiff > 100)
        motor_slow_down();
    else
        motor_pid(abs(differ) < 40 ? 0 : differ); //电机
}
/********************PID差速转弯********************/
void motor_pid(int16 diff)
{
    int16 rightSpeedHope, leftSpeedHope;
    int16 now_left_err, now_right_err;
    //利用电机差速进行转弯
    if (diff > DIFF_SPEED_LIMIT)
        diff = DIFF_SPEED_LIMIT;
    else if (diff < -DIFF_SPEED_LIMIT)
        diff = -DIFF_SPEED_LIMIT;
    //左轮PID计算
    rightSpeedHope = (int16)(speed_hope - 0.4 * diff); //利用电机差速，diff：+右转，-左转
    leftSpeedHope = (int16)(speed_hope + 0.4 * diff);  //diff是differ值------系数待确定---------!!
    now_left_err = leftSpeedHope - leftMotorSpeed;
    adjustLeft += (int16)(motorKp * (now_left_err - last_left_err) + motorKi * now_left_err + motorKd * (now_left_err + prelast_left_err - 2 * last_left_err));
    if (adjustLeft < 0)
        adjustLeft = 0;
    else if (adjustLeft >= 8000)
        adjustLeft = 8000;
    prelast_left_err = last_left_err;
    last_left_err = now_left_err;
    //右轮PID计算
    now_right_err = rightSpeedHope - rightMotorSpeed;
    adjustRight += (int16)(motorKp * (now_right_err - last_right_err) + motorKi * now_right_err + motorKd * (now_right_err + prelast_right_err - 2 * last_right_err));
    if (adjustRight < 0)
        adjustRight = 0;
    else if (adjustRight >= 8000)
        adjustRight = 8000;
    prelast_right_err = last_right_err;
    last_right_err = now_right_err;
    //给pwm波
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch0, 0); //右轮子
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch1, adjustRight);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch2, 0);
    LPLD_FTM_PWM_ChangeDuty(FTM0, FTM_Ch3, adjustLeft);
}
