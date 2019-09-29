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

