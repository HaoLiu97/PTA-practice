#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;
    cin >> N;
    unordered_set<int> set;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        if (t > 0) {
            set.insert(t);
        }
    }

    int i = 1;
    while(i <= INT_MAX) {
        auto iter = set.find(i);
        if(iter == set.end()) {
            cout<<i<<endl;
            return 0;
        }
        ++i;
    }

    return 0;
}
