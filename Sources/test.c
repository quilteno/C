#include <stdio.h>
#include <stdlib.h>

void insert(int a[], int n); //函数声明
int a[6] = {3, 6, 7, 2, 4, 5};

int main(int argc, const char **argv)
{
    insert(a, 4, 2);
    for (int i = 0; i < 6; i++)
    {
        printf("%d\n",a[i]);
    }
    
    return 0;
}

//函数
void insert(int a[], int m, int n)
{
    for (int i = m; i < m + n; i++)
    {
        int temp = a[i];
        for (int j = i - 1; j >= 0 && temp < a[j]; --j)
        {
            a[j + 1] = a[j];
        }
        a[i + 1] = temp;
    }
}