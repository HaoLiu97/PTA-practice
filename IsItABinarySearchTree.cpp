#include <bits/stdc++.h>

using namespace std;

bool isBinarySearchTree(vector<int> &node, int left, int right, bool mirror) {
    if (left >= right) {
        return true;
    }
    int root = node[left];
    int index = left + 1;
    if (!mirror) {
        for (; node[index] < root && index <= right; ++index);
        for (int i = index; i <= right; ++i) {
            if (node[i] < root) {
                return false;
            }
        }
    } else {
        for (; node[index] >= root && index <= right; ++index);
        for (int i = index; i <= right; ++i) {
            if (node[i] >= root) {
                return false;
            }
        }
    }
    return isBinarySearchTree(node, left + 1, index - 1, mirror) && isBinarySearchTree(node, index, right, mirror);
}

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
    int index = left + 1;
    if (!mirror) {
        for (; node[index] < root && index <= right; ++index);
    } else {
        for (; node[index] >= root && index <= right; ++index);
    }
    convert(node, left + 1, index - 1, mirror);
    convert(node, index, right, mirror);
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
    if (isBinarySearchTree(node, 0, N - 1, false)) {
        cout << "YES" << endl;
        convert(node, 0, N - 1, false);
        for (int i = 0; i < post_order.size(); ++i) {
            cout << post_order[i];
            if (i != post_order.size() - 1) {
                cout << " ";
            }
        }
    } else if (isBinarySearchTree(node, 0, N - 1, true)) {
        cout << "YES" << endl;
        convert(node, 0, N - 1, true);
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
