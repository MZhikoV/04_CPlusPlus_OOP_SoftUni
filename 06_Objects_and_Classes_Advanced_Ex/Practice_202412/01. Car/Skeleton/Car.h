#ifndef car_h
#define car_h

#include <string>


using namespace std;

class Car {
    string brand;
    string model;
    int year;

    public:
    Car(string brandInp, string modelInp, int yearInp): brand(brandInp), model(modelInp), year(yearInp) {};

    string GetBrand() const {return brand;};

    string GetModel() const {return model;};

    int GetYear() const {return year;};
};



#endif