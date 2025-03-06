#pragma once
#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car
{
public:
Car(string brand, string model, int year)
 : sBrand(brand), sModel(model), nYear(year) {};

auto GetBrand() const ->string
{
    return sBrand;
}

auto GetModel() const ->string
{
    return sModel;
}

auto GetYear() const -> int
{
    return nYear;
}

private:
string sBrand;
string sModel;
int nYear;
};


#endif