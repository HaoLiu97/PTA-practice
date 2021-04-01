#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    int N, M, t;
    cin>>N>>M;
    vector<int> coins;

    int min_V1 = INF;
    unordered_map<int, int> u_map;

    for(int i = 0; i < N; ++i) {
        cin>>t;
        u_map[t] ++;
        if(u_map[M-t]) {
            if(M-t==t&&u_map[t] <= 1) {
                continue;
            }
            min_V1 = min(min_V1, min(t, M-t));
        }
    }

    if(min_V1 == INF) {
        cout<<"No Solution"<<endl;
    } else {
        cout<<min_V1<< " "<<M-min_V1;
    }

    return 0;
}
