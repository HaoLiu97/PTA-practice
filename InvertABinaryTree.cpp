#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    int left = -1, right = -1;

    Node() {
        left = -1;
        right = -1;
    }
} tree[20];

void levelTraversal(int root) {
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto v = q.front();
            if (v == root) {
                cout << v;
            } else {
                cout << " " << v;
            }
            q.pop();
            if (tree[v].left != -1) {
                q.push(tree[v].left);
            }
            if (tree[v].right != -1) {
                q.push(tree[v].right);
            }
        }
    }
}

void invert(int root) {
    if (root == -1) return;
    swap(tree[root].left, tree[root].right);
    invert(tree[root].left);
    invert(tree[root].right);
}

vector<int> inorder;

void inorderTraversal(int root) {
    if (root == -1) return;
    inorderTraversal(tree[root].left);
    inorder.push_back(root);
    inorderTraversal(tree[root].right);
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;
    cin >> N;
    char c;
    unordered_set<int> set;
    for (int i = 0; i < N; ++i) {
        set.insert(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> c;
        if (c != '-') {
            t = c - '0';
            tree[i].left = t;
            set.erase(set.find(t));
        }
        cin >> c;
        if (c != '-') {
            t = c - '0';
            tree[i].right = t;
            set.erase(set.find(t));
        }
    }

    invert(*set.begin());
    levelTraversal(*set.begin());
    cout << endl;
    inorderTraversal(*set.begin());
    for (int i = 0; i < inorder.size(); ++i) {
        cout << inorder[i] << " \n"[i == inorder.size() - 1];
    }

    return 0;
}
