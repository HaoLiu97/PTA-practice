#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int getVal(char c) {
    if (isdigit(c)) {
        return c - '0';
    }
    return c - 'a' + 10;
}

int convert2val(string str, int radix) {
    int ret = 0;
    int t = 1;
    for (int i = str.length() - 1; i >= 0; --i) {
        ret += t * getVal(str[i]);
        t *= radix;
    }
    return ret;
}

string convert2strReversi(int num, int radix) {
    string ret;
    while (num) {
        ret += to_string(num % radix);
        num = num / radix;
    }
    return ret;
}

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
    int N, D;
    cin >> N;
    while (N >= 0) {
        cin >> D;
        string str = convert2strReversi(N, D);
        if (isPrime(N) && isPrime(convert2val(str, D))) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        cin >> N;
    }

    return 0;
}
