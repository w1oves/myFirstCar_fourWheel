#ifndef __SERVO
#define __SERVO

#define SERVO_ZERO_POINT 300
#define SERVO_LEFT 375
#define SERVO_RIGHT 215

void servo_leftTurn(void);
void servo_rightTurn(void);
void servo_midTurn(void);

#endif