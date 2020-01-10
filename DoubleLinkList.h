/*
双向链表数据结构实现
*/
#include "Status.h"
#include "stdlib.h"
#include "stdio.h"
#ifndef C2_5_H
#define C2_5_H
typedef int Element;
typedef struct DLNode
{
    Element data;
    DoubleLinkListNode *next;
    DoubleLinkListNode *prior;
}DoubleLinkListNode, *DoubleLinkList;

//初始化双向链表
void InitDoubleLinkList(DoubleLinkList *L);
//双向链表长度
int DoubleLinkListLength(DoubleLinkList *L);
//向链表插入元素
Status DoubleLinkListInsert(DoubleLinkList L, int i, Element e);
//对链表删除元素
Status DoubleLinkListDelete(DoubleLinkList L, int i, Element *e);
//清空链表
void ClearDoubleLinkList(DoubleLinkList L);
//销毁链表
void DestroyDoubleLinkList(DoubleLinkList L);
//获取链表第i个结点，并将值返回e
Element GetDoubleLinkListElem(DoubleLinkList L, int i, Element *e);
//获取后一个结点
Element NextDouhleLinkListElem(DoubleLinkList L, Element cur_e, Element *next_e);
//获取前一个结点
Element PriorDoubleLinkListElem(DoubleLinkList L, Element cur_e, Element *prior_e);
//索引链表，索引返回i
int IndexDoubleLinkList(DoubleLinkList L, Element cur_e, int i);
//访问链表结点
void DoubleLinkListTraverse(DoubleLinkList L, void(*visit)(Element));

#endif
