#ifndef ARRP_H
#define ARRP_H

#include <vector>
#include <memory>

#include "Company.h"

class ArrayOfPointers {

std::vector<Company *> data;

public:
void add(Company *c) {data.push_back(c);};

size_t getSize(void) const {return data.size();};

Company * get(size_t idx) {return data[idx];}

~ArrayOfPointers() {
    for (Company* curr:data) {
        delete curr;
    }
}


};



#endif