#ifndef includes_h
#define includes_h

#include <iostream>
#include <sstream>
#include <vector>  //check if something needs vector in this file
#include "City.h" //same check here

class CityDiff: public City {

public:

    std::pair<City, City> diffP;

    int difference;
    CityDiff()=default;
    CityDiff(std::pair<City, City> & inp) : diffP(inp) {};
};


//overload operator istream for reading a city
std::istream & operator>>(std::istream & istr, City& city) {
    unsigned int censusYear;
	std::string name;
	size_t population;

    istr>>name>>population>>censusYear;

    city=City(censusYear,name,population);

    return istr;
};


std::ostream & operator<<(std::ostream & ostr, CityDiff & city) {
    if(city.diffP.first.getName()==city.diffP.second.getName()) {
        ostr<<city.diffP.first.getName()<<" ("<<city.diffP.first.getCensusYear()
        <<" vs. "<<city.diffP.second.getCensusYear()<<")"<<std::endl;
    }
    else {
        ostr<<city.diffP.first.getName()<<" ("<<city.diffP.first.getCensusYear()<<") vs. "
        <<city.diffP.second.getName()<<" ("<<city.diffP.second.getCensusYear()<<")"<<std::endl;
    };
    ostr<<"population: ";
    if (city.difference>0) {ostr<<'+';}
    ostr<<city.difference<<std::endl;
    return ostr;
};


CityDiff operator - (const City & a, const City & b) {
   
   std::pair<City,City> inpP;
   inpP=std::make_pair(a,b);
    CityDiff dff(inpP);
    dff.difference=a.getPopulation()-b.getPopulation();
   return dff;
};


#endif