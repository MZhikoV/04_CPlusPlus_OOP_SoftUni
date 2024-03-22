#ifndef CAR_H
#define CER_H

#include<string>

using namespace std;

class Car {
    string brand;
    string model;
    int year;

    public:
        Car(const string & iBrand, const string & iModel, const int & iYear)
        : brand(iBrand), model(iModel), year(iYear) {};

    string GetBrand() const {
        return this->brand;
    };

    string GetModel() const {
        return this->model;
    };

    int GetYear() const {
        return this->year;
    };
};



#endif