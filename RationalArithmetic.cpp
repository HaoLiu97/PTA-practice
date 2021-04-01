#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

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

int main() {
    ll a1, a2, b1, b2;
    scanf("%lld/%lld", &a1, &b1);
    scanf("%lld/%lld", &a2, &b2);
    RationNumber r1(a1, b1), r2(a2, b2);
    cout << r1.toString() << " + " << r2.toString() << " = " << RationNumber(a1 * b2 + a2 * b1, b1 * b2).toString()
         << endl;
    cout << r1.toString() << " - " << r2.toString() << " = " << RationNumber(a1 * b2 - a2 * b1, b1 * b2).toString()
         << endl;
    cout << r1.toString() << " * " << r2.toString() << " = " << RationNumber(a1 * a2, b1 * b2).toString() << endl;
    cout << r1.toString() << " / " << r2.toString() << " = " << RationNumber(a1 * b2, b1 * a2).toString() << endl;

    return 0;
}
