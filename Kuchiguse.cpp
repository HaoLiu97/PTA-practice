#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

const int INF = 0x3f3f3f3f;

int main() {
    freopen("in.txt", "r", stdin);
    int N;
    cin>>N;
    vector<string> sentence;
    string str;
    int min_len = INF;
    cin.ignore();
    for(int i = 0; i < N; ++i) {
        getline(cin, str);
        sentence.push_back(str);
        min_len = min(min_len, (int)str.length());
    }

    int i = 1;
    bool flag = false;
    while(i <= min_len) {
        char cur = sentence[0][sentence[0].size()-i];
        for(int j = 1; j < N; ++j) {
            if(sentence[j][sentence[j].size()-i] != cur) {
                flag = true;
                break;
            }
        }
        if(flag) {
            break;
        }
        ++i;
    }

    --i;
    if(i == 0) {
        cout<<"nai"<<endl;
    } else {
        string s = sentence[0].substr(sentence[0].size()-i, i);
        s.erase(0,s.find_first_not_of(' '));
        cout<<s<<endl;
    }

    return 0;
}
