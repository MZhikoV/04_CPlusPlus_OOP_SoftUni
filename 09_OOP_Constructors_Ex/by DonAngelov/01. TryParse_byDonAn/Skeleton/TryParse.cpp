#include <string>
#include <cctype>
#include "TryParse.h"

#include <sstream>


    bool tryParse (const std::string & a, int & b) {
       std::istringstream inp(a);

       bool result=(bool)(inp>>b);

        return result;
    };
