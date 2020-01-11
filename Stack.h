#ifndef STD
#define STD
#include <stdio.h>
#include <stdlib.h>
#endif

#ifndef STACK_H
#define STACK_H
#define STACK_INIT_SIZE 50
#define STACK_INCEAMENT 2
typedef int StackElement;
typedef struct _Stack
{
    StackElement *top;  //栈顶
    StackElement *base; //栈基，即除栈顶之外的部分
    int stacksize;
} Stack;
Status InitStack(Stack *s);
Status Push(Stack *s, StackElement e);
StackElement Pop(Stack *s);
StackElement GetTop(Stack *s);

#endif