#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    vector<long double> nums(N), pre_sum(N + 1);
    pre_sum[0] = 0;
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
        pre_sum[i + 1] = pre_sum[i] + nums[i];
    }
    long double sum = 0;

    for (int i = 0; i < N; ++i) {
        sum = sum - pre_sum[i] * (N - i) + pre_sum[i + 1] * (i + 1);
    }

    printf("%.2Lf\n", sum);

    return 0;
}
