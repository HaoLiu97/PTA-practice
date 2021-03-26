#include <bits/stdc++.h>

using namespace std;

struct Node {
    string address;
    int val;
    Node *next;

    Node(string& a, int v) {
        address = a;
        val = v;
        next = nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int N, val;
    string start, address, next_address;
    unordered_map<string, Node *> u_map;
    u_map["-1"] = nullptr;
    vector<Node *> v;
    cin >> N >> start;
    for (int i = 0; i < N; ++i) {
        cin >> address >> val >> next_address;
        if (!u_map[address]) {
            u_map[address] = new Node(address, val);
        } else {
            u_map[address]->val = val;
        }

        if (!u_map[next_address] && next_address != "-1") {
            u_map[next_address] = new Node(next_address, 0);
        }
        u_map[address]->next = u_map[next_address];
    }

    Node *s = u_map[start];
    if (s == nullptr) {
        cout << "0 -1"<< endl;
        return 0;
    }

    while (s != nullptr) {
        v.push_back(s);
        s = s->next;
    }

    sort(v.begin(), v.end(), [](Node *a, Node *b) -> bool {
        return a->val < b->val;
    });

    cout << v.size() << " " << v[0]->address << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i]->address << " " << v[i]->val << " ";
        if (i == v.size() - 1) {
            cout << -1 << endl;
        } else {
            cout << v[i+1]->address <<endl;
        }
    }

    return 0;
}
