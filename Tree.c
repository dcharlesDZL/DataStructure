#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

typedef int TreeElem;
typedef struct _TreeNode
{
    TreeElem val;
    struct TreeNode *parent;
    struct TreeNode *child;
} TreeNode, *Tree;
// typedef struct _BiTreeNode
// {
//     TreeElem val;
//     struct BiTreeNode *lchild, *rchild;
// } BiTreeNode, *BiTree;
// 初始化树
Tree *InitTree()
{
    Tree *t;
    t = NULL;
    return t;
}

Status DestroyTree(Tree *tree)
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
Tree *AddNode(Tree t, TreeNode n, TreeNode parent)
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
}
Tree *CreateTree()
{
    Tree *node;
    node = (Tree *)malloc(sizeof(TreeNode));
    if (!node)
    {
        exit(ERROR);
    }
    return node;
}

void ClearTree();

void TreeEmpty();

void Root();

int main()
{
    Tree *test;
    test = InitTree();
    TreeNode *temp;
    temp = test;
    printf("%d", temp->val);
    DestroyTree(test);
}