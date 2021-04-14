#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    string cur, next;
    int N;
    cin >> cur >> N;
    for (int i = 0; i < N - 1; ++i) {
        int j = 0;
        next = "";
        while (j < cur.length()) {
            next += cur[j];
            int cnt = 1;
            while (cur[j + cnt] == cur[j]) {
                ++cnt;
            }
            next += char('0' + cnt);
            j += cnt;
        }
        cur = next;
    }
    cout << cur << endl;

    return 0;
}
