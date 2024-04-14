#ifndef CAR_H
#define CAR_H


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

class Car {
    private:
    string cBrand;
    string cModel;
    int cYear;

    public:
    Car (const string & make, const string & model, const int & produced): cBrand(make), cModel(model), cYear(produced) {};
    
    const string & GetBrand() const {
        return cBrand;
    }

    const string & GetModel() const {
        return cModel;
    }

    const int & GetYear() const {
        return cYear;
    }

};




#endif // !CAR_H    