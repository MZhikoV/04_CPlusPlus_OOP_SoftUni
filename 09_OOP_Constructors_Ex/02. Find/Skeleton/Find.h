#ifndef FIND_H
#define FIND_H

#include "Company.h"

#include <vector>


//Company* companyWithSearchedId = find(companies, searchId);

Company* find(const std::vector<Company*> & inpVector, const int & searchId) {
    for (auto it1=inpVector.begin(); it1!=inpVector.end(); it1++) {
        if ((*it1)->getId()==searchId) {
            return *it1;
        }
    }
    return nullptr;
};



#endif // !FIND_H

