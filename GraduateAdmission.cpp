#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Student {
    int Ge, Gi, no;
    vector<int> prefer_school;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> quota(M, 0);
    for (int i = 0; i < M; ++i) {
        cin >> quota[i];
    }

    vector<Student> students(N);
    vector<int> admit[M];
    int t;
    for (int i = 0; i < N; ++i) {
        cin >> students[i].Ge >> students[i].Gi;
        students[i].no = i;
        for (int j = 0; j < K; ++j) {
            cin >> t;
            students[i].prefer_school.push_back(t);
        }
    }
    vector<Student> o_students = students;
    sort(students.begin(), students.end(), [](Student &a, Student &b) {
        if (a.Ge + a.Gi == b.Ge + b.Gi) {
            if (a.Ge == b.Ge) {
                return a.no < b.no;
            }
            return a.Ge > b.Ge;
        }
        return a.Ge + a.Gi > b.Ge + b.Gi;
    });


    for (int i = 0; i < students.size(); ++i) {
        for (int j = 0; j < students[i].prefer_school.size(); ++j) {
            if (quota[students[i].prefer_school[j]] >= 1) {
                admit[students[i].prefer_school[j]].push_back(students[i].no);
                quota[students[i].prefer_school[j]]--;
                break;
            } else if (!admit[students[i].prefer_school[j]].empty()) {
                if (o_students[admit[students[i].prefer_school[j]].back()].Ge == students[i].Ge &&
                    o_students[admit[students[i].prefer_school[j]].back()].Gi == students[i].Gi) {
                    admit[students[i].prefer_school[j]].push_back(students[i].no);
                    quota[students[i].prefer_school[j]]--;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < M; ++i) {
        if (admit[i].empty()) {
            cout << endl;
        } else {
            sort(admit[i].begin(), admit[i].end());
            for (int j = 0; j < admit[i].size(); ++j) {
                cout << admit[i][j];
                if (j != admit[i].size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}
