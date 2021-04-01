#include <bits/stdc++.h>

using namespace std;

struct Node {
    string address;
    int val;
    string next_address;

    Node(string a, int v, string na) {
        address = a;
        val = v;
        next_address = na;
    }
};

int main() {
    vector<Node *> removed;
    vector<Node *> ans;

    int N, val;
    string start, address, next_address;
    unordered_map<string, Node *> u_map;

    cin >> start >> N;

    u_map["-1"] = nullptr;
    for (int i = 0; i < N; ++i) {
        cin >> address >> val >> next_address;
        u_map[address] = new Node(address, val, next_address);
    }

    unordered_map<int, int> u_set;
    Node *head = u_map[start];
    while (head != nullptr) {
        if (!u_set[abs(head->val)]) {
            u_set[abs(head->val)] = 1;
            ans.push_back(head);
        } else {
            removed.push_back(head);
        }
        head = u_map[head->next_address];
    }

    int n = ans.size();
    for (int i = 0; i <= n - 2; ++i) {
        cout << ans[i]->address << " " << ans[i]->val << " " << ans[i + 1]->address << endl;
    }
    if (n != 0) {
        cout << ans[n - 1]->address << " " << ans[n - 1]->val << " -1" << endl;
    }

    n = removed.size();
    for (int i = 0; i <= n - 2; ++i) {
        cout << removed[i]->address << " " << removed[i]->val << " " << removed[i + 1]->address << endl;
    }
    if (n != 0) {
        cout << removed[n - 1]->address << " " << removed[n - 1]->val << " -1" << endl;
    }

    return 0;
}
