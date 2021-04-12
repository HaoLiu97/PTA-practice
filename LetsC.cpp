#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

bool isPrime(int num) {
    if (num == 0 || num == 1) {
        return false;
    }
    if (num == 2) {
        return true;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, K;
    string id;
    cin>>N;
    unordered_map<string, string> u_map;
    for(int rank = 1; rank <= N; ++rank) {
        cin>>id;
        if(rank == 1) {
            u_map[id] = "Mystery Award";
        } else if(isPrime(rank)) {
            u_map[id] = "Minion";
        } else {
            u_map[id] = "Chocolate";
        }
    }

    cin>>K;
    for(int i = 0; i < K; ++i) {
        cin>>id;
        cout<<id<<": "<<(u_map[id].empty()?"Are you kidding?":u_map[id])<<endl;
        if(!u_map[id].empty()) {
            u_map[id] = "Checked";
        }
    }

    return 0;
}
