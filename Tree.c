#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

typedef int TreeElem;
typedef struct _TreeNode
{
	TreeElem val;
	struct TreeNode* parent;
	struct TreeNode* child;
} TreeNode, * Tree;
// typedef struct _BiTreeNode
// {
//     TreeElem val;
//     struct BiTreeNode *lchild, *rchild;
// } BiTreeNode, *BiTree;
// 初始化树
Tree* InitTree()
{
	Tree* t;
	t = NULL;
	return t;
}

Status DestroyTree(Tree* tree)
{
	if (tree)
	{
		free(tree);
		printf("OK");
		return OK;
	}
	else
		return ERROR;
}
Status AddNode(Tree t, TreeNode n, TreeNode parent)
{
	if (!t)
	{
		t->parent = NULL;
		t->val = n.val;
		t->child = t;
	}
	if (!parent.child)
	{
		printf("addnode error!");
		exit(ERROR);
	}
	parent.child = &n;
	return OK;
}
Tree* CreateTree()
{
	Tree* node;
	node = (Tree*)malloc(sizeof(TreeNode));
	if (!node)
    {
		exit(ERROR);
	}
	return node;
}

void ClearTree();

Status TreeEmpty(Tree t)
{
	if (t)
    {
		return FALSE;
	}
	else return TRUE;
}

TreeElem Root(Tree t)
{
    if (TreeEmpty(t)){
        printf("Tree is empty!");
    }
    TreeNode *temp;
    temp = &t;
    return temp->val;
}

int main()
{
	Tree* test;
	test = InitTree();
	printf("%d\n", TreeEmpty(test));
	TreeNode* temp;
	temp = &test;
	printf("%d\n", temp->val);
	DestroyTree(test);
    TreeNode a = {11, NULL, NULL};
    TreeNode b = {22, NULL, NULL};
    TreeNode c = {33, NULL, NULL};
}