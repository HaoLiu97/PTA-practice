#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct TreeNode {
    string val;
    int left, right;

    TreeNode() {
        left = right = -1;
    }
};

TreeNode tree[30];
vector<string> post_order;

int root;

string inorder(int cur) {
    if (cur == -1) return "";
    string ret;
    if (cur != root && (tree[cur].left != -1 || tree[cur].right != -1)) {
        ret += "(";
    }
    ret += inorder(tree[cur].left);
    ret += tree[cur].val;
    ret += inorder(tree[cur].right);
    if (cur != root && (tree[cur].left != -1 || tree[cur].right != -1)) {
        ret += ")";
    }
    return ret;
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, l, r;
    string str;
    cin >> N;

    unordered_set<int> set;
    for (int i = 1; i <= N; ++i) {
        set.insert(i);
    }

    for (int i = 1; i <= N; ++i) {
        cin >> str >> l >> r;
        tree[i].val = str;
        if (l != -1) {
            tree[i].left = l;
            auto iter = set.find(l);
            if (iter != set.end()) {
                set.erase(iter);
            }
        }
        if (r != -1) {
            tree[i].right = r;
            auto iter = set.find(r);
            if (iter != set.end()) {
                set.erase(iter);
            }
        }
    }
    root = *set.begin();
    cout << inorder(root);

    return 0;
}
