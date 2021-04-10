#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc) {
        cout << "Case #" << tc << ": ";
        ll a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        ll sum = a + b;
        if (a > 0 && b > 0 && sum < 0) {
            cout << "true" << endl;
        } else if (a < 0 && b < 0 && sum >= 0) {
            cout << "false" << endl;
        } else {
            if (sum > c) {
                cout << "true" << endl;
            } else {
                cout << "false" << endl;
            }
        }
    }
    return 0;
}
