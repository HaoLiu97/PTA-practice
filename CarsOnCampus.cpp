#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

string convert2time(int t) {
    char str[100];
    sprintf(str, "%02d:%02d:%02d", t / 3600, (t % 3600) / 60, t % 60);
    return string(str);
}

struct Op {
    string plate_num;
    int time;
    int op; // 0 进  1 出
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, K;
    cin >> N >> K;

    string plate_num, status;
    int hh, mm, ss;

    vector<Op> ops, new_ops;
    for (int i = 0; i < N; ++i) {
        cin >> plate_num;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        cin >> status;
        ops.push_back(Op{plate_num, hh * 3600 + mm * 60 + ss, status == "out"});
    }

    sort(ops.begin(), ops.end(), [](Op &a, Op &b) -> bool {
        if(a.plate_num == b.plate_num) {
            return a.time < b.time;
        }
        return a.plate_num < b.plate_num;
    });

    int max_time = 0;
    vector<string> max_time_cars;
    unordered_map<string, int> u_map;


    for(int i = 0; i < N - 1; ++i) {
        if(ops[i].plate_num == ops[i+1].plate_num && ops[i].op == 0 && ops[i+1].op == 1) {
            new_ops.push_back(ops[i]);
            new_ops.push_back(ops[i+1]);
            u_map[ops[i].plate_num] += ops[i+1].time - ops[i].time;
            ++i;
        }
    }

    for(auto & iter : u_map) {
        if(iter.second > max_time) {
            max_time = iter.second;
            max_time_cars.clear();
            max_time_cars.push_back(iter.first);
        } else if(iter.second == max_time) {
            max_time_cars.push_back(iter.first);
        }
    }
    sort(max_time_cars.begin(), max_time_cars.end());


    sort(new_ops.begin(), new_ops.end(), [](Op &a, Op &b) -> bool {
        return a.time < b.time;
    });

    int j = 0;
    int cnt = 0;
    for (int i = 0; i < K; ++i) {
        scanf("%d:%d:%d", &hh, &mm, &ss);
        int time = hh * 3600 + mm * 60 + ss;
        while (j < N && new_ops[j].time <= time) {
            if (new_ops[j].op == 0) {
                ++cnt;
            } else {
                --cnt;
            }

            ++j;
        }
        cout << cnt << endl;
    }

    for(string p:max_time_cars) {
        cout<<p<<" ";
    }
    cout<<convert2time(max_time)<<endl;

    return 0;
}
