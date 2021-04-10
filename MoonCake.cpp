#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct MoonCake {
    double inventory, total_price;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, D;
    cin >> N >> D;
    vector<MoonCake> records(N);
    for (int i = 0; i < N; ++i) {
        cin >> records[i].inventory;
    }

    for (int i = 0; i < N; ++i) {
        cin >> records[i].total_price;
    }

    sort(records.begin(), records.end(), [](MoonCake &a, MoonCake &b) -> bool {
        return a.total_price / a.inventory > b.total_price / b.inventory;
    });
    double cur_amount = 0, profit = 0;

    for (int i = 0; i < N; ++i) {
        if (cur_amount + records[i].inventory <= D) {
            cur_amount += records[i].inventory;
            profit += records[i].total_price;
        } else {
            profit = profit + (records[i].total_price / records[i].inventory) * (D - cur_amount);
            break;
        }
    }

    printf("%.2f\n", profit);

    return 0;
}
