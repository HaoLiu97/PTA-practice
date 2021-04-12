#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int Father[10005], Rank[10005], Cnt[10005];

int find(int x) {
    if (Father[x] == x) {
        return x;
    }
    return Father[x] = find(Father[x]);
}

void setUnion(int setA, int setB) {
    if (Rank[setA] < Rank[setB]) {
        Father[setA] = setB;
        Cnt[setB] += Cnt[setA];
    } else if (Rank[setA] > Rank[setB]) {
        Father[setB] = setA;
        Cnt[setA] += Cnt[setB];
    } else {
        Father[setB] = setA;
        Cnt[setA] += Cnt[setB];
        Rank[setA]++;
    }
}

void unionBird(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if(fa != fb) {
        setUnion(fa, fb);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    for(int i = 0; i < 10005; ++i) {
        Father[i] = i;
        Rank[i] = 0;
        Cnt[i] = 1;
    };
    int N, K, t0, t1;

    unordered_set<int> birds, trees;
    cin>>N;
    for(int i = 0; i < N; ++i) {
        cin>>K;
        if(K != 0) {
            cin >> t0;
            birds.insert(t0);
        }
        for(int j = 1; j < K; ++j) {
            cin>>t1;
            birds.insert(t1);
            unionBird(t0, t1);
        }
    }

    for(auto iter:birds) {
        trees.insert(find(iter));
    }

    cout<<trees.size()<<" "<<birds.size()<<endl;
    int Q;
    cin>>Q;
    vector<string> ans;
    for(int i = 0; i < Q; ++i) {
        cin>>t0>>t1;
        int fa = find(t0), fb = find(t1);
        if(fa == fb) {
            cout<<"Yes"<<endl;
        } else {
            cout<<"No"<<endl;
        }
    }

    return 0;
}
