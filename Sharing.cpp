#include <bits/stdc++.h>

using namespace std;

struct Node {
    char c;
    string address, next_address;

    Node(char ch, string& a, string& next_a) {
        c = ch;
        address = a;
        next_address = next_a;
    }
};

int main() {
    string address0, address1;
    int N;
    cin >> address0 >> address1 >> N;

    unordered_map<string, Node *> u_map;

    string a0, a1;
    char ch;
    for (int i = 0; i < N; ++i) {
        cin >> a0 >> ch >> a1;
        Node *node = new Node(ch, a0, a1);
        u_map[a0] = node;
    }

    unordered_set<string> u_set;
    Node *s0 = u_map[address0], *s1 = u_map[address1];
    while (s0) {
        u_set.insert(s0->address);
        if(s0->next_address == "-1") {
            break;
        }
        s0 = u_map[s0->next_address];
    }

    while(s1) {
        if(u_set.find(s1->address)!=u_set.end()) {
            cout<<s1->address<<endl;
            return 0;
        }
        if(s1->next_address == "-1") {
            break;
        }
        s1 = u_map[s1->next_address];
    }

    cout<<-1<<endl;

    return 0;
}
