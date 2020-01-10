
#include <stdio.h>
#include <heapapi.h>
#include <stdlib.h>
#include "Status.h"
#include "Heap.h"
#define SWAP(a, b)  \
    {               \
        heaptype c; \
        c = a;      \
        a = b;      \
        b = c;      \
    }
//定义游标temp
struct Temp
{
    heaptype num;
    int index;
} temp;
void InitHeap(struct Heap *heap, int maxsize)
{
    heap->num = (heaptype *)calloc(maxsize, sizeof(heaptype));
    heap->heapsize = 0;
    heap->Maxsize = maxsize;
}
Bool isEmptyHeap(struct Heap *heap)
{
    if (heap->heapsize == 0)
        return TRUE;
    else
        return FALSE;
}
void ClearHeap(struct Heap *heap)
{
    if (heap->num != NULL)
    {
        heap->heapsize = 0;
    }
    else
        printf("Heap is NULL!");
}
void InsertHeap(struct Heap *heap, heaptype x)
{
    if (heap)
    {
        heap->num[heap->heapsize] = x;
        //
        temp.index = heap->heapsize;
        temp.num = x;
        while (temp.index != 0) //如果游标不为根节点则继续循环
        {
            if (temp.index % 2 == 1)
            {
                //大于父节点，交换
                if (temp.num > heap->num[(heap->heapsize - 1) / 2])
                {
                    SWAP(heap->num[temp.index], heap->num[(temp.index - 1) / 2]);
                    temp.index = (temp.index - 1) / 2; //对游标重新赋值
                }
            }
            else if (temp.index % 2 == 0)
            {
                //大于父节点，交换
                if (temp.num > heap->num[(heap->heapsize - 2) / 2])
                {
                    SWAP(heap->num[temp.index], heap->num[(temp.index - 2) / 2]);
                    temp.index = (temp.index - 2) / 2;
                }
            }
        }
        heap->heapsize++; //堆大小加1
    }
    else
        printf("Heap is not initialized!");
}

int main()
{
    struct Heap *aHeap;
    InitHeap(aHeap, 100);

    return 0;
}