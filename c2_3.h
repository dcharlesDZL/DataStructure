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
Status GetLinklistElem(LinkList L, Element *e, int i);
Status LinklistInsert(LinkList *L, int i, Element e);
Status LinklistDelete(LinkList *L, int i, Element *e);
Status CreateLinklist(LinkList *L, int n);
Status MergeLinklist(LinkList *La, LinkList *Lb, LinkList *Lc);
//静态单链表

#endif //C2_3_H


/* 
typedef struct name1{}name2;
name1 为结构体类型名称 等价于 struct name1，name2为name1别名。
struct name3{}name4;
name3 为结构体名，name4为结构体变量名，当未使用typedef 关键字定义struct时，创建结构体变量前面必须有struct 关键字。
*/



