#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, K, v1, v2, t;
    cin >> N >> M;
    vector<int> G[N + 1];
    vector<int> degree(N + 1);
    for (int i = 0; i < M; ++i) {
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        degree[v2]++;
    }

    vector<int> ans, seq(N);
    cin >> K;
    for (int i = 0; i < K; ++i) {
        bool flag = true;
        vector<int> cur_degree = degree;
        for (int j = 0; j < N; ++j) {
            cin >> t;
            if(flag) {
                if (cur_degree[t] != 0) {
                    flag = false;
                } else {
                    for (int next:G[t]) {
                        cur_degree[next]--;
                    }
                }
            }
        }
        if(!flag) {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " \n"[i == ans.size() - 1];
    }

    return 0;
}
