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

vector<int> in, pre;

TreeNode *recur(int pre_l, int in_l, int len) {
    if (len <= 0)return nullptr;
    auto root = new TreeNode(pre[pre_l]);
    if (len == 1) return root;
    int i = 0;
    while (in[in_l + i] != pre[pre_l]) {
        ++i;
    }
    root->left = recur(pre_l + 1, in_l, i);
    root->right = recur(pre_l + i + 1, in_l + i + 1, len - i - 1);
    return root;
}

bool judge1(TreeNode *root) {
    if(root == nullptr) return true;
    if (root->val < 0) { // 根是红的
        if ((root->left && root->left->val < 0) || (root->right && root->right->val < 0)) {
            return false;
        }
    }
    return judge1(root->left) && judge1(root->right);
}

int getNum(TreeNode *root) {
    if (root == nullptr) return 0;
    int l = getNum(root->left);
    int r = getNum(root->right);
    return root->val > 0 ? max(l, r) + 1 : max(l, r);
}

bool judge2(TreeNode *root) {
    if (root == nullptr) return true;
    int l = getNum(root->left);
    int r = getNum(root->right);
    if(l != r) return false;
    return judge2(root->left) && judge2(root->right);
}

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    cin>>T;
    for (int tc = 0; tc < T; ++tc) {
        int N;
        cin >> N;
        pre.resize(N);
        for (int i = 0; i < N; ++i) {
            cin >> pre[i];
        }
        in = pre;
        sort(in.begin(), in.end(), [](int a, int b) -> bool {
            return abs(a) < abs(b);
        });
        auto root = recur(0, 0, N);
        if (root->val > 0 && judge1(root) && judge2(root)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
