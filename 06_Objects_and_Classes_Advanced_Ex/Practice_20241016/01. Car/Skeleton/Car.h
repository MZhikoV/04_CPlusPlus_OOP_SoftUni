#ifndef carrr_h
#define carrr_h

#include <string>

using namespace std;

class Car {

    std::string brand;
    std::string model;
    int year;

    public:
        Car () {};
        Car (std::string& inpBrand, std::string& inpModel, int& inpYear) 
        : brand(inpBrand), model(inpModel), year(inpYear) {};

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