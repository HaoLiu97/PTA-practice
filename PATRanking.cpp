#include <bits/stdc++.h>

using namespace std;

struct people {
    string r_num;
    int location, grade, loc_rank;
};

int main() {
    int N, K;
    cin >> N;
    string r_num;
    int grade, final_rank, location, local_rank;
    vector<people> peoples;
    vector<people> loc_peoples[N + 1];
    unordered_map<string, int> u_map;
    int cur = -1;
    for (int i = 1; i <= N; ++i) {
        cin >> K;
        for (int j = 0; j < K; ++j) {
            cur++;
            cin >> r_num >> grade;
            peoples.push_back(people{r_num, i, grade});
            u_map[r_num] = cur;
            loc_peoples[i].push_back(people{r_num, i, grade});
        }
        sort(loc_peoples[i].begin(), loc_peoples[i].end(), [](people &a, people &b) -> bool {
            return a.grade > b.grade;
        });
        int rank = 1;
        peoples[u_map[loc_peoples[i][0].r_num]].loc_rank = rank;
        for (int k = 1; k < loc_peoples[i].size(); ++k) {
            if (loc_peoples[i][k].grade == loc_peoples[i][k-1].grade) {
                peoples[u_map[loc_peoples[i][k].r_num]].loc_rank = rank;
            } else {
                rank = k + 1;
                peoples[u_map[loc_peoples[i][k].r_num]].loc_rank = rank;
            }
        }
    }

    sort(peoples.begin(), peoples.end(), [](people &a, people &b) -> bool {
        if(a.grade == b.grade) {
            return a.r_num < b.r_num;
        }
        return a.grade > b.grade;
    });

    int rank = 1;
    cout<<peoples.size()<<endl;
    for(int i = 0; i < peoples.size(); ++i) {
        if (i == 0 || peoples[i].grade != peoples[i-1].grade) {
            rank = i + 1;
        }

        cout<<peoples[i].r_num<<" "<<rank<< " "<<peoples[i].location<<" "<<peoples[i].loc_rank<<endl;
    }

    return 0;
}
