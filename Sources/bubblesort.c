#include "bubble.h"
#include <stdio.h>
// 头文件
int main(int argc, char *argv[])
{
    int n = 5;
    int a[5] = {44, 34, 32, 11, 64};
    bubble(a, n); //若不需要整理函数返回值1
    printf("整理后为");
    for (int i = 0; i < n; i++)
    {
        printf(",%d", a[i]);
    }
    return 0;
}