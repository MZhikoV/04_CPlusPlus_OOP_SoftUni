#ifndef OPERATORS_H
#define OPERATORS_H

#include <ostream>
#include <vector>
#include <string>
#include <sstream>


//std::vector<std::string> formattedLines;
//formattedLines << heading << separator;


std::vector<std::string>& operator<<(std::vector<std::string> & inp, std::string rightSide) {
    inp.push_back(rightSide);
    return inp;
};

std::string operator+(const std::string & leftSide, const int & rigthSide) {
    std::ostringstream ostr;
    ostr<<leftSide<<rigthSide;
    return ostr.str();
};

void operator<<(std::ostream & ostr, std::vector<std::string> & inp) {
    std::ostringstream ost;
    for (std::string & curr:inp) {
        ostr<<curr<<std::endl;
    };
    //return ost.str();
}







#endif // !OPERATORS_H
