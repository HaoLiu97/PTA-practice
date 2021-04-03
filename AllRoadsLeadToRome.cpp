#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Edge {
    int city;
    int dis;
};


int main() {
    freopen("in.txt", "r", stdin);
    int N, K, t;
    string c0, c1, c2;
    cin >> N >> K >> c0;
    unordered_map<string, int> name_map;
    unordered_map<int, string> r_name_map;
    vector<Edge> Graph[N];
    vector<int> path[N];

    vector<int> happy(N, 0);

    int cnt = 0;
    name_map[c0] = cnt;
    r_name_map[cnt] = c0;
    happy[cnt++] = 0;

    for (int i = 0; i < N - 1; ++i) {
        cin >> c1 >> t;
        name_map[c1] = cnt;
        r_name_map[cnt] = c1;
        happy[cnt++] = t;
    }

    for (int i = 0; i < K; ++i) {
        cin >> c1 >> c2 >> t;
        Graph[name_map[c1]].push_back(Edge{name_map[c2], t});
        Graph[name_map[c2]].push_back(Edge{name_map[c1], t});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    vector<int> dis(N, INF);
    vector<bool> vis(N, false);
    vector<int> h(N, 0);

    int S = name_map[c0], T = name_map["ROM"];
    pq.emplace(0, S);
    dis[S] = 0;
    h[S] = 0;
    path[S].push_back(S);
    vector<int> path_cnt(N + 1, 0);
    path_cnt[S] = 1;

    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int cur = pair.second;
        if (vis[cur]) { // 注意有环
           continue;
        }
        vis[cur] = true;

        for (int j = 0; j < Graph[cur].size(); ++j) {
            Edge edge = Graph[cur][j];
            if (!vis[edge.city]) {
                if (edge.dis + dis[cur] < dis[edge.city]) {
                    dis[edge.city] = edge.dis + dis[cur];
                    pq.emplace(dis[edge.city], edge.city);
                    path[edge.city] = path[cur];
                    path[edge.city].push_back(edge.city);
                    h[edge.city] = h[cur] + happy[edge.city];
                    path_cnt[edge.city] = path_cnt[cur];
                } else if (edge.dis + dis[cur] == dis[edge.city]) {
                    path_cnt[edge.city] = path_cnt[edge.city] + path_cnt[cur];
                    if (h[cur] + happy[edge.city] > h[edge.city]) {
                        path[edge.city] = path[cur];
                        path[edge.city].push_back(edge.city);
                        h[edge.city] = h[cur] + happy[edge.city];
                    } else if (h[cur] + happy[edge.city] == h[edge.city]) {
                        if (path[cur].size() + 1 < path[edge.city].size()) {
                            path[edge.city] = path[cur];
                            path[edge.city].push_back(edge.city);
                        }
                    }
                }
            }
        }
    }


    cout << path_cnt[T] << " " << dis[T] << " " << h[T] << " " << h[T] / (path[T].size() - 1) << endl;
    for (int i = 0; i < path[T].size(); ++i) {
        cout << r_name_map[path[T][i]];
        if (i != path[T].size() - 1) {
            cout << "->";
        }
    }

    return 0;
}
