#ifndef cow_h
#define cow_h

#include "animal.h"

#include <iostream>
#include <sstream>

class Cow : public Animal {

    unsigned milkPerDay; 
    //unsigned activeHours;

    public:

        Cow(std::istream & istr) : milkPerDay(0) {
            istr >> milkPerDay;
        };

         virtual unsigned getResult(unsigned weeks) const {
            return 7*milkPerDay * weeks;
        };

        virtual std::string getDescription() const { return "Cow"; };

        virtual std::string getInfo() const {
            std::ostringstream ostr;
            ostr << '<' << milkPerDay << ">";

            return ostr.str();
        };

};




#endif