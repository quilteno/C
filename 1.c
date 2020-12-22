#include <stdio.h>
/*头文件*/
void f(int *p); 
//定义函数
int main()
{
    int a = 4;      
    a++;
    f(&a);
    return 0;
}

void f(int *p)
{
    printf("a=%d\n", *p);
}
