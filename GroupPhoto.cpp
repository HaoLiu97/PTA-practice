#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Person {
    string name;
    int height;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, K;
    cin >> N >> K;
    vector<Person> persons(N);
    for (int i = 0; i < N; ++i) {
        cin >> persons[i].name >> persons[i].height;
    }

    int per_row = N / K;
    sort(persons.begin(), persons.end(), [](Person &a, Person &b) -> bool {
        if (a.height == b.height) {
            return a.name < b.name;
        }
        return a.height > b.height;
    });
    vector<vector<string>> group(K, vector<string>(per_row));
    group[0].resize(per_row + N % K);

    int cur = 0;
    for (int i = 0; i < group.size(); ++i) {
        int m = group[i].size();
        int highest = m / 2;
        int no = 1;
        group[i][highest] = persons[cur++].name;
        while (true) {
            if (highest - no >= 0) {
                group[i][highest - no] = persons[cur++].name;
            }
            if (highest + no <= m - 1) {
                group[i][highest + no] = persons[cur++].name;
            }
            if (highest - no < 0 && highest + no > m - 1) {
                break;
            }
            ++no;
        }
    }

    for (int i = 0; i < group.size(); ++i) {
        for (int j = 0; j < group[i].size(); ++j) {
            cout << group[i][j] << " \n"[j == group[i].size() - 1];
        }
    }

    return 0;
}
