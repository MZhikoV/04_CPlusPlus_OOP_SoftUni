#ifndef OPERATORS_H
#define OPERATORS_H

#include <string>
#include <sstream>

std::vector<std::string> & operator<<(std::vector<std::string> & a, const std::string & b) {
    a.push_back(b);
    return a;
};

std::ostream & operator<<(std::ostream & out, const std::vector<std::string> & b) {
    for (auto & currEl:b) {
        out<<currEl<<std::endl;
    };
    return out;
}


std::string operator+(const std::string & a, const int & b) {
    std::ostringstream ostr;
    ostr<<a<<b;
    return ostr.str();
};


#endif