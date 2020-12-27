#ifndef _BUBBLE_H_
#define _BUBBLE_H_
//#ifndef后面写头文件名的大写。例如test.h，——>_TEST_H_
/*包括两个函数swap和bubble，用法如下*/
void swap(int *a, int *b);
int bubble(int *number, int n);


int bubble(int *number, int n)
{
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (*(number + j) > *(number + j + 1))
            {
                swap(number+j, number + j+1);//地址一定要确认好，不要忘加j和j+1
                flag = 1;//若出现交换，则继续进行
            }
        }
        if(flag==0){//如果没有交换，说明已经交换完成，退出函数
            return 0;
        }
    }
    return 1;
}
//声明的函数和变量都要以冒号结尾
void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
    /*异或位运算交换两值*/
}
#endif