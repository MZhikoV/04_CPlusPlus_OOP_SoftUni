#ifndef TRYPARSE_H
#define TRYPARSE_H

#include <string>
#include <sstream>

bool tryParse(const std::string input, int & num) {
        std::istringstream istr(input);
        if (istr>>num) {
    return true;
        }
        else {
            return false;
        }
};




#endif