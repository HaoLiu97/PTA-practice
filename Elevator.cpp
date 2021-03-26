#include <bits/stdc++.h>

using namespace std;

const int UP = 6, DOWN = 4, STAY = 5;

int main() {
    int N, cur = 0, t;
    int time;
    cin >> N;
    time = STAY * N;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        if (t > cur) {
            time += (t - cur) * UP;
        } else {
            time += (cur - t) * DOWN;
        }
        cur = t;
    }

    cout << time;

    return 0;
}
