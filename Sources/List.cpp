#include <iostream>
#include <stdlib.h>
#define maxSize 6
using namespace std;
typedef struct LNode //
{
    int data;
    struct LNode *next; //
} LNode;
typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;

void creatlistR(LNode *&C, int a[], int n);   //尾插法
void creatlistF(LNode *&C, int a[], int n);   //头插法
void creatDlistR(DLNode *&C, int a[], int n); //双链表尾插法
void display(LNode *C, int length);           //打印链表
void mergeF(LNode *A, LNode *B, LNode *C);    //头插法归并

int main(int argc, const char **argv)
{
    LNode *L;
    int a[maxSize] = {2, 4, 5, 7, 9, 0};
    creatlistF(LNode * L, int a[], int maxSize);
    
    system("pause");
    return 0;
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
void creatlistR(LNode *&C, int a[], int n) //尾插法
{
    LNode *s, *r;                       //s指向新申请的结点,r指向C的终端结点
    C = (LNode *)malloc(sizeof(LNode)); //申请C的头结点空间
    C->next = NULL;
    r = C; //
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i]; //接纳a中元素
        r->next = s;    //r接纳新结点
        r = r->next;    //r指向终端结点,以便接纳下一个
    }
    r->next = NULL; //C终端结点指针域置为NULL
}
void creatlistF(LNode *&C, int a[], int n) //头插法
{
    LNode *s;
    C = (LNode *)malloc(sizeof(LNode));
    C->next = NULL;
    for (int i = 0; i < n; i++)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        /*头插法关键步骤*/
        s->next = C->next; //s的指针域指向C的开始结点
        C->next = s;       //头结点的指针指向s结点,s成为了新的开始结点
    }
}
void mergeR(LNode *A, LNode *B, LNode *C) //尾插法归并,C递增
{
    LNode *p = A->next; //p跟踪A的最小值
    LNode *q = B->next; //q跟踪B的最小值
    LNode *r;           //r始终指向终端结点
    C = A;
    C->next = NULL;
    free(B);
    r = C;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data) //如果p的数据域较小,则将p插入尾部
        {
            r->next = p; //此时实际操作为将p所指结点接到C后面,r为指向C的指针
            p = p->next; //p后移
            r = r->next; //r后移
        }
        else
        {
            r->next = q; //此时实际操作为将q所指结点接到C后面,r为指向C的指针
            q = q->next; //q后移
            r = r->next; //r后移
        }
    }
    r->next = NULL;
    if (p != NULL)
        r->next = p; //此时实际操作为,r=C=A所指的那一块内存的指针域指向p所指的结点
    if (q != NULL)
        r->next = q; //同上
}
void creatDlistR(DLNode *&L, int a[], int n) //双链表尾插法
{
    DLNode *s, *r;
    L = (DLNode *)malloc(sizeof(DLNode));
    L->prior = NULL;
    L->next = NULL;
    r = L; //r指向终端结点
    for (int i = 0; i < n; i++)
    {
        s = (DLNode *)malloc(sizeof(DLNode));
        s->data = a[i];
        r->next = s;
        s->prior = r;
        r = s;
    }
    r->next = NULL;
}