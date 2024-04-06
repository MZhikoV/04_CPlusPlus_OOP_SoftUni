#ifndef FIND_H
#define FIND_H

#include "Company.h"

#include <vector>



Company * find(std::vector<Company*> & companies, const int & searchId) {
    std::vector<Company*>::iterator it1=companies.begin();

    for (; it1!=companies.end(); it1++) {
        if ((*it1)->getId()==searchId) {
            return *it1;
        };
    };
    return nullptr;
};


/*string searchIdLine;
	getline(cin, searchIdLine);
	int searchId = stoi(searchIdLine);

	Company* companyWithSearchedId = find(companies, searchId);
    */
#endif // !FIND_H
