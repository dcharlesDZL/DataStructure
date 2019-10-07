#include"stdio.h"
int main()
{
    int i = 10;
    while(1)
    {
        if (i>0) 
        {
            i--;
            return i;
        }
    }
    return -1;
}