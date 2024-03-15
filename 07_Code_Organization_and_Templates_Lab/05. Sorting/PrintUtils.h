#ifndef PRINTUNITS_H
#define PRINTUNITS_H

using namespace std;


//printContainer<Set>(numbers.begin(), numbers.end());


template <typename T> void printContainer (typename T::iterator begin, typename T::iterator end) {

    for (; begin!=end;begin++) {
        cout<<*begin<<' ';
    }
    cout<<endl;
};






#endif //!PRINTUNITS_H