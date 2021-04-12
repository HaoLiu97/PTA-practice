#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> nums(N);
    int half_sum = 0, sum = 0;
    for(int i = 0; i < N; ++i) {
        cin>>nums[i];
    }

    sort(nums.begin(), nums.end());
    for(int i = 0; i < N/2; ++i) {
        half_sum += nums[i];
    }

    for(int i = N/2; i < N; ++i) {
        sum += nums[i];
    }

    int n1 = N-N/2, n2 = N/2;

    cout<<n1-n2<<" "<<sum-half_sum;

    return 0;
}
