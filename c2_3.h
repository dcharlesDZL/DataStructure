#if !defined(C2_3_H)
#define C2_3_H
#include <stdio.h>
#include "Status.h"
typedef int Element;
//单向链表
typedef struct LNode
{
    Element data;
    struct LNode *next;  //LNode 前必须加struct关键字
}ListNode,*LinkList;
//初始化链表
void InitList(LinkList *L)
{
    L = (LinkList)malloc(sizeof(ListNode));
    if(!L) exit(OVERFLOW);
    (*L)->next = NULL;
}
//销毁链表
void DestroyList(LinkList L)
{
    LinkList p;
    while(L)
    {
        p = L->next;
        free(L);
        L = p;
    }    
}
//清空链表
void ClearList(LinkList L)
{
    LinkList p = L->next;
    L->next = NULL;
    DestroyList(p);
}
//判断是否为空链表
Status EmptyList(LinkList L)
{
    if(L->next)
        return FALSE;
    else
        return TRUE;
}
//查询链表长度
int ListLength(LinkList L)
{
    int i = 0;
    LinkList p = L->next;
    while(p)
    {
        i++;
        p = p->next;
    }
    return i;
}
//获取链表元素
Status GetElem(LinkList *L, int i, Element *e)
{
    LinkList p = (*L)->next;
    while(p && i>=0)
    {
        p = p->next;
        i--;
    }
    if(!p || i<0) return ERROR;
    e = p->data;
    return OK;
}
//返回链表索引，查找元素位置
int LocateElem(LinkList L, Element e, Status(*compare)(Element, Element))
{
    int i = 0;
    while (L->next)
    {
        if(compare(e, L->data)) return i;
        i++;
        L = L->next;
    }
    return 0;
}
//下一个元素
Status NextElem(LinkList L, Element cur_e, Element *next_e)
{
    LinkList p = L->next;
    while(p)
    {
        if(cur_e == p->data)
        {
            next_e = p->next->data;
            return OK;
        };
        p = p->next;
    }
    return ERROR;
}
//前一个元素
Status PriorElem(LinkList L, Element cur_e, Element *prior_e)
{
    //p为游标，q暂存前一个元素 
    LinkList p = L->next, q = L;
    while(p)
    {
        if(cur_e == p->data)
        {
            prior_e = q->data;
            return OK;
        }        
        q = p;
        p = p->next;
    }
    return ERROR;
}
//链表插入元素
Status ListInsesrt(LinkList L, int i, Element e)
{
    
    int j = 0;
    LinkList I, p = L;
    while (p && j<i-1)
    {
        j++;
        p = p->next;
        if(j<1 || !p)
        {
            return ERROR;
        }
        I = (LinkList)malloc(sizeof(ListNode));
        I->data = e;
        I->next = p->next;
        p->next = I;
        return OK;
    }
}
//链表删除元素
Status ListDelete(LinkList L, int i, Element *e)
{
    LinkList q = NULL, p = L;
    int j = 1;
    if(p && i>1)
    {
        while(j<i && p)
        {
            q->next = p->next;
            j++;
            p = p->next;
        }
        e = q->data;
        free(p);
        return OK;        
    }
    return ERROR;
}
//对每一个元素调用visit函数
void ListTraverse(LinkList L, void(*visit)(Element))
{
    LinkList p = L;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }    
}

#endif //C2_3_H


/* 
typedef struct name1{}name2;
name1 为结构体类型名称 等价于 struct name1，name2为name1别名。
struct name3{}name4;
name3 为结构体名，name4为结构体变量名，当未使用typedef 关键字定义struct时，创建结构体变量前面必须有struct 关键字。
*/