#ifndef REMOVE_DUPLICATES_H
#define REMOVE_DUPLICATES_H

#include "Company.h"
#include <list>
#include <set>

using namespace std;

void removeDuplicates(list<Company*>::iterator it, list<Company*> &companies) {

set<Company*> companiesToDelete;

Company * theCompany=*it;

string theName=theCompany->getName();

it++;

    while (it!=companies.end()) {
        if (*it==theCompany) {
            it=companies.erase(it); //delete just the occurance in the list
        }
        else if ((*it)->getName()==theName) {
            companiesToDelete.insert(*it);
            it=companies.erase(it); 
        }
        else {
            it++;
        };

        for (auto &curr:companiesToDelete) {
            delete curr;
        };
    };
};

void removeDuplicates(list<Company*> &companies) {

    auto it=companies.begin();

    while (it!=companies.end()) {

        removeDuplicates(it, companies);
        it++;
    };
};

#endif // !REMOVE_DUPLICATES_H
