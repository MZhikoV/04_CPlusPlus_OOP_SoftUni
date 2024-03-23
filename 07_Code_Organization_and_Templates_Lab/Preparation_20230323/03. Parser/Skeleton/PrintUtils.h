#ifndef PRINT_V_H
#define PRINT_V_H

#include "Parser.h"

#include <vector>
#include <iostream>

template <typename T> void printVector(const std::vector<T> & inp) {
    for (const T  & elem:inp) {
        std::cout<<elem<<' ';
    };
    std::cout<<std::endl;
}

// template <typename T> std::ostream & operator<<(std::ostream & ostr,  T & rightHand) {
//     return ostr<<rightHand;
// }



#endif