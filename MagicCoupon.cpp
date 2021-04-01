#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;

int main() {
    int Nc, Np;
    vector<ll> c_pos, p_pos, c_neg, p_neg;
    ll t;

    cin >> Nc;
    for (int i = 0; i < Nc; ++i) {
        cin >> t;
        if (t > 0) {
            c_pos.push_back(t);
        } else if (t < 0) {
            c_neg.push_back(t);
        }
    }

    cin >> Np;
    for (int i = 0; i < Np; ++i) {
        cin >> t;
        if (t > 0) {
            p_pos.push_back(t);
        } else if (t < 0) {
            p_neg.push_back(t);
        }
    };

    sort(c_pos.begin(), c_pos.end(), [](ll &a, ll &b) -> bool {
        return a > b;
    });

    sort(c_neg.begin(), c_neg.end(), [](ll &a, ll &b) -> bool {
        return a < b;
    });

    sort(p_pos.begin(), p_pos.end(), [](ll &a, ll &b)->bool{
        return a > b;
    });

    sort(p_neg.begin(), p_neg.end(), [](ll &a, ll &b)->bool{
        return a < b;
    });

    ull ans = 0;
    for(int i = 0; i < min(c_pos.size(), p_pos.size()); ++i) {
        ans += c_pos[i]*p_pos[i];
    }

    for(int i = 0; i < min(c_neg.size(), p_neg.size()); ++i) {
        ans += c_neg[i]*p_neg[i];
    }

    cout<<ans<<endl;

    return 0;
}
