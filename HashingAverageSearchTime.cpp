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
    int Msize, N, M;
    cin >> Msize >> N >> M;

    while (!isPrime(Msize)) {
        ++Msize;
    }

    vector<int> hash(Msize, -1);
    int t;
    while (N--) {
        cin >> t;
        int step = 0;
        while (step <= Msize && hash[(t + step * step) % Msize] != -1) {
            ++step;
        }
        if (step <= Msize) {
            hash[(t + step * step) % Msize] = t;
        } else {
            cout << t << " cannot be inserted." << endl;
        }
    }

    int cnt = 0;
    for (int i = 0; i < M; ++i) {
        cin >> t;
        for(int step = 0; step <= Msize; ++step) {
            ++cnt;
            if(hash[(t + step * step) % Msize] == t || hash[(t + step * step) % Msize] == -1) {
                break;
            }
        }
    }

    printf("%.1f\n", (double) cnt / M);

    return 0;
}
