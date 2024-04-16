#ifndef CityUtils_h
#define CityUtils_h

#include "City.h"
#include <string>
#include <map>



City * initCity(std::string name, size_t population) {

    return new City(name,population);
};


std::map<size_t,const City*>  groupByPopulation(std::vector<const City*> cities, size_t & totalPopulation ) {

    std::map<size_t,const City*> ordered;
    int sum=0;

    for (auto currCity:cities) {
        ordered[(currCity->getPopulation())]=currCity;
        sum+=currCity->getPopulation();
    };

    totalPopulation=sum;


    // std::vector<const City*> result;

    // for (auto it=ordered.begin(); it!=ordered.end();it++) {
    //     result.push_back((*it).second);
    // };
return ordered;
 
};


/*

size_t totalPopulation
groupByPopulation(cities, totalPopulation);
*/



/*
std::vector<const City*> cities;

std::string name;
		size_t population;
		std::cin >> name >> population;

		cities.push_back(initCity(name, population));
*/

#endif