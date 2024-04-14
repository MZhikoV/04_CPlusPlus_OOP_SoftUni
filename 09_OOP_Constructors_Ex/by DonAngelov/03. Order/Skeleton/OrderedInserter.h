#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include "Company.h"
#include <vector>
#include <algorithm>

// Place your code here, as well as any other #include directives you might need
/*vector<const Company*> companies;

	OrderedInserter inserter{ companies };
    */


class OrderedInserter {
    std::vector<const Company *> & companyVector;
    public:
    OrderedInserter(std::vector<const Company*> & inpVector): companyVector(inpVector) {};

    void insert(const Company * c) {

        struct findData {
            int searchId;
            findData(int searchId): searchId(searchId) {};

            bool operator()(const Company* other) {
                return other->getId()>searchId;
            };
        }
        finder(c->getId());


            std::vector<const Company *>::iterator itFound=find_if(companyVector.begin(),companyVector.end(), finder);

            companyVector.insert(itFound,c);
    };

};


#endif // !ORDERED_INSERTER_H
