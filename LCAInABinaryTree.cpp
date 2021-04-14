#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> in, pre;
unordered_map<int, int> u_map;

int lca(int in_l, int in_r, int pre_root, int a, int b) {
    if (in_l > in_r)return -1;
    int in_root = u_map[pre[pre_root]];
    if (u_map[a] == in_root || u_map[b] == in_root) {
        return in[in_root];
    }
    if (u_map[a] < in_root && u_map[b] > in_root || u_map[a] > in_root && u_map[b] < in_root) {
        return in[in_root];
    } else if (u_map[a] < in_root && u_map[b] < in_root) {
        return lca(in_l, in_root - 1, pre_root + 1, a, b);
    } else if (u_map[a] > in_root && u_map[b] > in_root) {
        return lca(in_root + 1, in_r, pre_root + 1 + in_root - in_l, a, b);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int M, N;
    cin >> M >> N;
    in.resize(N);
    pre.resize(N);
    u_map.clear();

    for (int i = 0; i < N; ++i) {
        cin >> in[i];
        u_map[in[i]] = i;
    }
    for (int i = 0; i < N; ++i) {
        cin >> pre[i];
    }

    for (int i = 0; i < M; ++i) {
        int u, v, big, small;
        cin >> u >> v;
        auto iter1 = u_map.find(u);
        auto iter2 = u_map.find(v);
        if (iter1 == u_map.end() && iter2 == u_map.end()) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (iter1 == u_map.end()) {
            printf("ERROR: %d is not found.\n", u);
        } else if (iter2 == u_map.end()) {
            printf("ERROR: %d is not found.\n", v);
        } else {
            int ancestor = lca(0, N - 1, 0, u, v);
            if (ancestor == u) {
                printf("%d is an ancestor of %d.\n", u, v);
            } else if (ancestor == v) {
                printf("%d is an ancestor of %d.\n", v, u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, ancestor);
            }
        }
    }

    return 0;
}
