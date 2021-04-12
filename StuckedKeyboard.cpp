#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int k;
    string str;
    cin >> k >> str;
    unordered_map<char, int> u_map;
    int cnt = 1;
    for (int i = 1; i < str.length(); ++i) {
        if (str[i] == str[i - 1]) {
            cnt++;
        } else {
            if (cnt % k != 0) {
                u_map[str[i - 1]] = 1; // 不stuck
            } else if (u_map[str[i-1]] != 1) {
                u_map[str[i - 1]] = 2; // stuck
            }
            cnt = 1;
        }
    }

    if (str.length() >= 1) {
        if (cnt % k != 0) {
            u_map[str[str.length() - 1]] = 1; // 不stuck
        } else if (u_map[str[str.length() - 1]] != 1) {
            u_map[str[str.length() - 1]] = 2; // stuck
        }
    }

    set<char> set;
    for (int i = 0; i < str.length(); ++i) {
        if(u_map[str[i]] == 2) {
            cout<<str[i];
            u_map[str[i]] = 0;
            set.insert(str[i]);
        }
    }

    cout << endl;

    for (int i = 0; i < str.length();) {
        auto iter = set.find(str[i]);
        if (iter == set.end()) {
            cout << str[i++];
        } else {
            cout << str[i];
            i = i + k;
        }
    }

    return 0;
}
