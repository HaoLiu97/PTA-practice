#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

string convert(string num, int N) {
    string ans = "0.";
    string zero(100, '0');
    int len = num.length();

    num.erase(0, num.find_first_not_of('0'));
    if (num.empty()) { // 0
        return "0." + zero.substr(0, N) + "*10^0";
    }

    if (num[0] == '.') {
        int i = 1;
        while (num[i] == '0') {
            ++i;
        }
        if (i == num.length()) { // 0
            return "0." + zero.substr(0, N) + "*10^0";
        }
        num += zero;
        return ans + num.substr(i, N) + "*10^" + to_string(1 - i);
    }

    int i = 0;
    while (i < num.length() && num[i] != '.') {
        ++i;
    }
    if (i < N) {
        num += zero;
        return ans + num.substr(0, i) + num.substr(i + 1, N - i) + "*10^" + to_string(i);
    } else {
        return ans + num.substr(0, N) + "*10^" + to_string(i);
    }
}

int main() {
    string A, B;
    int N;
    cin >> N >> A >> B;
    string a = convert(A, N);
    string b = convert(B, N);
    if (a == b) {
        cout << "YES " << a << endl;
    } else {
        cout << "NO " << a << " " << b << endl;
    }

    return 0;
}
