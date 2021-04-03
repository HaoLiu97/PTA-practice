#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    ull N, p;
    cin >> N >> p;
    vector<ull> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = 0, cur_l = 0, cur_r = 0;
    while(cur_r <= N-1) {
        if(nums[cur_r] <= nums[cur_l] * p) {
            if(cur_r - cur_l + 1> r - l + 1) {
                r = cur_r;
                l = cur_l;
            }
            cur_r ++;
        } else {
            cur_l ++;
        }
    }

    cout<<r-l+1<<endl;

    return 0;
}
