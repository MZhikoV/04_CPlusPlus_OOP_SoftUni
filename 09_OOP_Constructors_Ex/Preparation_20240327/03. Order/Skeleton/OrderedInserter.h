#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include "Company.h"

#include <vector>
#include <algorithm>


class OrderedInserter {
    private:
    std::vector<const Company*> & companies;

    public:
    OrderedInserter(std::vector<const Company*> & companies) :companies(companies) {};

    void insert(const Company* c) {
        struct findData{
            int searchId;
            findData(int searchId): searchId(searchId) {};

            bool operator()(const Company * other) {
                return other->getId()>searchId;
            };
        } finder(c->getId());

        std::vector<const Company *>::iterator itFound=std::find_if(companies.begin(), companies.end(),finder);

        companies.insert(itFound,c);
    };

};

// Place your code here, as well as any other #include directives you might need


/*inserter.insert((const Company*)c);*/

#endif // !ORDERED_INSERTER_H
