#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, K, t, s1, s2;
    cin>>N;
    vector<set<int>> sets(N+1);
    for(int i = 1; i <= N; ++i) {
        cin>>M;
        for(int j = 0; j < M; ++j) {
            cin>>t;
            sets[i].insert(t);
        }
    }

    set<int> s;
    cin>>K;
    for(int i = 0; i < K; ++i) {
        cin>>s1>>s2;
        s.clear();
        set_intersection(sets[s1].begin(), sets[s1].end(), sets[s2].begin(), sets[s2].end(), inserter(s, s.begin()));
        printf("%.1f%%\n", (double)s.size()*100 / (sets[s1].size() + sets[s2].size() - s.size()));
    }

    return 0;
}
