#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int N, M;
    ll t;
    vector<ll> S1, S2;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        S1.push_back(t);
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> t;
        S2.push_back(t);
    }

    ll mid = (N + M - 1) / 2;
    ll p1 = 0, p2 = 0;
    ll no = -1;
    ll cur = 0;

    if (S1.empty()) {
        cur = S2[0];
    } else if (S2.empty()) {
        cur = S1[0];
    }

    while (no < mid) {
        if (p1 < S1.size() && (p2 >= S2.size() || S1[p1] <= S2[p2])) {
            cur = S1[p1];
            p1++;
        } else {
            cur = S2[p2];
            p2++;
        }
        no++;
    }

    cout << cur << endl;

    return 0;
}
