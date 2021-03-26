#include<queue>
#include<iostream>

using namespace std;

struct node {
    int x, y;

    node(int x, int y) : x(x), y(y) {}

    bool operator<(const node &b) const   //写在里面只用一个b，但是要用const和&修饰，并且外面还要const修饰;
    {
        if (x == b.x) return y >= b.y;
        else return x > b.x;
    }
};

int main() {
    priority_queue<node> pq;
    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
            pq.push(node(i, j));
    while (!pq.empty()) {
        cout << pq.top().x << " " << pq.top().y << endl;
        pq.pop();
    }
    return 0;
}