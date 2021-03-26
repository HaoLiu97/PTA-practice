#include<bits/stdc++.h>

using namespace std;

struct Node {
    vector<int> sons;
};

Node nodes[1000];
int ans[1000];
int max_depth = -1;

void dfs(int index, int depth) {
    if (nodes[index].sons.empty()) {
        ans[depth]++;
        max_depth = max(max_depth, depth);
        return;
    }
    for (auto son: nodes[index].sons) {
        dfs(son, depth + 1);
    }
}

void bfs() {
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        max_depth++;
        int size = q.size();
        while (size--) {
            int cur = q.front();
            q.pop();
            if (nodes[cur].sons.empty()) {
                ans[max_depth]++;
            } else {
                for (int son:nodes[cur].sons) {
                    q.push(son);
                }
            }
        }
    }
}

int main() {
    int N, M, K, ID;
    scanf("%d %d", &N, &M);
    if (N == 0) {
        return 0;
    }

    for (int i = 0; i < M; ++i) {
        int id;
        scanf("%d %d", &ID, &K);
        for (int j = 0; j < K; ++j) {
            scanf("%d", &id);
            nodes[ID].sons.push_back(id);
        }
    }

    //dfs(1, 0);
    bfs();

    for (int i = 0; i <= max_depth; ++i) {
        printf("%d", ans[i]);
        if (i != max_depth) {
            printf(" ");
        }
    }

    return 0;
}
