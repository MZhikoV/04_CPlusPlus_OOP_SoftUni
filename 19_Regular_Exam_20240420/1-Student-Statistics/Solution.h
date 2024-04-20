#ifndef Solution_h
#define Solution_h

#include <vector>  //
#include <memory>  //
#include <string> //
#include <iostream> //
#include <sstream>

#include "BaseStudent.h"

using namespace std;




class Student : public BaseStudent {


public:

    Student() : BaseStudent () {};


void init(std::istream & iS) override {
    iS>>name>>grade;
};


static bool readStudent(vector<shared_ptr<Student>> &data, const string & buffer) {
    if (buffer=="end") {
        return false;
    }

    istringstream inp(buffer);
    
    Student stud;
    stud.init(inp);

    shared_ptr<Student> student=make_shared<Student>(stud);

    data.push_back(student);

    return true;
};



static vector<int> processStudents(vector<shared_ptr<Student>> data) {

    vector<int> result (10,0);
    
    for (auto & curr:data) {

        int grade=curr->getGrade();
        int vectorIdx=grade/10;

        if (vectorIdx==10) {
            vectorIdx=9;
        };
        result[vectorIdx]++;

    };

    return result;
};




};


Student t;

#define readStudent(data, buffer) t.readStudent(data, buffer)

#define processStudents(data) t.processStudents(data)



#endif