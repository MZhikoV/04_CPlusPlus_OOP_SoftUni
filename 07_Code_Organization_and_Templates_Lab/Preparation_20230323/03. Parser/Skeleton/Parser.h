#ifndef PARSER_H
#define PARSER_H

#include "PrintUtils.h"

#include <iostream>
#include <sstream>

/*Parser<int> p(std::cin, stopLine);
		int n;
		std::vector<int> numbers;
		while (p.readNext(n)) {
			numbers.push_back(n);
		}
		printVector(numbers);*/


template <typename T> class Parser {
    std::string stopline;
    std::istream & istr;

    public:
    Parser(std::istream & istr, const std::string & line) : istr(istr), stopline(line) {};

    bool readNext( T & n) {
        std::string buffer;
        getline(istr,buffer);
        if (buffer==stopline) {
            return false;
        }
        else {
            std::istringstream istrn(buffer);
            istrn>>n;
            return true;
        };

        // while (istr>>n && n!=stopline) {
        //     return true;
        // };
        //     return false;
    };

};



#endif