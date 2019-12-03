#include "Status.h"
#define MAXSTRLEN 16
//串的堆分配
typedef struct{
    char *ch;
    int length;
}HString;

//初始化串
void InitHString();
