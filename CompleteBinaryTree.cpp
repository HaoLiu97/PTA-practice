#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct TreeNode {
    int left = -1, right = -1;

    TreeNode() {
        left = -1;
        right = -1;
    }
} tree[25];

int maxn = -1, ans;

void dfs(int root, int index) {
    if (index > maxn) {
        maxn = index;
        ans = root;
    }
    if (tree[root].left != -1) {
        dfs(tree[root].left, index * 2);
    }
    if (tree[root].right != -1) {
        dfs(tree[root].right, index * 2 + 1);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;
    cin >> N;
    string str;
    unordered_set<int> set;
    for (int i = 0; i < N; ++i) {
        set.insert(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> str;
        if (str != "-") {
            t = stoi(str);
            tree[i].left = t;
            auto iter = set.find(t);
            if (iter != set.end()) {
                set.erase(iter);
            }
        }
        cin >> str;
        if (str != "-") {
            t = stoi(str);
            tree[i].right = t;
            auto iter = set.find(t);
            if (iter != set.end()) {
                set.erase(iter);
            }
        }
    }

    int root = *set.begin();
    dfs(root, 1);
    if (maxn == N) {
        cout << "YES " << ans;
    } else {
        cout << "NO " << root << endl;
    }

    return 0;
}
