#include <bits/stdc++.h>

using namespace std;

#define MAXN 505

struct Edge {
    int node;
    int distance;
    int cost;
};

struct Dis {
    int distance;
    int cost;
};

vector<Edge> Adj[MAXN];
Dis dis[MAXN];
bool vis[MAXN];

int main() {
    int N, M, S, D;
    cin >> N >> M >> S >> D;

    int c1, c2, d, c;
    for (int i = 0; i < M; ++i) {
        cin >> c1 >> c2 >> d >> c;
        Adj[c1].push_back(Edge{c2, d, c});
        Adj[c2].push_back(Edge{c1, d, c});
    }

    fill(dis, dis+MAXN, Dis{INT_MAX, INT_MAX});
    vis[S] = true;
    dis[S] = Dis{0, 0};
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, S);
    vector<int> path[MAXN];
    path[S].push_back(S);

    while(!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int cur = pair.second;
        vis[pair.second] = true;

        for (int j = 0; j < Adj[cur].size(); ++j) {
            Edge edge = Adj[cur][j];
            if(!vis[edge.node]) {
                if (edge.distance + dis[cur].distance < dis[edge.node].distance) {
                    dis[edge.node].distance = edge.distance + dis[cur].distance;
                    dis[edge.node].cost = edge.cost + dis[cur].cost;
                    pq.emplace(dis[edge.distance].distance, edge.node);
                    path[edge.node] = path[cur];
                    path[edge.node].push_back(edge.node);
                } else if (edge.distance + dis[cur].distance == dis[edge.node].distance) {
                    if (edge.cost + dis[cur].cost < dis[edge.node].cost) {
                        dis[edge.node].cost = edge.cost + dis[cur].cost;
                        pq.emplace(dis[edge.distance].distance, edge.node);
                        path[edge.node] = path[cur];
                        path[edge.node].push_back(edge.node);
                    }
                }
            }
        }
    }

    for(int n:path[D]) {
        cout<<n<<" ";
    }

    cout<<dis[D].distance<<" "<<dis[D].cost<<endl;

    return 0;
}
