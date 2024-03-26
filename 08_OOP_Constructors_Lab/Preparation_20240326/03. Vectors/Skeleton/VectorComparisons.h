#ifndef VECTORCOMPARISON_H
#define VECTORCOMPARISON_H

#include "Vector.h"

class VectorLengthComparer {
public:
bool operator () (const Vector & first, const Vector & second) const {
    return first.getLength()<second.getLength();
}

};


template <typename T, typename Comparer> class ReverseComparer {
    public:
    bool operator () (const T & first, const T & second) const {
        Comparer compare;
    return !(compare(first,second));
};
};


#endif