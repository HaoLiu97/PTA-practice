#include<bits/stdc++.h>

using namespace std;

#define MAXK 2001

int main() {
    int K1, K2, exp;
    vector<double> P1(MAXK), P2(MAXK), P3(MAXK);
    vector<int> P1e, P2e;
    double coe;
    cin >> K1;
    for (int i = 0; i < K1; ++i) {
        cin >> exp >> coe;
        P1e.push_back(exp);
        P1[exp] = coe;
    }

    cin >> K2;
    for (int i = 0; i < K2; ++i) {
        cin >> exp >> coe;
        P2e.push_back(exp);
        P2[exp] = coe;
    }

    for (int i = 0; i < K1; ++i) {
        for (int j = 0; j < K2; ++j) {
            P3[P1e[i] + P2e[j]] += P1[P1e[i]] * P2[P2e[j]];
        }
    }

    int count = 0;
    for (int i = 0; i < MAXK; ++i) {
        if (P3[i] != 0) {
            count++;
        }
    }

    printf("%d", count);

    for(int i = MAXK-1; i >= 0; --i) {
        if(P3[i] != 0) {
            printf(" %d %.1f", i , P3[i]);
        }
    }

    return 0;
}
