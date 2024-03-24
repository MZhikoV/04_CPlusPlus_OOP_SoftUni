#ifndef SPLIT_HH
#define SPLIT_HH

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

/*
std::string joined = "";
	if (type == 'i') {
		std::vector<int> numbers = split<int>(line, separator);
		joined = join(numbers, joinStr);
	}
*/

    template <typename T> vector<T> split(const string & line, const char & separator) {
        vector<T> result;

        istringstream istr(line);
        string buffer;
        while (getline(istr,buffer,separator)) {
        istringstream bufferstream(buffer);
        T temp;
        bufferstream>>temp;
        result.push_back(temp);
        };

        return result;
    };


#endif