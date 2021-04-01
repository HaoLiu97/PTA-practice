#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    int N, t;
    cin >> N;
    vector<int> num;
    unordered_map<int, int> u_map;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        num.push_back(t);
        u_map[t]++;
    }

    for (int i = 0; i < N; ++i) {
        if(u_map[num[i]] == 1) {
            cout<<num[i]<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;

    return 0;
}
