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

    if(carry) {
        ret.push_back(carry + '0');
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int cnt[10];

int main() {
    string num;
    cin >> num;

    for (int i = 0; i < num.length(); ++i) {
        cnt[num[i] - '0']++;
    }

    string res = add(num, num);
    for (int i = 0; i < res.length(); ++i) {
        cnt[res[i] - '0']--;
    }

    int i;
    for (i = 0; i <= 9; ++i) {
        if (cnt[i] != 0) {
            cout << "No" << endl;
            break;
        }
    }

    if (i == 10) {
        cout << "Yes" << endl;
    }

    cout<<res;


    return 0;
}
