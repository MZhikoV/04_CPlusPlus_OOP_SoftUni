#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"

#include <memory>
#include <string>
#include <vector>



std::shared_ptr<Company> makeCompany (std::vector<std::string> & properties) {
    int id=stoi(properties[0]);
    std::string name=properties[1];
    std::vector<std::pair<char,char>> employees;

    for (size_t currEmp=2; currEmp<properties.size(); currEmp++) {
        employees.push_back(std::pair<char,char>(properties[currEmp][0],properties[currEmp][1]));
    };

    return std::shared_ptr<Company>(new Company(id,name,employees));

};




// /*  std::vector<std::string> */ int  {
//     std::vector<std::string> result;
//     int a;
//     return a;
// }

#endif // !MAKE_COMPANY_H
