#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    vector<int> v(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> v[i];
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = i + 1; j <= N; ++j) {
            vector<int> lie, isGood(N + 1, 1);
            isGood[i] = isGood[j] = -1;
            for (int k = 1; k <= N; ++k) {
                if (v[k] * isGood[abs(v[k])] < 0) {
                    lie.push_back(k);
                }
            }
            if (lie.size() == 2 && isGood[lie[0]] + isGood[lie[1]] == 0) {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    cout << "No Solution" << endl;

    return 0;
}
