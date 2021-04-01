#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main() {
    ull N;
    cin >> N;
    int first = 0, len = 0, maxn = sqrt(N) + 1;

    for (int i = 2; i < maxn; ++i) {

        int j = i, t = 1;
        for (; j <= maxn; ++j) {
            t = t * j;
            if (N % t != 0) {
                break;
            }
        }

        if (j - i > len) {
            first = i;
            len = j - i;
        }
    }

    if (first == 0) {
        cout << 1 << endl << N << endl;
    } else {
        cout << len << endl;
        for (int i = 0; i < len; ++i) {
            cout << first + i;
            if (i != len - 1) {
                cout << "*";
            }
        }
        cout << endl;
    }

    return 0;
}
