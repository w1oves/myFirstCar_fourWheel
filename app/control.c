#include "include.h"

PID motor;
PD servo;
PD servo_mode[5];
int16 speed_hope = 0; //速度期望值
void pid_int(void)
{
    motor.p = 72;
    motor.i = 4.5;
    motor.d = 4;
    if (speed_hope > 240)
    { /**********310-250**********/
        servo_mode[0].p = 1.1;
        servo_mode[STRAIGHT].p = 0.9;
        servo_mode[LEFT_TURN].p = 1.38;
        servo_mode[RIGHT_TURN].p = 1.3;
        servo_mode[BIG_TURN].p = 8.3;
        servo_mode[0].d = 0;
        servo_mode[STRAIGHT].d = 1.43;
        servo_mode[LEFT_TURN].d = 0.8;
        servo_mode[RIGHT_TURN].d = 1.03;
        servo_mode[BIG_TURN].d = 0;
    }
    if (speed_hope > 200 && speed_hope <= 240)
    {
        servo_mode[0].p = 1.1;
        servo_mode[STRAIGHT].p = 0.9;
        servo_mode[LEFT_TURN].p = 1.38;
        servo_mode[RIGHT_TURN].p = 1.3;
        servo_mode[BIG_TURN].p = 8.3;
        servo_mode[0].d = 0;
        servo_mode[STRAIGHT].d = 1.43;
        servo_mode[LEFT_TURN].d = 0.8;
        servo_mode[RIGHT_TURN].d = 1.03;
        servo_mode[BIG_TURN].d = 0;
    }
    servo.p = servo_mode[0].p;
    servo.d = servo_mode[0].d;
}
void DuojiPDSet(uint8 flag)
{

    if (flag == STRAIGHT) //直道
    {
        servo = servo_mode[STRAIGHT];
    }
    else if (flag == LEFT_TURN)
    {
        servo = servo_mode[LEFT_TURN];
    }
    else if (flag == RIGHT_TURN)
    {
        servo = servo_mode[RIGHT_TURN];
    }
    else if (flag == BIG_LEFT_TURN || flag == BIG_RIGHT_TURN)
    {
        servo = servo_mode[BIG_TURN];
    }
}