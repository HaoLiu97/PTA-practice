#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<vector<int>> G(201, vector<int>(201, INF));

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, t1, t2, d;
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2 >> d;
        G[t1][t2] = d;
        G[t2][t1] = d;
    }

    set<int> o_set;
    for (int i = 1; i <= N; ++i) o_set.insert(i);

    int K, n;
    cin >> K;
    int min_dis = INF, min_index = 0;
    for (int i = 1; i <= K; ++i) {
        cin >> n;
        vector<int> seq(n);
        set<int> tmp_set = o_set;
        int dis = 0;
        for (int j = 0; j < n; ++j) {
            cin >> seq[j];
            if (j != 0) {
                dis += G[seq[j]][seq[j - 1]];
            }
            auto iter = tmp_set.find(seq[j]);
            if (iter != tmp_set.end()) {
                tmp_set.erase(iter);
            }
        }
        if (!tmp_set.empty() || seq[0] != seq[n - 1] || dis > INF) {
            if (dis < INF) {
                cout << "Path " << i << ": " << dis << " (Not a TS cycle)" << endl;
            } else {
                cout << "Path " << i << ": NA (Not a TS cycle)" << endl;
            }
        } else {
            if (dis < min_dis) {
                min_dis = dis;
                min_index = i;
            }
            if (n == N + 1) {
                cout << "Path " << i << ": " << dis << " (TS simple cycle)" << endl;
            } else {
                cout << "Path " << i << ": " << dis << " (TS cycle)" << endl;
            }
        }
    }

    cout << "Shortest Dist(" << min_index << ") = " << min_dis << endl;

    return 0;
}
