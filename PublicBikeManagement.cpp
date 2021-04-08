#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Edge {
    int node, weight;
};

int main() {
    freopen("in.txt", "r", stdin);
    int Cmax, N, Sp, M;
    cin >> Cmax >> N >> Sp >> M;

    vector<int> bike_total(N + 1);
    int t1, t2, w;
    vector<Edge> G[N + 1];

    for (int i = 1; i <= N; ++i) {
        cin >> t1;
        bike_total[i] = t1;
    }

    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2 >> w;
        G[t1].push_back(Edge{t2, w});
        G[t2].push_back(Edge{t1, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dis(N + 1, INF);
    vector<bool> vis(N + 1, false);

    dis[0] = 0;
    pq.emplace(0, 0);
    vector<vector<int>> path[N + 1];
    path[0].push_back(vector<int>{0});

    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();

        int cur = pair.second;
        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;

        for (int i = 0; i < G[cur].size(); ++i) {
            Edge edge = G[cur][i];
            if (!vis[edge.node]) {
                if (edge.weight + dis[cur] < dis[edge.node]) {
                    dis[edge.node] = edge.weight + dis[cur];
                    pq.emplace(dis[edge.node], edge.node);

                    path[edge.node] = path[cur];
                    for (auto &p:path[edge.node]) {
                        p.push_back(edge.node);
                    }

                } else if (edge.weight + dis[cur] == dis[edge.node]) {
                    pq.emplace(dis[edge.node], edge.node);
                    auto tmp = path[cur];
                    for (auto &p:tmp) {
                        p.push_back(edge.node);
                    }
                    path[edge.node].insert(path[edge.node].end(), tmp.begin(), tmp.end());
                }
            }
        }
    }

    int ans_index = 0, min_sent = INF, min_take_back = INF;
    for (int i = 0; i < path[Sp].size(); ++i) {
        int sent = 0, take_back = 0, cur_bike = 0;
        for (int j = 1; j < path[Sp][i].size(); ++j) {
            cur_bike = cur_bike + bike_total[path[Sp][i][j]] - Cmax/2;
            if(cur_bike < 0) {
                sent += -cur_bike;
                cur_bike = 0;
            }
        }
        if(sent < 0) {
            sent = 0;
        }

        take_back = cur_bike;

        if (sent < min_sent) {
            min_sent = sent;
            min_take_back = take_back;
            ans_index = i;
        } else if (sent == min_sent) {
            if(take_back < min_take_back) {
                min_take_back = take_back;
                ans_index = i;
            }
        }
    }

    cout<<min_sent<<" ";
    for(int i = 0; i < path[Sp][ans_index].size(); ++i) {
        cout<<path[Sp][ans_index][i];
        if(i != path[Sp][ans_index].size() - 1) {
            cout<<"->";
        }
    }

    cout<<" "<<min_take_back<<endl;

    return 0;
}
