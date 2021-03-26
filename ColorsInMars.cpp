#include <bits/stdc++.h>

using namespace std;

char getVal(int num) {
    if (num >= 10) {
        return 'A' + num - 10;
    }
    return '0' + num;
}

string convert2str(int color, int radix) {
    string ret;
    int digit;
    if (color == 0) {
        return "00";
    }
    while (color != 0) {
        digit = color % radix;
        color = color / radix;
        ret.push_back(getVal(digit));
    }
    if (ret.length() == 1) {
        ret.push_back('0');
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    int R, G, B;
    cin >> R >> G >> B;

    cout << "#" << convert2str(R, 13) << convert2str(G, 13) << convert2str(B, 13) << endl;
    return 0;
}
