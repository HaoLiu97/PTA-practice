#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    int no, cnt;

    Node(int n, int c) {
        no = n;
        cnt = c;
    }

    bool operator<(const Node &b) const {
        if (cnt == b.cnt) {
            return no < b.no;
        }
        return cnt > b.cnt;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, K, t;
    cin >> N >> K;
    set<Node> Set;
    unordered_map<int, int> u_map;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        if (i == 0) {
            Set.insert(Node(t, 1));
            u_map[t]++;
        } else {
            int cnt = 1;
            cout << t << ": ";
            auto iter = Set.begin();
            cout << iter->no;
            ++iter;
            for (; iter != Set.end() && cnt < K; ++iter) {
                cout << " " << iter->no;
                ++cnt;
            }
            cout << endl;
            iter = Set.find(Node{t, u_map[t]});
            if (iter != Set.end()) {
                Set.erase(iter);
            }
            u_map[t]++;
            Set.insert(Node(t, u_map[t]));
        }
    }


    return 0;
}
