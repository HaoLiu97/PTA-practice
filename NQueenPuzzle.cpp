
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, K, t;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> N;
        vector<int> chess(N);
        bool flag = true;
        for (int j = 0; j < N; ++j) {
            cin >> chess[j];
            for (int k = 0; k < j; ++k) {
                if (chess[k] == chess[j] || chess[k] + j - k == chess[j] || chess[k] - j + k == chess[j]) {
                    flag = false;
                }
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
