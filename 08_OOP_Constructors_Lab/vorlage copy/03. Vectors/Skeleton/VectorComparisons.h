#ifndef VectorComparisons_hh
#define VectorComparisons_hh

#include "Vector.h"


class VectorLengthComparer {

    public:

    bool operator() (const Vector & a, const Vector & b ) const {
        return a.getLength()<b.getLength();
    };
};



template <typename T, typename Comparer> class ReverseComparer {

public:
    Comparer comp;

    bool operator() (const T & left, const T & right) const {
        return !comp(left,right);
    };
};


#endif