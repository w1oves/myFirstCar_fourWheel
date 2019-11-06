#ifndef __MOTOR
#define __MOTOR
//电机FTM模块号
#define MOTOR_FTM FTM0
//电机FTM通道号
#define MOTOR_CH_LEFT_PLUS FTM_Ch0
#define MOTOR_CH_LEFT_MINUS FTM_Ch1
#define MOTOR_CH_RIGHT_PLUS FTM_Ch2
#define MOTOR_CH_RIGHT_MINUS FTM_Ch3
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