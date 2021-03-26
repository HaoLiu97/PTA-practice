#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int dp[32];

ull fastPower(ull base, ull power) {
    ull result = 1;
    while (power > 0) {
        if (power & 1) {
            result = result * base;
        }
        power >>= 1;
        base = base * base;
    }
    return result;
}

ull solve(ull N) {
    ull ans = 0;
    if (N == 0) {
        ans = 0;
    } else if (N <= 9) {
        ans = 1;
    } else {
        string str_N = to_string(N);
        int len = str_N.length();
        int first_digit = str_N[0] - '0';
        ans = ans + first_digit * dp[len - 1];
        ans = ans + solve(N - first_digit * fastPower(10, len - 1));
        if (first_digit == 1) {
            ans = ans + N - first_digit * fastPower(10, len - 1) + 1;
        } else {
            ans = ans + fastPower(10, len - 1);
        }
    }
    return ans;
}

int main() {
    ull N;
    cin >> N;
    dp[1] = 1;
    int len = to_string(N).length();
    for (int i = 2; i <= len; ++i) {
        dp[i] = 10 * dp[i - 1] + fastPower(10, i - 1);
    }
    cout << solve(N) << endl;
    return 0;
}
