#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
    string brand;
    string model;
    int year;
    public:
    Car(string & nBrand, string & nModel, int & nYear) : brand(nBrand), model(nModel), year(nYear) {};

    string GetBrand() const{
        return brand;
    };

    string GetModel() const{
        return model;
    };

    int GetYear() const{
        return year;
    };
};

#endif // !CAR_H
