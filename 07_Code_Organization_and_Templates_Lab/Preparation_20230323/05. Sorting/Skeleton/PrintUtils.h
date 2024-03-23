#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include<iostream>



	//	printContainer<Set>(numbers.begin(), numbers.end());

template <typename T> void printContainer(typename T::iterator begin, typename T::iterator end) {
    for(; begin!=end; begin++){
        std::cout<<*begin<<' ';
    };
    std::cout<<std::endl;
};



#endif