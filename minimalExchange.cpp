#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
vector<int> num, process;

int merge(vector<int> &a, int s1, int e1, int s2, int e2) {
    vector<int> tmp;
    int ret = 0;
    int p1 = s1, p2 = s2;
    while (p1 <= e1 && p2 <= e2) {
        if (a[p1] <= a[p2]) {
            tmp.push_back(a[p1++]);
        } else {
            tmp.push_back(a[p2++]);
            ret = ret + e1 - p1 + 1;
        }
    }

    while (p1 <= e1) {
        tmp.push_back(a[p1++]);
    }

    while (p2 <= e2) {
        tmp.push_back(a[p2++]);
        ret = ret + e1 - p1 + 1;
    }

    for (int i = 0; i < tmp.size(); ++i) {
        a[s1 + i] = tmp[i];
    }
    return ret;
}

int mergeSort(vector<int> &a) {
    int seg_len = 1;
    int len = a.size();
    int ret = 0;
    while (seg_len < len) {
        for (int i = 0; i + seg_len <= len - 1;) {
            ret += merge(a, i, i + seg_len - 1, i + seg_len, min(len - 1, i + 2 * seg_len - 1));
            i = i + 2*seg_len;
        }
        seg_len *= 2;
    }
    return ret;
}

int main() {
    int N;
    cin >> N;
    int t;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        num.push_back(t);
    }

    cout<<mergeSort(num);

    return 0;
}
