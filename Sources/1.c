#include <stdio.h>

float scf();

int main(int argc, const char **argv)
{

    printf("%10.2f.", scf());

    return 0;
}

float scf(){
    float a;
    scanf("%f",&a);

    return a;
}