#include <bits/stdc++.h>

using namespace std;

struct Student {
    string ID;
    double grade[4];
};

int getRank(vector<double> &grades, double grade) {
    int left = 0, right = grades.size();
    while (left < right) {
        int mid = (left + right) >> 1;
        if(grade < grades[mid]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left + 1;
}

int main() {
    int N, M;
    cin >> N >> M;

    unordered_map<string, Student> u_map;
    string ID;
    double grade0, grade1, grade2, avg;
    vector<double> C, Math, E, A;

    for (int i = 0; i < N; ++i) {
        cin >> ID >> grade0 >> grade1 >> grade2;
        avg = (grade0 + grade1 + grade2) / 3;
        u_map[ID] = Student{ID, grade0, grade1, grade2, avg};
        C.push_back(grade0);
        Math.push_back(grade1);
        E.push_back(grade2);
        A.push_back(avg);
    }

    sort(C.begin(), C.end(), [](double &a, double &b) -> bool {
        return a > b;
    });

    sort(Math.begin(), Math.end(), [](double &a, double &b) -> bool {
        return a > b;
    });

    sort(E.begin(), E.end(), [](double &a, double &b) -> bool {
        return a > b;
    });

    sort(A.begin(), A.end(), [](double &a, double &b) -> bool {
        return a > b;
    });

    for (int j = 0; j < M; ++j) {
        cin >> ID;
        if (u_map.find(ID) == u_map.end()) {
            cout << "N/A" << endl;
        } else {
            int rankC, rankM, rankE, rankA;
            rankC = getRank(C, u_map[ID].grade[0]);
            rankM = getRank(Math, u_map[ID].grade[1]);
            rankE = getRank(E, u_map[ID].grade[2]);
            rankA = getRank(A, u_map[ID].grade[3]);
            int min_rank = min(min(rankC, rankM), min(rankE, rankA));
            cout << min_rank << " ";
            if (rankA == min_rank) {
                cout << "A" << endl;
            } else if (rankC == min_rank) {
                cout << "C" << endl;
            } else if (rankM == min_rank) {
                cout << "M" << endl;
            } else {
                cout << "E" << endl;
            }
        }
    }

    return 0;
}
