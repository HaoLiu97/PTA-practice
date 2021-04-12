#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

void downAdjust(vector<int> &process, int low, int high) {
    int i = low, j = 2 * i + 1;
    while (j <= high) {
        if (j + 1 <= high && process[j] < process[j + 1]) j = j + 1;
        if (process[i] >= process[j]) break;
        swap(process[i], process[j]);
        i = j;
        j = 2 * i + 1;
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> num, process;
    int t;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        num.push_back(t);
    }

    for (int i = 0; i < N; ++i) {
        cin >> t;
        process.push_back(t);
    }

    int i = 1, j;
    while (i < N && process[i - 1] <= process[i]) ++i;
    j = i;
    while (i < N && process[i] == num[i]) ++i;

    if (i == N) {
        cout << "Insertion Sort" << endl;
        sort(process.begin(), process.begin() + j + 1);
    } else {
        cout << "Heap Sort" << endl;
        i = N - 1;
        while (i >= 1 && process[i] >= process[0]) --i;
        swap(process[0], process[i]);
        downAdjust(process, 0, i - 1);
    }

    cout << process[0];
    for (int l = 1; l < N; ++l) {
        cout << " " << process[l];
    }

    return 0;
}
