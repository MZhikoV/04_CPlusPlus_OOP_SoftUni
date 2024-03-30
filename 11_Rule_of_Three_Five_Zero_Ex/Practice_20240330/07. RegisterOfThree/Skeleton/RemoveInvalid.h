#ifndef REMOVE_INVALID_H
#define REMOVE_INVALID_H

#include "Company.h"

bool removeInvalid(const Company& c) {
    if (c.getId()<=0) {
        return true;
    }
    else {
        return false;
    };
};

#endif // !REMOVE_INVALID_H
