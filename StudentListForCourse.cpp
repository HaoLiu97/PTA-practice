#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, K, C, t;
    scanf("%d %d", &N, &K);
    char name[100];
    vector<vector<string>> u_map(K + 1);

    for (int i = 0; i < N; ++i) {
        scanf("%s %d", name, &C);
        for (int j = 0; j < C; ++j) {
            cin >> t;
            u_map[t].push_back(name);
        }
    }

    for (int i = 1; i <= K; ++i) {
        sort(u_map[i].begin(), u_map[i].end(), [](string &a, string &b) -> bool {
            return a < b;
        });
        printf("%d %d\n", i, u_map[i].size());
        for (string &name:u_map[i]) {
            printf("%s\n", name.c_str());
        }
    }

    return 0;
}
