#include "include.h"

#define DEFAULT_MID (COLUMN / 2-15)
#define MIN_WHITE_STRAIGHT

uint8 leftLine[ROW];   //左边缘线
uint8 rightLine[ROW];  //右边缘线
uint8 middleLine[ROW]; //中线

int16 differ; //计算偏移量结果
uint16 rightSum = 0;
uint16 leftSum = 0;
uint16 midSum = 0;
//白色：1
//黑色：0
uint8 top_track = 0; //赛道最高点：上面都是1
void imageDeal(void)
{
    uint8 i, j;

    /********************搜底层左右边线********************/
    //搜底层左边线
    for (j = DEFAULT_MID; j > 0; j--)
    {
        if (Image_Data[ROW - 1][j] && !Image_Data[ROW - 1][j - 1] && !Image_Data[ROW - 1][j - 2])
        {
            leftLine[ROW - 1] = j;
            break;
        }
    }
    //搜底层右边线
    rightLine[ROW - 1] = COLUMN;
    for (j = DEFAULT_MID; j < COLUMN; j++)
    {
        if (Image_Data[ROW - 1][j] && !Image_Data[ROW - 1][j + 1] && !Image_Data[ROW - 1][j + 2])
        {
            rightLine[ROW - 1] = j;
            break;
        }
    }
    middleLine[ROW - 1] = (rightLine[ROW - 1] + leftLine[ROW - 1]) >> 1;

    /********************搜左右边线********************/
    for (i = ROW; i > 0; i--)
    {
        leftLine[i - 1] = 0;
        for (j = middleLine[i]; j > 0; j--)
            if (Image_Data[i - 1][j] && !Image_Data[i - 1][j - 1] && !Image_Data[i - 1][j - 2])
            {
                leftLine[i - 1] = j;
                break;
            }

        rightLine[i - 1] = COLUMN;
        for (j = middleLine[i]; j < COLUMN; j++)
            if (Image_Data[i - 1][j] && !Image_Data[i - 1][j + 1] && !Image_Data[i - 1][j + 2])
            {
                rightLine[i - 1] = j;
                break;
            }

        middleLine[i - 1] = (rightLine[i - 1] + leftLine[i - 1]) >> 1;
    }
    /********************弯道判别********************/
    
    // for (shangyan = ROW - 3;
    //      (shangyan > 2) &&
    //      (leftLine[shangyan - 2] < zhongdian || leftLine[shangyan - 1] < zhongdian || leftLine[shangyan] < zhongdian) && (rightLine[shangyan - 2] > zhongdian || rightLine[shangyan - 1] > zhongdian || rightLine[shangyan] > zhongdian);
    //      shangyan--)
    //     ; //寻找赛道上边沿

    for (top_track = ROW - 10; top_track > 10; top_track--)
    {
        if (leftLine[top_track] > DEFAULT_MID && leftLine[top_track - 1] > DEFAULT_MID && leftLine[top_track - 2] > DEFAULT_MID)
        {
            if (middleLine[top_track] > DEFAULT_MID)
                howToDo.road = LEFT_TURN;
            break;
        }
        if (rightLine[top_track] < DEFAULT_MID && rightLine[top_track - 1] < DEFAULT_MID && rightLine[top_track - 2] < DEFAULT_MID)
        {
            if (middleLine[top_track] < DEFAULT_MID)
                howToDo.road = RIGHT_TURN;
            break;
        }
    }
    if(top_track<=10)
    {
        howToDo.road=STRAIGHT;
    }
    differ=(middleLine[top_track]+middleLine[ROW/2])/2;
    differ-=DEFAULT_MID;
}


void autoRun(void)
{
    ServoPDSet(STRAIGHT);
    // switch (howToDo.road)
    // {
    // case STRAIGHT:
    //     differ=0;
    //     break;
    // case LEFT_TURN:
    //     differ=-40;
    //     break;
    // case RIGHT_TURN:
    //     differ=40;
    //     break;
    // default:
    //     break;
    // }
    ServoPd(differ);
}