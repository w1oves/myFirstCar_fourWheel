#ifndef __IMAGE_PRE_DEAL
#define __IMAGE_PRE_DEAL

void image_select(uint8 *dst, uint8 *src); //240*40二值化为60*160,其中，每一行有40个字节，每个字节被转换为4个像素
void stopLine_select(uint8 *dst1, uint8 *src1);
#endif