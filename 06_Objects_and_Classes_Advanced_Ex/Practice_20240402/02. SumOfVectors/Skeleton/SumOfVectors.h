#ifndef SUMOFVECTORS_H
#define SUMOFVECTORS_H

#include <vector>
#include <string>



std::vector<std::string> operator+(const std::vector<std::string> & a, const std::vector<std::string> & b) {
    std::vector<std::string>result;
    result.resize(a.size());

    for (size_t idx=0; idx<a.size(); idx++) {
        result[idx]=a[idx]+' '+b[idx];
    };
    return result;
};

#endif // !SUMOFVECTORS_H
