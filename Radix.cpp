#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;

int getVal(char c) {
    if (isdigit(c)) {
        return c - '0';
    }
    return c - 'a' + 10;
}

ull convert(string str, int radix) {
    ull ret = 0;
    ull t = 1;
    for (int i = str.length() - 1; i >= 0; --i) {
        ret += t * getVal(str[i]);
        t *= radix;
    }
    return ret;
}

ull findRadix(string N2, ull num) {
    int max_digit = 0;
    for (int i = 0; i < N2.length(); ++i) {
        max_digit = max(max_digit, getVal(N2[i]));
    }

    ull low = max_digit + 1;
    ull high = max(low, num);
    while (low <= high) {
        ull mid = (low + high) / 2;
        ull t = convert(N2, mid);
        if (t == num) {
            return mid;
        } else if (t < num) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    string N1, N2;
    ull tag, radix, N1val;
    cin >> N1 >> N2 >> tag >> radix;
    if (tag == 2) {
        swap(N1, N2);
    }

    N1val = convert(N1, radix);

    radix = findRadix(N2, N1val);

    if (radix == -1) {
        cout << "Impossible" << endl;
    } else {
        cout << radix << endl;
    }

    return 0;
}
