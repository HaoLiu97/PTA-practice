#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

string add(string s1, string s2) {
    string s;
    int carry = 0;
    for (int i = 0; i < max(s1.length(), s2.length()); ++i) {
        int a = 0, b = 0;
        if (i < s1.length()) {
            a = s1[s1.length() - 1 - i] - '0';
        }
        if (i < s2.length()) {
            b = s2[s2.length() - 1 - i] - '0';
        }
        int c = (a + b + carry) % 10;
        s = char('0' + c) + s;
        carry = (a + b + carry) / 10;
    }

    if (carry > 0) s = "1" + s;
    return s;
}

bool isPalindrome(string s) {
    for (int i = 0; i < s.length() / 2 + 1; ++i) {
        if (s[i] != s[s.length() - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    string N, rN, sum;
    cin >> N;
    for (int i = 0; i < 10; ++i) {
        if (isPalindrome(N)) {
            cout << N << " is a palindromic number.\n";
            return 0;
        }
        rN = N;
        reverse(rN.begin(), rN.end());
        sum = add(N, rN);
        cout << N << " + " << rN << " = " << sum << endl;
        N = sum;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}
