#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    string o_str, t_str;
    cin >> o_str >> t_str;

    unordered_map<char, int> u_map;
    for (char &c:t_str) {
        u_map[toupper(c)] = 1;
    }

    for (char &c:o_str) {
        if (u_map[toupper(c)] != 1) {
            cout << (char)toupper(c);
            u_map[toupper(c)] = 1;
        }
    }

    cout<<endl;

    return 0;
}
