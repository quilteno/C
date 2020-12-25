#include <stdio.h>

int main(int argc, const char **argv)
{
    int num;
    FILE *fp = fopen("1.in", "r");
    if (fp)
    {
        fscanf(fp, "%d", &num);
        printf("%d\n", num);
        fclose(fp);
    }
    else{
        printf("打不开文件");
    }

    return 0;
}