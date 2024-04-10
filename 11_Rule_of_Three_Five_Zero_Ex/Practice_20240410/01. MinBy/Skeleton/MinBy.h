#ifndef MIN_BY_H
#define MIN_BY_H

#include <vector>

std::string minBy(const std::vector<std::string> & values, bool (*lessThanBy)(const std::string& a, const std::string& b)) {
    std::string result=values[0];
    for (size_t idx=1;idx<values.size();idx++) {
        if (lessThanBy(values[idx],result)) {
            result=values[idx];
        };
    };
    return result;
}



/*

minBy(values, lessThanByLex)
std::vector<std::string> values =

bool lessThanByLex(const std::string& a, const std::string& b) {
	return a < b;
*/
// Place your code here

#endif // !MIN_BY_H
