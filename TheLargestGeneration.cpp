#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const int MAX_N = 105;

struct TreeNode {
    vector<int> child;
};

TreeNode tree[MAX_N];

int main() {
    freopen("in.txt", "r", stdin);
    int N, M;
    cin>>N>>M;

    int cur, child_num, child;
    for(int i = 0; i < M; ++i) {
        cin>>cur>>child_num;
        for(int j = 0; j < child_num; ++j) {
            cin>>child;
            tree[cur].child.push_back(child);
        }
    }

    int maxi_gen = 1, maxi = 0, cur_gen = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int size = q.size();
        if(size > maxi) {
            maxi = size;
            maxi_gen = cur_gen;
        }
        for(int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop();
            for(int c:tree[cur].child) {
                q.push(c);
            }
        }
        cur_gen ++;
    }

    cout<<maxi<<" "<<maxi_gen<<endl;

    return 0;
}
