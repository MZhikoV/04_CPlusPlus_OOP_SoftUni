#ifndef PrintUtils_hh
#define PrintUtils_hh


template <typename T> void printContainer (typename T::iterator begin, typename T::iterator end) {
    for (;begin!=end;begin++) {
        cout<<*begin;
    }
    cout<<endl;
};


//std::set<int, Reverse<int, LessThan<int> > >
//printContainer<Set>(numbers.begin(), numbers.end());

#endif