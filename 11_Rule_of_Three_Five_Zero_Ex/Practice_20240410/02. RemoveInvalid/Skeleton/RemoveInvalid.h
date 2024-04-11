#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"


	void removeInvalid(std::list<Company*> & companies) {
        for (std::list<Company*>::iterator it=companies.begin(); it!=companies.end();) {
            if ((*it)->getId()<0) {
                it=companies.erase(it);                  
            }
            else {
                it++;
            };
        };
    };


// Place your code here

#endif // !REMOVE_INVALID_H
