#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;


int bags[101];
bool selected[10001][101];

int main() {
    freopen("in.txt", "r", stdin);
    int N, M;
    cin >> N >> M;
    vector<int> coins(N);
    vector<int> ans;
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end(), [](int a, int b) -> bool {
        return a > b;
    });

    fill(bags + 1, bags + 101, -INF);

    for(int i = 0; i < N; ++i) {
        for(int j = M; j >= coins[i]; --j) {
            if( bags[j] <= bags[j-coins[i]] + coins[i]) {
                bags[j] = bags[j-coins[i]] + coins[i];
                selected[i][j] = true;
            }
        }
    }

    if(bags[M] != M){
        cout << "No Solution" << endl;
        return 0;
    }

    int j = M, i = N-1;
    while(true){
        if(selected[i][j]){
            cout << coins[i];
            j -= coins[i];
            if(j != 0)
                cout << " ";
        }
        i--;
        if(j == 0 || i == 0)
            break;
    }
    cout << endl;

    return 0;
}
