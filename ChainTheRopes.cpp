#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> ropes(N);
    for(int i = 0; i < N; ++i) {
        cin>>ropes[i];
    }
    sort(ropes.begin(), ropes.end());
    int length = 0;
    length = ropes[0];
    for(int i = 1; i < N; ++i) {
        length = (length + ropes[i]) / 2;
    }
    cout<<length<<endl;

    return 0;
}
