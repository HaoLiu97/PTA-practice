#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    string str, str1;
    getline(cin, str);
    for(char& c:str) {
        if(isalnum(c)) {
            str1 += tolower(c);
        } else {
            str1 += ' ';
        }
    }
    unordered_map<string, int> word_cnt;
    stringstream ss(str1);
    int max_cnt = 0;
    string max_word;
    while(ss>>str) {
        word_cnt[str]++;
        if(word_cnt[str] > max_cnt) {
            max_cnt = word_cnt[str];
            max_word = str;
        } else if(word_cnt[str] == max_cnt) {
            if(str < max_word) {
                max_word = str;
            }
        }
    }

    cout<<max_word<<" "<<max_cnt<<endl;

    return 0;
}
