#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

#include <string>
#include <map>
#include <sstream>



std::string getProfitReport(Company * startData, Company * endData,std::map<int, ProfitCalculator> & profitCalculatorsByCompany) {

    std::ostringstream ostr;
    for(startData; ; startData++) {
        //profitCalculatorsByCompany[startData->getId()]

        ostr<<startData->getName()<<" = "<<profitCalculatorsByCompany[startData->getId()].calculateProfit(*startData)<<std::endl;
        if (startData==endData) {
            break;
        };
    };

return ostr.str();
}





/*
	Company* fromInclusive = &companies[0];
	Company* toInclusive = &companies[companies.size() - 1];

	cout << getProfitReport(fromInclusive, toInclusive, profitCalculatorsByCompany) << endl*/

#endif // !PROFIT_REPORT_H
