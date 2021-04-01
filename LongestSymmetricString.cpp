#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;

string str;
int l;

int expandFromCenter(int center) {
    int left = center >> 1, right = (center + 1) >> 1;

    while (left >= 0 && right <= l - 1) {
        if(str[left] != str[right]) {
            break;
        }
        --left;
        ++right;
    }
    return right - left - 1;
}

int main() {
    getline(cin, str);
    l = str.length();
    int maxi = 0;
    for (int i = 0; i <= 2 * l - 2; ++i) {
        maxi = max(maxi, expandFromCenter(i));
    }

    cout<<maxi<<endl;

    return 0;
}
