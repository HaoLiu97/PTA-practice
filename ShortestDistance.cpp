#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, d;
    cin >> N;
    vector<int> dis_sum(N + 2);
    for (int i = 1; i <= N; ++i) {
        cin >> d;
        if (i == 0) {
            dis_sum[i + 1] = d;
        } else {
            dis_sum[i + 1] = dis_sum[i] + d;
        }
    }

    int M, e1, e2;
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin>>e1>>e2;
        if(e1 > e2) {
            swap(e1, e2);
        }
        cout<<min(dis_sum[e2] - dis_sum[e1], dis_sum[N+1] - dis_sum[e2] + dis_sum[e1])<<endl;
    }

    return 0;
}
