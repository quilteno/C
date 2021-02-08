#include <iostream>
#include <stdlib.h>
#define maxSize 6
using namespace std;
typedef struct LNode //
{
    int data;
    struct LNode *next; //
} LNode;

void creatlistR(LNode *&C, int a[], int n);//
void creatlistF(LNode *&C, int a[], int n);//
void display(LNode *C, int length); //

int main(int argc, const char **argv)
{
    int number[maxSize] = {0};
    for (int i = 0; i < 100; i++) //
    {
        number[i] = (rand()%100);
    }
    LNode *L;
    int a = 1;
    int *q = &a;
    creatlistR(L, number, maxSize);
    LNode *p = L->next;
    // printf("L->data= %d\n", L->data); //
    printf("p->date %d\n", p->data);
    printf("p->next->data %d\n", p->next->data);
    printf("链表L:");
    display(L, maxSize);  //
    
    system("pause");    //
    return 0;
}

void creatlistR(LNode *&C, int a[], int n) //
{
    LNode *s, *r;         
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    for (int i = 0; i < n;i++)     
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;         
        r = r->next;         
    }
    r->next = NULL;          
}

void creatlistF(LNode *&C, int a[],int n) //
{
    LNode *s;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        /*头插法关键步骤*/
        s->next = C->next;
        C->next = s;      
    }
}

void display(LNode *C, int length) 
{
    LNode *r;
    r = C->next;           
    for (int i = 0; i < length; i++)
    {
        printf("%4d ", r->data);
        r = r->next;         
    }
    printf("\n");
}