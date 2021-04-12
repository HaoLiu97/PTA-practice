#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

void postOrder(vector<int> &heap, int cur) {
    if (cur >= heap.size())return;
    postOrder(heap, 2 * cur + 1);
    postOrder(heap, 2 * cur + 2);
    cout<<heap[cur]<<" \n"[cur==0];
}

int main() {
    freopen("in.txt", "r", stdin);
    int M, N;
    cin >> M >> N;
    for (int tc = 0; tc < M; ++tc) {
        vector<int> heap(N);
        for (int i = 0; i < N; ++i) {
            cin >> heap[i];
        }

        int type = -1;

        for (int i = 1; i < heap.size(); ++i) {
            if (heap[i] > heap[(i - 1) / 2]) {
                if (type == -1) {
                    type = 1; // 小堆
                } else if (type == 2) { // 大堆
                    type = 0; // 不是堆
                    break;
                }
            }

            if (heap[i] < heap[(i - 1) / 2]) {
                if (type == -1) {
                    type = 2; // 大堆
                } else if (type == 1) { // 小堆
                    type = 0; // 不是堆
                    break;
                }
            }
        }

        if (type == 0) {
            cout << "Not Heap" << endl;
        } else if (type == 1) {
            cout << "Min Heap" << endl;
        } else if (type == 2) {
            cout << "Max Heap" << endl;
        }
        postOrder(heap, 0);
    }

    return 0;
}
