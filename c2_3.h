#if !defined(C2_3_H)
#define C2_3_H
#include <stdio.h>
#include "Status.h"
typedef int Element;
#define MAXSIZE 1000
//单向链表
typedef struct LNode
{
    Element data;
    struct LNode *next;  //LNode 前必须加struct关键字
}ListNode,*LinkList;
// Status GetLinklistElem(LinkList L, Element *e, int i);
// Status LinklistInsert(LinkList *L, int i, Element e);
// Status LinklistDelete(LinkList *L, int i, Element *e);
// Status CreateLinklist(LinkList *L, int n);
// Status MergeLinklist(LinkList *La, LinkList *Lb, LinkList *Lc);
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
    }
    return ERROR;    
}
//静态单链表
// typedef struct 
// {
//     Element data;
//     int cur;
// }component, StaticLinklist[MAXSIZE];


#endif //C2_3_H


/* 
typedef struct name1{}name2;
name1 为结构体类型名称 等价于 struct name1，name2为name1别名。
struct name3{}name4;
name3 为结构体名，name4为结构体变量名，当未使用typedef 关键字定义struct时，创建结构体变量前面必须有struct 关键字。
*/



