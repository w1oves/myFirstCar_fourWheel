
#include "OV7725_REG.h"
#include "common.h"
#define ARR_SIZE(a) (sizeof((a))/sizeof(((a)[0])))

typedef struct
{
  uint8 addr;
  uint8 val;
}reg_s;

//��������ͷ ����
#define OV7725_EAGLE_W           320                                  //��������ͷͼ����
#define OV7725_EAGLE_H            240                                    //��������ͷͼ��߶�
#define OV7725_EAGLE_SIZE         (OV7725_EAGLE_W * OV7725_EAGLE_H/8)  //ͼ��ռ�ÿռ��С
#define OV7725_EAGLE_DMA_NUM      (OV7725_EAGLE_SIZE)                  //DMA�ɼ�����

//���� ����ͷ ����
#define CAMERA_W            OV7725_EAGLE_W              //��������ͷͼ����
#define CAMERA_H            OV7725_EAGLE_H              //��������ͷͼ��߶�

#define CAMERA_SIZE         OV7725_EAGLE_SIZE           //ͼ��ռ�ÿռ��С
#define CAMERA_DMA_NUM      OV7725_EAGLE_DMA_NUM        //DMA�ɼ�����


void OV7725_EAGLE_Delay_ms(uint16 ms);

uint8 OV7725_eagle_reg_init(void);
void comfirmIIC();