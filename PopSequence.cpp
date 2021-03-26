#include <bits/stdc++.h>

using namespace std;

int M, N;

bool solve(vector<int> &sequence) {
    if (N == 0) {
        return true;
    }
    stack<int> Stack;
    int cur_push = 1, cur_pop_index = 0;
    while(cur_pop_index < N) {
        while(Stack.empty() || Stack.top() != sequence[cur_pop_index]) {
            if(cur_push > N || Stack.size() >= M) {
                break;
            }
            Stack.push(cur_push++);
        }
        if(Stack.top() != sequence[cur_pop_index]) {
            return false;
        }
        Stack.pop();
        cur_pop_index ++;
    }
    return true;
}

int main() {
    int K, t;
    cin >> M >> N >> K;
    stack<int> s;
    vector<int> sequence;
    for (int i = 0; i < K; ++i) {
        sequence.clear();
        for (int j = 1; j <= N; ++j) {
            cin >> t;
            sequence.push_back(t);
        }

        if (solve(sequence)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
