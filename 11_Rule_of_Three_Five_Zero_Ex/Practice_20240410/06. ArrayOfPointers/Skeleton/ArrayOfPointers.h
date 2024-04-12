#ifndef arrpoint_h
#define arrpoint_h

#include "Company.h"

#include <vector>




class ArrayOfPointers {
        std::vector<Company *> arr;
        //int arr_comp;
    public:
        ArrayOfPointers();

        void add(Company* c);

        size_t getSize() const;

        Company* get(int i);

        ~ArrayOfPointers();

};



#endif