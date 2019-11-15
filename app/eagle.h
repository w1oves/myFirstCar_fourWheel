
#include "OV7725_REG.h"
#include "common.h"
#define ARR_SIZE(a) (sizeof((a))/sizeof(((a)[0])))

typedef struct
{
  uint8 addr;
  uint8 val;
}reg_s;

//配置摄像头 属性
#define OV7725_EAGLE_W           320                                  //定义摄像头图像宽度
#define OV7725_EAGLE_H            240                                    //定义摄像头图像高度
#define OV7725_EAGLE_SIZE         (OV7725_EAGLE_W * OV7725_EAGLE_H/8)  //图像占用空间大小
#define OV7725_EAGLE_DMA_NUM      (OV7725_EAGLE_SIZE)                  //DMA采集次数

//配置 摄像头 参数
#define CAMERA_W            OV7725_EAGLE_W              //定义摄像头图像宽度
#define CAMERA_H            OV7725_EAGLE_H              //定义摄像头图像高度

#define CAMERA_SIZE         OV7725_EAGLE_SIZE           //图像占用空间大小
#define CAMERA_DMA_NUM      OV7725_EAGLE_DMA_NUM        //DMA采集次数


void OV7725_EAGLE_Delay_ms(uint16 ms);

uint8 OV7725_eagle_reg_init(void);
void comfirmIIC();