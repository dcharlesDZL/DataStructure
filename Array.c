#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Status.h"

typedef int ArrayElem;
typedef int Dimension;
typedef int ArrayLen;
//typedef int ArrayWidth;
typedef struct _Array
{
    Dimension x;
    ArrayLen y;
    ArrayElem *arr;
} Array;

/*=====*/
ArrayElem a[10] = {1, 2, 3, 4, 5, 6, 23, 1};
// Array2 aa[2][10];
/*=====*/
//基本操作
//初始化数组
Array InitArray(Dimension n, ArrayLen m)
{
    Array Arr;
    if (n == 0 || m == 0)
    {
        exit(ERROR);
    }
    ArrayElem *arr = (ArrayElem *)calloc(n * m, sizeof(ArrayElem));
    if (!arr)
    {
        exit(OVERFLOW);
    }
    Arr.arr = *arr;
    Arr.x = n;
    Arr.y = m;
    return Arr;
}
//销毁数组
Status DestroyArray(ArrayElem *arr)
{
    free(arr);
    if (!arr)
    {
        return OK;
    }
}
//取值
ArrayElem Value(Array arr, Dimension m, ArrayLen n, ArrayElem e)
{
    if (!arr.arr || arr.x == 0 || arr.y == 0)
    {
        printf("Array is ERROR");
        exit(ERROR);
    }
    if (m >= arr.x || n >= arr.y)
    {
        exit(ERROR);
    }
    ArrayElem *temp = arr.arr;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < arr.y; j++)
        {
            temp += 1;
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        temp += 1;
    }
    e = *temp;
}
//赋值
void Assign();

int main()
{
    // printf("%d", aa[1][8]);
    InitArray(3, 2);
    return 0;
}
