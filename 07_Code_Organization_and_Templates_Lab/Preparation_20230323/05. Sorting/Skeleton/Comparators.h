#ifndef COMPARATORS_H
#define COMPARATORS_H

template <class T> class LessThan {
    public:
    bool operator () (const T & first, const T & second) const {
        return first<second;
    };
};

template <typename T, typename Comparator> class Reverse {
    public:
    bool operator() (const T & first, const T & second) const {
        Comparator elementC;
        return !elementC(first,second);
    };
};

#endif