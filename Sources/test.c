#include <stdio.h>
#include "sort.h"
//头文件
int bubble_mine(int *bubble_a, int bubble_n);

int main(int argc,const char **argv){
    int a[] = {20, 10, 10, 30, 40};
    //设置样本
    ///////////////排序函数放置位置///////////////
    bubble_mine(a, 5);
    ////////////////////////////////////////////
    printf("整理后为");
    for (int i = 0; i < 5; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}//主函数
int bubble_mine(int *a, int bubble_n)
{
    int flag = 0;
    for (int i = 0; i < bubble_n; i++)
    {
        flag = 0;
        for (int j = 0; j < bubble_n - i-1; j++)
        {
            if (*(a + j) > *(a + j + 1))
            {
                swap(a + j, a + j + 1); //地址一定要确认好，不要忘加j和j+1
                flag = 1;                             //若出现交换，则继续进行
            }
        }
        if (flag == 0)
        { //如果没有交换，说明已经交换完成，退出函数
            return 0;
        }
    }
    return 1;
}