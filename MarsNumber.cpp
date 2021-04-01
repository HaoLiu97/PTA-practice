#include <bits/stdc++.h>

using namespace std;


vector<string> mars = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
vector<string> higher = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
unordered_map<string, int> num;
unordered_map<string, int> higher_num;

string convert2mars(int num) {
    string ret;
    if(num == 0) {
        return "tret";
    }

    if(num % 13 == 0) {
        num = num / 13;
        ret = higher[num % 13];
        num = num / 13;
    } else {
        ret = mars[num % 13];
        num = num / 13;
    }
    while (num) {
        ret = higher[num % 13] + " " + ret;
        num = num / 13;
    }

    return ret;
}


int main() {
    for (int i = 0; i < mars.size(); ++i) {
        num[mars[i]] = i;
    }

    for (int i = 0; i < higher.size(); ++i) {
        higher_num[higher[i]] = i;
    }

    int N;
    cin >> N;
    string input;
    getchar();
    for (int i = 0; i < N; ++i) {
        getline(cin, input);
        if (isdigit(input[0])) {
            cout << convert2mars(stoi(input)) << endl;
        } else {
            stringstream ss(input);
            vector<string> mars_num;
            string t;
            while (ss >> t) {
                mars_num.push_back(t);
            }
            int ans = 0;
            if (mars_num.size() >= 2) {
                for (int j = 0; j <= (int) mars_num.size() - 2; ++j) {
                    ans = ans * 13 + higher_num[mars_num[j]];
                }
                ans = ans * 13 + num[mars_num[mars_num.size() - 1]];
            } else {
                ans = num[mars_num[0]];
                if (ans == 0) {
                    ans = higher_num[mars_num[0]] * 13;
                }
            }
            cout << ans << endl;
        }
    }


    return 0;
}
