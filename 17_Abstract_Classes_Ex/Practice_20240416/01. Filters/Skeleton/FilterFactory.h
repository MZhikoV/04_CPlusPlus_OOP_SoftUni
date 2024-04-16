#ifndef FilterFactory_hh
#define FilterFactory_hh

#include "Filter.h"


class FilterCapitals: public Filter {

public:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol>='A' && symbol<='Z');
    };
};

class FilterLowLetters: public Filter {

public:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol>='a' && symbol<='z');
    };
};

class FilterNumbers: public Filter {

public:
    virtual bool shouldFilterOut(char symbol) const override {
        return (symbol>='0' && symbol<='9');
    };
};


class FilterFactory {

public:
    Filter* buildFilter(const std::string & filterDefinition) const {
         
         if (filterDefinition=="0-9"){
                return new FilterNumbers();
            }
            else if (filterDefinition=="A-Z"){
                return new FilterCapitals();
            } else {
                return new FilterLowLetters();
            };
    };
};



#endif