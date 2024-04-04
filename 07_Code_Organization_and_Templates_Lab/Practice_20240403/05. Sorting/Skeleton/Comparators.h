#ifndef COMPARR_H
#define COMPARR_H

#include<iostream>
#include <string>
#include <sstream>

template <typename T> class LessThan {
    public:
    bool operator() (const T & first, const T & second) {
        return first<second;
    };
};

template <typename T , typename Comparator> class Reverse {
    public:
        bool operator() (const T & first, const T & second) {
            Comparator compelem;
            return !compelem(first, second);
        };
};

/*
if (type == 'i') {
		Parser<int> p(std::cin, stopLine);
		int n;
		typedef std::set<int, Reverse<int, LessThan<int> > > Set;
		Set numbers;
		while (p.readNext(n)) {
			numbers.insert(n);
		}
		printContainer<Set>(numbers.begin(), numbers.end());
	}
    */

#endif