#ifndef SumOfVectorss_h
#define SumOfVectorss_h


#include <vector>
#include <string>

std::vector<std::string> operator+(const std::vector<std::string>& left, const std::vector<std::string>& right) {
    
    std::vector<std::string> result;
    result.resize(left.size());

    for (int i=0; i<left.size();i++) {
        result[i]=left[i]+' '+right[i];
    };

    return result;
};





#endif