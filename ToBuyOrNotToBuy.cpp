#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    string beam1, beam2;
    cin>>beam1>>beam2;
    unordered_map<char, int> u_map;

    for(int i = 0; i < beam2.length(); ++i) {
        u_map[beam2[i]] ++;
    }

    for(int i = 0; i < beam1.length(); ++i) {
        if(u_map[beam1[i]] > 0) {
            u_map[beam1[i]] --;
        }
    }

    bool flag = false;
    int cnt = 0;
    for(auto iter:u_map) {
        if(iter.second != 0) {
            flag = true;
            cnt += iter.second;
        }
    }

    if(!flag) {
        cout<<"Yes "<<beam1.length() - beam2.length()<<endl;
    } else {
        cout<<"No "<<cnt<<endl;
    }

    return 0;
}
