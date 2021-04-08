#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;


struct Node {
    int arrive, deal;
};

int main() {
    int N, K;
    cin >> N >> K;

    vector<Node> record;
    int hour, minute, second, t;
    for (int i = 0; i < N; ++i) {
        scanf("%d:%d:%d %d", &hour, &minute, &second, &t);
        int arrive = hour * 3600 + minute * 60 + second;
        int deal = t * 60;
        if (arrive <= 17 * 3600) {
            record.push_back(Node{arrive, deal});
        }
    }

    N = record.size();
    sort(record.begin(), record.end(), [](Node &a, Node &b) -> bool {
        return a.arrive < b.arrive;
    });

    double wait_total = 0;
    for (int i = 0; i < N; ++i) {
        if (record[i].arrive < 8 * 3600) {
            wait_total = wait_total + 8 * 3600 - record[i].arrive;
            record[i].arrive = 8 * 3600;
        }
    }

    priority_queue<int, vector<int>, greater<>> pq; // end time
    int i = 0;
    // 前K个一开门就不用等了
    while (i < N && pq.size() < K) {
        pq.push(record[i].arrive + record[i].deal);
        ++i;
    }

    for (; i < N; ++i) {
        int time = pq.top();
        pq.pop();
        if (record[i].arrive < time) {
            wait_total = wait_total + time - record[i].arrive;
            pq.push(time + record[i].deal);
        } else {
            pq.push(record[i].arrive + record[i].deal);
        }
    }

    printf("%.1f\n", wait_total/(N*60));

    return 0;
}
