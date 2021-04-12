#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;
    cin >> N;
    priority_queue<int, vector<int>, greater<>> pq;
    int maxi = 0;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        t = t - 1;
        if (t > maxi) {
            pq.push(t);
        }
        while (!pq.empty() && pq.top() <= maxi) {
            pq.pop();
        }
        maxi = max(maxi, (int) pq.size());
    }
    cout << maxi << endl;

    return 0;
}
