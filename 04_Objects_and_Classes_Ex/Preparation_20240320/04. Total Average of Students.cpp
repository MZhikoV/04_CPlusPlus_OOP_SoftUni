#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

class Student {

    string name;
    string surname;
    double totalAvg;

    public:
    Student (): totalAvg(0) {};
    Student (istream & istr);

    string getName() {return name;};
    string getSurname() {return surname;};
    double getAvg() {return totalAvg;};

    string printStudent();
};

Student::Student(istream & istr) {
    istr>>name>>surname>>totalAvg;
}

string Student::printStudent() {
    ostringstream outp;
    outp<<name<<' '<<surname<<' '<<totalAvg<<endl;

    return outp.str();
};


double calculateAvg(vector<Student> &students) {
     double sumAvg=0;

    for (auto & currentS:students) {
     cout<<currentS.printStudent();
        sumAvg+=currentS.getAvg();
    };
    return sumAvg/students.size();
}



int main() {

    vector<Student> students;

    int num;
    cin>>num;
    int inpStudentsNum=num;
    cin.ignore();

    if(num<=0) {
        cout<<"Invalid input"<<endl;
        return 1;
    };

    while (inpStudentsNum--) {
        students.push_back(cin);
    };

   
    cout<<calculateAvg(students)<<endl;
    
    
    system("pause");
    return 0;
}
