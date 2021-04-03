#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

string read[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

// 读一个0-9999的数字
string readASeg(int num) {
    string ret;
    int thousand = num / 1000;
    int hundred = num / 100 - thousand * 10;
    int ten = num / 10 - 100 * thousand - 10 * hundred;
    int ge = num % 10;
    if (thousand) {
        ret += read[thousand] + " Qian";
        if (hundred != 0 || ten != 0 || ge != 0) {
            ret += " ";
        }
        if (hundred == 0 && (ten != 0 || ge != 0)) {
            ret += "ling ";
        }
    }

    if (hundred) {
        ret += read[hundred] + " Bai";
        if (ten != 0 || ge != 0) {
            ret += " ";
        }
        if (ten == 0 && ge != 0) {
            ret += "ling ";
        }
    }

    if (ten) {
        ret += read[ten] + " Shi";
        if (ge != 0) {
            ret += " ";
        }
    }

    if (ge) {
        ret += read[ge];
    }

    return ret;
}

int main() {
    int num;
    cin >> num;
    string ans;
    if (num < 0) {
        ans += "Fu ";
        num = -num;
    }

    int part1 = num / 100000000;
    int part2 = num / 10000 - part1 * 10000;
    int part3 = num % 10000;

    string p1, p2, p3;
    p1 = readASeg(part1);
    p2 = readASeg(part2);
    p3 = readASeg(part3);

    if (part1 != 0) {
        ans += p1 + " Yi";
        if (part2 != 0 || part3 != 0) {
            ans += " ";
            if(part2 <= 999) {
                ans += "ling ";
            }
        }
    }

    if(part2) {
        ans += p2 + " Wan";
        if(part3 != 0) {
            ans += " ";
            if(part3 <= 999) {
                ans += "ling ";
            }
        }
    }

    if(part3) {
        ans += p3;
    }

    if(ans.empty()) {
        ans = "ling";
    }

    cout << ans << endl;

    return 0;
}
