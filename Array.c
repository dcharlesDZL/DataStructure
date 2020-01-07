/* 
定义了二维数组结构体，
利用线性空间实现二维数组。
*/

#include <stdio.h>
#include <stdlib.h>
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

//基本操作
//初始化数组
Array InitArray(Dimension n, ArrayLen m)
{
    Array Arr;
    if (n == 0 || m == 0)
    {
        exit(ERROR);
    }
    Arr.arr = (ArrayElem *)calloc(n * m, sizeof(ArrayElem));
    if (!Arr.arr)
    {
        exit(OVERFLOW);
    }
    Arr.x = n;
    Arr.y = m;
    return Arr;
}
//销毁数组
Status DestroyArray(Array *arr)
{
    free(arr->arr);
    arr->x = 0;
    arr->y = 0;
    if (!arr->arr)
    {
        printf("ok");
    }
}
//取值
ArrayElem Value(Array arr, Dimension m, ArrayLen n)
{
    if (!arr.arr || arr.x == 0 || arr.y == 0)
    {
        printf("Array is ERROR");
        exit(ERROR);
    }
    if (m >= arr.x || n >= arr.y)
    {
        printf("over dimension!");
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
    ArrayElem e = *temp;
    return e;
}
//赋值
Status Assign(Array arr, Dimension m, ArrayLen n, ArrayElem e)
{
    if (!arr.arr || arr.x == 0 || arr.y == 0)
    {
        printf("Array is ERROR");
        exit(ERROR);
    }
    if (m >= arr.x || n >= arr.y)
    {
        printf("over dimension!");
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
    *temp = e;
    return OK;
}
//测试
int main()
{
    Array test;
    test = InitArray(3, 2);
    if (!test.arr)
    {
        printf("asdf");
    }
    printf("%d, %d\n", test.x, test.y);
    ArrayElem a;
    a = Value(test, 0, 1);
    printf("%d\n", a);
    Assign(test, 0, 0, 12);
    a = Value(test, 0, 0);
    printf("%d\n", a);
    DestroyArray(&test);
}
