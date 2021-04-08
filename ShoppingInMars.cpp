#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    vector<int> d(N), pre_sum(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
        if (i == 0) {
            pre_sum[i + 1] = d[i];
        } else {
            pre_sum[i + 1] = pre_sum[i] + d[i];
        }
    }

    int min_lose = INF;
    vector<pair<int, int>> solutions;
    for (int i = 1; i <= N; ++i) {
        int l = 0, r = i - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pre_sum[i] - pre_sum[mid] < M) {
                r = mid - 1;
            } else if (pre_sum[i] - pre_sum[mid] == M) {
                min_lose = 0;
                solutions.emplace_back(mid + 1, i);
                break;
            } else {
                l = mid + 1;
            }
        }
        l = min(l, r);
        if(l == -1) continue;
        if (pre_sum[i] - pre_sum[l] - M > 0) {
            if (pre_sum[i] - pre_sum[l] - M < min_lose) {
                min_lose = pre_sum[i] - pre_sum[l] - M;
                solutions.clear();
                solutions.emplace_back(l + 1, i);
            } else if (pre_sum[i] - pre_sum[l] - M == min_lose) {
                solutions.emplace_back(l + 1, i);
            }
        }
    }

    for (int i = 0; i < solutions.size(); ++i) {
        cout << solutions[i].first << "-" << solutions[i].second << endl;
    }

    return 0;
}
