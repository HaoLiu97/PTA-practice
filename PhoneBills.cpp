#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    string name;
    int month, day, hour, minute, status, time;
};

vector<int> tolls(25, 0);

double billFromZero(Node const &node) {
    double total = tolls[node.hour] * node.minute + tolls[24] * 60 * node.day;
    for (int i = 0; i < node.hour; ++i) {
        total += tolls[i] * 60;
    }
    return total / 100.0;
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;

    for (int i = 0; i < 24; ++i) {
        cin >> tolls[i];
        tolls[24] += tolls[i];
    }

    cin >> N;
    vector<Node> record(N);
    int MM, dd, HH, mm;
    string name, status;

    for (int i = 0; i < N; ++i) {
        cin >> record[i].name;
        scanf("%d:%d:%d:%d", &record[i].month, &record[i].day, &record[i].hour, &record[i].minute);
        cin >> status;
        record[i].status = (status == "on-line");
        record[i].time = record[i].day * 24 * 60 + record[i].hour * 60 + record[i].minute;
    }

    sort(record.begin(), record.end(), [](Node &a, Node &b) -> bool {
        if (a.name == b.name) {
            return a.time < b.time;
        }
        return a.name < b.name;
    });

    vector<Node> new_record;
    for(int i = 0; i + 1 < N; ++i) {
        if(record[i].name == record[i+1].name && record[i].status == 1 && record[i+1].status == 0) {
            new_record.push_back(record[i]);
            new_record.push_back(record[i+1]);
            ++i;
        }
    }

    int month = new_record[0].month;
    int i = 0;
    while(i < new_record.size()) {
        printf("%s %02d\n", new_record[i].name.c_str(), month);
        double total = 0;
        do {
            double money = billFromZero(new_record[i+1]) - billFromZero(new_record[i]);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",
                   new_record[i].day, new_record[i].hour, new_record[i].minute, new_record[i + 1].day, new_record[i + 1].hour,
                   new_record[i + 1].minute, new_record[i + 1].time - new_record[i].time, money);
            total += money;
            i = i + 2;
        }while(new_record[i].name == new_record[i-2].name);
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}
