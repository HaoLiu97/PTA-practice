#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    vector<int> nums(N), pre_max(N), suff_min(N);
    if (N >= 1) {
        pre_max[0] = -INF;
        suff_min[N - 1] = INF;
    }
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        if (i >= 1) {
            pre_max[i] = max(pre_max[i - 1], nums[i - 1]);
        }
    }

    for (int i = N - 2; i >= 0; --i) {
        suff_min[i] = min(suff_min[i + 1], nums[i + 1]);
    }

    vector<int> ans(0);
    for (int i = 0; i < N; ++i) {
        if (nums[i] > pre_max[i] && nums[i] < suff_min[i]) {
            ans.push_back(nums[i]);
        }
    }

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
