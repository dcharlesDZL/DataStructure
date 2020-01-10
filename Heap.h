typedef int heaptype;
struct Heap
{
    heaptype *num;
    int heapsize;
    int Maxsize;
};
/*********************/
//初始化堆
void InitHeap(struct Heap *heap, int maxsize);
//清除堆
void ClearHeap(struct Heap *heap);
//检查堆是否为空
Bool isEmptyHeap(struct Heap *heap);
//向堆插入元素
void InsertHeap(struct Heap *heap, heaptype x);
