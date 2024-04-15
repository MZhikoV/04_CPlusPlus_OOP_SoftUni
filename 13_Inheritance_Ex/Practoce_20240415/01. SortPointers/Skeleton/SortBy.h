#ifndef SORT_BY_H
#define SORT_BY_H

#include "Company.h"
#include <algorithm>


void sortBy(Company**  &begin, Company** end, bool(*lessThanBy)(const Company& a , const Company& b)) {

    std::sort(*begin,*end,lessThanBy);

    // for (Company **i = begin; i < end; i++)
    // {
    //     for (Company **j = begin; j < (end - 1); j++)
    //     {
    //         if (!lessThanBy(**(j), **(j + 1)))
    //         {
    //             std::swap(**(j), **(j + 1));
    //         };
    //     };
    // };

};


//sortBy(companyPtrs, companyPtrs + numCompanies, lessThanByName);

//companyPtrs[i] = new Company(id, name);

//bool lessThanByName(const Company& a, const Company& b)

#endif // !SORT_BY_H
