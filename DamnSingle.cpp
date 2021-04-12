#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, t1, t2;
    cin >> N;
    unordered_map<int, int> u_map;
    for (int i = 0; i < N; ++i) {
        cin >> t1 >> t2;
        u_map[t1] = t2;
        u_map[t2] = t1;
    }
    cin >> M;
    set<int> Set, SetSingle;
    for(int i = 0; i < M; ++i) {
        cin>>t1;
        Set.insert(t1);
    }

    for(auto iter:Set) {
        if(u_map.find(iter) == u_map.end()) {
            SetSingle.insert(iter);
        } else if(Set.find(u_map[iter]) == Set.end()) {
            SetSingle.insert(iter);
        }
    }

    cout<<SetSingle.size()<<endl;
    for(auto iter = SetSingle.begin(); iter != SetSingle.end(); ++iter) {
        printf("%05d", *iter);
        if(iter != (--SetSingle.end())) {
            printf(" ");
        }
    }

    return 0;
}
