#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;


int main() {
    freopen("in.txt", "r", stdin);
    int N, digit;
    cin >> N;
    ull Z, z1, z2;
    for (int i = 0; i < N; ++i) {
        cin >> Z;
        string z = to_string(Z);
        digit = z.length();
        z1 = stoull(z.substr(0, digit / 2));
        z2 = stoull(z.substr(digit / 2));
        z1 = z1 * z2;
        if (z1 != 0 && Z % z1 == 0) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
