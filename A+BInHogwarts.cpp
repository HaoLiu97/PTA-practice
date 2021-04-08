#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int g1, s1, k1, g2, s2, k2;
    int carry = 0;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    k1 = k1 + k2;
    carry = k1 / 29;
    k1 = k1 % 29;

    s1 = s1 + s2 + carry;
    carry = s1 / 17;
    s1 = s1 % 17;

    g1 = g1 + g2 + carry;
    printf("%d.%d.%d\n", g1, s1, k1);

    return 0;
}
