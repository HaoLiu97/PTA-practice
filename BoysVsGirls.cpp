#include <bits/stdc++.h>

using namespace std;

struct Student {
    string name, gender, ID;
    int grade;
};

int main() {
    int N;
    cin>>N;
    Student male{"", "M", "", 101}, female{"", "F", "", -1};
    string name, gender, ID;
    int grade;

    for(int i = 0; i < N; ++i) {
        cin>>name>>gender>>ID>>grade;
        if(gender == "M") {
            if(grade < male.grade) {
                male.name = name;
                male.ID = ID;
                male.grade = grade;
            }
        } else {
            if(grade > female.grade) {
                female.name = name;
                female.ID = ID;
                female.grade = grade;
            }
        }
    }

    bool flag = false;
    if(female.grade == -1) {
        cout<<"Absent"<<endl;
        flag = true;
    } else {
        cout<<female.name<<" "<<female.ID<<endl;
    }

    if(male.grade == 101) {
        cout<<"Absent"<<endl;
        flag = true;
    } else {
        cout<<male.name<<" "<<male.ID<<endl;
    }

    if(flag) {
        cout<<"NA"<<endl;
    } else {
        cout<<female.grade-male.grade<<endl;
    }

    return 0;
}
