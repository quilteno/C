#ifndef _SORT_H_
#define _SORT_H_
//#ifndef后面写头文件名的大写。例如test.h，——>_TEST_H_
/*排序头文件，提供多种数组排序*/
void swap(int *swap_a, int *swap_b);
int bubble(int *bubble_a, int n);
void choice(int *choice_a, int n);

//冒泡排序
int bubble(int *bubble_a, int bubble_n)
{
    int flag = 0;
    for (int i = 0; i < bubble_n; i++)
    {
        for (int j = 0; j < bubble_n - i; j++)
        {
            if (*(bubble_a + j) > *(bubble_a + j + 1))
            {
                swap(bubble_a + j, bubble_a + j + 1); //地址一定要确认好，不要忘加j和j+1
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
//声明的函数和变量都要以冒号结尾
void swap(int *swap_a, int *swap_b)
{
    *swap_a ^= *swap_b;
    *swap_b ^= *swap_a;
    *swap_a ^= *swap_b;
    /*异或位运算交换两值*/
}

//选择排序法
void choice(int *choice_a, int choice_n)
{
    int temp = 0;
    int c;
    for (int i = 0; i < choice_n - 1; i++)
    {
        temp = *(choice_a + i);
        c = 0;
        for (int j = i + 1; j < choice_n; j++)
        {
            if (temp > *(choice_a + j))
            {
                temp = *(choice_a + j);
                c = j;
            }
        }
        if (c != 0)
        {

            *(choice_a + c) = *(choice_a + i);
            *(choice_a + i) = temp;
        }
    }
}

#endif