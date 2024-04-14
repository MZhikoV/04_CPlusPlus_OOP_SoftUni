#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

#include <sstream>
#include <string>

std::string getProfitReport(const Company* fromInclusive,const Company* toInclusive, std::map<int, ProfitCalculator> profitCalculatorsByCompany) {
    std::ostringstream ostr;

    for (fromInclusive; fromInclusive<=toInclusive; fromInclusive++) {
        ostr<<fromInclusive->getName();

        ostr<<" = ";

        ostr<<(profitCalculatorsByCompany[fromInclusive->getId()]).calculateProfit(*fromInclusive);

        ostr<<std::endl;
    };

return ostr.str();
};





//getProfitReport(fromInclusive, toInclusive, profitCalculatorsByCompany)
//Company* fromInclusive = &companies[0];
//Company* toInclusive = &companies[companies.size() - 1];
//map<int, ProfitCalculator> profitCalculatorsByCompany;

#endif // !PROFIT_REPORT_H
