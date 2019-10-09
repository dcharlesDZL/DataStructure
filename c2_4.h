/*
循环列表数据结构实现
循环链表与普通链表不同的一点在于其尾结点是指向首结点的，当操作链表时要考虑当前指针是否指向尾结点，即next指针是否指向头节点。
*/
#include "Status.h"
#include "stdio.h"
#include "stdlib.h"
#ifndef C2_4_H
#define C2_4_H
typedef int Element;
//定义循环列表节点结构体
typedef struct CLinkListNode
{
    Element data;
    CLinkListNode *next;
}CycleLinkListNode, *CycleLinkList;

//初始化循环链表
void InitCycleLinkList()
{
    CycleLinkList L;
    L = (CycleLinkList)malloc(sizeof(CycleLinkListNode));
    if (!L)
    {
        exit(OVERFLOW);
    }
    L->next = L;
}
//循环链表插入
void CycleLinkListInsert(CycleLinkList L, Element e)
{
    CycleLinkList p, I;
    p = L;
    I = (CycleLinkList)malloc(sizeof(CycleLinkListNode));
    I->next = p->next;
    p->next = I;
    if (p->next == L)
    {
        p->next = I;
        I->next = L;
    }
}
#endif