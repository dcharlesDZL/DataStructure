/*
该文件为栈数据结构的定义及操作声明
*/
#include "stdio.h"
#include "stdlib.h"
#include "Status.h"
#define STACK_INIT_SIZE 50
#define STACK_INCEAMENT 2
typedef int StackElement;
typedef struct _Stack
{
    StackElement *top;  //栈顶
    StackElement *base; //栈基，即除栈顶之外的部分
    int stacksize;
} Stack;
//初始化栈
Status InitStack(Stack *s)
{
    s->base = (StackElement *)malloc(STACK_INIT_SIZE * sizeof(StackElement));
    if (!s->base)
    {
        exit(OVERFLOW);
    }
    s->top = s->base;
    s->stacksize = STACK_INIT_SIZE;
    return OK;
}
//向栈中压入元素
Status Push(Stack *s, StackElement e)
{
    if (s->top - s->base >= s->stacksize)
    {
        s->base = (StackElement *)realloc(s->base, (s->stacksize + STACK_INCEAMENT) * sizeof(StackElement));
        if (!s->base)
        {
            exit(OVERFLOW);
        }
        s->top = s->base + s->stacksize;
        s->stacksize += STACK_INCEAMENT;
    }
    *(s->top) = e;
    s->top++;
    return OK;
}
// 出栈
StackElement Pop(Stack *s) //必须用指针接收数据，否则内部作用域非指针变量接收之后，外部变量不发生变化。
{
    StackElement e;
    if (!s || s->top == s->base)
    {
        printf("error:stack is empty!\n");
        return 0;
    }

    e = *(--s->top);
    return e;
}
// 获取栈顶元素
StackElement GetTop(Stack *s) // top总为待接收新的压栈元素状态。
{
    if (s->top == s->base)
    {
        printf("error!");
        exit(ERROR);
    }
    StackElement e;
    e = *(s->top - 1);
    return e;
}

int main()
{
    Stack a;
    printf("%d\n", *a.base);
    InitStack(&a);
    printf("%p\n", a.base);
    StackElement i = 12;
    StackElement j = 13;
    StackElement k = 14;
    Push(&a, i);
    Push(&a, j);
    Push(&a, k);
    StackElement e;
    e = GetTop(&a);
    printf("%d", e);
    printf("%d\n", Pop(&a));
    printf("%d\n", Pop(&a));
    printf("%d\n", Pop(&a));
    printf("%d\n", Pop(&a));
}