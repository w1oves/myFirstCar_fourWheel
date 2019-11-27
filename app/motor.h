#ifndef __MOTOR
#define __MOTOR
//电机加减速占空比
#define MOTOR_DUTY_SPEED_UP 8000
#define MOTOR_DUTY_SLOW_DOWN 9000
//电机控制函数
void motor_speed_up(void);
void motor_slow_down(void);
void motor_left_turn(void);
void motor_right_turn(void);
void motor_stop(void);
#endif