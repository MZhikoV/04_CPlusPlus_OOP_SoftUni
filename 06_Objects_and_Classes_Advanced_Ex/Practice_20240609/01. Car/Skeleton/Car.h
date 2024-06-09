#ifndef car_h
#define car_h

#include <string>

using namespace std;

class Car {
    string brand;
    string model;
    int year;

public:
    Car(): year(0) {};
    Car(string inpBrand, string inpModel, int inpYear) : brand(inpBrand), model(inpModel), year(inpYear) {};

    string GetBrand() const {return brand;};

    string GetModel() const {return model;}

    int GetYear() const {return year;}
};



#endif