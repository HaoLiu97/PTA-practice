#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Node {
    string card_number;
    int grade;
};

struct Site {
    string site;
    int cnt;
};

int main() {
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    int N, M, t;
    cin >> N >> M;
    string id;
    unordered_map<string, vector<Node *>> u1;
    unordered_map<string, int> u2, u2_cnt;
    unordered_map<string, unordered_map<string, int>> u3;
    Node nodes[N];
    for (int i = 0; i < N; ++i) {
        cin >> id >> t;
        string level = id.substr(0, 1);
        string site = id.substr(1, 3);
        string time = id.substr(4, 6);
        string testee_number = id.substr(10, 3);
        nodes[i] = Node{id, t};
        u1[level].push_back(&nodes[i]);
        u2[site] += t;
        u2_cnt[site]++;
        u3[time][site]++;
    }

    int type;
    string term;
    for (int i = 1; i <= M; ++i) {
        cin >> type >> term;
        cout << "Case " << i << ": " << type << " " << term << endl;
        if (type == 1) {
            if(u1.find(term) == u1.end()) {
                cout << "NA" << endl;
                continue;
            }
            sort(u1[term].begin(), u1[term].end(), [](Node *a, Node *b) {
                if (a->grade == b->grade) {
                    return a->card_number < b->card_number;
                }
                return a->grade > b->grade;
            });
            for (int j = 0; j < u1[term].size(); ++j) {
                cout << u1[term][j]->card_number << " " << u1[term][j]->grade << endl;
            }
        } else if (type == 2) {
            if(u2.find(term) == u2.end()) {
                cout<<"NA"<<endl;
                continue;
            }
            cout << u2_cnt[term] << " " << u2[term] << endl;
        } else if (type == 3) {
            if(u3.find(term) == u3.end()) {
                cout << "NA" << endl;
                continue;
            }
            vector<Site> sites;
            for(auto iter:u3[term]) {
                sites.push_back(Site{iter.first, iter.second});
            }
            sort(sites.begin(), sites.end(), [](Site&a, Site&b) ->bool{
                if(a.cnt == b.cnt) {
                    return a.site < b.site;
                }
                return a.cnt>b.cnt;
            });
            for (int j = 0; j < sites.size(); ++j) {
                cout << sites[j].site << " " << sites[j].cnt<< endl;
            }
        }
    }

    return 0;
}
