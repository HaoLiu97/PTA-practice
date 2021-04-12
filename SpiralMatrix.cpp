#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end(), greater<int>());
    int n = 1, m = N;
    for (int i = 2; i <= N / i; ++i) {
        if (N % i == 0) {
            n = i;
            m = N / i;
        }
    }

    vector<vector<int>> matrix(m, vector<int>(n));
    int index = 0, i = 0, j = 0, up = 0, down = m - 1, left = 0, right = n - 1;
    while (index < N) {
        for (; j <= right; ++j) {
            matrix[i][j] = nums[index++];
        }
        if (index == N)break;
        j = right;
        ++up;
        ++i;

        for (; i <= down; ++i) {
            matrix[i][j] = nums[index++];
        }
        if (index == N)break;
        i = down;
        --right;
        --j;

        for (; j >= left; --j) {
            matrix[i][j] = nums[index++];
        }
        if (index == N)break;
        j = left;
        --down;
        --i;

        for (; i >= up; --i) {
            matrix[i][j] = nums[index++];
        }
        if (index == N)break;
        i = up;
        ++j;
        ++left;
    }

    for (auto &row:matrix) {
        for (int k = 0; k < n; ++k) {
            cout << row[k] << " \n"[k == n - 1];
        }
    }

    return 0;
}
