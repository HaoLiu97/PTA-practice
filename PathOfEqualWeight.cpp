#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    vector<int> next;

    TreeNode() {
        val = 0;
    };
};

TreeNode tree[101];

vector<int> path;

vector<vector<int>> paths;

int S;

void dfs(int cur, int s) {
    path.push_back(tree[cur].val);

    if (s == 0 && tree[cur].next.empty()) {
        paths.push_back(path);
        path.pop_back();
        return;
    }

    if (s < 0) {
        path.pop_back();
        return;
    }

    for (int i = 0; i < tree[cur].next.size(); ++i) {
        int child = tree[cur].next[i];
        dfs(child, s - tree[child].val);
    }

    path.pop_back();
}

int main() {
    int N, M;
    cin >> N >> M >> S;

    for (int i = 0; i < N; ++i) {
        cin >> tree[i].val;
    }

    int ID, K, t;
    for (int i = 0; i < M; ++i) {
        cin >> ID >> K;
        for (int j = 0; j < K; ++j) {
            cin >> t;
            tree[ID].next.push_back(t);
        }
    }

    dfs(0, S - tree[0].val);

    sort(paths.begin(), paths.end());
    for (int i = paths.size() - 1; i >= 0; -- i) {
        auto p = paths[i];
        for (int i = 0; i < p.size(); ++i) {
            cout << p[i];
            if (i != p.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
