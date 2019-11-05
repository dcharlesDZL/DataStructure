#include <stdio.h>
typedef int heaptype;
#define HEAPMAXSIZE 100;
typedef struct MaxHeap
{
    heaptype* heap;
    int heapsize;
    int Maxsize;
};
/*********************/
//初始化堆
void InitHeap(MaxHeap* heap, int maxsize);
//清除堆
void ClearHeap(MaxHeap* heap);
//检查堆是否为空
void isEmptyHeap(MaxHeap* heap);
//向堆插入元素
void InsertHeap(MaxHeap* heap, heaptype x);

