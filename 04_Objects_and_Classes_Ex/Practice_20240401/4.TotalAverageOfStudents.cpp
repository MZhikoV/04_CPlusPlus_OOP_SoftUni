#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

class Student {
    string name;
    string surname;
    double average;

    public:
    Student(istream & istr) {
        getline(istr,name);
        getline(istr,surname);
        istr>>average; istr.ignore();
    }
   // Student(string nam, string surn, double avg) : name(nam),surname(surn), average(avg) {};
    double getAverage() {
        return average;
    };
    
    string getName() {
        return name;
    };

    string getSurname() {
        return surname;
    };

};

int num;
cin>>num;
cin.ignore();

double totalAvg;
vector < Student> students;
while (num--) {
    Student a(cin);
    students.push_back(a);
    totalAvg+=a.getAverage();
};

for (auto curr:students) {
    cout<<curr.getName()<<' '<<curr.getSurname()<<' '<<curr.getAverage()<<endl;
};

cout<<totalAvg/students.size();


system("pause");
return 0;
}