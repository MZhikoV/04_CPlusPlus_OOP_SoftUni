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

class Students {
    private:
        string name;
        string surname;
        double average;
        double totalAverage=0;

    public:
        void setInfo(string & inpName, string & inpSurname, double & inpAvg) {
            name=inpName;
            surname=inpSurname;
            average=inpAvg;
        }

        void setAvg() {
            totalAverage+=average;
        }

        string getInfo();

        double getAvg(int & num);
};

string Students::getInfo () {
    ostringstream outp;
    outp<<name<<' '<<surname<<' '<<average<<endl;
    return outp.str();
};

double Students::getAvg(int & num) {
    return totalAverage/num;
};


int main() {
    int num;
    cin>>num;
    
    if (num>0) {
    vector<Students> stV;

    Students student;
    int count=num;
    while (count-- && count>=0) {
        string name;
        string surname;
        double avg;
        cin>>name>>surname>>avg;
        student.setInfo(name,surname,avg);
        student.setAvg();
        stV.push_back(student);
    }

    for (int i=0; i<num;i++) {
        cout<<stV[i].getInfo();
    }

    cout<<student.getAvg(num)<<endl;
    }
    else {
        cout<<"Invalid input"<<endl;
    }

    system("pause");
    return 0;
}
