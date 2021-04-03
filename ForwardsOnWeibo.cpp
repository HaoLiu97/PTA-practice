#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int N, L, K, M, t, S, cnt;
vector<int> vis;
vector<vector<int>> follower;

void dfs(int cur, int depth) {
    vis[cur] = depth;
    if(depth == L) {
        return;
    }
    for(int i = 0; i < follower[cur].size(); ++i) {
        if(vis[follower[cur][i]] > depth + 1) {
            if(vis[follower[cur][i]] == INF) {
                ++cnt;
            }
            dfs(follower[cur][i], depth + 1);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N >> L;

    follower = vector<vector<int>>(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> M;
        for (int j = 0; j < M; ++j) {
            cin >> t;
            follower[t].push_back(i);
        }
    }

    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> S;
        vis = vector<int>(N + 1, INF);
        vis[S] = 0;
        cnt = 0;
        dfs(S, 0);
        cout<<cnt<<endl;
    }

    return 0;
}
