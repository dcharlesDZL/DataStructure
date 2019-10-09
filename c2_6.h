/*
该文件为栈数据结构的定义及操作声明
*/
#include "stdio.h"
#include "stdlib.h"
#include "Status.h"
#ifndef C2_6_H
#define C2_6_H
#define STACK_INIT_SIZE 50
#define STACK_INCEAMENT 2
typedef int Element;
typedef struct Stack
{
    Element *top;//栈顶
    Element *base;//栈基，即除栈顶之外的部分
    int stacksize;
};
//初始化栈
void InitStack(Stack S);
//向栈中压入元素
void Push(Stack *S, Element e);



#endif