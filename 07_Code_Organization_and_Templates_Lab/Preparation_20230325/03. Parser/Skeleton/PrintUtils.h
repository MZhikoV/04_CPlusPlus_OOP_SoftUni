#ifndef PRINTUTILS_H
#define PRINTUTILS_H

#include "Parser.h"

template <typename T>void printVector(const std::vector<T> & numbers) {
       
        bool isFirst=true;
        
        for (const T & elem:numbers) {
            
            if(isFirst) {
            isFirst=false;
            }
            else {
                std::cout<<' ';
            };

            std::cout<<elem;
        };
        std::cout<<std::endl;
    };

#endif