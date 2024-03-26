#ifndef SPLIT_H
#define SPLIT_H


#include <vector>
#include <string>
#include <sstream>

template <typename T> std::vector<T> split(const std::string & line, const char & separator) {
   std::vector<T> result;

    std::istringstream istr(line);
    std::string temp;
    while (getline(istr,temp,separator)) {
    std::istringstream buffer(temp);
    T tempPart;
    buffer>>tempPart;
    result.push_back(tempPart);
    };

    return result;
}



/*if (type == 'i') {
		std::vector<int> numbers = split<int>(line, separator);
		joined = join(numbers, joinStr);*/



#endif