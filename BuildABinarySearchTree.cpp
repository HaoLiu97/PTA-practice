#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    int left, right;
    int left_cnt, right_cnt;
};

TreeNode tree[101];
vector<int> vals;

int cntRightChild(int root);

int cntLeftChild(int root) {
    if (tree[root].left == -1) {
        return 0;
    }
    if (tree[root].left_cnt == 0) {
        tree[root].left_cnt = cntLeftChild(tree[root].left) + cntRightChild(tree[root].left) + 1;
    }

    return tree[root].left_cnt;
}

int cntRightChild(int root) {
    if (tree[root].right == -1) {
        return 0;
    }
    if (tree[root].right_cnt == 0) {
        tree[root].right_cnt = cntLeftChild(tree[root].right) + cntRightChild(tree[root].right) + 1;
    }

    return tree[root].right_cnt;
}

void fillTree(int root, int start, int end) {
    if (start > end) {
        return;
    }

    if (start == end) {
        tree[root].val = vals[start];
        return;
    }

    int r_index = cntLeftChild(root);
    tree[root].val = vals[start + r_index];
    if (tree[root].left != -1) {
        fillTree(tree[root].left, start, start + r_index - 1);
    }

    if (tree[root].right != -1) {
        fillTree(tree[root].right, start + r_index + 1, end);
    }
}


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; ++i) {
        cin >> tree[i].left >> tree[i].right;
    }

    int t;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        vals.push_back(t);
    }

    sort(vals.begin(), vals.end());
    fillTree(0, 0, N - 1);

    queue<TreeNode *> q;
    q.push(&tree[0]);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode *cur = q.front();
            if (cur != &tree[0]) {
                cout << " " << cur->val;
            } else {
                cout << cur->val;
            }
            if (cur->left != -1) {
                q.push(&tree[cur->left]);
            }

            if (cur->right != -1) {
                q.push(&tree[cur->right]);
            }

            q.pop();
        }
    }


    return 0;
}
