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
    int L, K;
    cin >> L >> K;
    string num;
    cin >> num;
    for (int i = 0; i <= L - K; ++i) {
        string cur = num.substr(i, K);
        if(isPrime(stoi(cur))) {
            cout<<cur<<endl;
            return 0;
        }
    }
    cout<<404<<endl;

    return 0;
}
