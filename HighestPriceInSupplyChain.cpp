#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> G[100005];
int max_depth = 0, max_cnt = 0;

void dfs(int cur, int depth) {
    if(G[cur].empty()) { // 叶子节点
        if(depth > max_depth) {
            max_depth = depth;
            max_cnt = 1;
        } else if(depth == max_depth) {
            max_cnt ++;
        }
        return;
    }

    for (int i = 0; i < G[cur].size(); ++i) {
        dfs(G[cur][i], depth + 1);
    }
}


int main() {
    freopen("in.txt", "r", stdin);
    int N;
    double P, r;
    cin >> N >> P >> r;
    r = r * 0.01;
    vector<int> s(N);

    int root;
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
        if (s[i] != -1) {
            G[s[i]].push_back(i);
        } else {
            root = i;
        }
    }

    dfs(root, 0);

    double ans = P * pow(1 + r, max_depth);
    printf("%.2f %d\n", ans, max_cnt);

    return 0;
}
