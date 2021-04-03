#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Student {
    int id;
    vector<int> grades;
    int total;
    int perfect = 0;
    bool show = false;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, K, M;
    cin >> N >> K >> M;

    vector<int> full_mark(K + 1);
    for (int i = 1; i <= K; ++i) {
        cin >> full_mark[i];
    }

    vector<Student> record(N + 1, Student{0, vector<int>(K + 1, -1)});
    int user_id, problem_id, partial_score_obtained;

    for (int i = 0; i < M; ++i) {
        cin >> user_id >> problem_id >> partial_score_obtained;
        if (partial_score_obtained != -1) {
            record[user_id].grades[problem_id] = max(record[user_id].grades[problem_id], partial_score_obtained);
            record[user_id].show = true;
        } else {
            record[user_id].grades[problem_id] = max(record[user_id].grades[problem_id], 0);
        }
    }

    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        record[i].id = i;
        for (int j = 1; j <= K; ++j) {
            if (record[i].grades[j] != -1) {
                sum += record[i].grades[j];
                if(record[i].grades[j] == full_mark[j]) {
                    record[i].perfect ++;
                }
            }
        }
        record[i].total = sum;
    }

    sort(record.begin() + 1, record.end(), [](Student &a, Student &b) -> bool {
        if (a.total == b.total) {
            if(a.perfect == b.perfect) {
                return a.id < b.id;
            }
            return a.perfect > b.perfect;
        }
        return a.total > b.total;
    });

    int rank = 1;
    for (int i = 1; i <= N; ++i) {
        if (record[i].show) {
            if (i >= 2 && record[i].total < record[i - 1].total) {
                rank = i;
            }
            printf("%d %05d %d ", rank, record[i].id, record[i].total);
            for (int j = 1; j < record[i].grades.size(); ++j) {
                if (record[i].grades[j] != -1) {
                    cout << record[i].grades[j];
                } else {
                    cout << "-";
                }
                if (j != record[i].grades.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
