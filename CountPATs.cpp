#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const ull MOD = 1000000007;

int main() {
    freopen("in.txt", "r", stdin);
    string str;
    cin>>str;
    int len = str.length();

    ull pre_p_cnt = 0, suf_t_cnt = 0;
    vector<ull> pre(len), suf(len);
    for(int i = 0; i < len; ++i) {
        if(str[i] == 'P') {
            pre_p_cnt ++;
        } else if(str[i] == 'A'){
            pre[i] = pre_p_cnt;
        }
    }

    for(int i = len-1; i >= 0; --i) {
        if(str[i] == 'T') {
            suf_t_cnt ++;
        } else if(str[i] == 'A'){
            suf[i] = suf_t_cnt;
        }
    }

    ull ans = 0;
    for(int i = 0; i < len; ++i) {
        ans = (ans + pre[i]*suf[i]) % MOD;
    }

    cout<<ans<<endl;

    return 0;
}
