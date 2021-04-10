#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    string id;
    int virtue, talent;
};

int main() {
    freopen("in.txt", "r", stdin);
    string id;
    int N, L, H, v, t;
    cin >> N >> L >> H;
    vector<Node> sagas, noblemen, foolmen, others;
    for (int i = 0; i < N; ++i) {
        cin >> id >> v >> t;
        if (v >= L && t >= L) {
            if (v >= H && t >= H) {
                sagas.push_back(Node{id, v, t});
            } else if (v >= H && t < H) {
                noblemen.push_back(Node{id, v, t});
            } else if (v >= t) {
                foolmen.push_back(Node{id, v, t});
            } else {
                others.push_back(Node{id, v, t});
            }
        }
    }
    auto cmp = [](Node &a, Node &b) -> bool {
        if (a.talent + a.virtue == b.talent + b.virtue) {
            if (a.virtue == b.virtue) {
                return a.id < b.id;
            }
            return a.virtue > b.virtue;
        }
        return a.talent + a.virtue > b.talent + b.virtue;
    };

    sort(sagas.begin(), sagas.end(), cmp);
    sort(noblemen.begin(), noblemen.end(), cmp);
    sort(foolmen.begin(), foolmen.end(), cmp);
    sort(others.begin(), others.end(), cmp);

    cout << sagas.size() + noblemen.size() + foolmen.size() + others.size() << endl;
    for (auto &node:sagas) {
        cout << node.id << " " << node.virtue << " " << node.talent << endl;
    }
    for (auto &node:noblemen) {
        cout << node.id << " " << node.virtue << " " << node.talent << endl;
    }
    for (auto &node:foolmen) {
        cout << node.id << " " << node.virtue << " " << node.talent << endl;
    }
    for (auto &node:others) {
        cout << node.id << " " << node.virtue << " " << node.talent << endl;
    }

    return 0;
}
