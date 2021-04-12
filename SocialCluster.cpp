#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int Father[1001], Rank[1001];

int find(int x) {
    if (Father[x] == x) {
        return x;
    }
    return Father[x] = find(Father[x]);
}

void setUnion(int setA, int setB) {
    if (Rank[setA] < Rank[setB]) {
        Father[setA] = setB;
    } else if (Rank[setA] > Rank[setB]) {
        Father[setB] = setA;
    } else {
        Father[setB] = setA;
        Rank[setA]++;
    }
}

int main() {
    int N, K, t;
    vector<int> hobby(1001, -1);
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        Father[i] = i;
        Rank[i] = 0;
    }

    vector<int> Si(N + 1, 0);

    for (int i = 1; i <= N; ++i) {
        scanf("%d: ", &K);
        for (int j = 0; j < K; ++j) {
            cin >> t;
            if (hobby[t] == -1) {
                hobby[t] = i;
            } else {
                int fa = find(hobby[t]);
                int fb = find(i);
                if (fa != fb) {
                    setUnion(fa, fb);
                }
            }
        }
    }

    int cnt = 1;
    for (int i = 1; i <= N; ++i) {
        Si[find(i)]++;
    }

    sort(Si.begin() + 1, Si.end(), greater<int>());
    while (Si[cnt] != 0) {
        ++cnt;
    }
    --cnt;
    cout << cnt << endl;
    for (int i = 1; i <= cnt; ++i) {
        cout << Si[i] << " \n"[i == cnt];
    }

    return 0;
}
