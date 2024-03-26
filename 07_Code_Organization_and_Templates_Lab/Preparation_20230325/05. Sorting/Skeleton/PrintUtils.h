#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include <iostream>


template <class T> void printContainer (typename T::iterator begin, typename T::iterator end) {

    for (;begin!=end;begin++) {
        std::cout<<*begin<<' ';
    };
    std::cout<<std::endl;
}





/*if (type == 'i') {
		Parser<int> p(std::cin, stopLine);
		int n;
		typedef std::set<int, Reverse<int, LessThan<int> > > Set;
		Set numbers;
		while (p.readNext(n)) {
			numbers.insert(n);
		}
		printContainer<Set>(numbers.begin(), numbers.end());*/

#endif