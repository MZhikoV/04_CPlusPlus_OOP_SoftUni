#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"

#include <memory>
#include <string>
#include <vector>
#include <set>
#include <sstream>



Company * parseUniqueCompanies(const std::string &input, int & numCompanies, std::string (*byParameter) (const Company& c)) {

std::vector<Company> companies;
std::set<std::string>uniqueIds;

std::istringstream istr(input);

int id;
while (istr>>id) {
    std::string name;
    istr>>name;

    Company c(id,name); 
    std::string uniqueId=byParameter(c);

    if (uniqueIds.find(uniqueId) == uniqueIds.end()) {
        uniqueIds.insert(uniqueId);
        companies.push_back(c);
    };
};

Company * returnArr=new Company[companies.size()];

for (size_t numCompanies=0; numCompanies<companies.size(); numCompanies++) {
    returnArr[numCompanies]=companies[numCompanies];
};

return returnArr;
}

#endif // !PARSE_COMPANIES_H
