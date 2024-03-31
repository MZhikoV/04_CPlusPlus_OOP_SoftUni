#ifndef ARRAYP_H
#define ARRAYP_H

#include "Company.h"
#include <vector>

class ArrayOfPointers {

std::vector<Company *> companies;

public:
ArrayOfPointers() = default;

void add(Company *c) {
    companies.push_back(c);
};

size_t getSize() const {
    return companies.size();
};


Company * get(size_t num) {
    return companies[num];
};




};

#endif