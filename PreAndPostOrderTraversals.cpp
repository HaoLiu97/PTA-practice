#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct TreeNode {
    int val;
    TreeNode *left, *right;

    TreeNode(int v) {
        val = v;
    }
};

vector<int> inorder;

void inorderTraversal(TreeNode *root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    inorder.push_back(root->val);
    inorderTraversal(root->right);
}

vector<int> pre, post;
bool isUnique = true;
int N;

TreeNode *recur(int pre_l, int post_l, int len) {
    if (len <= 0) return nullptr;
    if (len == 1) return new TreeNode(pre[pre_l]);
    TreeNode *root = nullptr;
    if (pre[pre_l] == post[post_l + len - 1]) {
        root = new TreeNode(pre[pre_l]);
        int i = 0;
        while (pre[pre_l + 1] != post[post_l + i]) {
            ++i;
        }
        ++i;
        if (i == len - 1) {
            isUnique = false;
        }

        root->left = recur(pre_l + 1, post_l, i);
        root->right = recur(pre_l + i + 1, post_l + i, len - i - 1);
    }

    return root;
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N;
    pre.resize(N);
    post.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> post[i];
    }

    auto root = recur(0, 0, N);
    inorderTraversal(root);
    if (isUnique) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    for (int i = 0; i < inorder.size(); ++i) {
        cout << inorder[i] << " \n"[i == inorder.size() - 1];
    }

    return 0;
}
