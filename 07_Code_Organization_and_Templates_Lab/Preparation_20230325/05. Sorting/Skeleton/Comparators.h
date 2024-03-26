#ifndef COMPARATORS_H
#define COMPARATORS_H

template <typename T> class LessThan {

    public:

    bool operator()(const T & first, const T & second) const {
        return first<second;
    };
};

template <typename T, typename Comparator> class Reverse {

    Comparator comparator;

    public:
    bool operator<(const Reverse & other) const {
        return false;
    }
}





/*char type;
	std::cin >> type; std::cin.ignore();
	std::string stopLine;
	std::getline(std::cin, stopLine);

	if (type == 'i') {
		Parser<int> p(std::cin, stopLine);
		int n;
		typedef std::set<int, Reverse<int, LessThan<int> > > Set;
		Set numbers;
		while (p.readNext(n)) {
			numbers.insert(n);
		}
		printContainer<Set>(numbers.begin(), numbers.end());
	}*/

#endif