#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

using namespace std;

int main() {
    map<int, bool> mp;
    int m, n, u, v, a;
    scanf("%d %d", &m, &n);
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &pre[i]);
        mp[pre[i]] = true;
    }
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        if (!mp[u] && !mp[v]) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        } else if (!mp[u] || !mp[v]) {
            printf("ERROR: %d is not found.\n", !mp[u] ? u : v);
        } else {
            int big = max(u, v), small = min(u, v);
            for (int j = 0; j < n; j++) {
                a = pre[j];
                if (pre[j] <= big && pre[j] >= small) break;
            }
            if (a == u || a == v) {
                printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
            } else {
                printf("LCA of %d and %d is %d.\n", u, v, a);
            }
        }
    }
    return 0;
}