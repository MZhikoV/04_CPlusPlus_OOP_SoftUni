#ifndef array_hh
#define array_hh

#include <vector>



template <typename T> class Array: public std::vector<T> {


public:
    Array (size_t sizeA) : std::vector<T>(sizeA) {};

    size_t getSize() const {
        return this->size();
    };

};





#endif