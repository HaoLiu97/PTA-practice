#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll gcd(ll m, ll n) {
    ll t = 1;
    while (t != 0) {
        t = m % n;
        m = n;
        n = t;
    }
    return m;
}

class RationNumber {
public:
    ll a, b;
    bool pos;

    string toString() {
        if (a == 0 && b == 0) {
            return "Inf";
        }
        if (a == 0) {
            return "0";
        }
        string ret;
        ll integer = a / b;
        ll r_a;
        r_a = a % b;
        if (!pos) {
            ret += "(-";
        }

        if (integer) {
            ret += to_string(integer);
        }
        if (r_a != 0) {
            if (integer) {
                ret += " ";
            }
            ret += to_string(r_a) + "/" + to_string(b);
        }

        if (!pos) {
            ret += ")";
        }

        return ret;
    }

    RationNumber(ll a, ll b) {
        if (b == 0) {
            this->a = 0;
            this->b = 0;
            return;
        }
        if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
            pos = false;
            a = abs(a);
            b = abs(b);
        } else {
            pos = true;
        }
        int g = gcd(a, b);
        this->a = a / g;
        this->b = b / g;
    }
};

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    ll a1, a2, b1, b2;
    scanf("%d", &N);
    scanf("%lld/%lld", &a1, &b1);
    RationNumber cur_sum(a1, b1);

    for(int i = 1; i < N; ++i) {
        a1 = cur_sum.a;
        if(!cur_sum.pos) {
            a1 = -a1;
        }
        b1 = cur_sum.b;
        scanf("%lld/%lld", &a2, &b2);
        cur_sum = RationNumber(a1 * b2 + a2 * b1, b1 * b2);
    }

    cout<<cur_sum.toString()<<endl;

    return 0;
}
