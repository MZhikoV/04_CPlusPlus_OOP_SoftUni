#ifndef PARSERI_H
#define PARSERI_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T> class Parser {
    istream & istr;
    string stopLine;

    public:
        Parser(istream & istr, const string & stopLine) : istr(istr), stopLine(stopLine) {};


    bool readNext(T & n) {
        string buffer;
        getline(istr,buffer);
        if (buffer!=stopLine) {
            istringstream ist(buffer);
            ist>>n;
            return true;
        }
        else {
            return false;
        }
    };
};


/*
Parser<int> p(std::cin, stopLine);
		int n;
		std::vector<int> numbers;
		while (p.readNext(n)) {
			numbers.push_back(n);
		}
		printVector(numbers);
        */

#endif