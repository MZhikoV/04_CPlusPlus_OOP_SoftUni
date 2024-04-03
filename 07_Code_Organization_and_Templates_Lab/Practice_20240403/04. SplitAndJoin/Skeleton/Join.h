#ifndef JOINN_H
#define JOINN_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template <typename T> string join(vector<T> & data, const string & joinStr) {
    ostringstream ostr;
    bool isFirst=true;
    for ( T & curr : data) {
        if (isFirst) {
            isFirst=false;
        }
        else {
            ostr<<joinStr;
        };
        ostr<<curr;
    };
    ostr<<endl;
    return ostr.str();
};




/*
std::vector<int> numbers = split<int>(line, separator);
		joined = join(numbers, joinStr);
        */
#endif