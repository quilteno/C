#include <stdio.h>
#include <bubble.h>
//头文件
int main(int argc, const char **argv)
{
    // int *number;
    int n;
    printf("type how much numbers\n");
    scanf("%d", &n);
    int a[n];
    char c[n+1];
    scanf("%s", c);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int)c[i]-48;
    }
    
    // number = &a[0];
    bubble(&a[0], n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }

    return 0;
} //主函数
