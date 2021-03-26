#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n1, n2, n;
    n = s.length();
    n1 = 2;
    n2 = n - 2;
    while (n1 <= n2) {
        n1++;
        n2 = n2 - 2;
    }
    n1--;
    n2 = n2 + 2;
    int left = 0, right = s.length() - 1;
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < n2; ++j) {
            if (i == n1 - 1) {
                cout<<s[left++];
            } else {
                if(j == 0) {
                    cout<<s[left++];
                } else if(j == n2 - 1){
                    cout<<s[right--]<<endl;
                } else {
                    cout<<" ";
                }
            }
        }
    }


    return 0;
}
