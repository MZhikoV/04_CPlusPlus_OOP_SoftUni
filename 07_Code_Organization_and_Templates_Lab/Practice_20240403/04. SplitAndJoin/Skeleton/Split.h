#ifndef SPLITT_H
#define SPLITT_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T> vector<T> split( string & line, const char & separator) {
    vector<T>result;
    istringstream istr(line);
    string buffer;
    while (getline(istr,buffer,separator)) {
        istringstream ist(buffer);
        T temp;
        ist>>temp;
        result.push_back(temp);
    };
    return result;
};



/*
std::vector<int> numbers = split<int>(line, separator);
		joined = join(numbers, joinStr);
        */

#endif