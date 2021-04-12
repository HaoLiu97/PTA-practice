#include <bits/stdc++.h>

using namespace std;

typedef struct TreeNode *AVLTree;
struct TreeNode {
    int val;
    AVLTree left;
    AVLTree right;
};

int Height(AVLTree T) {
    if (T) {
        int HL = Height(T->left);/*左子树的长度*/
        int HR = Height(T->right);/*右子树的长度*/
        int HH = max(HL, HR);/*树的高度为左子树和右子树中高的*/
        return HH + 1;
    }
    return 0;
}

AVLTree RRFix(AVLTree Tree)/*右右单旋*/
{
    AVLTree T = Tree->right;
    Tree->right = T->left;
    T->left = Tree;
    return T;
}

AVLTree RLFix(AVLTree Tree)/*右左旋转*/
{
    AVLTree T = Tree->right->left;
    Tree->right->left = T->right;
    T->right = Tree->right;
    Tree->right = T->left;
    T->left = Tree;
    return T;
}

AVLTree LLFix(AVLTree Tree)/*左左单旋*/
{
    AVLTree T = Tree->left;
    Tree->left = T->right;
    T->right = Tree;
    return T;
}

AVLTree LRFix(AVLTree Tree)/*左右旋转*/
{
    AVLTree T = Tree->left->right;
    Tree->left->right = T->left;
    T->left = Tree->left;
    Tree->left = T->right;
    T->right = Tree;
    return T;
}

AVLTree Insert(AVLTree T, int data) {
    if (!T)/*建立根节点*/
    {
        T = (AVLTree) malloc(sizeof(struct TreeNode));
        T->val = data;
        T->left = T->right = nullptr;
    } else {
        if (data > T->val)/*如果大于根结点*/
        {
            T->right = Insert(T->right, data);
            if (Height(T->left) - Height(T->right) == -2)/*如果插入的结点导致树不再平衡*/
            {
                if (data > T->right->val)/*如果插入结点的值大于树的右子树的根节点的值就是右右插入*/
                {
                    T = RRFix(T);/*右右单旋*/
                } else/*如果小于就是右左插入*/
                {
                    T = RLFix(T);/*右左单旋*/
                }
            }
        } else if (data < T->val)/*如果小于根结点的值*/
        {
            T->left = Insert(T->left, data);
            if (Height(T->right) - Height(T->left) == -2)/*如果插入结点导致树不平衡*/
            {
                if (data > T->left->val)/*如果待插入结点大于左子树的根节点的值就是左右插入*/
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

void levelTraversal(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto v = q.front();
            if (v == root) {
                cout << v->val;
            } else {
                cout << " " << v->val;
            }
            q.pop();
            if (v->left) {
                q.push(v->left);
            }
            if (v->right) {
                q.push(v->right);
            }
        }
    }
}

int max_index = -1;

void dfs(TreeNode *cur, int cur_index) {
    if (cur == nullptr)return;
    max_index = max(max_index, cur_index);
    dfs(cur->left, cur_index * 2);
    dfs(cur->right, cur_index * 2 + 1);
}

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    AVLTree Tree = nullptr;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        Tree = Insert(Tree, data);
    }
    levelTraversal(Tree);
    cout << endl;
    dfs(Tree, 1);
    if (max_index == n) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
