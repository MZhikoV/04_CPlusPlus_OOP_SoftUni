#ifndef VECTORCOMPARISONS_H
#define VECTORCOMPARISONS_H

#include <iostream>
#include "Vector.h"

class VectorLengthComparer {
    public:
    bool operator()(const Vector &a, const Vector & b) const {
        return a.getLength()<b.getLength();
    };
};

template <typename T, typename Comp>  class ReverseComparer {
    public:
    Comp comparer;

    bool operator() (const T &a, const T &b) const {
        return comparer(b,a);
    };
};

#endif