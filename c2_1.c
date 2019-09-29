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
int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,10};
    List *m;
    InitList(m);
    return 0;
}

