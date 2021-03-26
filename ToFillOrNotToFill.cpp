#include <bits/stdc++.h>

using namespace std;

struct GasStation {
    double price, dis;
};

int main() {
    double C_max, D, D_avg;
    int N;
    cin >> C_max >> D >> D_avg >> N;

    vector<GasStation> GasStations;
    double price, dis;
    for (int i = 0; i < N; ++i) {
        cin >> price >> dis;
        GasStations.push_back(GasStation{price, dis});
    }

    GasStations.push_back(GasStation{0, D});

    sort(GasStations.begin(), GasStations.end(), [](GasStation &a, GasStation &b) -> bool {
        return a.dis < b.dis;
    });

    double per_tank_dis = C_max * D_avg;
    if (GasStations[0].dis != 0) {
        printf("The maximum travel distance = 0.00\n");
        return 0;
    }

    vector<vector<int>> G_arrives(N + 1);

    for (int i = 0; i < GasStations.size(); ++i) {
        for (int j = i + 1; j < GasStations.size(); ++j) {
            if (GasStations[j].dis - GasStations[i].dis <= per_tank_dis) {
                G_arrives[i].push_back(j);
            }
        }
    }

    double cur_cost = 0, cur_gas = 0, max_distance = 0;
    int cur_station = 0;
    // N号加油站设定为终点
    while (cur_station != N) {
        if (G_arrives[cur_station].empty()) {
            max_distance = GasStations[cur_station].dis + per_tank_dis;
            break;
        }

        double min_price = 1000000;
        int min_no = -1;
        int less_price_no = -1;
        for (auto station:G_arrives[cur_station]) {
            if (GasStations[station].price < GasStations[cur_station].price && less_price_no == -1) {
                less_price_no = station;
            }
            if (GasStations[station].price < min_price) {
                min_price = GasStations[station].price;
                GasStations[station].price = min_price;
                min_no = station;
            }
        }

        if (less_price_no != -1) { // 有比当前便宜的，就过去
            double min_dis_need_to_travel = GasStations[less_price_no].dis - GasStations[cur_station].dis;
            cur_cost += (min_dis_need_to_travel / D_avg - cur_gas) * GasStations[cur_station].price;
            cur_gas = 0;
            cur_station = less_price_no;
            continue;
        }

        cur_cost += (C_max - cur_gas) * GasStations[cur_station].price;
        cur_gas = C_max - (GasStations[min_no].dis - GasStations[cur_station].dis) / D_avg;
        cur_station = min_no;
    }

    if (cur_station == N) {
        printf("%.2f\n", cur_cost);
    } else {
        printf("The maximum travel distance = %.2f\n", max_distance);
    }

    return 0;
}
