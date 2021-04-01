#include <bits/stdc++.h>

using namespace std;

struct Person{
    string name;
    int age, worth;
};

int main() {
    int N, K;
    cin>>N>>K;
    ios::sync_with_stdio(false);
    vector<Person> persons;
    string name;
    int age, worth;

    for(int i = 0; i < N; ++i) {
        cin>>name>>age>>worth;
        persons.push_back(Person{name, age, worth});
    }

    sort(persons.begin(), persons.end(), [](Person &a, Person&b) -> bool {
        if(a.worth == b.worth) {
            if(a.age == b.age) {
                return a.name < b.name;
            }
            return a.age < b.age;
        }
        return a.worth > b.worth;
    });

    int M, Amin, Amax;
    for(int i = 1; i <= K; ++i) {
        cin>>M>>Amin>>Amax;
        cout<<"Case #"<<i<<":"<<endl;
        int cnt = 0;
        for(int j = 0; j < persons.size(); ++j) {
            if(cnt >= M) break;
            if(persons[j].age >= Amin && persons[j].age <= Amax) {
                cout<<persons[j].name<<" "<<persons[j].age<<" "<<persons[j].worth<<endl;
                cnt++;
            }
        }
        if(cnt == 0) {
            cout<<"None"<<endl;
        }
    }

    return 0;
}
