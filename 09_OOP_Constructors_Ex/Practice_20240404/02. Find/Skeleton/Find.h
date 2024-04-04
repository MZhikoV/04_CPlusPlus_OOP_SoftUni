#ifndef FIND_H
#define FIND_H

#include "Company.h"
#include <vector> 
#include <iostream>

Company* find(std::vector<Company*> & companies, const int & searchID) {

   // Company * result;
    std::vector<Company*>::iterator it1=companies.begin();

    for ( ;it1!=companies.end();it1++ ) {
        if ((*it1)->getId()==searchID) {
            return *it1;
        }  
        };
        return nullptr;
}
#endif // !FIND_H
