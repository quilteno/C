#include <stdio.h>
#include <stdlib.h>

#define LINE 80
#define ROW 80

void initprint(int a[][ROW]); //函数声明
void go(int a[][ROW]);        //演化函数
void copy(int a[][ROW]);      //复制二维数组
int live(int line, int row);  //计算周围细胞数
void randm(int a[][ROW]);

int b[LINE][ROW] = {0};//定义全局变量b,

int main(int argc, const char **argv)
{
    int a[LINE][ROW] = {0};   //初始化变量a
    a[1][2] = a[2][3] = a[3][1] = a[3][2] = a[3][3] = 1;
    //初始化细胞
    randm(a);
    while (1==1)
    {
        copy(a);
        system("cls");
        initprint(a);
        go(a);
    }

    return 0;
}

//函数
void initprint(int a[][ROW])
{
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            if (a[i][j] == 0)
            {
                printf(" "); //如果值为0则打印空白
            }
            else
            {
                printf("O");
            }
        }
        printf("\n");
    }
}

void go(int matrix[][ROW])
{
    for (int i = 1; i < LINE - 1; i++)
    {
        for (int j = 1; j < ROW - 1; j++)
        {
            int c = live(i, j);
            if (c == 3) //如果周围细胞数为3,则变为存活
            {
                matrix[i][j] = 1;
            }
            else if (c == 2) //如果周围细胞数为2,则不变
            {
            }
            else
            {
                matrix[i][j] = 0; //其他情况细胞死亡
            }
        }
    }
}

int live(int line, int row)
{
    int count = 0;
    for (int i = line - 1; i < line + 2; i++)
    {
        for (int j = row - 1; j < row + 2; j++)
        {
            if (i == line && j == row)
            {
            }
            else
            {
                count += b[i][j]; //计算周围细胞数,不包括自己
            }
        }
    }

    return count;
}

void copy(int new[][ROW])
{
    for (int i = 0; i < LINE; i++)
    {
        for (int j = 0; j < ROW; j++)
        {
            b[i][j] = new[i][j];
        }
    }
}

void randm(int a[][ROW]){
    for (int i = 1; i < LINE-1; i++)
    {
        for (int j = 1; j < ROW-1; j++)
        {
            a[i][j] = (rand() % 2);
        }
        
    }
    
}
