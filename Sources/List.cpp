#include <iostream>
#include <stdlib.h>
#define maxSize 5
using namespace std;
typedef struct LNode //单链表结点
{
    int date;
    struct LNode *next; //指向后继结点指针
} LNode;

void creatlistR(LNode *&C, int a[], int n); //尾插�?
void creatlistF(LNode *&C, int a[], int n); //头插�?
void merge(LNode *A, LNode *B, LNode *&C);  //归并
void display(LNode *C, int length);         //打印单链表
void reverse(LNode)

int main(int argc, const char **argv)
{
    int number[maxSize] = {1,3,5,7,9};
    int number2[maxSize] = {0,2,4,6,8};
    for (int i = 0; i < maxSize; i++) //设置一�?0�?100的数�?
    {
        // number[i] = (rand() % maxSize);
        // number[i] = (i+5)%10;
    }
    LNode *L1;
    LNode *L2;
    LNode *L3;
    creatlistR(L1, number, maxSize);
    creatlistR(L2, number2, maxSize);
    display(L1, maxSize); //打印链表
    display(L2, maxSize); //打印链表
    merge(L1, L2, L3);
    display(L3, 2*maxSize); //打印链表

    system("pause"); //运完完成后保持窗口
    return 0;
}

void creatlistR(LNode *&C, int a[], int n) //尾插法
{
    LNode *s, *r; //s指向新的结点,r指向终结点
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    r = C;
    for (int i = 0; i < n; i++) //接受结点的值
    {
        s = (LNode *)malloc(sizeof(LNode)); //开辟内存空间
        s->date = a[i];
        r->next = s; //r来接纳新结点
        r = r->next; //r指向终结点
    }
    r->next = NULL; //针域为NULL
}

void creatlistF(LNode *&C, int a[], int n) //头插法
{
    LNode *s;
    C = (LNode *)malloc(sizeof(LNode *));
    C->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->date = a[i];
        /*下面两个关键步*/
        s->next = C->next; //s所指新结点指针域指向C开始结
        C->next = s;       //头结点的指针域指向s结点,使s称为新结�?
    }
}

void display(LNode *C, int length) //打印链表
{
    LNode *r;
    r = C->next; //定位指针
    for (int i = 0; i < length; i++)
    {
        if (i % 10 == 0 && i != 0)
        {
            printf("\n");
        }
        printf("%02d ", r->date);
        r = r->next; //打印后进入下一结点
    }
    printf("\n");
}

void merge(LNode *A, LNode *B, LNode *&C) //采用头插法归并,为递减序列
{
    LNode *p = A->next;
    LNode *q = B->next;
    LNode *s;
    C = A;
    C->next = NULL;
    //free(B);
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
    /*插完一列表后,还得将另一用头插法逐个插入C的头结点*/
    while (p != NULL)
    {
        s = p;
        p = p->next;
        s->next = C->next;
        C->next = s;
    }
    while (q != NULL)
    {
        s = q;
        q = q->next;
        s->next = C->next;
        C->next = s;
    }
}