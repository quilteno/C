#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
// 头文
#define N 500000
#define L 2000
void arrprint(int number[]);
void randomNumber(int numebr[], int len);

int main(int argc, char *argv[])
{

    int a[N];
    randomNumber(a, N);
    //设置样本
    clock_t start = clock();//记录时间
    ///////////////排序函数放置位置///////////////
    // mergeSort(a,0,N-1);
    // bubbleSort(a, N);
    choiceSort(a,N);
    ////////////////////////////////////////////
    printf("Run Time:%f\n", ((double)clock() - start) / CLOCKS_PER_SEC);//打印程序运行花费时间
    // arrPrint(a, N);
    return 0;
}

void arrPrint(int *number, int len)
{
    printf("整理后为\n");
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        printf("%03d ", *(number + i));
        flag++;
        if (flag % (N / L) == 0)
        {
            printf("\n");
        }
    }
}
void randomNumber(int *number, int len)
{
    for (int i = 0; i < len; i++)
    {
        number[i] = rand() % N;
    }
}