#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

string convert(int no) {
    if (no >= 1 && no <= 13) {
        return "S" + to_string(no);
    }
    if (no >= 14 && no <= 26) {
        return "H" + to_string(no - 13);
    }
    if (no >= 27 && no <= 39) {
        return "C" + to_string(no - 26);
    }
    if (no >= 40 && no <= 52) {
        return "D" + to_string(no - 39);
    }
    return "J" + to_string(no - 52);
}

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> order(55), cur(55), tmp(55);
    for(int i = 1; i <= 54; ++i) {
        cin>>order[i];
        cur[i] = i;
    }

    while(N--) {
        for(int i = 1; i <= 54; ++i) {
            tmp[order[i]] = cur[i];
        }
        cur = tmp;
    }

    for(int i = 1; i <= 54; ++i) {
        cout<<convert(cur[i])<<" \n"[i==54];
    }

    return 0;
}
