#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Student {
    string name;
    string surname;
    double avg;

public:
    Student() : avg(0) {};
    Student(istream & istr) {
        istr>>name>>surname>>avg;
    }

    string getName() const {return name;};

    string getSurname() const {return surname;}

    double getAvg() const {return avg;}

};

int main() {

    int num;
    double totalAvg=0;
    cin>>num;

    vector<Student> students;

    for (int i=0; i<num;i++) {
        Student curr(cin);
        students.push_back(curr);
    };

    if (students.empty()) {
        cout<<"Invalid input"<<endl;
    }
    else {
        for (auto el:students) {
            cout<<el.getName()<<' '<<el.getSurname()<<' '<<el.getAvg()<<endl;
            totalAvg+=el.getAvg();
        };
        cout<<totalAvg/num<<endl;
    };

    system("pause");
    return 0;
}