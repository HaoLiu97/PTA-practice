#include <bits/stdc++.h>

using namespace std;

struct person{
    int id, end_time, queue;

    bool operator <(const person &p) const {
        return this->end_time > p.end_time;
    };
};

string convert(int t) {
    int hour, min;
    hour = 8 + t / 60;
    min = t % 60;
    char s[100];

    sprintf(s, "%02d:%02d", hour, min);

    return string(s);
}

int main() {
    int N, M, K, Q, t;
    vector<int> cost_times, q;

    cost_times.push_back(0);
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= K; ++i) {
        cin >> t;
        cost_times.push_back(t);
    }

    for (int i = 0; i < Q; ++i) {
        cin >> t;
        q.push_back(t);
    }

    priority_queue<person> pq;
    vector<int> q_times(N + 1);
    vector<int> finish_times(K + 1);

    for (int i = 1; i <= N*M && i <= K; ++i) {
        q_times[(i - 1)%N + 1] += cost_times[i];
        pq.push(person{i, q_times[(i - 1)%N + 1], (i - 1)%N + 1});
        finish_times[i] = q_times[(i - 1)%N + 1];
    }


    int cur = N*M + 1;
    while(!pq.empty()) {
        person p = pq.top();
        pq.pop();
        if(cur <= K) {
            finish_times[cur] = q_times[p.queue] + cost_times[cur];
            q_times[p.queue] = finish_times[cur];
            pq.push(person{cur, finish_times[cur], p.queue});
            cur++;
        }
    }

    for(int i = 0; i < Q; ++i) {
        if(finish_times[q[i]] - cost_times[q[i]] < 540) {
            cout << convert(finish_times[q[i]]);
        } else {
            cout << "Sorry";
        }
        if(i != Q-1) {
            cout<<endl;
        }
    }

    return 0;
}
