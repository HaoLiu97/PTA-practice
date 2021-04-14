#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

struct Student {
    string id;
    int Gp, Gmid, Gfinal, G;
};

int main() {
    int P, M, N, g;
    string id;
    cin >> P >> M >> N;
    unordered_map<string, int> u1, u2;
    for (int i = 0; i < P; ++i) {
        cin >> id >> g;
        if(g >= 200) {
            u1[id] = g;
        }
    }

    for (int i = 0; i < M; ++i) {
        cin >> id >> g;
        if (g == 0) g = -2;
        u2[id] = g;
    }

    vector<Student> ans;
    for (int i = 0; i < N; ++i) {
        cin >> id >> g;
        if (u1[id] >= 200) {
            int g_mid, g_total = g;
            if (u2[id] == -2) {
                g_mid = 0;
            } else if (u2[id] == 0) {
                g_mid = -1;
            } else {
                g_mid = u2[id];
            }
            if (g_mid > g) {
                g_total =  round(g_mid * 0.4 + g * 0.6);
            }

            if (g_total >= 60) {
                ans.push_back(Student{id, u1[id], g_mid, g, g_total});
            }
        }
    }

    sort(ans.begin(), ans.end(), [](Student &a, Student &b) -> bool {
        if (a.G == b.G) {
            return a.id < b.id;
        }
        return a.G > b.G;
    });

    for (auto &s:ans) {
        cout << s.id << " " << s.Gp << " " << s.Gmid << " " << s.Gfinal << " " << s.G << endl;
    }

    return 0;
}
