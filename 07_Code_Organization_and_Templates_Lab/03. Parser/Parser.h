#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
/*if (type == 'i') {
        Parser<int> p(std::cin, stopLine);
        int n;
        std::vector<int> numbers;
        while (p.readNext(n)) {
            numbers.push_back(n);
        }
        printVector(numbers);
    }
    else if (type == 'w') {
        Parser<std::string> p(std::cin, stopLine);
        std::string w;
        std::vector<std::string> words;
        while (p.readNext(w)) {
            words.push_back(w);
        }
        printVector(words);
    }*/

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