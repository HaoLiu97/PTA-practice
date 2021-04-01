#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    int weight, rank, index;
};

int main() {
    int Np, Ng, t;
    cin >> Np >> Ng;

    vector<Node> programmers;
    vector<int> order;

    for (int i = 0; i < Np; ++i) {
        cin >> t;
        programmers.push_back(Node{t, 1, i});
    }

    for (int i = 0; i < Np; ++i) {
        cin >> t;
        order.push_back(t);
    }

    int cnt = 0;

    int i, cur_rank;
    int cur_group_winner_index;
    vector<Node> cur_group;


    while (cnt < Np - 1) {
        i = 0;
        cur_rank = (Np - cnt) / Ng + 1;
        if((Np-cnt)%Ng != 0) {
            cur_rank ++;
        }
        while (i < Np) { // 每一轮比赛
            cur_group.clear();
            cur_group_winner_index = -1;

            while (cur_group.size() < Ng && i < Np) {
                if (programmers[order[i]].rank == 1) {
                    cur_group.push_back(programmers[order[i]]);
                    if (cur_group_winner_index == -1 || programmers[order[i]].weight > programmers[cur_group_winner_index].weight) {
                        cur_group_winner_index = order[i];
                    }
                }
                ++i;
            }

            for (int j = 0; j < cur_group.size(); ++j) {
                if (cur_group[j].index != cur_group_winner_index) {
                    programmers[cur_group[j].index].rank = cur_rank;
                    ++cnt;
                }
            }
        }
    }


    for(int i = 0; i < programmers.size(); ++i) {
        cout<<programmers[i].rank;
        if(i != programmers.size() -1) {
            cout<<" ";
        }
    }

    return 0;
}
