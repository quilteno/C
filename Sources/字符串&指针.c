#include <stdio.h>
#include <string.h>

const int N = 5;

int main(int argc, const char **argv)
{
    char *c[N];
    char d[N][10];
    for (int i = 0; i < N; i++)
    {
        /* code */
        c[i] = d[i];//为指针数组指向地址
    }

    for (int i = 0; i < N; i++)
    {
            scanf("%s", c[i] );//读入字符串
    }

    for (int i = 0;i < N; i++)
    {
        for (int j = 0, n = strlen(d[i]); j < n; j++)//使用了一次strlen计算长度
        {
            /* code */
            printf("%c", *(c[i]+j));//说明地址是紧挨着的
        }
        printf("\n");
    }

    return 0;
}