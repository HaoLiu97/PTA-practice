#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, L, t;
    cin>>N;
    unordered_map<int, int> u_map;
    int cnt = 0;
    cin>>M;
    for(int i = 0; i < M; ++i) {
        cin>>t;
        u_map[t] = ++cnt;
    }
    cin>>L;
    vector<int> stripes;
    for(int i = 0; i < L; ++i) {
        cin>>t;
        if(u_map[t]) {
            stripes.push_back(u_map[t]);
        }
    }

    if(stripes.empty()) {
        cout<<0<<endl;
        return 0;
    }

    int len = 1, n = stripes.size();
    vector<int> dp(n, 0);
    for(int i = 0; i < n; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (stripes[j] <= stripes[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    cout<<*max_element(dp.begin(), dp.end())<<endl;

    return 0;
}
