#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    regex re("([+-])([1-9])\\.([0-9]+)E([+-])([0-9]+)");

    string notation;
    cin >> notation;

    smatch result;
    regex_match(notation, result, re);

    if (result[1] == "-") {
        cout << "-";
    }

    string ans;
    int exp;
    sscanf(result[5].str().c_str(), "%d", &exp);
    if (result[4] == "-") {
        string zero(9999, '0');
        ans = "0." + zero.substr(0, exp - 1) + result[2].str() + result[3].str();
        cout << ans << endl;
        return 0;
    } else {
        string p1 = result[2], p2 = result[3];
        if (exp == 0) {
            ans = p1 + "." + p2;
            cout << ans << endl;
        }
        if(p1.length() + p2.length() < exp + 1) {
            string zero(9999, '0');
            p2 = p2 + zero.substr(0, exp + 1 - p1.length() - p2.length());
        }
        ans = p1 + p2.substr(0, exp + 1 - p1.length());
        if(p2.length() > exp + 1 - p1.length()) {
            ans += "." + p2.substr(exp + 1 - p1.length());
        }
        cout<<ans<<endl;
    }

    return 0;
}
