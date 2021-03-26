#include <bits/stdc++.h>

using namespace std;

int main() {
    double W, T, L;
    vector<string> choice(3);
    double ans = 1;

    for (int i = 0; i < 3; ++i) {
        cin >> W >> T >> L;
        double maxi = max(W, max(T, L));
        if (maxi == W) {
            choice[i] = "W";
        } else if (maxi == T) {
            choice[i] = "T";
        } else {
            choice[i] = "L";
        }
        ans *= maxi;
    }

    ans = (ans * 0.65 - 1) * 2;
    cout << choice[0] << " " << choice[1] << " " << choice[2] << " ";
    printf("%.2lf", ans);

    return 0;
}
