#ifndef REMOVE_INVALIDD_H
#define REMOVE_INVALIDD_H

#include "Company.h"

#include <list>


void removeInvalid(std::list<Company*> & companies) {

    for (auto it1=companies.begin(); it1!=companies.end();) {
        if ((*it1)->getId()<0) {
            it1=companies.erase(it1);
        }
        else {
            it1++;
        };
    };
};

#endif // !REMOVE_INVALID_H