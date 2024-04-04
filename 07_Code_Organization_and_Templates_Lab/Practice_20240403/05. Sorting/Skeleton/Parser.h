#ifndef PARSEER_H
#define PARSEER_H

#include<iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T> class Parser {
    istream & istr;
    string endLine;

    public:
        Parser(istream & istr, string endLine) : istr(istr), endLine(endLine) {};

    bool readNext( T & elem) {
        string buffer;
        getline(istr,buffer);
        if (buffer!=endLine) {
        istringstream ist(buffer);
        ist>>elem;
        return true;
        }
        else {
            return false;
        };
    };
};

#endif