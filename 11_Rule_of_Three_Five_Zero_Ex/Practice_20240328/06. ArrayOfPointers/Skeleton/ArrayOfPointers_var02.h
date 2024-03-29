#ifndef ARRP_H
#define ARRP_H

#include <vector>
#include <memory>

#include "Company.h"

class ArrayOfPointers {

std::vector<std::shared_ptr<Company>> data;

public:
void add(Company *c) {data.push_back(std::shared_ptr<Company>(c));};

size_t getSize(void) const {return data.size();};

Company * get(size_t idx) {return data[idx].get();}

};



#endif