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

Node* reverseLinkedList(Node* head) {
    if(!head|| !head->next) {
        return head;
    }

    Node *p = head, *p2;
    while(p->next) {
        p2 = p;
        p = p->next;
    }
    p2->next = nullptr;
    p->next = reverseLinkedList(head);
    return p;
}

Node* reverseLinkedList(Node* head, int K) {
    if(!head|| !head->next || K <= 1) {
        return head;
    }

    int i = 1;
    Node *p = head, *new_head, *next_head;
    while(p->next && i < K) {
        p = p->next;
        ++i;
    }
    if(i != K) {
        return head;
    }
    next_head = reverseLinkedList(p->next, K);
    p->next = nullptr;
    new_head = reverseLinkedList(head);
    head->next = next_head; // head现在变tail
    return new_head;
}

int main() {
    ios::sync_with_stdio(false);
    int N, K, val;
    string start, address, next_address;
    unordered_map<string, Node *> u_map;
    u_map["-1"] = nullptr;
    cin >> start >> N >> K;
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

    Node* head = reverseLinkedList(u_map[start], K);
    while(head) {
        cout<<head->address<<" "<<head->val<<" ";
        if(head->next) {
            cout<<head->next->address<<endl;
        } else {
            cout << -1 <<endl;
        }
        head = head->next;
    }

    return 0;
}
