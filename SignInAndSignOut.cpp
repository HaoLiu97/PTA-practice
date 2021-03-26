#include<bits/stdc++.h>

using namespace std;

int main() {
    int M, hour, minute, second;
    scanf("%d", &M);
    string ID_number;
    vector<string> IDs;
    int min_time = INT_MAX, max_time = INT_MIN;
    string min_num, max_num;
    int t;
    for (int i = 0; i < M; ++i) {
        cin>>ID_number;
        scanf("%d:%d:%d", &hour, &minute, &second);
        t = hour*3600+minute*60+second;
        if(t < min_time) {
            min_time = t;
            min_num = ID_number;
        }

        scanf("%d:%d:%d", &hour, &minute, &second);
        t = hour*3600+minute*60+second;
        if(t > max_time) {
            max_time = t;
            max_num = ID_number;
        }
    }

    cout<<min_num<<" "<<max_num;
    return 0;
}
