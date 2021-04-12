#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int cnt = 0;

vector<int> G[501];
bool vis[501];
void dfs(int cur) {
    cnt ++;
    vis[cur] = true;
    for(int i = 0; i < G[cur].size(); ++i) {
        if(!vis[G[cur][i]]) {
            dfs(G[cur][i]);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, t1, t2;
    cin >> N >> M;
    vector<int> degree(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2;
        G[t1].push_back(t2);
        G[t2].push_back(t1);
        degree[t1]++;
        degree[t2]++;
    }

    dfs(1);

    int even_cnt = 0, odd_cnt = 0;
    for (int i = 1; i <= N; ++i) {
        if (degree[i] % 2 == 0) {
            even_cnt++;
        } else {
            odd_cnt++;
        }
    }
    for (int i = 1; i <= N; ++i) {
        cout << degree[i] << " \n"[i == N];
    }

    if(cnt != N) {
        cout << "Non-Eulerian" << endl;
        return 0;
    }

    if (odd_cnt == 0) {
        cout << "Eulerian" << endl;
    } else if (odd_cnt == 2) {
        cout << "Semi-Eulerian" << endl;
    } else {
        cout << "Non-Eulerian" << endl;
    }

    return 0;
}
