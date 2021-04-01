#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin>>N>>K;
    int student_num, course_no;
    string name;
    unordered_map<string, vector<int>> u_map;

    for(int i = 0; i < K; ++i) {
        cin>>course_no>>student_num;
        for(int j = 0; j < student_num; ++j) {
            cin>>name;
            u_map[name].push_back(course_no);
        }
    }

    for(int i = 0; i < N; ++i) {
        cin>>name;
        cout<<name<<" "<<u_map[name].size();
        sort(u_map[name].begin(), u_map[name].end());
        for(int no:u_map[name]) {
            cout<<" "<<no;
        }
        cout<<endl;
    }

    return 0;
}
