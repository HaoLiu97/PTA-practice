#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    int M, N, S;
    cin>>M>>N>>S;
    unordered_map<string, int> winner;
    string t;
    for(int i = 1; i <= M; ++i) {
        cin>>t;
        if(i >= S && (i - S) % N == 0) {
            if(winner[t]) {
                S ++;
            } else {
                cout<<t<<endl;
                winner[t] = 1;
            }
        }
    }

    if(S > M) {
        cout<<"Keep going..."<<endl;
        return 0;
    }

    return 0;
}
