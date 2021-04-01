#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define INF 0x3f3f3f3f;

struct Student {
    string ID, name;
    int grade;
};

int main() {
    ios::sync_with_stdio(false);
    int N, C;
    cin>>N>>C;
    string ID, name;
    int grade;
    vector<Student> students;
    for(int i = 0; i < N; ++i) {
        cin>>ID>>name>>grade;
        students.push_back(Student{ID, name, grade});
    }

    if(C == 1) {
        sort(students.begin(), students.end(), [](Student &a, Student & b) -> bool {
            return a.ID < b.ID;
        });
    } else if(C == 2) {
        sort(students.begin(), students.end(), [](Student &a, Student & b) -> bool {
            if(a.name == b.name) {
                return a.ID < b.ID;
            }
            return a.name < b.name;
        });
    } else {
        sort(students.begin(), students.end(), [](Student &a, Student & b) -> bool {
            if(a.grade == b.grade) {
                return a.ID < b.ID;
            }
            return a.grade < b.grade;
        });
    }

    for(auto s:students){
        cout<<s.ID<<" "<<s.name<<" "<<s.grade<<endl;
    }

    return 0;
}
