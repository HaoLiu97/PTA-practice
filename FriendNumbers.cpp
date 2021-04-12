
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

int main() {
    freopen("in.txt", "r", stdin);
    int N, t;
    cin >> N;
    set<int> Set;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        Set.insert(digitSum(t));
    }

    cout << Set.size() << endl;
    for (auto iter:Set) {
        cout << iter << " \n"[iter == *(--Set.end())];
    }

    return 0;
}
