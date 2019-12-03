#include "c4_2_2.h"
#include "stdlib.h"
void InitHString(HString *h){
	if (!h) exit(OVERFLOW);
	h->length = MAXSTRLEN;
	h->ch = (HString*)malloc(h->length);
}