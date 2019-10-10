/*
该文件为双向链表的操作实现
*/
#include "c2_5.h"
void InitDoubleLinkList(DoubleLinkList *L)
{
    L = (DoubleLinkList)malloc(sizeof(DoubleLinkListNode));
    if(L)
    {
        (*L)->next = (*L)->prior = L;
    }
    else 
    {
        exit(OVERFLOW);
    }
}
int DoubleLinkListLength(DoubleLinkList *L)
{
    int i = 0;
    DoubleLinkList p = L;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}
//双向链表因其包含前后两个结点，所以插入操作要对四个指向进行赋值。
Status DoubleLinkListInsert(DoubleLinkList L, int i, Element e)
{
    DoubleLinkList p = L, I;
    int j = 1;
    if((i>1) && i<DoubleLinkListLength(&L))
    {
        while (p && j<i)
        {
            p = p->next;
            j++;
        }
        I = (DoubleLinkList)malloc(sizeof(DoubleLinkListNode));
        I->data = e;
        I->prior = p;
        I->next = p->next;
        p->next->prior = I;
        p->next = I;
        return OK;
    }
    return ERROR;
}
Status DoubleLinkListDelete(DoubleLinkList L, int i, Element *e)
{
    DoubleLinkList p = L;
    int j = 1;
    if((i>1) && (i<DoubleLinkListLength(&L)))
    {
        while (p && j<i)
        {
            p = p->next;
            j++;
        }
        e = p->data;
        p->prior = p->next;
        p->next->prior = p->prior;
        return OK;
    }
    return ERROR;
}