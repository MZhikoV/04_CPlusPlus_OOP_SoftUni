#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"

#include <string>
#include <set>
#include <sstream>
#include <vector>

// Company* companies;
//companies = parseUniqueCompanies(input.str(), numCompanies, byId);
//std::string byId(const Company& c)

Company* parseUniqueCompanies(const std::string & input, int & numCompanies, std::string (*byCriteria)(const Company& c)) {

std::vector<Company > companies;
std::set<std::string> identifier;

std::istringstream istr(input);
int buffId;
std::string buffName;

while (istr>>buffId) {
    istr>>buffName;

    Company curr(buffId,buffName);
    std::string identify=byCriteria(curr);

    if(identifier.find(identify)==identifier.end()) {
        identifier.insert(identify);
        companies.push_back(curr);
        numCompanies++;
    };
};

Company* returnArr=new Company[companies.size()];

for (size_t idx=0; idx<companies.size(); idx++) {
    returnArr[idx]=companies[idx];
};
return returnArr;
};

#endif // !PARSE_COMPANIES_H
