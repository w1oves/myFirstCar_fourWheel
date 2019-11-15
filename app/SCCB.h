#ifndef SCCB_H
#define SCCB_H

//SCCBπ‹Ω≈≈‰÷√
#define SCCB_SCL  PTB2
#define SCCB_SDA  PTB3

#define SCL_H      PTB2_O=1
#define SCL_L      PTB2_O=0
#define SCL_DDR_O  DDRB3=1
#define SCL_DDR_I  DDRB3=0

#define SDA_H      PTB3_O=1
#define SDA_L      PTB3_O=0
#define SDA_DDR_O  DDRB3=1
#define SDA_DDR_I  DDRB3=0
#define SDA_IN     PTB3_I

#define ADDR_OV7725  0x42

#define DEV_ADR    ADDR_OV7725

#define SCCB_DELAY()   SCCB_delay(300)

extern void SCCB_GPIO_Init(void);
extern int SCCB_WriteByte(uint16 WriteAddress , uint8 SendByte);
extern int SCCB_ReadByte(uint8 *pBuffer , uint16 length , uint8 ReadAddress);

#endif