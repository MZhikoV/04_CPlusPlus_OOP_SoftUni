#ifndef TRYPARSEE_H
#define TRYPARSEE_H

#include <sstream>
#include <string>

bool tryParse(const std::string & input, int & num) {
    std::string buffer;
    std::istringstream istr(input);
    if (istr>>num) {
        return true;
    }
    else {
        return false;
    };
};



#endif