#ifndef Comparators_hh
#define Comparators_hh


template <typename T> struct LessThan {
	bool operator() (const T & first, const T & second ) const {
		return first<second;
	};
};


template <typename T, typename Comparator> class Reverse {
	public:
	bool operator () (const T & first, const T & second) const {
		Comparator comp;
		return (!comp(first,second));
	};
};


/*
if (type == 'i') {
		Parser<int> p(std::cin, stopLine);
		int n;
		typedef std::set<int, Reverse<int, LessThan<int> > > Set;
		Set numbers;
		while (p.readNext(n)) {
			numbers.insert(n);
		}
		printContainer<Set>(numbers.begin(), numbers.end());
	}
	else if (type == 'w') {
		Parser<std::string> p(std::cin, stopLine);
		std::string w;
		typedef std::set<std::string, Reverse<std::string, LessThan<std::string> > > Set;
		Set words;
		while (p.readNext(w)) {
			words.insert(w);
		}
		printContainer<Set>(words.begin(), words.end());
	}
	else if (type == 's') {
		Parser<Song> p(std::cin, stopLine);
		Song s;
		typedef std::set<Song, Reverse<Song, LessThan<Song> > > Set;
		Set songs;
		while (p.readNext(s)) {
			songs.insert(s);
		}
		printContainer<Set>(songs.begin(), songs.end());
*/



#endif