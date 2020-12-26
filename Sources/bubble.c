#include <stdio.h>
//头文件
int bubble(int *number, int n);
int main(int argc, const char **argv)
{
    // int *number;
    int n;
    int r;
    printf("type how much numbers\n"); //输入多少个数
    scanf("%d", &n);
    int a[n];
    char c[n + 1]; //末尾通常为'\0'故要增加1
    scanf("%s", c);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int)c[i] - 48; //用字符法一次将字符录入
    }

    // number = &a[0];
    r = bubble(&a[0], n);  //向函数输入地址值，在函数内操作地址进行运算
    printf("返回值=%d\n",r); //测试返回值

    return 0;
} //主函数

int bubble(int *number, int n)
{
    int flag = 0;  //定义状态
    int count = 0; //添加计数器
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (*(number + j) > *(number + j + 1)) //采用三次取异或法交换两值
            {
                *(number + j) ^= *(number + j + 1);
                *(number + j + 1) ^= *(number + j);
                *(number + j) ^= *(number + j + 1);
                flag = 1; //若出现交换，则继续进行
                count++;
            }
        }
        if (flag == 0)
        {
            printf("比较整齐\n整理之后为:\n"); //若没有交换，则退出函数
            for (int i = 0; i < n; i++)
            {
                printf("%d\n", *(number + i)); //打印整理之后的值
            }
            printf("count=%d\n", count);
            return 1;
        }
    }
    printf("有点乱\n整理之后为:\n"); //若没有交换，则退出函数
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", *(number + i)); //打印整理之后的值
    }
    printf("共便利了%d次\n", count); //打印计数
    return 2;
}