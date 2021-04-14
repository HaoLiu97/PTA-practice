#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, t1, t2;
    cin >> N >> M;
    unordered_map<int, set<int>> table;
    for (int i = 0; i < N; ++i) {
        cin >> t1 >> t2;
        table[t1].insert(t2);
        table[t2].insert(t1);
    }

    int K;
    for (int i = 0; i < M; ++i) {
        cin >> K;
        set<int> goods;
        bool flag = true;
        for (int j = 0; j < K; ++j) {
            cin >> t1;
            if (flag) {
                set<int> tmp_set;
                set_intersection(goods.begin(), goods.end(), table[t1].begin(), table[t1].end(),
                                 insert_iterator<set<int>>(tmp_set, tmp_set.begin()));
                if(!tmp_set.empty()) {
                    flag = false;
                }
                goods.insert(t1);
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}

