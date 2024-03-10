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
    Car (string make, string model, int produced): cBrand(make), cModel(model), cYear(produced) {};
    
    string GetBrand() const {
        return this->cBrand;
    }

    string GetModel() const {
        return this->cModel;
    }

    int GetYear() const {
        return this->cYear;
    }

};




#endif // !CAR_H    