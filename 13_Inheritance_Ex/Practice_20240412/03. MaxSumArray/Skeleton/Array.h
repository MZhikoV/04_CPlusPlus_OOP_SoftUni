#ifndef ARRAYYY_H
#define ARRAYYY_H

#include <vector>



template <typename T> class Array: public std::vector<T> {

    public:

    Array(size_t arrSize) : std::vector<T>(arrSize) {};

    size_t getSize() const {
        return this->size();
    };
};



#endif