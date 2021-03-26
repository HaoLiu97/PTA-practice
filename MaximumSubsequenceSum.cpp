#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    vector<int> nums;
    int K, t;
    cin >> K;
    for (int i = 0; i < K; ++i) {
        cin >> t;
        nums.push_back(t);
    }

    int t_sum = 0, start, end, t_start, t_end;
    int max_sum = INT_MIN;
    start = t_start = nums[0];
    end = t_end = nums[0];
    for (int i = 0; i < K; ++i) {
        if (t_sum >= 0) {
            t_sum += nums[i];
            t_end = nums[i];
        } else {
            t_sum = nums[i];
            t_start = nums[i];
            t_end = nums[i];
        }

        if (t_sum > max_sum) {
            max_sum = t_sum;
            start = t_start;
            end = t_end;
        }
    }

    if (max_sum >= 0) {
        cout << max_sum << " " << start << " " << end;
    } else {
        cout << 0 << " " << nums[0] << " " << nums[K - 1];
    }

    return 0;
}
