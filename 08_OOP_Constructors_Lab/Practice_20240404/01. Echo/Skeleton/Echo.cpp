#ifndef ECHOO_H
#define ECHOO_H

#include <iostream>


#include "Echo.h"

bool echoOn=true;

void echo(const std::string & input) {
    if (echoOn) {
    std::cout<<input<<std::endl;
    };
};



#endif