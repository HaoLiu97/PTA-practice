#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;

struct TreeNode {
    int left, right;

    TreeNode() {
        left = right = -1;
    };
};

TreeNode tree[40];
int r;

void postOrder(int root) {
    if (root == -1) {
        return;
    }
    postOrder(tree[root].left);
    postOrder(tree[root].right);
    if (root != r) {
        cout << root << " ";
    } else {
        cout<< r<<endl;
    }
}


int main() {
    int N;
    cin >> N;
    string op;
    int num;
    stack<int> s;
    int cur = -1;
    r = -1;

    for (int i = 0; i < 2 * N; ++i) {
        cin >> op;
        if (op == "Pop") {
            cur = s.top();
            s.pop();
        } else {
            cin >> num;
            s.push(num);
            if (r == -1) {
                r = num;
            }
            if (tree[cur].left == -1) {
                tree[cur].left = num;
            } else {
                tree[cur].right = num;
            }
            cur = num;
        }
    }

    postOrder(r);

    return 0;
}
