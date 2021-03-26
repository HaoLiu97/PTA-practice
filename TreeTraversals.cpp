#include <bits/stdc++.h>

using namespace std;

vector<int> post_order, in_order;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

TreeNode *recur(int i_left, int i_right, int p_left, int p_right) {
    if (i_left > i_right) {
        return nullptr;
    }

    if (i_left == i_right) {
        return new TreeNode(in_order[i_left]);
    }

    TreeNode *root = new TreeNode(post_order[p_right]);
    for (int i = i_left; i <= i_right; ++i) {
        if (in_order[i] == post_order[p_right]) {
            int len = i - i_left;
            root->left = recur(i_left, i_left + len - 1, p_left, p_left + len - 1);
            root->right = recur(i + 1, i_right, p_left + len, p_right - 1);
            break;
        }
    }

    return root;
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

int main() {
    int N, t;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> t;
        post_order.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        cin >> t;
        in_order.push_back(t);
    }

    auto root = recur(0, N - 1, 0, N - 1);
    levelTraversal(root);

    return 0;
}