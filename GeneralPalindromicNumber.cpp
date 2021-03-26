#include<bits/stdc++.h>

using namespace std;

bool isPalindromic(vector<int>& s, int left, int right) {
    if (left >= right) {
        return true;
    }
    return s[left] == s[right] && isPalindromic(s, left + 1, right - 1);
}

bool isPalindromic(vector<int>& s) {
    return isPalindromic(s, 0, s.size() - 1);
}

vector<int> convert2str(int num, int radix) {
    vector<int> ret;
    while (num) {
        ret.push_back(num % radix);
        num = num / radix;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    int N, radix;
    cin >> N >> radix;
    auto s = convert2str(N, radix);
    if (isPalindromic(s)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    for (int i = 0; i < s.size(); ++i) {
        printf("%d%c", s[i], " \n"[i == s.size() - 1]);
    }

    return 0;
}
