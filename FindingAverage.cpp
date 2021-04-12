#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N, legal_cnt = 0;
    cin >> N;
    string str;
    double sum = 0, temp;

    char a[50], b[50];
    for (int i = 0; i < N; ++i) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++)
            if(a[j] != b[j]) flag = 1;
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            legal_cnt++;
        }
    }

    if (legal_cnt == 1) {
        printf("The average of 1 number is %.2lf\n", sum);
    } else if (legal_cnt >= 2) {
        printf("The average of %d numbers is %.2lf\n", legal_cnt, sum / legal_cnt);
    } else {
        printf("The average of 0 numbers is Undefined\n");
    }

    return 0;
}
