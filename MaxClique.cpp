#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int Nv, Ne, v1, v2;
    cin >> Nv >> Ne;
    set<int> G[Nv + 1];

    for (int i = 0; i < Ne; ++i) {
        cin >> v1 >> v2;
        G[v1].insert(v2);
        G[v2].insert(v1);
    }

    int M, K;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> K;
        vector<int> vs(K);
        bool flag = true;
        set<int> tmp_set, tmp_set2;
        for (int j = 0; j < K; ++j) {
            cin >> vs[j];
            if (flag) {
                tmp_set2.clear();
                set_difference(tmp_set.begin(), tmp_set.end(), G[vs[j]].begin(), G[vs[j]].end(),
                               insert_iterator<set<int>>(tmp_set2, tmp_set2.begin()));
                if (!tmp_set2.empty()) {
                    flag = false;
                }
            }
            tmp_set.insert(vs[j]);
        }

        if (flag) {
            bool flag2 = true;
            for (int j = 1; j <= Nv; ++j) {
                if (tmp_set.find(j) == tmp_set.end()) {
                    tmp_set2.clear();
                    set_difference(tmp_set.begin(), tmp_set.end(), G[j].begin(), G[j].end(),
                                   insert_iterator<set<int>>(tmp_set2, tmp_set2.begin()));
                    if (tmp_set2.empty()) {
                        flag2 = false;
                    }
                }
            }
            if (flag2) {
                cout << "Yes" << endl;
            } else {
                cout << "Not Maximal" << endl;
            }
        } else {
            cout << "Not a Clique" << endl;
        }
    }

    return 0;
}
