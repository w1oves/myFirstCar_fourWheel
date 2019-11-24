#ifndef __CONTROL
#define __CONTROL
#define STRAIGHT 1
#define LEFT_TURN 2
#define RIGHT_TURN 3
#define BIG_TURN 4
#define BIG_RIGHT_TURN BIG_TURN
#define BIG_LEFT_TURN BIG_TURN
typedef struct pid
{
    float32 p;
    float32 i;
    float32 d;
} PID;
typedef struct pd
{
    float32 p;
    float32 d;
} PD;
void pid_int(void);
void DuojiPDSet(uint8 flag);
#endif