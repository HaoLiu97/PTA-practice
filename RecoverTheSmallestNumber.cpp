#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;

int main() {
    int N;
    cin >> N;
    string num;
    vector<string> nums;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        nums.push_back(num);
    }

    sort(nums.begin(), nums.end(), [](string &a, string &b) -> bool {
        return a + b < b + a;
    });

    string ans;
    for (auto n:nums) {
        ans += n;
    }

    while (ans[0] == '0'&&ans.length() >= 2) {
        ans.erase(ans.begin());
    }

    cout<<ans<<endl;

    return 0;
}
