#ifndef MIN_BY_H
#define MIN_BY_H

#include <string>
#include <vector>

std::string minBy(const std::vector<std::string> & values, bool (* lessBy)(const std::string& a, const std::string& b)) {
    std::string result=values[0];

    for (size_t idx=1; idx<values.size(); idx++) {
        if (lessBy(values[idx],result)) {
            result=values[idx];
        };
    };

    return result;
};

// minBy(values, lessThanByLex) 

#endif // !MIN_BY_H
