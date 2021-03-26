#include <bits/stdc++.h>

using namespace std;

vector<int> post_order;

void convert(vector<int> &node, int left, int right, bool mirror) {
    if (left > right) {
        return;
    }
    int root = node[left];
    if (left == right) {
        post_order.push_back(root);
        return;
    }
    int i = left + 1, j = right;
    if (!mirror) {
        while (i <= right && node[i] < root)++i;
        while (j >= left + 1 && node[j] >= root)--j;
    } else {
        while (i <= right && node[i] >= root)++i;
        while (j >= left + 1 && node[j] < root)--j;

    }
    if (i - j != 1) {
        return;
    }
    convert(node, left + 1, j, mirror);
    convert(node, i, right, mirror);
    post_order.push_back(root);
}

int main() {
    int N, t;
    cin >> N;
    vector<int> node;
    for (int i = 0; i < N; ++i) {
        cin >> t;
        node.push_back(t);
    }

    convert(node, 0, N - 1, false);
    if (post_order.size() != N) {
        post_order.clear();
        convert(node, 0, N - 1, true);
    }

    if (post_order.size() == N) {
        cout << "YES" << endl;
        for (int i = 0; i < post_order.size(); ++i) {
            cout << post_order[i];
            if (i != post_order.size() - 1) {
                cout << " ";
            }
        }
    } else {
        cout << "NO" << endl;
    }


    return 0;
}
