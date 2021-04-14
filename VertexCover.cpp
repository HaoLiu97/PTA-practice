#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

inline int getVal(int v1, int v2) {
    return (v1 << 15) | v2;
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, v1, v2;
    cin>>N>>M;
    vector<int> G[N];
    unordered_set<int> Set;
    for(int i = 0; i < M; ++i) {
        cin>>v1>>v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
        Set.insert(getVal(v1, v2));
        Set.insert(getVal(v2, v1));
    }

    int K, Nv;
    cin>>K;
    for(int i = 0; i < K; ++i) {
        unordered_set<int> cur_set = Set;
        cin>>Nv;
        int cur;
        for(int j = 0; j < Nv; ++j) {
            cin>>cur;
            for(int k = 0; k < G[cur].size(); ++k) {
                int next = G[cur][k];
                auto iter = cur_set.find(getVal(cur,next));
                if(iter != cur_set.end()) {
                    cur_set.erase(iter);
                }
                iter = cur_set.find(getVal(next, cur));
                if(iter != cur_set.end()) {
                    cur_set.erase(iter);
                }
            }
        }
        if(cur_set.empty()) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
