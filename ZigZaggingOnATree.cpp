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

vector<int> inorder, post;
int N;

TreeNode *recur(int inorder_l, int post_l, int len) {
    if (len <= 0) return nullptr;
    if (len == 1) return new TreeNode(inorder[inorder_l]);
    TreeNode *root = new TreeNode(post[post_l + len - 1]);
    int i = 0;
    while (inorder[inorder_l + i] != root->val) {
        ++i;
    }
    root->left = recur(inorder_l, post_l, i);
    root->right = recur(inorder_l + i + 1, post_l + i, len - 1 - i);

    return root;
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N;
    inorder.resize(N);
    post.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> inorder[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> post[i];
    }

    auto root = recur(0, 0, N);
    queue<TreeNode *> q;
    vector<int> level;
    q.push(root);
    bool zig = false;
    TreeNode *cur;
    while (!q.empty()) {
        int size = q.size();
        level.clear();
        for (int i = 0; i < size; ++i) {
            cur = q.front();
            level.push_back(cur->val);
            q.pop();
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        if (cur == root) {
            cout << cur->val;
            continue;
        }
        if (!zig) {
            for (int i = 0; i < level.size(); ++i) {
                cout << " " << level[i];
            }
        } else {
            for (int i = (int) level.size() - 1; i >= 0; --i) {
                cout << " " << level[i];
            }
        }
        zig = !zig;
    }

    return 0;
}
