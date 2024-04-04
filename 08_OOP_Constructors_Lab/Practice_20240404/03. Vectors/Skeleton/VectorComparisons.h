#ifndef VECTORR_H
#define VECTORR_H

#include "Vector.h"


class VectorLengthComparer { 
    public:
    bool operator() (const Vector& leftSide, const Vector& rightSide) const {
        return leftSide.getLength()<rightSide.getLength();
    };
};


template <typename T, typename Comparer> class ReverseComparer {

    Comparer comparator;
    public:
    bool operator() (const T & first, const T & second) const {
        return !comparator(first,second);
    };
};


#endif