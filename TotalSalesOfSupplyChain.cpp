#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> G[100005];

double P, r;
double total = 0;
unordered_map<int, int> u_map;


void dfs(int cur, int depth) {
    if(G[cur].empty()) { // 叶子节点
        total += u_map[cur]*P * pow(r, depth);
        return;
    }

    for (int i = 0; i < G[cur].size(); ++i) {
        dfs(G[cur][i], depth + 1);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, m, t;
    cin >> N >> P >> r;
    r = 1 + r * 0.01;

    for (int i = 0; i < N; ++i) {
        cin >> m;
        if(m != 0) {
            for (int j = 0; j < m; ++j) {
                cin>>t;
                G[i].push_back(t);
            }
        } else {
             cin>>t;
            u_map[i] = t;
        }
    }

    dfs(0, 0);

    printf("%.1f\n", total);

    return 0;
}
