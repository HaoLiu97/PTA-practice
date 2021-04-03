#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Student {
    string name, id;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, grade;
    string name, id;
    cin >> N;
    vector<Student> records[101];
    for (int i = 0; i < N; ++i) {
        cin >> name >> id >> grade;
        records[grade].push_back(Student{name, id});
    }

    int grade1, grade2;
    cin >> grade1 >> grade2;

    bool flag = false;
    for (int i = grade2; i >= grade1; --i) {
        for (auto &s:records[i]) {
            cout << s.name << " " << s.id << endl;
            flag = true;
        }
    }

    if (!flag) {
        cout << "NONE" << endl;
    }

    return 0;
}
