#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

vector<int> sequence;
void heapPath(vector<int> &heap, int cur) {
    if(cur < heap.size()) {
        sequence.push_back(heap[cur]);
    }

    if (cur * 2 + 1 >= heap.size()) { // 是叶子节点
        for (int i = 0; i < sequence.size(); ++i) {
            cout << sequence[i] << " \n"[i == sequence.size() - 1];
        }
        return;
    }

    if(cur * 2 + 2 <= heap.size() - 1) {
        heapPath(heap, cur * 2 + 2);
        sequence.pop_back();
        heapPath(heap, cur * 2 + 1);
        sequence.pop_back();
    } else if(cur * 2 + 1 <= heap.size() - 1) {
        heapPath(heap, cur * 2 + 1);
        sequence.pop_back();
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin >> N;
    vector<int> heap(N);
    for (int i = 0; i < N; ++i) {
        cin >> heap[i];
    }

    heapPath(heap, 0);

    int type = -1;

    for(int i = 1; i < heap.size(); ++i) {
        if(heap[i] > heap[(i-1)/2]) {
            if(type == -1) {
                type = 1; // 小堆
            } else if(type == 2) { // 大堆
                type = 0; // 不是堆
                break;
            }
        }

        if(heap[i] < heap[(i-1)/2]) {
            if(type == -1) {
                type = 2; // 大堆
            } else if(type == 1) { // 小堆
                type = 0; // 不是堆
                break;
            }
        }
    }

    if(type == 0) {
        cout<<"Not Heap"<<endl;
    } else if(type == 1) {
        cout<<"Min Heap"<<endl;
    } else if(type == 2) {
        cout<<"Max Heap"<<endl;
    }

    return 0;
}
