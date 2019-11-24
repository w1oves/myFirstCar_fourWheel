#ifndef __INIT
#define __INIT

void init(void);
void uart_init(void);
void blue_init(void);
void switch_init(void);
void led_init(void);
void motor_init(void);
void servo_init(void);
void camera_init(void);
void DMA_TransmitInit();
void pit0_init();
void nvic_init();
#endif