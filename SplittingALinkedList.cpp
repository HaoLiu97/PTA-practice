#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    int data, address, next;

    Node(int d, int a, int n) {
        data = d;
        address = a;
        next = n;
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int head, N, K, address, data, next;
    cin >> head >> N >> K;
    unordered_map<int, Node *> u_map;
    for (int i = 0; i < N; ++i) {
        cin >> address >> data >> next;
        u_map[address] = new Node{data, address, next};
    }

    vector<Node *> va, vb, vc;
    int p = head;
    while (p != -1) {
        if (u_map[p]->data < 0) {
            va.push_back(u_map[p]);
        } else if (u_map[p]->data >= 0 && u_map[p]->data <= K) {
            vb.push_back(u_map[p]);
        } else {
            vc.push_back(u_map[p]);
        }
        p = u_map[p]->next;
    }

    va.insert(va.end(), vb.begin(), vb.end());
    va.insert(va.end(), vc.begin(), vc.end());

    for (int i = 0; i < va.size(); ++i) {
        printf("%05d %d ", va[i]->address, va[i]->data);
        if (i != va.size() - 1) {
            printf("%05d\n", va[i + 1]->address);
        } else {
            printf("-1\n");
        }
    }


    return 0;
}
