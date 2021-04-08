#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
unordered_map<char, char> u_map{{'1', '@'},
                                {'0', '%'},
                                {'l', 'L'},
                                {'O', 'o'}};

bool modify(string &password) {
    bool flag = false;
    for (char &c : password) {
        if (u_map[c]) {
            c = u_map[c];
            flag = true;
        }
    }
    return flag;
}

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    string user_name, password;
    vector<pair<string, string>> records;
    for (int i = 0; i < N; ++i) {
        cin >> user_name >> password;
        if (modify(password)) {
            records.emplace_back(user_name, password);
        }
    }

    if (records.empty()) {
        if (N == 1) {
            printf("There is 1 account and no account is modified\n");
        } else {
            printf("There are %d accounts and no account is modified", N);
        }
    } else {
        cout << records.size() << endl;
        for (auto &p:records) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
