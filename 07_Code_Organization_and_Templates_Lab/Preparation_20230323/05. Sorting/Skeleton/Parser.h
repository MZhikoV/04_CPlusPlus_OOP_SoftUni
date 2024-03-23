#ifndef PARSER_HH
#define PARSER_HH

#include "PrintUtils.h"
#include "Song.h"
#include <iostream>
#include <sstream>
#include <string>

/*Parser<int> p(std::cin, stopLine);
		int n;
		typedef std::set<int, Reverse<int, LessThan<int> > > Set;
		Set numbers;
		while (p.readNext(n)) {
			numbers.insert(n);
		}
		printContainer<Set>(numbers.begin(), numbers.end());
	}*/

template <typename T> class Parser {
    std::istream & istr;
    std::string stopLine;

    public:
    Parser(std::istream & inp, const std::string & inpLine): istr(inp),stopLine(inpLine) {};

    bool readNext( T & inp) {
        std::string buffer;
        getline (istr,buffer);
        if (buffer==stopLine) {
            return false;
        }
        else {
            std::istringstream istr(buffer);
            istr>>inp;
            return true;
        };

    };
};


#endif