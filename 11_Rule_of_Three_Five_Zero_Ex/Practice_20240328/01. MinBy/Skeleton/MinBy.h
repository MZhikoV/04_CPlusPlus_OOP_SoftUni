#ifndef MIN_BY_H
#define MIN_BY_H

// Place your code here
#include <string>
#include <vector>

 std::string minBy(const std::vector<std::string> & values, bool (*lessThanBy)(const std::string& a, const std::string& b)) {
    std::string less=values[0];

    for (const std::string & curr:values) {
        if(lessThanBy(curr,less)) {
            less=curr;
        };
    };
    return less;
 };

#endif // !MIN_BY_H
