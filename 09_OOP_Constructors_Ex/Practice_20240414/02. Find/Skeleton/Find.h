#ifndef FIND_H
#define FIND_H

#include "Company.h"

#include <vector>
#include <algorithm>



Company* find(std::vector<Company*> & companies,const int & searchId) {

for (size_t idx=0; idx<companies.size(); idx++) {
    if (companies[idx]->getId()==searchId) {
        return companies[idx];
    };
};

return nullptr;
};

//Company* companyWithSearchedId = find(companies, searchId);
//vector<Company*> companies;
//int searchId = stoi(searchIdLine);

#endif // !FIND_H
