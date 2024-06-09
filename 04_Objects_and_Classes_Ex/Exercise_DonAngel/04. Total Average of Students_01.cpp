#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;



class Student
{
    string sName;
    string sSurname;
    double sAverage;

public:
    Student() : sAverage(0){};
    Student(istream &istr);
    string printStudent();
    double getAverage() {return sAverage;};
};

Student::Student(istream &istr)
{
    getline(istr,sName);
    getline(cin,sSurname);
    istr >> sAverage; istr.ignore();
};

string Student::printStudent() {
    ostringstream ostr;
    ostr<<sName<<' '<<sSurname<<' '<<sAverage<<endl;
    return ostr.str();
};

typedef vector<Student> studentV;

double averageStudents(studentV & dataVector) {
        double average=0;
    for (auto currAverage:dataVector) {
        average+=currAverage.getAverage();
    }
    return average/dataVector.size();
}



int main()
{

    

    studentV studentsData;

    int studentsNum;
    cin >> studentsNum;
    cin.ignore();

    if (studentsNum <= 0)
    {
        cout << "Invalid input" << endl;
        return 0;
    };

    studentsData.reserve(studentsNum);

    while (studentsNum--)
    {
        studentsData.push_back(Student(cin));
    }

    for (auto currStudent:studentsData) {
        cout<<currStudent.printStudent();
    }

   // cout<<fixed<<setprecision(1)<<
    cout<<averageStudents(studentsData)<<endl;

    system("pause");
    return 0;
}
