#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

int vis[MAXN];
vector<int> Adj[MAXN];

void dfs(int s) {
    vis[s] = 1;
    for(int node:Adj[s]) {
        if(!vis[node]) {
            dfs(node);
        }
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int c1, c2, c;
    for (int i = 0; i < M; ++i) {
        cin >> c1 >> c2;
        Adj[c1].push_back(c2);
        Adj[c2].push_back(c1);
    }

    for (int i = 0; i < K; ++i) {
        fill(vis, vis + MAXN, 0);
        cin >> c; // lost city
        int cnt = 0;
        vis[c] = 1;
        for (int j = 1; j <= N; ++j) {
            if (!vis[j]) {
                dfs(j);
                cnt++;
            }
        }
        cout << cnt - 1 << endl;
    }

    return 0;
}
