#ifndef PRINTS_H
#define PRINTS_H

#include<iostream>
#include <string>
#include <sstream>

using namespace std;

template <typename T> void printContainer (typename T::iterator begin, typename T::iterator end) {
    for (; begin!=end; begin++) {
        cout<<*begin<<' ';
    }
    cout<<endl;
};


/*
typedef std::set<int, Reverse<int, LessThan<int> > > Set;

		printContainer<Set>(numbers.begin(), numbers.end());
        */


#endif