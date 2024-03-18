#include <string>
#include <cctype>
#include "TryParse.h"


    bool tryParse (const std::string & a, int & b) {
        for (size_t i=0; i<a.length();i++) {
            if (isalpha(a[i])) {
                return false;
            };
        };

        
        b=stoi(a);
        return true;
    };
