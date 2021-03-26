#include <bits/stdc++.h>

using namespace std;

#define MAXV 100000
#define INF 10000000

struct edge {
    int v;
    int dis;
};

vector<edge> Adj[MAXV];
int d[MAXV]; // C1到这的最短距离
bool vis[MAXV] = {false};
int r_num[MAXV]; // 每个城市的救援队数量
int path_num[MAXV]; // C1过去的最短路径条数
int r_total[MAXV]; // C1过来的救援队数量

int main() {
    int N, M, C1, C2;
    scanf("%d %d %d %d", &N, &M, &C1, &C2);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &r_num[i]);
    }

    int v1, v2, dis;
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", &v1, &v2, &dis);
        Adj[v1].push_back(edge{v2, dis});
        Adj[v2].push_back(edge{v1, dis});
    }

    fill(d, d + MAXV, INF);

    d[C1] = 0;
    path_num[C1] = 1;
    r_total[C1] = r_num[C1];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;
    pq.push(pair<int, int>(0, C1));

    while (!pq.empty()) {
        int u = pq.top().second;
        vis[u] = true;
        pq.pop();

        for (auto e:Adj[u]) {
            if (e.dis + d[u] < d[e.v]) {
                d[e.v] = e.dis + d[u];
                path_num[e.v] = path_num[u];
                r_total[e.v] = r_total[u] + r_num[e.v];
                pq.push(pair<int, int>(d[e.v], e.v));
            } else if (e.dis + d[u] == d[e.v]) {
                path_num[e.v] += path_num[u];
                if (r_total[u] + r_num[e.v] > r_total[e.v]) {
                    r_total[e.v] = r_total[u] + r_num[e.v];
                }
            }
        }
    }

    printf("%d %d", path_num[C2], r_total[C2]);

    return 0;
}
