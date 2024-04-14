#ifndef FIND_H
#define FIND_H

#include "Company.h"

#include<vector>


//Company* companyWithSearchedId = find(companies, searchId);

Company* find(const std::vector<Company*> & compV, const int & searchedId ) {
    for (auto it1=compV.begin(); it1!=compV.end(); it1++) {
        if ((*it1)->getId()==searchedId) {
            return *it1;
        }
    }
    return nullptr;
}



#endif // !FIND_H

