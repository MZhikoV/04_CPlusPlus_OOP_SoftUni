#ifndef operators_h
#define operators_h

#include <ostream>
#include <vector>
#include <string>
#include <sstream>


std::string operator+(std::string leftside, int rightside) {
    std::ostringstream ostr;
    ostr<<leftside<<rightside;
    return ostr.str();
};

std::vector<std::string>& operator<<(std::vector<std::string>& leftside, std::string rightside) {
    leftside.push_back(rightside);
    return leftside;
};

std::ostream& operator<<(std::ostream & out, std::vector<std::string>&rightside) {
    std::ostringstream ostr;
    for (size_t i=0; i<rightside.size(); i++) {
        ostr<<rightside[i]<<std::endl;
    }
   return out<<ostr.str();
};


#endif