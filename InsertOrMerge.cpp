#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;
vector<int> num, process;

int merge(vector<int> &a, int start, int mid, int end) {
    vector<int> tmp;
    int ret = 0;
    int p1 = start, p2 = mid + 1;
    while (p1 <= mid || p2 <= end) {
        if (p2 > end || (p1 <= mid && a[p1] <= a[p2])) {
            tmp.push_back(a[p1++]);
        } else {
            tmp.push_back(a[p2++]);
            ret = ret + mid - p1 + 1;
        }
    }

    for (int i = 0; i < tmp.size(); ++i) {
        a[start + i] = tmp[i];
    }

    return ret;
}

void mergeSort(vector<int> &a) {
    int seg_len = 1;
    int len = a.size();
    while (seg_len < len) {
        int sum = 0;
        for (int i = 0; i + seg_len <= len - 1;) {
            sum += merge(a, i, i + seg_len - 1, min(len - 1, i + 2 * seg_len - 1));
            i = i + 2*seg_len;
        }
        if(sum != 0) {
            break;
        }
        seg_len *= 2;
    }
}

int main() {
    int N;
    cin >> N;
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
        cout << "Merge Sort" << endl;
        mergeSort(process);
    }

    cout << process[0];
    for (int l = 1; l < N; ++l) {
        cout << " " << process[l];
    }

    return 0;
}
