#include <bits/stdc++.h>

using namespace std;

string add(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    if (num2.length() > num1.length()) {
        return add(num2, num1);
    }

    string ret;
    int carry = 0, cur;
    for (int i = 0; i < num1.length(); ++i) {
        if (i < num2.length()) {
            cur = num1[i] - '0' + num2[i] - '0' + carry;
            carry = cur / 10;
            cur = cur % 10;
            ret.push_back(cur + '0');
        } else {
            cur = num1[i] - '0' + carry;
            carry = cur / 10;
            cur = cur % 10;
            ret.push_back(cur + '0');
        }
    }

    if (carry) {
        ret.push_back(carry + '0');
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

bool isPalindromic(string s, int left, int right) {
    if (left >= right) {
        return true;
    }
    return s[left] == s[right] && isPalindromic(s, left + 1, right - 1);
}

int main() {
    string N, reversiN;
    int K;
    cin >> N >> K;
    int i;
    for (i = 0; i < K; ++i) {
        if(isPalindromic(N, 0, N.length() - 1)) {
            break;
        }
        reversiN = N;
        reverse(reversiN.begin(), reversiN.end());
        N = add(N, reversiN);
    }

    cout<<N<<endl<<i<<endl;

    return 0;
}
