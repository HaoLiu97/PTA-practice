#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode *AVLTree;
struct TreeNode {
    int Data;
    AVLTree Left;
    AVLTree Right;
};

int Height(AVLTree T) {
    if (T) {
        int HL = Height(T->Left);/*左子树的长度*/
        int HR = Height(T->Right);/*右子树的长度*/
        int HH = max(HL, HR);/*树的高度为左子树和右子树中高的*/
        return HH + 1;
    }
    return 0;
}

AVLTree RRFix(AVLTree Tree)/*右右单旋*/
{
    AVLTree T = Tree->Right;
    Tree->Right = T->Left;
    T->Left = Tree;
    return T;
}

AVLTree RLFix(AVLTree Tree)/*右左旋转*/
{
    AVLTree T = Tree->Right->Left;
    Tree->Right->Left = T->Right;
    T->Right = Tree->Right;
    Tree->Right = T->Left;
    T->Left = Tree;
    return T;
}

AVLTree LLFix(AVLTree Tree)/*左左单旋*/
{
    AVLTree T = Tree->Left;
    Tree->Left = T->Right;
    T->Right = Tree;
    return T;
}

AVLTree LRFix(AVLTree Tree)/*左右旋转*/
{
    AVLTree T = Tree->Left->Right;
    Tree->Left->Right = T->Left;
    T->Left = Tree->Left;
    Tree->Left = T->Right;
    T->Right = Tree;
    return T;
}

AVLTree Insert(AVLTree T, int data) {
    if (!T)/*建立根节点*/
    {
        T = (AVLTree) malloc(sizeof(struct TreeNode));
        T->Data = data;
        T->Left = T->Right = nullptr;
    } else {
        if (data > T->Data)/*如果大于根结点*/
        {
            T->Right = Insert(T->Right, data);
            if (Height(T->Left) - Height(T->Right) == -2)/*如果插入的结点导致树不再平衡*/
            {
                if (data > T->Right->Data)/*如果插入结点的值大于树的右子树的根节点的值就是右右插入*/
                {
                    T = RRFix(T);/*右右单旋*/
                } else/*如果小于就是右左插入*/
                {
                    T = RLFix(T);/*右左单旋*/
                }
            }
        } else if (data < T->Data)/*如果小于根结点的值*/
        {
            T->Left = Insert(T->Left, data);
            if (Height(T->Right) - Height(T->Left) == -2)/*如果插入结点导致树不平衡*/
            {
                if (data > T->Left->Data)/*如果待插入结点大于左子树的根节点的值就是左右插入*/
                {
                    T = LRFix(T);
                } else/*如果待插入结点小于左子树的根节点的值就是左左插入*/
                {
                    T = LLFix(T);
                }
            }
        }
    }
    return T;
}

int main() {
    int n;
    cin >> n;
    AVLTree Tree = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Tree = Insert(Tree, data);
    }
    if (Tree) {
        cout << Tree->Data << endl;
    }
    return 0;
}
