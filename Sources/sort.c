#include "sort.h"
#include <stdio.h>
#include <stdlib.h>
// 头文件
const int N = 5; //设置排序的样本数

int main(int argc, char *argv[])
{
    int a[] = {20, 10, 10, 30, 40};
    //设置样本
    ///////////////排序函数放置位置///////////////
    bubble(a, N);
    ////////////////////////////////////////////
    printf("整理后为");
    for (int i = 0; i < N; i++)
    {
        printf(" %d", a[i]);
    }
    return 0;
}