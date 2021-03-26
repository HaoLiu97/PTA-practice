#include <bits/stdc++.h>

using namespace std;

#define MAXLEN 10005

int main() {
    char s1[MAXLEN], s2[MAXLEN];
    cin.getline(s1, MAXLEN, '\n');
    cin.getline(s2, MAXLEN, '\n');
    unordered_map<char, int> u_map;
    int i = 0;
    while (s2[i] != 0) {
        u_map[s2[i]] = 1;
        ++i;
    }

    i = 0;
    while (s1[i] != 0) {
        if(!u_map[s1[i]]) {
            printf("%c", s1[i]);
        }
        ++i;
    }

    return 0;
}
