#ifndef SORTBY_H
#define SORTBY_H

#include "Company.h"

#include <algorithm>

template <typename Iterator>
void swap(Iterator a, Iterator b) {
    auto temp = *a;
    *a = *b;
    *b = temp;
}

template <typename Iterator, typename Comparator>
void sortBy(Iterator begin, Iterator end, Comparator comp) {
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = begin; j != end - 1; ++j) {
            if (!comp(**j, **(j + 1))) {
                swap(j, j + 1);
            }
        }
    }
}



#endif //SORTBY_H