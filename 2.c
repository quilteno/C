#include<stdio.h>                    

void f(int *p);                         
int main()                          
{                                    
    int a=3;                       
    a++;
    f(&a);
    a++;
    
    return 0;
}

void f(int *p){
    printf("a=%d\n",*p);
}
