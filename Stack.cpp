#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;
#define lowbit(x) ((x)&(-x))
#define MAXN 100005

int a[MAXN];
void update(int x, int v) {
    while(x < MAXN) {
        a[x] += v;
        x += lowbit(x);
    }
}

int prefixSum(int x) {
    int sum = 0;
    while(x) {
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}

int peekMedian(int n) {
    int left = 0, right = MAXN - 1;
    int median_index = (n+1)/2, mid;
    while(left < right) {
        mid = (left + right) >> 1;
        if(prefixSum(mid) < median_index) {
            left = mid + 1;
        } else {
            right = mid;
        };
    }
    return left;
}

int main() {
    int N;
    cin >> N;

    string op;
    int num;
    stack<int> Stack;
    for (int i = 0; i < N; ++i) {
        cin>>op;
        if(op == "Pop") {
            if(Stack.empty()) {
                cout<<"Invalid"<<endl;
            } else {
                update(Stack.top() , -1);
                cout<<Stack.top()<<endl;
                Stack.pop();
            }
        } else if(op == "PeekMedian") {
            if(Stack.empty()) {
                cout<<"Invalid"<<endl;
            } else {
                cout<<peekMedian(Stack.size())<<endl;
            }
        } else if(op == "Push"){
            cin>>num;
            Stack.push(num);
            update(num, 1);
        } else {
            cout<<"Invalid"<<endl;
        }
    }

    return 0;
}
