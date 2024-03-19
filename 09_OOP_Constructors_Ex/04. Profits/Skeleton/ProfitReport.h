#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"
#include <string>
#include <sstream>

// Place your code here, as well as any other #include directives you might need

//	cout << getProfitReport(fromInclusive, toInclusive, profitCalculatorsByCompany) << endl;

std::string getProfitReport( Company * startP,  Company* endP, std::map<int, ProfitCalculator> & calculatedProfit) {

std::string separator=" = ";
std::ostringstream result;

for(;;){
result<<(startP->getName())<<separator<< calculatedProfit[startP->getId()].calculateProfit(*startP)<<std::endl;

if(startP==endP) {
    break;
}
else {
    startP++;
}

};
return result.str();
};



#endif // !PROFIT_REPORT_H
