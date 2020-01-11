#include <stdio.h>
#include "Status.h"
#include "Stack.h"
typedef int TreeElem;
typedef BiTreeNode StackElement;
typedef struct _BiTreeNode
{
    TreeElem val;
    BiTreeNode *lchild;
    BiTreeNode *rchild;
} BiTreeNode, *BiTree;
void InitBiTree(BiTree T)
{
    T = NULL;
}

void DestroyBiTree(BiTree T)
{
    if (T)
    {
        DestroyBiTree(T->lchild);
        DestroyBiTree(T->rchild);
    }
    free(T);
    T = NULL;
}

void BiTreeEmpty(BiTree T)
{
    if (T)
    {
        return TRUE;
    }
    else
        return FALSE;
}
// 递归法 求解 二叉树深度
int BiTreeDepth(BiTree T)
{
    // 树为空则数深度为0
    if (T == NULL)
    {
        printf("树的深度为0.");
        return 0;
    }
    // 左子树为空，右子树不空，则树的深度为左子树深度加1
    if (T->lchild == NULL && T->rchild != NULL)
    {
        int rdepth = BiTreeDepth(T->lchild) + 1;
        return rdepth;
    }
    // 右子树为空，左子树不空，则树的深度为左子树深度加1
    if (T->lchild != NULL && T->rchild == NULL)
    {
        int ldepth = BiTreeDepth(T->rchild) + 1;
        return ldepth;
    }
}
//非递归法求界二叉树深度
int BiTreeDepth2(BiTree T)
{
    BiTreeNode * temp;
    temp = T;
    int depth = 0;
    Stack *s;
    InitStack(s);
    if(!temp){
        return depth;
    }
    while(temp->rchild){
        depth++;
        Push(s, temp->rchild);
        while(temp->lchild){
            
        }
    }
}