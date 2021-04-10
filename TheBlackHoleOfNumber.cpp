#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int reverse(int N) {
    string str = to_string(N);
    while(str.length() < 4) {
        str = '0' + str;
    }
    reverse(str.begin(), str.end());
    return atoi(str.c_str());
}

int main() {
    int N;
    cin >> N;
    string str = to_string(N);
    sort(str.begin(), str.end());
    N = atoi(str.c_str());
    int a = N, b = reverse(N), c;
    while (1) {
        if (a < b) {
            swap(a, b);
        }
        c = a - b;
        printf("%04d - %04d = %04d\n", a, b, c);
        if (c == 6174 || c == 0)break;
        str = to_string(c);
        sort(str.begin(), str.end());
        a = atoi(str.c_str());
        b = reverse(a);
    }


    return 0;
}
