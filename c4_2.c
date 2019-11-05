#include "c4_2.h"
#include <heapapi.h>
#include <stdlib.h>


void InitHeap(struct Heap* heap, int maxsize)
{
    heap->num = (heaptype*)calloc(maxsize, sizeof(heaptype));
    heap->heapsize = 0;
    heap->Maxsize = maxsize;
}
Bool isEmptyHeap(struct Heap* heap)
{
    if(heap->heapsize == 0) return TRUE;
    else return FALSE;
}
void ClearHeap(struct Heap* heap)
{
    if(heap->num != NULL)
    {
        heap->heapsize = 0;
    }
    else printf("Heap is NULL!");
}
void InsertHeap(struct Heap* heap, heaptype x)
{
    if(heap->heapsize != 0)
    {
        heap->num[heap->heapsize] = x;
        if(heap->heapsize%2 == 1)
        {
            //if(heap->num[heap->heapsize] > heap->num[(heap->heapsize-1)/2 ])
        }
    }
}
int main()
{
    struct Heap* aHeap;
    InitHeap(aHeap, 100);

    return 0;
}