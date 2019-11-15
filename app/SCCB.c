#include "common.h"
#include "SCCB.h"

GPIO_InitTypeDef gpio_init_sccb_struct;

static void SCCB_delay(uint16 i);

static void SCCB_delay(volatile uint16 time)
{
  while(time)
    time--;
}

void SCCB_GPIO_Init(void)
{
  // 配置 PTA26/PTA27为GPIO功能,输出,高电平，禁用中断
  gpio_init_sccb_struct.GPIO_PTx = PTB;
  gpio_init_sccb_struct.GPIO_Pins = GPIO_Pin2|GPIO_Pin3;
  gpio_init_sccb_struct.GPIO_Dir = DIR_OUTPUT;
  gpio_init_sccb_struct.GPIO_Output = OUTPUT_H;
  gpio_init_sccb_struct.GPIO_PinControl = IRQC_DIS;
  LPLD_GPIO_Init(gpio_init_sccb_struct);
}

static uint8 SCCB_Start(void)
{
  SDA_H;
  SCL_H;
  SCCB_DELAY();
  
  SDA_DDR_I;
  if(!SDA_IN)
  {
    SDA_DDR_O;
    return 0;
  }
  SDA_DDR_O;
  SDA_L;
  
  SCCB_DELAY();
  SCL_L;
  
  if(SDA_IN)
  {
    SDA_DDR_O;
    return 0;
  }
  
  return 1;
}

static void SCCB_Stop(void)
{
  SCL_L;
  SDA_L;
  SCCB_DELAY();
  SCL_H;
  SCCB_DELAY();
  SDA_H;
  SCCB_DELAY();
}

static void SCCB_Ack(void)
{
  SCL_L;
  SCCB_DELAY();
  SDA_L;
  SCCB_DELAY();
  SCL_H;
  SCCB_DELAY();
  SCL_L;
  SCCB_DELAY();
}

static void SCCB_NoAck(void)
{
  SCL_L;
  SCCB_DELAY();
  SDA_H;
  SCCB_DELAY();
  SCL_H;
  SCCB_DELAY();
  SCL_L;
  SCCB_DELAY();
}

static int SCCB_WaitAck(void)
{
  SCL_L;
  SDA_DDR_I;
  
  SCCB_DELAY();
  SCL_H;
  
  SCCB_DELAY();
  if(SDA_IN)
  {
    SDA_DDR_O;
    SCL_L;
    return 0;
  }
  
  SDA_DDR_O;
  SCL_L;
  return 1;
}

static void SCCB_SendByte(uint8 SendByte)
{
  uint8 i = 8;
  while(i--)
  {
    if(SendByte&0x80)
      SDA_H;
    else
      SDA_L;
    SendByte<<=1;
    SCCB_DELAY();
    SCL_H;
    SCCB_DELAY();
    SCL_L;
  }
}

static int SCCB_ReceiveByte(void)
{
  uint8 i = 8;
  uint8 ReceiveByte=0;
  
  SDA_DDR_I;
  while(i--)
  {
    ReceiveByte<<=1;
    SCL_L;
    SCCB_DELAY();
    SCL_H;
    SCCB_DELAY();
    
    if(SDA_IN)
      ReceiveByte |=0x01;
  }
  SDA_DDR_O;
  SCL_L;
  return ReceiveByte;
}

static int SCCB_WriteByte_one(uint16 WriteAddress , uint8 SendByte);

int SCCB_WriteByte(uint16 WriteAddress , uint8 SendByte)
{
  uint8 i = 0;
  while(0==SCCB_WriteByte_one ( WriteAddress, SendByte ))
  {
    i++;
    if(i==20)
      return 0;
  }
  return 1;
}

int SCCB_WriteByte_one(uint16 WriteAddress , uint8 SendByte)
{
  if(!SCCB_Start())
    return 0;
  SCCB_SendByte(DEV_ADR);
  if(!SCCB_WaitAck())
  {
    SCCB_Stop();
    return 0;
  }
  SCCB_SendByte((uint8)(WriteAddress&0x00ff));
  SCCB_WaitAck();
  SCCB_SendByte(SendByte);
  SCCB_WaitAck();
  SCCB_Stop();
  return 1;
}

static int SCCB_ReadByte_one(uint8 *pBuffer , uint16 length , uint8 ReadAddress);

int SCCB_ReadByte(uint8 *pBuffer , uint16 length , uint8 ReadAddress)
{
  uint8 i=0;
  while(0==SCCB_ReadByte_one(pBuffer , length , ReadAddress))
  {
    i++;
    if(i==30)
      return 0;
  }
  return 1;
}

int SCCB_ReadByte_one(uint8 *pBuffer , uint16 length , uint8 ReadAddress)
{
  if(!SCCB_Start())
  {
    printf("\n:a");
    return 0;
  }
  SCCB_SendByte(DEV_ADR);
  if(!SCCB_WaitAck())
  {
    printf("\n:b");
    SCCB_Stop();
    return 0;
  }
  SCCB_SendByte(ReadAddress);
  SCCB_WaitAck();
  SCCB_Stop();
  
  if(!SCCB_Start())
    return 0;
  SCCB_SendByte(DEV_ADR+1);
  
  if(!SCCB_WaitAck())
  {
    SCCB_Stop();
    return 0;
  }
  while(length)
  {
    *pBuffer=SCCB_ReceiveByte();
    if(length==1)
      SCCB_NoAck();
    else
      SCCB_Ack();
    pBuffer++;
    length--;
  }
  SCCB_Stop();
  return 1;
}