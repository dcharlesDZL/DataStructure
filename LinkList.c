#include"stdio.h"
#include"stdlib.h"
typedef struct _LinkList
{
	int val;
	struct _LinkList* next;
}LNode, *LinkList;
int main()
{
//创建链表
	LNode* header = NULL, *end = NULL, *node = NULL;
	for (int i = 0; i < 10; i++) {
		node = (LNode*)malloc(sizeof(LNode));
		if (node != NULL) {
			node->val = i;
			node->next = NULL;
			if (header == NULL) {
				header = node;
				end = node;
			}
			else {
				end->next = node;
				end = node;
			}
		}
	}
//显示链表
	LNode* temp;
	temp = header;

	while (temp) {
		printf("linknode is :%d \n", temp->val);
		temp = temp->next;
	}
}