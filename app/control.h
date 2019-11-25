#ifndef __CONTROL
#define __CONTROL
#define DEFAULT__SERVO 0
#define STRAIGHT__SERVO 1
#define LEFT_TURN__SERVO 2
#define RIGHT_TURN__SERVO 3
#define BIG_TURN__SERVO 4
typedef struct 
{
    float32 p;
    float32 i;
    float32 d;
} PID;
typedef struct 
{
    float32 p;
    float32 d;
} PD;
void pid_int(void);
void ServoPDSet(uint8 flag);
#endif