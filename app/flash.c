#include "include.h"
#define servoPD_SECTOR   (128)
#define servoPD_ADDR     (servoPD_SECTOR*2048)// FLASH_TEST_SECTOR*(2048)
#define servoPD_DATA_SIZE           (20)           //两个数组，每个20B

void Save_servoPD_parameter(void)
{
  LPLD_Flash_SectorErase(servoPD_ADDR);
  LPLD_Flash_ByteProgram(servoPD_ADDR, (uint32*)&servoKp5, servoPD_DATA_SIZE);
  LPLD_Flash_ByteProgram(servoPD_ADDR+servoPD_DATA_SIZE, (uint32*)servoKd5, servoPD_DATA_SIZE);
}

void Read_servoPD_parameter( void)//读取伺服系统参数
{
  uint32 *ptr_source,*ptr_destination;//设定两个指针指向待读取数据和储存区
  uint8 size=0;
  ptr_source=(uint32*)servoPD_ADDR;
  ptr_destination=(uint32*)servoKp5;
  size = (servoPD_DATA_SIZE - 1)/4 + 1;  //确定待读取数据个数(大小)
  for(;size>0;size--)
  {
    *ptr_destination = *ptr_source;
    ptr_source++;
    ptr_destination++;
  }
  
  ptr_destination=(uint32*)servoKd5;
  size = (servoPD_DATA_SIZE - 1)/4 + 1;  
  for(;size>0;size--)//完成读取数据
  {
    *ptr_destination = *ptr_source;
    ptr_source++;
    ptr_destination++;
  }  
}
#define MotorPID_SECTOR   (129)
#define MotorPID_ADDR     (MotorPID_SECTOR*2048)// FLASH_TEST_SECTOR*(2048)
#define MotorPID_DATA_SIZE           (28)           
void Save_MotorPID_parameter(void)
{
  uint32 MotorPID_Arr[6]={0};
  uint32 *pointer=0;
  pointer = (uint32 *)(&motorKp);
  MotorPID_Arr[0] = *pointer;
  pointer = (uint32 *)(&motorKi);
  MotorPID_Arr[1] = *pointer;
  pointer = (uint32 *)(&motorKd);
  MotorPID_Arr[2] = *pointer;
  /*
  pointer = (uint32 *)(&DistanceSet);
  MotorPID_Arr[3] = *pointer;
  pointer = (uint32 *)(&Distance_Kp);
  MotorPID_Arr[4] = *pointer;  
  pointer = (uint32 *)(&Distance_Ki);
  MotorPID_Arr[5] = *pointer;  
  */
  
  LPLD_Flash_SectorErase(MotorPID_ADDR);
  LPLD_Flash_ByteProgram(MotorPID_ADDR, MotorPID_Arr, MotorPID_DATA_SIZE);
}
//------------------------------------------------------------------------------------------------------
void Read_MotorPID_parameter( void)
{
  uint32 *ptr_source,*ptr_destination;
  uint8 size=0;
  uint32 MotorPID_Arr[6]={0};
  uint32 *pointer=0;
  
  ptr_source=(uint32*)MotorPID_ADDR;
  ptr_destination=(uint32*)MotorPID_Arr;
  size = (MotorPID_DATA_SIZE - 1)/4 + 1;
  
  for(;size>0;size--)
  {
    *ptr_destination = *ptr_source;
    ptr_source++;
    ptr_destination++;
  }
  
  pointer = (uint32 *)(&motorKp);
  *pointer = MotorPID_Arr[0];
  pointer = (uint32 *)(&motorKi);
  *pointer = MotorPID_Arr[1];
  pointer = (uint32 *)(&motorKd);
  *pointer = MotorPID_Arr[2];
  /*
  pointer = (uint32 *)(&DistanceSet);
  *pointer = MotorPID_Arr[3];  
  pointer = (uint32 *)(&Distance_Kp);
  *pointer = MotorPID_Arr[4]; 
  pointer = (uint32 *)(&Distance_Ki);
  *pointer = MotorPID_Arr[5];    
  */
}