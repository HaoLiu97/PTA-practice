#include <bits/stdc++.h>

using namespace std;

#define MAXN 10005

vector<int> Graph[MAXN];
bool vis[MAXN];
int components_cnt = 0;
int max_height = 0;
vector<int> t_ans;

void dfs(int node, int height) {
    vis[node] = true;
    if (height > max_height) {
        max_height = height;
        t_ans.clear();
        t_ans.push_back(node);
    } else if (max_height == height) {
        t_ans.push_back(node);
    }

    for (int n:Graph[node]) {
        if (!vis[n]) {
            dfs(n, height + 1);
        }
    }
}

int main() {
    int N;
    cin >> N;
    int node1, node2;
    for (int i = 0; i < N - 1; ++i) {
        cin >> node1 >> node2;
        Graph[node1].push_back(node2);
        Graph[node2].push_back(node1);
    }

    for (int i = 1; i <= N; ++i) {
        if (!vis[i]) {
            dfs(i, 0);
            components_cnt++;
        }
    }

    if (components_cnt != 1) {
        printf("Error: %d components", components_cnt);
    } else {
        vector<int> ans = t_ans;

        t_ans.clear();
        max_height = 0;
        fill(vis, vis + MAXN, false);

        dfs(ans[0], 0);
        ans.insert(ans.end(), t_ans.begin(), t_ans.end());
        sort(ans.begin(), ans.end());

        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            if (ans[i - 1] != ans[i]) {
                cout << endl << ans[i];
            }
        }
        cout<<endl;
    }

    return 0;
}
