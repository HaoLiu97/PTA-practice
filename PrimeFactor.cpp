#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    ull N, origin_N;
    cin >> N;
    if(N == 1) {
        cout<<"1=1"<<endl;
        return 0;
    }
    origin_N = N;
    vector<pair<ull, ull>> factors;
    for (int i = 2; i * i <= N; ++i) {
        int cnt = 0;
        while (N % i == 0) {
            N = N / i;
            cnt++;
        }
        if (cnt >= 1) {
            factors.emplace_back(i, cnt);
        }
    }

    if(N!=1) {
        factors.emplace_back(N, 1);
    }
    cout << origin_N << "=";
    for (int i = 0; i < factors.size(); ++i) {
        cout<<factors[i].first;
        if(factors[i].second>=2) {
            cout<<"^"<<factors[i].second;
        }
        if(i != factors.size()-1) {
            cout<<"*";
        }
    }

    return 0;
}
