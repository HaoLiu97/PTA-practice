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

int N;
vector<int> pre, post, in;
bool flag = true;

void postorderTraversal(TreeNode *root) {
    if (root == nullptr || !flag) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    if (flag) {
        cout << root->val << endl;
        flag = false;
    }
}

TreeNode *recur(int pre_l, int in_l, int len) {
    if (len <= 0)return nullptr;
    auto root = new TreeNode(pre[pre_l]);
    if (len == 1) return root;
    int i = 0;
    while(in[in_l + i] != pre[pre_l]) {
        ++i;
    }
    root->left = recur(pre_l + 1, in_l, i);
    root->right = recur(pre_l + i + 1, in_l + i + 1, len - i - 1);
    return root;
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N;
    pre.resize(N);
    in.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> pre[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> in[i];
    }
    auto root = recur(0, 0, N);
    postorderTraversal(root);

    return 0;
}
