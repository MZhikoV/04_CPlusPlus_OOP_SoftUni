#ifndef range_h
#define range_h

#include "Range.h"

#include<algorithm>



    Range::Range() : rangeFirst(0), rangeLength(0), valueCounts(nullptr) {};



    void Range::add(T value){

        T first=rangeFirst;
        T last=rangeFirst+rangeLength-1;

        if (empty()) {
            resize(value,value);
        }
        else if (value<first) {
            resize(value,last);
        }
        else if (value>last) {
            resize(first,value);
        };

        valueCounts[getIndex(value)]++;

    };

    size_t Range::getCount(T value) const {
        //does the number belongs to the range
        if (value>=rangeFirst && value<=(rangeFirst+rangeLength-1)) {
            return valueCounts[getIndex(value)];
        }
        else {
            return 0;
        };
    };



    void Range::clear() {
         if (!empty()) {
            delete [] valueCounts;
            valueCounts=nullptr;
            rangeFirst=0;
            rangeLength=0;
        };
    };



    void Range::resize(T first, T last) {

        T newFirst=first;
        T newLength=last-first+1;

        size_t * newCounts= new size_t[newLength] {0};

        if (!empty()) {
            std::copy(valueCounts, valueCounts+rangeLength, newCounts+(rangeFirst-first));

        clear();
        };

        rangeFirst=newFirst;
        rangeLength=newLength;
        valueCounts=newCounts;
    };

    bool Range::empty() const {
        return valueCounts==nullptr;
    };

    Range::Range(const Range& other) : rangeFirst(0), rangeLength(0), valueCounts(nullptr) {
       *this=other;
    };

    Range& Range::operator=(const Range& other) {
        clear();

        rangeFirst=other.rangeFirst;
        rangeLength=other.rangeLength;
        valueCounts=copyValues(other);

        return *this;
    };

    Range::~Range() {
        clear();
    };

    size_t Range::getIndex(T value) const {
        return value-rangeFirst;
    };



#endif