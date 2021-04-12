#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int v) {
        val = v;
        left = nullptr;
        right = nullptr;
    }
};

void insert(TreeNode *root, int val) {
    if (val <= root->val) {
        if (root->left == nullptr) {
            root->left = new TreeNode(val);
        } else {
            insert(root->left, val);
        }
    } else {
        if (root->right == nullptr) {
            root->right = new TreeNode(val);
        } else {
            insert(root->right, val);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;
    cin >> N;
    cin >> t;
    TreeNode *root = new TreeNode(t);
    for (int i = 1; i < N; ++i) {
        cin >> t;
        insert(root, t);
    }

    int n1 = 0, n2 = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        n2 = n1;
        n1 = size;
        for (int i = 0; i < size; ++i) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
    }

    cout <<n1 <<" + " << n2 <<" = "<< n1 + n2 << endl;

    return 0;
}
