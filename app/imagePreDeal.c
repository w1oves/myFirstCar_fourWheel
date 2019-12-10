#include "include.h"
/********************软件二值化算法********************/
//MODIFY:可以加上code
//FASTCAR
//uint16 SampleRow[ROW] = {8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18,
//                         19, 20, 21, 22, 23, 24, 25, 26, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45,
  //                       47, 50, 52, 54, 57, 59, 62, 65, 69, 72, 75, 79, 83, 87, 92, 96, 102, 107, 113, 118, 125, 132, 139, 146, 155, 163, 173, 182, 192, 202, 213};
//WNC
 uint16 SampleRow[ROW] = {29, 30, 31, 32, 33, 34, 35, 36, 37, 38,
                          39, 40, 41, 43, 44, 45, 47, 48, 49, 51,
                          52, 54, 55, 56, 58, 60, 61, 63, 65, 66,
                          68, 70, 72, 74, 77, 79, 82, 84, 87, 90,
                          93, 96, 100, 104, 107, 112, 116, 121, 125, 131,
                          136, 142, 148, 155, 161, 169, 176, 185, 193, 202};
//MY
//uint16 SampleRow[ROW] = {0};
void image_select(uint8 *dst, uint8 *src) //240*40二值化为60*160,其中，每一行有40个字节，每个字节被转换为4个像素
{
      
    int16 line = 0;

    //MODIFY: line可以改为uint8型变量
    uint8 colour[2] = {1, 0}; //0 和 1 分别对应的颜色
    int16 i = 0, j = 0;
    //for(i=0;i<ROW;i++)
    //{
//      SampleRow[i]=4*i;
  //  }
    // for ( i = 50; i < 110; i++)
    // {
    //     SampleRow[i-50]=i;
    // }

    uint8 tmpsrc = 0;
    for (i = 0; i < H; i++) //将src的图像二值化,缩小化
    {
        if (i == SampleRow[line])
        {
            line++;
            for (j = 1; j <= V / 8; j++)
            {
                tmpsrc = *(src + i * V / 8 + j);
                *dst++ = colour[(tmpsrc >> 6) & 0x01];
                *dst++ = colour[(tmpsrc >> 4) & 0x01];
                *dst++ = colour[(tmpsrc >> 2) & 0x01];
                *dst++ = colour[(tmpsrc >> 0) & 0x01];
            }
        }
    }
}

void stopLine_select(uint8 *dst1, uint8 *src1) //40-160行每隔一行选择一行进行二值化
{
    uint8 colour[2] = {1, 0}; //0 和 1 分别对应的颜色
    int16 i = 0, j = 0;
    uint8 tmpsrc = 0;
    for (i = 40; i < 160;)
    {
        for (j = 1; j <= V / 8; j++)
        {
            tmpsrc = *(src1 + i * V / 8 + j);
            *(dst1++) = colour[(tmpsrc >> 6) & 0x01];
            *(dst1++) = colour[(tmpsrc >> 4) & 0x01];
            *(dst1++) = colour[(tmpsrc >> 2) & 0x01];
            *(dst1++) = colour[(tmpsrc >> 0) & 0x01];
        }
        i += 2;
    }
}