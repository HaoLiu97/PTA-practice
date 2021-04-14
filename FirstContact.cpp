#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

int main() {
    int N, M, a, b;
    string aa, bb;
    cin >> N >> M;
    unordered_map<int, vector<int>> G;
    unordered_map<int, vector<int>> G2;
    for (int i = 0; i < M; ++i) {
        cin >> aa >> bb;
        a = stoi(aa);
        b = stoi(bb);
        if (aa.length() == bb.length()) { // 同性
            G[a].push_back(b);
            G[b].push_back(a);
        } else {
            G2[a].push_back(b);
            G2[b].push_back(a);
        }
    }

    int K;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> aa >> bb;
        a = stoi(aa);
        b = stoi(bb);
        set<int> a_friends, b_friends;
        for (int j = 0; j < G[a].size(); ++j) {
            if (G[a][j] != b) {
                a_friends.insert(G[a][j]);
            }
        }
        for (int j = 0; j < G[b].size(); ++j) {
            if (G[b][j] != a) {
                b_friends.insert(G[b][j]);
            }
        }
        vector<pii> ans;

        auto &curG = (aa.length() == bb.length()) ? G : G2;

        for (auto iter = a_friends.begin(); iter != a_friends.end(); ++iter) {
            for (int j = 0; j < curG[*iter].size(); ++j) {
                if (b_friends.find(curG[*iter][j]) != b_friends.end()) {
                    ans.emplace_back(*iter, curG[*iter][j]);
                }
            }
        }

        sort(ans.begin(), ans.end(), [](pii &a, pii &b) {
            if (abs(a.first) == abs(b.first)) {
                return abs(a.second) < abs(b.second);
            }
            return abs(a.first) < abs(b.first);
        });

        cout << ans.size() << endl;
        for (pii &a:ans) {
            printf("%04d %04d\n", abs(a.first), abs(a.second));
        }
    }

    return 0;
}
