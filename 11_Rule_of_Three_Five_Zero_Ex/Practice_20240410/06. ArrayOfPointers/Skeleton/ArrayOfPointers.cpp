#include "ArrayOfPointers.h"



// class ArrayOfPointers {
//         Company * arr=new Company();
//     public:
        
        ArrayOfPointers::ArrayOfPointers() {};

        void ArrayOfPointers::add(Company* c) {
            arr.push_back(c);
        };

        size_t ArrayOfPointers::getSize() const {
            return arr.size();
        };

        Company* ArrayOfPointers::get(int i) {
            return arr[i];
        };

        ArrayOfPointers::~ArrayOfPointers() {
            for (Company * curr:arr) {
                delete curr;
            };
        }

