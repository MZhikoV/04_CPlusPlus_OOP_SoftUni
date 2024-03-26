#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

template <typename T> class Parser{
    std::istream & istr;
    std::string stopLine;

    public:
    
    Parser(std::istream & istr, const std::string & stopLine) : istr(istr), stopLine(stopLine) {};

    bool readNext(T & n) {
        std::string buffer;
        getline(istr,buffer);
        if (buffer!=stopLine) {
            std::istringstream iss(buffer);
            T temp;
            iss>>temp;
            n=temp;
            return true;
        }
        else {
            return false;
        };
    };

    

};





/*if (type == 'i') {
		Parser<int> p(std::cin, stopLine);
		int n;
		std::vector<int> numbers;
		while (p.readNext(n)) {
			numbers.push_back(n);
		}
		printVector(numbers);
	}*/


#endif