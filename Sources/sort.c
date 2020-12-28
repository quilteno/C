#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"
// 头文
#define N 10000//生成数组大小
#define L 20//共输出多少行，注释掉arrPrint可不管
void arrprint(int number[]);//输出数组函数
void randomNumber(int numebr[], int len);//生成随机数

int main(int argc, char *argv[])
{

    int a[N];
    randomNumber(a, N);
    //设置样本
    clock_t start = clock();//记录时间
    ///////////////排序函数放置位置///////////////
    HeapSort(a, N);
    // mergeSort(a,0,N-1);
    // bubbleSort(a, N);
    // choiceSort(a,N);
    ////////////////////////////////////////////
    printf("Run Time:%f\n", ((double)clock() - start) / CLOCKS_PER_SEC);//打印程序运行花费时间
    printf("midum=%d\nlast=%d\n", a[N / 2], a[N-1]);//打印中值和尾值
    // arrPrint(a, N);
    return 0;
}

void arrPrint(int *number, int len)
{
    printf("整理后为\n");
    int flag = 0;
    for (int i = 0; i < len; i+=N/100)
    {
        printf("%03d ", *(number + i));
        flag++;
        if (flag % (N / L) == 0)
        {
            printf("\n");//打印L行
        }
    }
}
void randomNumber(int *number, int len)
{
    for (int i = 0; i < len; i++)
    {
        number[i] = rand() % 1000;//生成最大1000的随机数 
    }
}