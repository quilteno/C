#define maxSize 100

typedef struct  //不常用
{
    int data[maxSize];  //存放元素数组
    int length; //顺序表长度
} Sqlist;

int A[maxSize];  //常用
int n;

typedef struct LNode
{
    int data;//数据域
    struct LNode *next;//后继结点指针
} LNode;  //定义结点类型

typedef struct DLNode
{
    int data;
    struct DLNode *prior;
    struct DLNode *next;
} DLNode;
/*分配结点*/
LNode *A = (LNode)malloc(sizeof(LNode));