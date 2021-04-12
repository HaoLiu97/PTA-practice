#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int Father[10005], Rank[10005], Cnt[10005], Min[10005], Estate[10005], Area[10005];
int FEstate[10005], FArea[10005];

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
        Min[setB] = min(Min[setA], Min[setB]);
    } else if (Rank[setA] > Rank[setB]) {
        Father[setB] = setA;
        Cnt[setA] += Cnt[setB];
        Min[setA] = min(Min[setA], Min[setB]);
    } else {
        Father[setB] = setA;
        Cnt[setA] += Cnt[setB];
        Min[setA] = min(Min[setA], Min[setB]);
        Rank[setA]++;
    }
}

void unionNode(int a, int b) {
    int fa = find(a);
    int fb = find(b);
    if (fa != fb) {
        setUnion(fa, fb);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, id, father, mother, k, t, Mestate, area;
    for (int i = 0; i < 10005; ++i) {
        Father[i] = i;
        Cnt[i] = 1;
        Min[i] = i;
    }
    cin >> N;
    set<int> Set;
    for (int i = 0; i < N; ++i) {
        cin >> id >> father >> mother >> k;
        if (mother != -1) {
            unionNode(id, mother);
            Set.insert(mother);
        }
        if (father != -1) {
            unionNode(id, father);
            Set.insert(father);
        }
        Set.insert(id);
        for (int j = 0; j < k; ++j) {
            cin >> t;
            unionNode(id, t);
            Set.insert(t);
        }
        cin >> Mestate >> area;
        Estate[id] = Mestate;
        Area[id] = area;
    }

    set<int> FSet;
    for (auto iter:Set) {
        int f = find(iter);
        FEstate[f] += Estate[iter];
        FArea[f] += Area[iter];
        FSet.insert(f);
    }

    struct Ans {
        int min_id, number;
        double avg_set, avg_area;
    };

    vector<Ans> ans;
    ans.reserve(FSet.size());
    for (auto iter:FSet) {
        ans.push_back(Ans{Min[iter], Cnt[iter], (double) FEstate[iter] / Cnt[iter], (double) FArea[iter] / Cnt[iter]});
    }
    sort(ans.begin(), ans.end(), [](Ans &a, Ans &b) -> bool {
        if (a.avg_area == b.avg_area) {
            return a.min_id < b.min_id;
        }
        return a.avg_area > b.avg_area;
    });

    cout << ans.size() << endl;
    for (auto a:ans) {
        printf("%04d %d %.3lf %.3lf\n", a.min_id, a.number, a.avg_set, a.avg_area);
    }

    return 0;
}
