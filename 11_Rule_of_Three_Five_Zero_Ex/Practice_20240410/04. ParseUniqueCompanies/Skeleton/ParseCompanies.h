#ifndef PARSE_COMPANIES_H
#define PARSE_COMPANIES_H

#include "Company.h"

#include <string>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <memory>


Company* parseUniqueCompanies(const std::string & input, int & numCompanies, std::string (*byCrit)(const Company& c)) {

    std::vector<Company> sortedComp;
    std::set<std::string> uniqueParam;

    std::istringstream istr(input);

    int cid;

    while (istr>>cid) {
        std::string name;
        istr>>name;

        Company c(cid,name);

        std::string param=byCrit(c);

        auto itFount=uniqueParam.find(param);
        if (itFount==uniqueParam.end()) {
            uniqueParam.insert(param);
            sortedComp.push_back(c);
        };
    };

        Company * returnArr= new Company [sortedComp.size()];

        for ( numCompanies=0; numCompanies<sortedComp.size(); numCompanies++) {
            returnArr[numCompanies]=sortedComp[numCompanies];
        };

        /*Company * returnArr=new Company[companies.size()];

for (size_t numCompanies=0; numCompanies<companies.size(); numCompanies++) {
    returnArr[numCompanies]=companies[numCompanies];
};*/

        // std::vector<std::unique_ptr<Company *>> returnArr;

        // for (size_t numCompanies=0; numCompanies<sortedComp.size(); numCompanies++) {

        // std::unique_ptr<Company *>Currcomp=std::make_unique<Company *>(sortedComp[numCompanies]);

        // returnArr.push_back(Currcomp);
        // };

    return returnArr;
}

/*
int numCompanies;
	Company* companies;

    int numCompanies;
	
	if (uniquenessCriteria == 1) {
		companies = parseUniqueCompanies(input.str(), numCompanies, byId);

        std::string byId(const Company& c) {
	std::ostringstream asStringOut;
	asStringOut << c.getId();
	return asStringOut.str();
}

*/


// Place your code here

#endif // !PARSE_COMPANIES_H
