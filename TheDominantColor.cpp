#include <bits/stdc++.h>

using namespace std;

int main() {
    int M, N, t;
    cin>>M>>N;
    unordered_map<int, int> u_map;
    int max_cnt = 0, color;
    for(int i = 0; i < M; ++i) {
        for(int j = 0; j < N; ++j) {
            cin>>t;
            u_map[t]++;
            if(u_map[t] > max_cnt) {
                max_cnt = u_map[t];
                color = t;
            }
        }
    }

    cout<<color<<endl;

    return 0;
}
