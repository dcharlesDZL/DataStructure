#ifndef C2_1_C
#define C2_1_C
#include "c2_1.h"
//初始化列表
Status InitList(List *L)
{
    (*L).element = (Element * ) malloc(INIT_LIST_LENGTH*sizeof(Element));
    if (!(*L).element) exit(OVERFLOW);
    (*L).listlength = INIT_LIST_LENGTH;
    (*L).currentlength = 0;
    return OK;
}
Status DestroyList(List *L)
{
    free((*L).element);
    (*L).currentlength = 0;
    (*L).listlength = 0;
}
Status ClearList(List *L)
{
    (*L).currentlength = 0;
}
Status ListEmpty(List L)
{
    if (L.currentlength == 0)
    {
        printf("list is empty!");
        return TRUE;        
    }
    else
    {
        printf("list is not empty!");
        return FALSE;      
    }
}

Status ListLength(List L)
{
    return L.currentlength;
}
Status GetElem(List L, int i, Element *e)
{
    if (i<1 || i>L.currentlength)
    return ERROR;
    else
    *e = L.element[i-1];
    return OK;
}
Status compare(Element i, Element j)
{
    if (i == j){return OK;}
    else{return ERROR;}
}
int LocateElem(List L, Element e, Status compare())
{
    int i = 1;
    for (i;i<L.currentlength;i++)
    {
        if (compare(L.element[i], e))
        return i;
        else
        {
            printf("the list is not exist the element: ", e);
        }
        
    }
}
Status PriorElem(List L, Element cur_e, Element *pre_e)
{
    int i = 1;
    //首元素无前驱
    if (L.element[0] == cur_e)
    {return ERROR;}
    else 
    {
        while(i < L.currentlength)
        {
            if (cur_e == L.element[i])
            {
                *pre_e = L.element[i-1];
                return OK;
            }
            else i++;
        }

    }
}
Status NextElem(List L, Element cur_e, Element *next_e)
{
    int i = 1;
    //最后一个元素没有后继
    if (cur_e == L.element[L.currentlength - 1])
    {
        return ERROR;
    }
    else
    {
        while(i < L.currentlength)
        {
            if (cur_e == L.element[i])
            {
                next_e = L.element[i+1];
                return OK;
            }
            else i++;            
        }
    }
}
Status ListInsert(List *L, int i, Element e)
{
    //首先判断i值是否合法

    //判断存储空间是否已满，若空间已满，则开辟新的空间

    //定义插入位置，并将Element e插入

}




#endif

int main()
{
    List m;
    InitList(&m);
    ListEmpty(m);
    DestroyList(&m);
    ListEmpty(m);
    return 0;
}

