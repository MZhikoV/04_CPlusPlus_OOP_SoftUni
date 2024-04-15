#ifndef REMOVEDUP_H
#define REMOVEDUP_H

#include <list>
#include <set>

using namespace std;

void removeDuplicates(std::list<Company*> ::iterator it, std::list<Company *>& companies) {

    std::set<Company*>companiesToDelete;

    Company* theCompany=*it;

    std::string theName=theCompany->getName(); 

    it++;
    while (it!=companies.end())
    {
        if(*it==theCompany) {
            it=companies.erase(it); //delete just the occurance in the list
        }
        else if ((*it)->getName()==theName) {
            //we have just found company with the same name, but not the same pointer
            //add it for deletion
            companiesToDelete.insert(*it);
            it=companies.erase(it);
        }
        else {
            it++;
        }
    }
    

    for(auto company:companiesToDelete) {
        delete company;
    }

};

void removeDuplicates(std::list<Company*> & companies) {
    auto itCurr=companies.begin();

    while (itCurr!=companies.end())
    {
        removeDuplicates(itCurr,companies);
        itCurr++;
    };    
};


#endif