#ifndef FilterFactory_h
#define FilterFactory_h

#include "Filter.h"
#include <string>


class NumbersFilter:public Filter {

    protected:
	virtual bool shouldFilterOut(char symbol) const {
        return symbol>='0' && symbol<='9';
    };
};

class AllCapsFilter:public Filter {

    protected:
	virtual bool shouldFilterOut(char symbol) const {
        return symbol>='A' && symbol<='Z';
    };
};

class SmallLettersFilter:public Filter {

    protected:
	virtual bool shouldFilterOut(char symbol) const {
        return symbol>='a' && symbol<='z';
    };
};

class FilterFactory {

    public:

        Filter* buildFilter(const std::string & filterDefinition) const {
            if (filterDefinition=="0-9"){
                return new NumbersFilter();
            }
            else if (filterDefinition=="A-Z"){
                return new AllCapsFilter();
            } else {
                return new SmallLettersFilter();
            };
        };
};


#endif