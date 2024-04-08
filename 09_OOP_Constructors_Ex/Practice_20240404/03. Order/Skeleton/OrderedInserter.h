#ifndef ORDERED_INSERTERR_H 
#define ORDERED_INSERTERR_H

#include "Company.h"

#include <vector>
#include <algorithm>



//create class with Function Call Operator () for comparing class elements by specific criteria 
class VectorIdComparer {
        private:
        int searchId;
    public:
    VectorIdComparer(int searchId): searchId(searchId) {};

    bool operator()(const Company* other) const {
        return other->getId()>searchId;
    };
};


//using find_if algorithm with the created predicate 

class OrderedInserter {

std::vector<const Company*> & companies;

public:
    OrderedInserter(std::vector<const Company*> & companies ) : companies(companies) {};

    void insert(const Company* c) {

        VectorIdComparer vectorPredicate(c->getId());

        std::vector<const Company*>::iterator itFound=find_if(companies.begin(), companies.end(), vectorPredicate);

        companies.insert(itFound,c);
    };         
};




#endif // !ORDERED_INSERTER_H
