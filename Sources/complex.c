#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct complex
{
    float real;
    float imaging;
}complex;

void sum(struct complex *complex_a,struct complex *complex_b);//函数声明
float mode(struct complex *complex_a);

int main(int argc,const char **argv)
{
    struct complex a,b;
    a.real = 5;a.imaging = 2;b.real = 3;b.imaging = 4;
    scanf("%f+%fi", &a.real, &a.imaging);
    scanf("%f+%fi", &a.real, &a.imaging);
    sum(&a, &b);
    printf("|b| = %f", mode(&b));
    return 0;
}

//函数
void sum(struct complex *a,struct complex *b)
{
    a->real += b->real;
    a->imaging += b->imaging;
    printf("a = %f + %fi\n", a->real, a->imaging);
}

float mode(struct complex *complex_a)
{
    float m = pow(pow(complex_a->real, 2) + pow(complex_a->imaging, 2), 0.5);

    return m;
}