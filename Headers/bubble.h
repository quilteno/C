#ifndef _BUBBLE_H_
#define _BUBBLE_H_
//#ifndef后面写头文件名的大写。例如test.h，——>_TEST_H_
   /*代码部分*/
extern int a;   //变量一般加extern好点，表示此处是声明，不是定义
extern int *number;
int bubble(int *number,int n);

int bubble(int *number, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i; j++)
        {
            if (*(number + j) > *(number + j + 1))
            {
                *(number + j) ^= *(number + j + 1);
                *(number + j + 1) ^= *(number + j);
                *(number + j) ^= *(number + j + 1);
            }
        }
    }
}
//声明的函数和变量都要以冒号结尾
   /*代码部分*/
#endif