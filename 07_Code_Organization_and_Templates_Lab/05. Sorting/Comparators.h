#ifndef COMPARATORS_H
#define COMPARATORS_H

using namespace std;

/*if (type == 'i') {
		Parser<int> p(std::cin, stopLine);
		int n;
		typedef std::set<int, Reverse<int, LessThan<int> > > Set;
		Set numbers;
		while (p.readNext(n)) {
			numbers.insert(n);
		}
		printContainer<Set>(numbers.begin(), numbers.end());*/


template <typename T> class LessThan {

    public:
     bool operator() (const T & first , const T & second) const {
    return first < second;
};
};


template <typename T, typename Comparator> class Reverse {
    
    public:
    bool operator() (const T & first, const T & second) const {
        Comparator compElem;
        return !compElem(first,second);
    };
};


#endif // !COMPARATORS_H