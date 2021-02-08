#include <iostream>
#include <stdlib.h>
#define maxSize 100
using namespace std;
typedef struct LNode //
{
    int date;
    struct LNode *next; //
} LNode;

void creatlistR(LNode *&C, int a[], int n); //
void creatlistF(LNode *&C, int a[], int n); //
void merge(LNode *A, LNode *B, LNode *&C);  //
void display(LNode *C, int length);         //

int main(int argc, const char **argv)
{
    int number[maxSize] = {0};
    for (int i = 0; i < 100; i++) //
    {
        number[i] = (rand() % 100);
    }
    LNode *L;
    creatlistR(L, number, maxSize);
    creatlistF(L, number, maxSize);
    display(L, maxSize); //

    system("pause"); //
    return 0;
}

void creatlistR(LNode *&C, int a[], int n) //
{
    LNode *s, *r; //
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    for (int i = 0; i < n; i++) //
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->date = a[i];
        r->next = s; //
        r = r->next; //
    }
    r->next = NULL; //
}

void creatlistF(LNode *&C3, int a[], int n) //
{
    LNode *s;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->date = a[i];
        /**/
        s->next = C->next; //
        C->next = s;       //
    }
}

void display(LNode *C, int length) //
{
    LNode *r;
    r = C->next; //
    for (int i = 0; i < length; i++)
    {
        printf("%d\n", r->date);
        r = r->next; //
    }
}

void merge(LNode *A, LNode *B, LNode *&C) //
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *s;
    C = A;
    C->next = NULL;
    free(B);
    while (p != NULL && q != NULL)
    {
        if (p->date <= q->date)
        {
            s = p;
            p = p->next;
            s->next = C->next;
            C->next = s;
        }
        else
        {
            s = q;
            q = q->next;
            s->next = C->next;
            C->next = s;
        }
    }
    /**/
    while (p!=NULL)
    {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    while (q!=NULL)
    {
        s = q;
        p = q->next;
        s->next = C->next;
        C->next = s;
    }
}