#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    string school;
    int score, test_cnt;
};

int main() {
    freopen("in.txt", "r", stdin);
    int N, score;
    string id, school;
    cin >> N;
    unordered_map<string, double> scores;
    unordered_map<string, int> testees;

    for (int i = 0; i < N; ++i) {
        cin >> id >> score >> school;
        transform(school.begin(), school.end(), school.begin(), ::tolower);
        if (id[0] == 'A') {
            scores[school] += score;
        } else if (id[0] == 'B') {
            scores[school] += score / 1.5;
        } else {
            scores[school] += score * 1.5;
        }
        testees[school]++;
    }

    vector<Node> ans;
    for (auto iter = scores.begin(); iter != scores.end(); ++iter) {
        ans.push_back(Node{iter->first, (int) floor(iter->second), testees[iter->first]});
    }

    sort(ans.begin(), ans.end(), [](Node &a, Node &b) -> bool {
        if (a.score == b.score) {
            if (a.test_cnt == b.test_cnt) {
                return a.school < b.school;
            }
            return a.test_cnt < b.test_cnt;
        }
        return a.score > b.score;
    });

    cout<<ans.size()<<endl;
    int rank = 1;
    for (int i = 0; i < ans.size(); ++i) {
        if(i == 0) {
            cout<<rank<<" "<<ans[i].school<<" "<<ans[i].score<<" "<<ans[i].test_cnt<<endl;
        } else {
            if(ans[i].score != ans[i-1].score) {
                rank = i + 1;
            }
            cout<<rank<<" "<<ans[i].school<<" "<<ans[i].score<<" "<<ans[i].test_cnt<<endl;
        }
    }

    return 0;
}
