#include <bits/stdc++.h>

using namespace std;

#define MAXN 1005

struct Edge {
    string name;
    int weight;
};

unordered_map<string, vector<Edge>> Adj;
unordered_map<string, bool> vis;
vector<vector<string>> names;
int group_no = -1;

void dfs(string name) {
    vis[name] = true;
    names[group_no].push_back(name);
    for (const auto &neighbor : Adj[name]) {
        if (!vis[neighbor.name]) {
            dfs(neighbor.name);
        }
    }
}

int main() {
    int N, K;
    cin >> N >> K;

    string name1, name2;
    int w;
    for (int i = 0; i < N; ++i) {
        cin >> name1 >> name2 >> w;
        Adj[name1].push_back(Edge{name2, w});
        Adj[name2].push_back(Edge{name1, w});
    }

    for (auto iter = Adj.begin(); iter != Adj.end(); ++iter) {
        if (!vis[iter->first]) {
            names.emplace_back();
            ++group_no;
            dfs(iter->first);
        }
    }

    vector<pair<string, int>> ans;
    int gang_cnt = 0;
    for (int i = 0; i < names.size(); ++i) {
        if (names[i].size() >= 3) {
            int weight = 0, cur_people_weight;
            int max_people_weight = 0, index;
            for (int j = 0; j < names[i].size(); ++j) {
                cur_people_weight = 0;
                for (int k = 0; k < Adj[names[i][j]].size(); ++k) {
                    weight += Adj[names[i][j]][k].weight;
                    cur_people_weight += Adj[names[i][j]][k].weight;
                }
                if(cur_people_weight > max_people_weight) {
                    max_people_weight = cur_people_weight;
                    index = j;
                }
            }
            if (weight > 2*K) {
                ++gang_cnt;
                ans.emplace_back(names[i][index], names[i].size());
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << gang_cnt<<endl;
    for(auto & an : ans) {
        cout<<an.first<<" "<<an.second<<endl;
    }

    return 0;
}
