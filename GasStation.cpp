#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Edge {
    int node, weight;
};

int N, M, K, Ds, d;

string gasName(int no) {
    return "G" + to_string(no - N);
}

vector<bool> vis;
vector<int> dis;
vector<Edge> G[1020];

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.emplace(0, s);
    while (!pq.empty()) {
        auto pair = pq.top();
        pq.pop();
        int cur = pair.second;
        if (vis[cur]) { // 注意有环
            continue;
        }
        vis[cur] = true;
        for (int j = 0; j < G[cur].size(); ++j) {
            Edge edge = G[cur][j];
            if (!vis[edge.node]) {
                if (edge.weight + dis[cur] < dis[edge.node]) {
                    dis[edge.node] = edge.weight + dis[cur];
                    pq.emplace(dis[edge.node], edge.node);
                }
            }
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N >> M >> K >> Ds;
    string str_p1, str_p2;
    int p1, p2;
    unordered_map<string, int> gas_map;
    int gas_no = N + 1;
    for (int i = 1; i <= M; ++i) {
        gas_map["G" + to_string(i)] = gas_no++;
    }

    for (int i = 0; i < K; ++i) {
        cin >> str_p1 >> str_p2 >> d;
        if (str_p1[0] == 'G') {
            p1 = gas_map[str_p1];
        } else {
            p1 = atoi(str_p1.c_str());
        }

        if (str_p2[0] == 'G') {
            p2 = gas_map[str_p2];
        } else {
            p2 = atoi(str_p2.c_str());
        }

        G[p1].push_back(Edge{p2, d});
        G[p2].push_back(Edge{p1, d});
    }

    vector<double> min_dis(N + M + 1, INF), avg_dis(N + M + 1, 0);
    for (int i = N + 1; i <= N + M; ++i) {
        vis = vector<bool>(N + M + 1, false);
        dis = vector<int>(N + M + 1, INF);
        dis[i] = 0;
        dijkstra(i);
        double total_dis = 0;
        for (int j = 1; j <= N; ++j) {
            if (dis[j] < min_dis[i]) {
                min_dis[i] = dis[j];
            }
            if (dis[j] > Ds) {
                min_dis[i] = INF;
                break;
            }
            total_dis += dis[j];
        }
        avg_dis[i] = total_dis / N;
    }

    int ans_index = -1;
    double mmin_dis = -1, mmin_avg = INF;
    for (int i = N + 1; i <= N + M; ++i) {
        if (min_dis[i] != INF && min_dis[i] > mmin_dis) {
            mmin_dis = min_dis[i];
            mmin_avg = avg_dis[i];
            ans_index = i;
        } else if (min_dis[i] == mmin_dis) {
            if (avg_dis[i] < mmin_avg) {
                mmin_avg = avg_dis[i];
                ans_index = i;
            }
        }
    }

    if(ans_index == -1) {
        cout<<"No Solution"<<endl;
    } else {
        cout << gasName(ans_index) << endl;
        printf("%.1f %.1f\n", min_dis[ans_index], avg_dis[ans_index]);
    }
    return 0;
}
