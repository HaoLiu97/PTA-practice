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
    int M, N;
    cin >> M >> N;
    while (!isPrime(M)) {
        ++M;
    }

    vector<int> hash(M, -1);
    int t;
    while (N--) {
        cin >> t;
        int step = 0;
        while (step <= M - 1 && hash[(t + step * step) % M] != -1) {
            ++step;
        }
        if (step <= M - 1) {
            hash[(t + step * step) % M] = t;
            cout<<(t + step * step) % M;
        } else {
            cout<<"-";
        }
        if(N != 0) {
            cout<<" ";
        }
    }

    return 0;
}
