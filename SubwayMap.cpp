#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

int s, t, minCnt, minTransfer;
unordered_map<int, int> line;
vector<vector<int>> G(10000);
vector<bool> vis;
vector<int> path, tmp_path;

inline int getLine(int s1, int s2) {
    return line[(s1 << 15) | s2];
}

int cntTransfer(vector<int> &p) {
    int cnt = 0;
    for (int i = 1; i < p.size(); ++i) {
        if (getLine(p[i + 1], p[i]) != getLine(p[i], p[i - 1])) {
            cnt++;
        }
    }

    return cnt;
}

void dfs(int cur, int cnt) {
    if (cur == t) {
        int cntT = cntTransfer(tmp_path);
        if (cnt < minCnt) {
            minCnt = cnt;
            minTransfer = cntT;
            path = tmp_path;
        } else if (cnt == minCnt && cntT < minTransfer) {
            minTransfer = cntT;
            path = tmp_path;
        }
        return;
    }

    for (int i = 0; i < G[cur].size(); ++i) {
        if (!vis[G[cur][i]]) {
            vis[G[cur][i]] = true;
            tmp_path.push_back(G[cur][i]);
            dfs(G[cur][i], cnt + 1);
            vis[G[cur][i]] = false;
            tmp_path.pop_back();
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, K, t1, t2;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> M;
        cin >> t1;
        for (int j = 1; j < M; ++j) {
            cin >> t2;
            G[t1].push_back(t2);
            G[t2].push_back(t1);
            line[(t1 << 15) | t2] = i;
            line[(t2 << 15) | t1] = i;
            t1 = t2;
        }
    }

    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> s >> t;
        minCnt = INF;
        minTransfer = INF;
        vis = vector<bool>(10000, false);
        tmp_path = vector<int>(1, s);
        dfs(s, 0);

        cout << path.size() << endl;
        vector<int> ans_site, ans_line;
        for (int j = 0; j < path.size(); ++j) {
            if (j == 0 || j == path.size() - 1) {
                ans_site.push_back(path[j]);
                if(j == 0) {
                    ans_line.push_back(getLine(path[j], path[j + 1]));
                }
            } else if (getLine(path[j], path[j - 1]) != getLine(path[j], path[j + 1])) {
                ans_site.push_back(path[j]);
                ans_line.push_back(getLine(path[j], path[j + 1]));
            }
        }
        for (int j = 0; j < ans_line.size(); ++j) {
            printf("Take Line#%d from %04d to %04d.\n", ans_line[j], ans_site[j], ans_site[j + 1]);
        }
    }

    return 0;
}
