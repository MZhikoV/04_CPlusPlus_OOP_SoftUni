#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;


template <typename T> class Parser
{
    istream &inp;
    string endLine;

public:
    Parser(istream &inp, const string &endLine) : inp(inp), endLine(endLine){};

    bool readNext(T &methodT)
    {
        string buffer;
        getline(inp, buffer);
        if (buffer == endLine)
        {
            return false;
        }
        istringstream istr(buffer);
        istr >> methodT;
        return true;
    }
};

#endif //! PARSER_H