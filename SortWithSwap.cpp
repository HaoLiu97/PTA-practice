#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin>>N;
    vector<int> nums(N);
    unordered_map<int, int> order;
    unordered_set<int> set;
    for(int i = 0; i < N; ++i) {
        cin>>nums[i];
        order[nums[i]] = i;
        if(nums[i] != i) {
            set.insert(i);
        }
    }

    int cnt = 0;
    while(true) {
        while (order[0] != 0) {
            int a = order[0], b = order[order[0]];
            auto iter = set.find(a);
            set.erase(iter);
            order[order[0]] = a;
            order[0] = b;
            swap(nums[a], nums[b]);
            cnt++;
        }
        if(set.find(0) != set.end()) {
            set.erase(0);
        }
        if(set.empty()) break;
        int a = 0;
        int b = *set.begin();
        order[nums[b]] = a;
        order[0] = b;
        set.insert(0);
        swap(nums[a], nums[b]);
        cnt++;
    }

    cout<<cnt<<endl;

    return 0;
}
