#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

#include <sstream>
#include <map>


std::string getProfitReport(Company * startP, Company * endP, std::map<int, ProfitCalculator> & profitCalculatorsByCompany) {
    std::ostringstream ostr;

    for (startP; startP<=endP;startP++) {
        //        ostr<<((*startP).getName())<<" = "<<profitCalculatorsByCompany.find((*startP).getId())->second.calculateProfit(*startP)<<std::endl;

        ostr<<((*startP).getName())<<" = "<<profitCalculatorsByCompany[(*startP).getId()].calculateProfit(*startP)<<std::endl;
    };

    return ostr.str();
}




//cout<< id<<" = "<<profit
//cout << getProfitReport(fromInclusive, toInclusive, profitCalculatorsByCompany) 

//Company* fromInclusive = &companies[0];
//	Company* toInclusive = &companies[companies.size() - 1];
//map<int, ProfitCalculator> profitCalculatorsByCompany;


// Place your code here, as well as any other #include directives you might need

#endif // !PROFIT_REPORT_H
