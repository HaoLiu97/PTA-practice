#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, K, t1, t2;
    cin >> N >> M;
    vector<pii> edges;
    for (int i = 0; i < M; ++i) {
        cin >> t1 >> t2;
        edges.emplace_back(t1, t2);
    }

    cin >> K;
    for (int i = 0; i < K; ++i) {
        vector<int> color(N);
        set<int> Set;
        for (int j = 0; j < N; ++j) {
            cin >> color[j];
            Set.insert(color[j]);
        }
        bool flag = true;
        for (auto &p:edges) {
            if (color[p.first] == color[p.second]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << Set.size() << "-coloring" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
