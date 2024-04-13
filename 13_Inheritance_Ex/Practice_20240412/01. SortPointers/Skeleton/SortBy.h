#ifndef SORT_BY_H
#define SORT_BY_H

#include <algorithm>

#include "Company.h"


void sortBy(Company** & begin, Company** end, bool (*lessThanBy)(const Company& a, const Company& b)) {

    //std::sort(**begin,**end,lessThanBy); 
    
    for (Company **i = begin; i < end; i++)
    {
        for (Company **j = begin; j < (end - 1); j++)
        {
            if (!lessThanBy(**(j), **(j + 1)))
            {
                std::swap(**(j), **(j + 1));
            };
        };
    };
};

/*
std::string minBy(const std::vector<std::string> & values, bool (*lessThanBy)(const std::string& a, const std::string& b)) {
    std::string less=values[0];

    for (const std::string & curr:values) {
        if(lessThanBy(curr,less)) {
            less=curr;
        };
    };
    return less;
 };

*/

//begin<end
//begin++

#endif // !SORT_BY_H
