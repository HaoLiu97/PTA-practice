#include <bits/stdc++.h>

using namespace std;

int main() {
    int k, N;
    double a;
    map<int, double> mp;
    int cnt = 2;
    while (cnt--) {
        cin >> k;
        for (int i = 0; i < k; ++i) {
            cin >> N >> a;
            mp[N] += a;
        }
    }

    vector<pair<int, double>> v_mp;
    v_mp.reserve(mp.size());

    for (auto iter:mp) {
        if (iter.second != 0) {
            v_mp.emplace_back(iter.first, iter.second);
        }
    }

    sort(v_mp.begin(), v_mp.end(), [](const pair<int, double> &p1, const pair<int, double> &p2) -> bool {
        return p1.first > p2.first;
    });

    cout << v_mp.size();
    if (!v_mp.empty()) {
        printf(" ");
    }

    for (auto iter = v_mp.begin(); iter != v_mp.end();) {
        printf("%d %.1lf", iter->first, iter->second);
        if ((++iter) != v_mp.end()) {
            printf(" ");
        }
    }

    return 0;
}
