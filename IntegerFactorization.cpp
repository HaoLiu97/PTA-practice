#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int N, K, P;
vector<int> pows, t_ans, ans;

int max_fac_sum = -1;
void dfs(int cur_index, int cur_sum, int cur_K, int fac_sum) {
    if(cur_K == K) {
        if(cur_sum == N && fac_sum > max_fac_sum) {
            max_fac_sum = fac_sum;
            ans = t_ans;
        }
        return;
    }
    while(cur_index >= 1) {
        if(cur_sum + pows[cur_index] <= N) {
            t_ans[cur_K] = cur_index;
            dfs(cur_index, cur_sum + pows[cur_index], cur_K + 1, fac_sum + cur_index);
        }
        --cur_index;
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> N >> K >> P;

    int t = 0, i = 0;
    while (t <= N) {
        t = pow(i, P);
        ++i;
        pows.push_back(t);
    }
    t_ans.resize(K);
    dfs(pows.size() - 1, 0, 0, 0);

    if(max_fac_sum == -1) {
        cout<<"Impossible"<<endl;
        return 0;
    }

    cout << N << " = ";
    for (i = 0; i < ans.size(); ++i) {
        cout << ans[i] << "^" << P;
        if (i != ans.size() - 1) {
            cout<<" + ";
        }
    }

    return 0;
}
