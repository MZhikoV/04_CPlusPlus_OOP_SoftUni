#include "IndexedSet.h"



 //IndexedSet::

/*
    std::set<Value> valuesSet;
    Value * valuesArray;
*/


    IndexedSet::IndexedSet(): valuesArray(nullptr) {};


    IndexedSet::IndexedSet(const IndexedSet& other): valuesArray(nullptr) {
        *this=other;
    };


    void IndexedSet::add(const Value& v) {
        if (valuesSet.insert(v).second) { //check if we have an insertion
            clearIndex(); //adding elements to set, invalidating cash, new indexing will occure
        };
    };


    size_t IndexedSet::size() const {
        return valuesSet.size();
    };


    const Value& IndexedSet::operator[](size_t index) {
        if (valuesArray==nullptr) {
            buildIndex();
        };
        return valuesArray[index];
    };


    IndexedSet& IndexedSet::operator=(const IndexedSet& other) {
        if (this!=&other) {
            clearIndex();
            valuesSet=other.valuesSet;
        };
        return *this;
    };


    IndexedSet::~IndexedSet() {
        clearIndex();
    };


    void IndexedSet::buildIndex() {
        clearIndex();

        valuesArray= new Value[valuesSet.size()];
        size_t curr=0;
        for (auto c:valuesSet) {
            valuesArray[curr++]=c;
        };
    };


    void IndexedSet::clearIndex() {
        if (valuesArray!=nullptr) {
            delete [] valuesArray;
        };
        valuesArray=nullptr;
    };
