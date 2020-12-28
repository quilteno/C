#ifndef _SORT_H_
#define _SORT_H_
#define ArrLen 100000
//#ifndef后面写头文件名的大写。例如test.h，——>_TEST_H_
/*排序头文件，提供多种数组排序*/
void swap(int *swap_a, int *swap_b);
int bubbleSort(int *bubble_a, int n);
void choiceSort(int *choice_a, int n);
void merge(int arr[], int start, int mid, int end);
void mergeSort(int arr[], int start, int end);
void HeapSort(int a[], int n);
void HeapAdjust(int a[], int s, int m);

//冒泡排序
int bubbleSort(int *bubble_a, int bubble_n)
{
    int flag = 0;
    for (int i = 0; i < bubble_n; i++)
    {
        for (int j = 0; j < bubble_n - i - 1; j++)
        {
            if (*(bubble_a + j) > *(bubble_a + j + 1))
            {
                swap(bubble_a + j, bubble_a + j + 1); //地址一定要确认好，不要忘加j和j+1
                flag = 1;                             //若出现交换，则继续进行
            }
        }
        if (flag == 0)
        { //如果没有交换，说明已经交换完成，退出函数
            return 0;
        }
    }
    return 1;
}
//声明的函数和变量都要以冒号结尾
void swap(int *swap_a, int *swap_b)
{
    *swap_a ^= *swap_b;
    *swap_b ^= *swap_a;
    *swap_a ^= *swap_b;
    /*异或位运算交换两值*/
}

//选择排序法
void choiceSort(int *choice_a, int choice_n)
{
    int temp = 0;
    int c;
    for (int i = 0; i < choice_n - 1; i++)
    {
        temp = *(choice_a + i);
        c = 0;
        for (int j = i + 1; j < choice_n; j++)
        {
            if (temp > *(choice_a + j))
            {
                temp = *(choice_a + j);
                c = j;
            }
        }
        if (c != 0)
        {

            *(choice_a + c) = *(choice_a + i);
            *(choice_a + i) = temp;
        }
    }
}
//归并排序法
void merge(int arr[], int start, int mid, int end)
{
    int result[ArrLen];
    int k = 0;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            result[k++] = arr[i++];
        }
        else
        {
            result[k++] = arr[j++];
        }
    }
    if (i == mid + 1)
    {
        while (j <= end)
            result[k++] = arr[j++];
    }
    if (j == end + 1)
    {
        while (i <= mid)
            result[k++] = arr[i++];
    }
    for (j = 0, i = start; j < k; i++, j++)
    {
        arr[i] = result[j];
    }
}
void mergeSort(int arr[], int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
//堆排序
void HeapAdjust(int a[],int s,int m)//一次筛选的过程
{
    int rc,j;
    rc=a[s];
    for(j=2*s;j<=m;j=j*2)//通过循环沿较大的孩子结点向下筛选
    {
        if(j<m&&a[j]<a[j+1]) j++;//j为较大的记录的下标
        if(rc>a[j]) break;
        a[s]=a[j];s=j;
    }
    a[s]=rc;//插入
}
void HeapSort(int a[],int n)
{
    int temp,i;
    for(i=n/2;i>0;i--)//通过循环初始化顶堆
    {
        HeapAdjust(a,i,n);
    }
    for(i=n;i>0;i--)
    {
        temp=a[1];
        a[1]=a[i];
        a[i]=temp;//将堆顶记录与未排序的最后一个记录交换
        HeapAdjust(a,1,i-1);//重新调整为顶堆
    }
}
#endif