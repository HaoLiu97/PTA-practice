#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int N, t = 0;
int level[1005];
vector<int> vals;

void inOrder(int root) {
    if (root >= N) return;
    inOrder(root * 2 + 1);
    level[root] = vals[t++];
    inOrder(root * 2 + 2);
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N;
    if (N == 0) return 0;
    vals = vector<int>(N);
    for (int i = 0; i < N; ++i) {
        cin >> vals[i];
    }
    sort(vals.begin(), vals.end());
    inOrder(0);
    for (int i = 0; i < N; ++i) {
        cout << level[i] << " \n"[i == N - 1];
    }

    return 0;
}
