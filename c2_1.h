#ifndef C2_1_H
#define C2_1_H

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

#ifndef LISTTYPE
#define LISTTYPE
//typedef int ListType;
typedef int Element;
#endif
//typedef int Data;
typedef struct 
{
    Element *element;
    int currentlength;
    int listlength;
}List;

//初始化列表
Status InitList(List *L);
//销毁列表
Status DestroyList(List *L);
//清空列表
Status ClearList(List *L);
//判断列表是否为空
Status ListEmpty(List L);
//列表长度
int ListLength(List L);
//获取元素
int GetElem(List L, int i, Element *e);
//返回第一个与e满足compare关系的元素
Element LocateElem(List L, Element e,Status (compare)(Element, Element));
//返回前驱元素
Element PriorElem(List L, Element cur_e, Element *pre_e);
//返回后继元素
Element NextElem(List L, Element cur_e, Element *next_e);
//插入元素
Status ListInsert(List *L, int i, Element e);
//删除元素
Element ListDelete(List *L, int i, Element *e);
//便利所有元素
Status ListTraverse(List L, Status (visit)(Element));

#endif





