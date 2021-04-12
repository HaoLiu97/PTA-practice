#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Edge {
    int node;
    int dis, time;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, v1, v2, one_way, length, time, s, d;
    cin >> N >> M;
    vector<Edge> G[N + 1];
    for (int i = 0; i < M; ++i) {
        cin >> v1 >> v2 >> one_way >> length >> time;
        G[v1].push_back(Edge{v2, length, time});
        if (one_way == 0) {
            G[v2].push_back(Edge{v1, length, time});
        }
    }
    cin >> s >> d;
    int shortest_dis, fastest_time;

    vector<int> shortest_path[N], fastest_path[N];
    vector<int> dis(N, INF), times(N, INF);
    vector<bool> vis(N, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dis[s] = 0;
    times[s] = 0;
    shortest_path[s].push_back(s);
    fastest_path[s].push_back(s);

    // 最短的
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int cur = pair.second;
        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;
        for (int i = 0; i < G[cur].size(); ++i) {
            int next = G[cur][i].node;
            if (G[cur][i].dis + dis[cur] < dis[next] || (G[cur][i].dis + dis[cur] == dis[next] && G[cur][i].time + times[cur] < times[next])) {
                dis[next] = G[cur][i].dis + dis[cur];
                times[next] = G[cur][i].time + times[cur];
                shortest_path[next] = shortest_path[cur];
                shortest_path[next].push_back(next);
                pq.emplace(dis[next], next);
            }
        }
    }
    shortest_dis = dis[d];

    times = vector<int>(N, INF);
    vector<int> nodes_num(N, INF);
    vis = vector<bool>(N, false);
    times[s] = 0;
    nodes_num[s] = 0;

    pq.emplace(0, s);
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int cur = pair.second;
        if (vis[cur]) {
            continue;
        }
        vis[cur] = true;
        for (int i = 0; i < G[cur].size(); ++i) {
            int next = G[cur][i].node;
            if (G[cur][i].time + times[cur] < times[next] || (G[cur][i].time + times[cur] == times[next]&&nodes_num[cur] + 1 < nodes_num[next])) {
                times[next] = G[cur][i].time + times[cur];
                nodes_num[next] = nodes_num[cur] + 1;
                fastest_path[next] = fastest_path[cur];
                fastest_path[next].push_back(next);
                pq.emplace(times[next], next);
            }
        }
    }
    fastest_time = times[d];

    if(shortest_path[d] == fastest_path[d]) {
        cout<<"Distance = "<<shortest_dis<<"; Time = "<<fastest_time<<": ";
        for (int i = 0; i < shortest_path[d].size(); ++i) {
            cout << shortest_path[d][i];
            if (i != shortest_path[d].size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    } else {
        cout<<"Distance = "<<shortest_dis<<": ";
        for (int i = 0; i < shortest_path[d].size(); ++i) {
            cout << shortest_path[d][i];
            if (i != shortest_path[d].size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
        cout<<"Time = "<<fastest_time<<": ";
        for (int i = 0; i < fastest_path[d].size(); ++i) {
            cout << fastest_path[d][i];
            if (i != fastest_path[d].size() - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    return 0;
}
