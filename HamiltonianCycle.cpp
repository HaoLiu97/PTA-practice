#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, K, n, t1, t2;
    cin >> N >> M;
    vector<int> G[N+1];
    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2;
        G[t1].push_back(t2);
        G[t2].push_back(t1);
    }

    cin>>K;
    for(int i = 0; i < K; ++i) {
        cin>>n;
        vector<int> path(n);
        bool flag = true;
        unordered_map<int, int> path_map;
        for(int j = 0; j < n; ++j) {
            cin>>path[j];
            path_map[path[j]] ++;
            if(path_map[path[j]] >= 2 && j != n-1) {
                flag = false;
            }
            if(j >= 1 && find(G[path[j-1]].begin(), G[path[j-1]].end(), path[j]) == G[path[j-1]].end()) {
                flag = false;
            }
        }
        if(n != N + 1 || path[0] != path[n-1] || !flag) {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl;
    }

    return 0;
}
