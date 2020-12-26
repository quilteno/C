#include <stdio.h>
#include <string.h>
//头文件

int mian(int argc, const char **argv)
{
    char c[4][10] = {
        "贾荣凯\0",
        "兰一凡\0",
        "毛小松\0",
        "李俊伟\0"};

    for (int i = 0; i < 4; i++)
    {
        if (strcmp("毛小松", c[i]))
        {
            printf("Found\n");
            return 0;
        }
    }
    return 1;
} //主函数