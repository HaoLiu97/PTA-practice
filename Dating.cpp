#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

string week[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    freopen("in.txt", "r", stdin);
    vector<string> strs(4);
    cin >> strs[0] >> strs[1] >> strs[2] >> strs[3];
    int len = min(strs[0].length(), strs[1].length());

    int i = 0;
    for (; i < len; ++i) {
        if (strs[0][i] <= 'G' && strs[0][i] >= 'A' && strs[0][i] == strs[1][i]) {
            cout<<week[strs[0][i]-'A']<<" ";
            break;
        }
    }

    ++i;
    for (; i < len; ++i) {
        if ((strs[0][i] <= 'N' && strs[0][i] >= 'A' || isdigit(strs[0][i])) && strs[0][i] == strs[1][i]) {
            if(strs[0][i] <= 'N' && strs[0][i] >= 'A') {
                printf("%02d:", strs[0][i]-'A' + 10);
            } else if(isdigit(strs[0][i])) {
                printf("%02d:", strs[0][i]-'0');
            }
            break;
        }
    }

    len = min(strs[2].length(), strs[3].length());
    i = 0;
    for(; i < len; ++i) {
        if (isalpha(strs[2][i]) && strs[2][i] == strs[3][i]) {
            break;
        }
    }
    printf("%02d\n", i);

    return 0;
}
